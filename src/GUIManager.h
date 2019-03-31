#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include "GUIRenderer.h"

// This class is responsible for
// providing many instances to the main class
// for body creations
class GUIManager
{
	public:
		GUIManager();
		~GUIManager();

		std::vector<OGLBody*> m_body;	// vector holding pointer to OGLBody named m_body;

		// Functions instance
		OGLBody* createbody(string windowLabel, float p1x, float p1y, float p2x, float p2y, float col1, float col2, float col3);
};