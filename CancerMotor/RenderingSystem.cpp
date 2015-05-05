#include "RenderingSystem.h"


RenderingSystem::RenderingSystem(RenderingContext* rendContx)
{
	RC = rendContx;
	_projection = rendContx->get_projection();
}

RenderingSystem::~RenderingSystem()
{
	delete RC;
}

void RenderingSystem::Draw(GameObject* objectToDraw)
{
	if (objectToDraw->GetComponent<Renderable>() == nullptr || objectToDraw->GetComponent<Transformable>() == nullptr)
		return;
	ObjIT = drawableObj.begin();
	while (ObjIT != drawableObj.end())
	{

		if (*ObjIT == objectToDraw)
			return;
		ObjIT++;
	}
	drawableObj.push_back(objectToDraw);
}


void RenderingSystem::RenderFrame()
{
	

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glFlush();
	glUseProgram(RC->getProgramIndex());


	ObjIT = drawableObj.begin();
	while (ObjIT != drawableObj.end())
	{

		GameObject* OTD = *ObjIT;
		Renderable* Rend = OTD->GetComponent<Renderable>();

		Transformable* Trans = OTD->GetComponent<Transformable>();
		
		//glBindBuffer(GL_ARRAY_BUFFER, Rend->vertexBuffer);
	
		//glEnableVertexAttribArray(Rend->vertexArray);	
		glBindVertexArray(Rend->vertexArray);


		glUniform1f(RC->get_alphaChannel(), Rend->getAlpha());
		
		glm::mat4 _worldtransform = glm::translate(glm::vec3(Trans->GetOrigin()[0], Trans->GetOrigin()[1], Trans->GetOrigin()[2]));
		_worldtransform *= glm::rotate(Trans->GetRotation()[0], glm::vec3(0.0f, 1.0f, 0.0f)) * glm::rotate(Trans->GetRotation()[1], glm::vec3(1.0f, 0.0f, 0.0f)) * glm::rotate(Trans->GetRotation()[2], glm::vec3(0.0f, 0.0f, 1.0f));
		
		glUniformMatrix4fv(RC->get_worldIndex(), 1, GL_FALSE, glm::value_ptr(_worldtransform));

		

		//glVertexAttribPointer(RC->get_positionIndex(), 3, GL_FLOAT, GL_FALSE, 32, reinterpret_cast<GLvoid*>(0));
		//glVertexAttribPointer(RC->get_colorIndex(), 3, GL_FLOAT, GL_FALSE, 32, reinterpret_cast<GLvoid*>(12));
		//glVertexAttribPointer(RC->get_textureIndex(), 2, GL_FLOAT, GL_FALSE, 32, reinterpret_cast<GLvoid*>(24));


		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, Rend->indexBuffer);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Rend->hasTexture == true ? Rend->getTextureID() : 0u);


		glDrawElements(GL_TRIANGLES, Rend->get_indexSize(), GL_UNSIGNED_INT, reinterpret_cast<GLvoid*>(0));

		glBindTexture(GL_TEXTURE_2D, 0u);
		
		//glBindVertexArray(0u);
		//glBindBuffer(GL_ARRAY_BUFFER, 0);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		ObjIT++;

	}

	_cameraObscura = glm::inverse(glm::translate(glm::vec3(0.0f, 0.0f, 0.0f))) * glm::rotate(0.0f, glm::vec3(0.0f, 1.0f, 0.0f)) * glm::rotate(0.0f, glm::vec3(1.0f, 0.0f, 0.0f)) * glm::rotate(0.0f, glm::vec3(0.0f, 0.0f, 1.0f));
	_cameraObscura *= glm::rotate(0.0f, glm::vec3(0.0f, 1.0f, 0.0f)) * glm::rotate(0.0f, glm::vec3(1.0f, 0.0f, 0.0f)) * glm::rotate(0.0f, glm::vec3(0.0f, 0.0f, 1.0f));

	glUniformMatrix4fv(RC->get_cameraIndex(), 1, GL_FALSE, glm::value_ptr(_cameraObscura));

	glUseProgram(0);

	SwapBuffers(RC->getHDC());
}