#pragma once

#include "OGLText.h"
#include "Vector2D.h"
#include <string>
#include <iostream>

using namespace std;

OGLText::OGLText(string text, const int size, Vector2D& position)
{
	m_text = text;
	m_size = size;
	m_GLfont = new GLFont();
	m_GLfont->Create("franklin_gothic.glf");
	m_position = position;
}

OGLText::~OGLText()
{
	delete m_GLfont;
	m_GLfont = NULL;
}

void OGLText::SetPosition(Vector2D& newposition)
{
	m_position = newposition;
}

void OGLText::SetSize(const int newsize)
{
	m_size = newsize;
}

void OGLText::SetText(const string newtext)
{
	m_text = newtext;
}

void OGLText::Render()
{
	float tlx = m_topleft.GetX();
	float tly = m_topleft.GetY();
	float brx = m_bottomright.GetX();
	float bry = m_bottomright.GetY();

	float col1 = c1;
	float col2 = c2;
	float col3 = c3;

	float text_x = m_position.GetX();
	float text_y = m_position.GetY();

	m_GLfont->Begin();
	glColor3f(1.000f, 1.000f, 1.000f);
	m_GLfont->TextOut(m_text.c_str(), text_x, text_y, 0, m_size);

	// terminal test
	//cout << m_text.c_str() << endl;
	m_GLfont->End();
}

bool OGLText::MouseMove(int x, int y)
{
	int mouseX = x;
	int mouseY = y;

	m_position.SetX((float)mouseX);
	m_position.SetY((float)mouseY);

	//int mouseX = x;
	//int mouseY = y;

	//int offset_x = mouseX + (m_position.GetX());
	//int offset_y = mouseY + (m_position.GetY());

	//m_position.SetX((float)mouseX);
	//m_position.SetY((float)mouseY);

	//m_bottomright.SetX((float)offset_x);
	//m_bottomright.SetY((float)offset_y);

	return true;
}

bool OGLText::MouseLBUp(int x, int y)
{
	return true;
}

bool OGLText::MouseLBDown(int x, int y)
{
	return true;
}