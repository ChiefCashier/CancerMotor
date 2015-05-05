#include "ObjectLoader.h"
#include "Buffer.h"

ObjectLoader::ObjectLoader()
{
}


ObjectLoader::~ObjectLoader()
{
}
Object* ObjectLoader::LoadObject(char* GameObjectName)
{
	std::vector<glm::vec3> vPosition;
	std::vector<glm::vec3> tPosition;
	std::vector<int> index;
	std::vector<int> uvIndex;

	int indexSize;
	int vertexSize;

	GLfloat* vertices;
	GLuint* indices;

	FILE * file = fopen(GameObjectName, "r");
	if (!file)
	{
		printf("kaik meni infernaalisesti\n");

	}

	else
	{
		while (1)
		{
			char line[128];

			int IsEof = fscanf(file, "%s", line);
			if (IsEof == EOF)
				break;
			if (strcmp(line, "v") == 0)
			{
				glm::vec3 vertex;
				fscanf(file, "%f", &vertex.x);
				fscanf(file, "%f", &vertex.y);
				fscanf(file, "%f", &vertex.z);
				vPosition.push_back(vertex);
			}
			if (strcmp(line, "vt") == 0)
			{
				glm::vec3 uv;
				fscanf(file, "%f", &uv.x);
				fscanf(file, "%f", &uv.y);
				fscanf(file, "%f", &uv.z);
				tPosition.push_back(uv);
			}
			if (strcmp(line, "f") == 0)
			{
				int uv;
				int tempus_index;
				fscanf(file, "%d/%d", &tempus_index, &uv);
				index.push_back(tempus_index);
				uvIndex.push_back(uv);

				fscanf(file, "%d/%d", &tempus_index, &uv);
				index.push_back(tempus_index);
				uvIndex.push_back(uv);

				fscanf(file, "%d/%d", &tempus_index, &uv);
				index.push_back(tempus_index);
				uvIndex.push_back(uv);
			}
		}


		indexSize = uvIndex.size();
		vertexSize = vPosition.size();
		vertices = new GLfloat[8 * indexSize];


		for (int i = 0; i < indexSize; i++)
		{
			int g = uvIndex.at(i) - 1;

			vertices[i * 8 + 0] = vPosition.at(index.at(i) - 1).x;
			vertices[i * 8 + 1] = vPosition.at(index.at(i) - 1).y;
			vertices[i * 8 + 2] = vPosition.at(index.at(i) - 1).z;
			vertices[i * 8 + 3] = /*0.0f;//*/ 0.74f;
			vertices[i * 8 + 4] = /*0.0f;//*/ 0.12f;
			vertices[i * 8 + 5] = /*0.0f;//*/ 0.25f;
			vertices[i * 8 + 6] = tPosition.at(g).x;
			vertices[i * 8 + 7] = tPosition.at(g).y;
		}

		indices = new GLuint[uvIndex.size()];
		int x = uvIndex.size();
		for (unsigned int i = 0; i < uvIndex.size(); i++)
		{
			indices[i] = i;
		}

		

	}

	Buffer b = Buffer();
	

	indexBuffer = b.CreateIndexBuffer(indices, uvIndex.size());
	vertexBuffer = b.CreateVertexBuffer(vertices, uvIndex.size());

	vertexArray = b.CreateVertexArray(vertexBuffer, indexBuffer, indices, vertices, uvIndex.size());


	Object* returnObj = new Object();

	returnObj->_indexSize = indexSize;
	returnObj->_vertexSize = vertexSize;
	returnObj->_indices = indices;
	returnObj->_vertices = vertices;
	returnObj->indexBuffer = indexBuffer;
	returnObj->vertexBuffer = vertexBuffer;
	returnObj->vertexArray = vertexArray;

	return returnObj;
}