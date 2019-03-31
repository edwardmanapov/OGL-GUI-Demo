// Instruction for compiler to use the library only once
// during the compiling
#pragma once

#include "GUIRenderer.h"
#include "OGLWindow.h"
#include <iostream>
#include "GLFont.h"
#include <gl/GL.h>
#include <cstdlib>


// -----------------------------------------------CLASS HEAD----------------------------------------------------------
OGLHead::OGLHead()
{

}

OGLHead::OGLHead(string windowLabel, float p1x, float p1y, float p2x, float p2y, float col1, float col2, float col3)
{
	float temp = p1y + ((p1y - m_bottomright.GetY())) / 100 * 7;
	float temp0 = p1x + ((m_bottomright.GetX() - p1x)) / 100 * 5;

	// Calls a function from OGLText and returns a pointer to the object text
	text = new OGLText(windowLabel, 7, Vector2D(temp0, temp));

	m_topleft.SetX(p1x);
	m_topleft.SetY(p1y);

	m_bottomright.SetX(p2x);
	m_bottomright.SetY(p2y);

	c1 = col1;
	c2 = col2;
	c3 = col3;
}


OGLHead::~OGLHead()
{

}


void OGLHead::Render()
{
	float tlx = m_topleft.GetX();
	float tly = m_topleft.GetY();
	float brx = tlx + ( m_bottomright.GetX() - tlx );
	float bry = tly + (( tly - m_bottomright.GetY()))/100*5;

	float col1 = c1;
	float col2 = c2;
	float col3 = c3;

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.184f, 0.310f, 0.310f);

	glVertex2f(tlx, bry);
	glVertex2f(brx, bry);
	glVertex2f(tlx, tly);
	glVertex2f(brx, tly);

	glEnd();

	text->Render();
}


// Checks if the current x, y are in a the specified range
// and return true if the condition is true
bool OGLHead::Indicator(int x, int y)
{
	if (x > m_topleft.GetX() && x < m_bottomright.GetX())
	{
		if ((y > m_topleft.GetY()) && (y < m_topleft.GetY() + ((m_topleft.GetY() - m_bottomright.GetY()) / 100 * 7)))
		{
			return true;
		}
	}
	return false;
}


bool OGLHead::MouseMove(int x, int y)
{
	int mouseX = x;
	int mouseY = y;

	// Calculating the offsets for each x, y
	int offset_x = mouseX - (m_topleft.GetX() - m_bottomright.GetX());
	int offset_y = mouseY - (m_topleft.GetY() - m_bottomright.GetY());

	m_topleft.SetX((float)mouseX);
	m_topleft.SetY((float)mouseY);

	m_bottomright.SetX((float)offset_x);
	m_bottomright.SetY((float)offset_y);

	// Definition of 5% of the title bar to temp and temp0 according to y, x
	float temp = m_topleft.GetY() + ((m_topleft.GetY() - m_bottomright.GetY())) / 100 * 5;
	float temp0 = m_topleft.GetX() + ((m_bottomright.GetX() - m_topleft.GetX())) / 100 * 5;

	text->MouseMove(x, y);
	text->SetPosition(Vector2D(temp0, temp));

	return true;
}

bool OGLHead::MouseLBUp(int x, int y)
{
	draggable = false;
	cout << "MouseLBUp click test" << endl;
	return true;
}

bool OGLHead::MouseLBDown(int x, int y)
{
	if (Indicator(x, y))
	{
		draggable = true;
	}
	return true;
}


// -------------------------------------------------CLASS BUTTON--------------------------------------------------------
OGLButton::OGLButton()
{

}

OGLButton::OGLButton(string buttonLabel, float p1x, float p1y, float p2x, float p2y, float col1, float col2, float col3)
{
	float temp = p2y - (p1x / 100 * 10);
	float temp0 = p2x + (p1x / 100 * 65);

	// Calls a function from OGLText and returns a pointer to the object buttontext
	buttontext = new OGLText(buttonLabel, 7, Vector2D(temp0, temp));

	m_topleft.SetX(p1x);
	m_topleft.SetY(p1y);

	m_bottomright.SetX(p2x);
	m_bottomright.SetY(p2y);

	c1 = col1;
	c2 = col2;
	c3 = col3;
}

OGLButton::~OGLButton()
{

}

void OGLButton::Render()
{
	float tlx = m_topleft.GetX();
	float tly = m_topleft.GetY();
	float brx = m_bottomright.GetX();
	float bry = m_bottomright.GetY();

	float col1 = c1;
	float col2 = c2;
	float col3 = c3;

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(col1, col2, col3);

	glVertex2f(tlx, bry);
	glVertex2f(brx, bry);
	glVertex2f(tlx, tly);
	glVertex2f(brx, tly);

	glEnd();

	buttontext->Render();
}

// Checks if the current x, y are in a the specified range
// and return true if the condition is true
bool OGLButton::Indicator(int x, int y)
{
	if (x > m_topleft.GetX() && x < m_bottomright.GetX())
	{
		if ((y > m_topleft.GetY()) && (y < m_topleft.GetY() + ((m_topleft.GetY() - m_bottomright.GetY()) / 100 * 7)))
		{
			return true;
		}
	}
	return false;
}


bool OGLButton::MouseMove(int x, int y)
{
	float tlx, tly, brx, bry;

	tlx = m_topleft.GetX();
	tly = m_topleft.GetY();

	brx = m_bottomright.GetX();
	bry = m_bottomright.GetY();

	m_topleft.SetX((float)tlx + x); // + x
	m_topleft.SetY((float)tly + y);	// + y

	m_bottomright.SetX((float)brx + x);	// + x
	m_bottomright.SetY((float)bry + y);	// + y

	buttontext->MouseMove(x, y);

	return true;
}

bool OGLButton::MouseLBUp(int x, int y)
{
	draggable = false;
	return true;
}

bool OGLButton::MouseLBDown(int x, int y)
{
	if (Indicator(x, y))
	{
		draggable = true;
	}
	return true;
}


// --------------------------------------------------CLASS BODY------------------------------------------------------------
OGLBody::OGLBody()
{
	// Calls a function from OGLHead and returns a pointer to the object m_head
	m_head = new OGLHead();
	draggable = false;
}

OGLBody::OGLBody(string windowLabel, float p1x, float p1y, float p2x, float p2y, float col1, float col2, float col3)
{
	// Calls a function from OGLHead and returns a pointer to the object m_head
	m_head = new OGLHead(windowLabel, p1x, p1y, p2x, p2y, col1, col2, col3);

	m_topleft.SetX(p1x);
	m_topleft.SetY(p1y);

	m_bottomright.SetX(p2x);
	m_bottomright.SetY(p2y);

	c1 = col1;
	c2 = col2;
	c3 = col3;

	draggable = false;
}

OGLBody::~OGLBody()
{

}

// OGLBody calls a function createbutton of OGLButton
// and returns a point to it
OGLButton* OGLBody::createbutton(string buttonLabel, float p1x, float p1y, float p2x, float p2y, float col1, float col2, float col3)
{
	OGLButton* newbutton = new OGLButton(buttonLabel, p1x, p1y, p2x, p2y, col1, col2, col3);
	m_buttons.push_back(newbutton);

	return newbutton;
}


void OGLBody::Render()
{
	float tlx = m_topleft.GetX();
	float tly = m_topleft.GetY();
	float brx = m_bottomright.GetX();
	float bry = m_bottomright.GetY();

	float col1 = c1;
	float col2 = c2;
	float col3 = c3;

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(col1, col2, col3);

	glVertex2f(tlx, bry);
	glVertex2f(brx, bry);
	glVertex2f(tlx, tly);
	glVertex2f(brx, tly);

	glEnd();

	m_head->Render();

	// Iterates the buttons vector and calls the render function on it
	for (vector<OGLButton*>::iterator it = m_buttons.begin(); it != end(m_buttons); it++)
	{
		(*it)->Render();
	}
}

// Checks if the current x, y are in a the specified range
// and return true if the condition is true
bool OGLBody::Indicator(int x, int y)
{
	if (x > m_topleft.GetX() && x < m_bottomright.GetX())
	{
		if ((y > m_topleft.GetY()) && (y < m_topleft.GetY() + ((m_topleft.GetY() - m_bottomright.GetY()) / 100 * 7)))
		{
			return true;
		}
	}
	return false;
}


bool OGLBody::MouseMove(int x, int y)
{
	int mouseX = x;
	int mouseY = y;

	int offset_x = mouseX - (m_topleft.GetX() - m_bottomright.GetX());
	int offset_y = mouseY - (m_topleft.GetY() - m_bottomright.GetY());

	if (draggable)
	{
		m_topleft.SetX((float)mouseX);
		m_topleft.SetY((float)mouseY);

		m_bottomright.SetX((float)offset_x);
		m_bottomright.SetY((float)offset_y);

		m_head->MouseMove(x, y);

		// Iterates the buttons vector and calls the MouseMove function on it
		for (vector<OGLButton*>::iterator it = m_buttons.begin(); it != end(m_buttons); it++)
		{
			Listener *plistener = static_cast<Listener*>(*it);
			plistener->MouseMove(x, y);

			//float startp_x, startp_y;
			//startp_x = mouse_startp.GetX();
			//startp_y = mouse_startp.GetY();

			//// Abs difference
			//float diff_x = x - startp_x;
			//float diff_y = y - startp_y;

			////  x > start_x	move right	+ diff
			////  x < start_y move left	- diff
			////  y > start_y move left	+ diff
			////	y < start_y move right	- diff

			//if (x > startp_x)
			//{
			//	x = diff_x;
			//}
			//else if (x < startp_x)
			//{
			//	x = diff_x;
			//}

			//if (y > startp_y)
			//{
			//	y = diff_y;
			//}
			//else if (y < startp_y)
			//{
			//	y = diff_y;
			//}
		}
	}

	//cout << "MouseMove test" << endl;

	return true;
}

bool OGLBody::MouseLBUp(int x, int y)
{
	draggable = false;
	cout << "MouseLBUp click test" << endl;
	return true;
}

bool OGLBody::MouseLBDown(int x, int y)
{
	if (Indicator(x, y))
	{
		draggable = true;

		mouse_startp.SetX(x);
		mouse_startp.SetY(y);

		// Terminal test
		cout << "MouseLBDown click test on HEAD" << endl;
	}

	//cout << "MouseLBDown click test ANYWHERE" << endl;

	for (vector<OGLButton*>::iterator it = m_buttons.begin(); it != end(m_buttons); it++)
	{
		float tlx = (*it)->m_topleft.GetX();
		float tly = (*it)->m_topleft.GetY();
		float brx = (*it)->m_bottomright.GetX();
		float bry = (*it)->m_bottomright.GetY();

		/*cout << "TLX: " << tlx << " BRX: " << brx << endl;
		cout << "TLY: " << tly << " BRY: " << bry << endl <<endl;
		cout << "CLX: " << x << " CLY: " << y << endl;*/

		if (x > tlx  && x < brx)
		{
			if (y < tly && y > bry)
			{
				// cout << "MouseLBDown click test" << endl;
				return true;
			}
		}
		return false;
	}

	return true;
}
