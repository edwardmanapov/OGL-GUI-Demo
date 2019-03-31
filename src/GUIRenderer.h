// Instruction for compiler to use the library only once
// during the compiling
#pragma once

#include "Core.h"
#include "Vector2D.h"
#include "Vector4D.h"
#include "OGLText.h"
#include <string>
#include <vector>

using namespace std;

// -----------------------------------------------CLASS HEAD----------------------------------------------------------
class OGLHead : public Core
{
	private:
		Vector2D		m_topleft;
		Vector2D		m_bottomright;

		float			c1;
		float			c2;
		float			c3;

		bool draggable;	// Flag indicator
		OGLText *text;	// Point to an object text


	public:
		OGLHead();
		OGLHead(string windowLabel, float p1x, float p1y, float p2x, float p2y, float col1, float col2, float col3);
		~OGLHead();

		void Render();

		// Bool type flag declarations for mouse events
		bool			Indicator(int x, int y);
		bool			MouseMove(int x, int y);
		bool			MouseLBUp(int x, int y);
		bool			MouseLBDown(int x, int y);
};


// -------------------------------------------------CLASS BUTTON--------------------------------------------------------
class OGLButton : public Core
{
	public:
		Vector2D		m_topleft;
		Vector2D		m_bottomright;

		float			c1;
		float			c2;
		float			c3;

		bool draggable;		// Flag indicator
		OGLText *buttontext;	// Pointer to an object buttontext

		OGLButton();
		OGLButton(string buttonLabel, float p1x, float p1y, float p2x, float p2y, float col1, float col2, float col3);
		~OGLButton();

		void Render();

		// Bool type flag declarations for mouse events
		bool			Indicator(int x, int y);
		bool			MouseMove(int x, int y);
		bool			MouseLBUp(int x, int y);
		bool			MouseLBDown(int x, int y);
};


// --------------------------------------------------CLASS BODY------------------------------------------------------------
class OGLBody : public Core
{
	private:
		Vector2D		m_topleft;
		Vector2D		m_bottomright;

		OGLHead  *OGLBody::m_head;	// Instance of OGLClass named as m_head
		vector<OGLButton*> m_buttons; // Vector of OGLButton named as m_buttons

		float			c1;
		float			c2;
		float			c3;

		bool draggable;		// Flag indicator
		Vector2D mouse_startp;	// Vector2D for holdind the mouse start position


	public:
		OGLBody();
		OGLBody(string windowLabel, float p1x, float p1y, float p2x, float p2y, float col1, float col2, float col3);
		~OGLBody();

		OGLButton* OGLBody::createbutton(string buttonLabel, float p1x, float p1y, float p2x, float p2y, float col1, float col2, float col3);

		void Render();

		// Bool type flag declarations for mouse events
		bool			Indicator(int x, int y);
		bool			MouseMove( int x, int y );
		bool			MouseLBUp( int x, int y );
		bool			MouseLBDown( int x, int y );
};
