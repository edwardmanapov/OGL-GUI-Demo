#pragma once

#include <Windows.h>
#include "GLFont.h"
#include <string>
#include <gl/GL.h>
#include "Renderable.h"
#include "Vector2D.h"
#include "Core.h"

using namespace std;

// Inherits from Renderable
// based on GLFont structure
// Creates Text instances
class OGLText : public Core
{
	public:
		OGLText::OGLText(const string text = "empty text", const int size = 5, Vector2D& position = Vector2D());
		~OGLText();

		void Render();
		void SetText(const string text);
		void SetPosition( Vector2D&);
		void SetSize(const int size);

		bool			MouseMove(int x, int y);
		bool			MouseLBUp(int x, int y);
		bool			MouseLBDown(int x, int y);


	private:
		Vector2D m_position;
		GLFont* m_GLfont;	// Pointer to m_GLfont object
		string m_text;
		int m_size;

		Vector2D		m_topleft;
		Vector2D		m_bottomright;

		float			c1;	// meant for color definition
		float			c2;	// >>
		float			c3; // >>
};
