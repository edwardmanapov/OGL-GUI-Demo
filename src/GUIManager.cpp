#include "GUIManager.h"


GUIManager::GUIManager()
{

}


GUIManager::~GUIManager()
{
}

// Function creates a body
// and returns a point to it
OGLBody* GUIManager::createbody(string windowLabel, float p1x, float p1y, float p2x, float p2y, float col1, float col2, float col3)
{
	OGLBody* newbody = new OGLBody(windowLabel, p1x, p1y, p2x, p2y, col1, col2, col3);

	m_body.push_back(newbody);

	return newbody;
}

