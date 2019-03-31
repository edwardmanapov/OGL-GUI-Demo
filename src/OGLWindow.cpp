#include "OGLWindow.h"
#include "Resource.h"
#include <gl/GL.h>
#include <iostream>
#include "Renderable.h"
#include "GLFont.h"
#include <gl/GLU.h>
#include "GUIManager.h"

bool dragable = false;

// Instance of GUIRenderManager named main
// Responsible for creating windows
GUIManager main;

// Pointers to instances so we can call their functions
OGLBody* win1;
OGLBody* win2;
OGLBody* win3;
OGLBody* win4;
OGLBody* win5;
OGLBody* win6;

OGLButton* but1;
OGLButton* but2;
OGLButton* but3;
OGLButton* but4;
OGLButton* but5;
OGLButton* but6;

OGLWindow::OGLWindow()
{

}

OGLWindow::~OGLWindow()
{

}

OGLWindow::OGLWindow(HINSTANCE hInstance, int width, int height)
{
	InitWindow(hInstance, width, height);
}

HGLRC OGLWindow::CreateOGLContext(HDC hdc)
{
	unsigned int pixelformat;
	HGLRC hglrc;

	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Support Window
		PFD_SUPPORT_OPENGL |						// Format Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request RGBA Format
		32,											// Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits mask
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// Z-Buffer depth
		0,											// Stencil Buffer
		0,											// Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(pixelformat=ChoosePixelFormat(hdc,&pfd)))
	{
		return 0;
	}

	if(!SetPixelFormat(hdc,pixelformat,&pfd))
	{
		return 0;
	}

	if (!(hglrc=wglCreateContext(hdc)))
	{
		return 0;
	}

	if(!wglMakeCurrent(hdc,hglrc))
	{
		return 0;
	}

	return hglrc;
}

void OGLWindow::DestroyOGLWindow()
{
	DestroyOGLContext();

	DestroyWindow( m_hwnd );

	m_hwnd = NULL;
	m_hdc = NULL;
}

BOOL OGLWindow::DestroyOGLContext()
{
	if ( m_hglrc )
	{
		wglMakeCurrent( NULL, NULL );
		wglDeleteContext( m_hglrc );
		m_hglrc = NULL;
	}

	if ( !ReleaseDC ( m_hwnd, m_hdc ) )
		return FALSE;

	return TRUE;
}

BOOL OGLWindow::InitWindow(HINSTANCE hInstance, int width, int height)
{
	m_width = width;
	m_height = height;

	m_hwnd = CreateWindowEx( WS_EX_APPWINDOW | WS_EX_WINDOWEDGE,
		L"OGLWindow", L"OGLWindow", WS_OVERLAPPEDWINDOW | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, // WS_MINIMIZEBOX & WS_SYSMENU are modified for the parent window so that it can not be resized
		0, 0, width, height, NULL, NULL, hInstance, NULL);


	if ( ! m_hwnd )
		return FALSE;

	m_hdc = GetDC( m_hwnd );

	if ( !(m_hglrc = CreateOGLContext( m_hdc )) )
		return FALSE;

	//std::cout << "In OGLWindow::InitWindow: width, height = " << m_width << ", " << m_height << std::endl;

	// Instance's calls
	win1 = main.createbody("Mainframe Alpha", -200, 300, 200, -200, 0.961f, 1.000f, 0.980f);		// Window A
	win2 = main.createbody("Mainframe B", -500, 300, -300, -200, 0.961f, 1.000f, 0.980f);		// Window B
	win3 = main.createbody("Mainframe C", 300, 300, 500, -200, 0.961f, 1.000f, 0.980f);	// Window C

	but1 = win1->createbutton("Function A", 120, 150, -130, 200, 0.184f, 0.310f, 0.310f);	// button 1
	but2 = win1->createbutton("Function B", 120, 0, -130, 50, 0.184f, 0.310f, 0.310f);	// button 2
	but3 = win1->createbutton("Function C", 120, -150, -130, -100, 0.502f, 0.000f, 0.000f);	// button 3

	return TRUE;
}

void OGLWindow::SetVisible ( BOOL visible )
{
	ShowWindow ( m_hwnd, visible? SW_SHOW : SW_HIDE );
}

void OGLWindow::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	// Iterator for each vector of OGLBody
	// calls the render function for each object
	for (vector<OGLBody*>::iterator it = main.m_body.begin(); it != end(main.m_body); it++)
	{
		(*it)->Render();
	}

	glFlush();

	SwapBuffers(m_hdc);
	return;
}

void OGLWindow::Resize( int width, int height )
{
	//std::cout << "Window resized: (w, h) = (" << width << ", " << height << ")\n";

	m_width = width;
	m_height = height;

	glViewport( 0, 0, width, height );

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho( -0.5*width, 0.5*width, -0.5*height, 0.5*height, -10.0, 10.0);

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	return;
}

void OGLWindow::InitOGLState()
{
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
}

BOOL OGLWindow::MouseLBDown ( int x, int y )
{
	// Converting world coordinated into frame buffer coordinates
	int mouseX = x - m_width / 2;
	int mouseY = -y + m_height / 2;

	dragable = true;

	// Iterator for each vector of OGLBody
	// calls the MouseLBDown function for each object
	for (vector<OGLBody*>::iterator it = main.m_body.begin(); it != end(main.m_body); it++)
	{
		Listener *plistener = static_cast<Listener*>(*it);
		plistener->MouseLBDown(mouseX, mouseY);
	}

	// Terminal test
	//cout << "testDOWN" << endl;

	return TRUE;
}

BOOL OGLWindow::MouseLBUp ( int x, int y )
{
	// Converting world coordinated into frame buffer coordinates
	int mouseX = x - m_width / 2;
	int mouseY = -y + m_height / 2;

	dragable = false;

	// Iterator for each vector of OGLBody
	// calls the MouseLBUp function for each object
	for (vector<OGLBody*>::iterator it = main.m_body.begin(); it != end(main.m_body); it++)
	{
		Listener *plistener = static_cast<Listener*>(*it);
		plistener->MouseLBUp(mouseX, mouseY);
	}

	// Terminal test
	//cout << "testUP" << endl;

	return TRUE;
}

BOOL OGLWindow::MouseMove ( int x, int y )
{
	//std::cout << "//Model Space// mouse coordinates: (x, y) = " << x << ", " << y << ")\n";

	// Converting world coordinated into frame buffer coordinates
	int mouseX = x - m_width / 2;
	int mouseY = -y + m_height / 2;

	// Iterator for each vector of OGLBody
	// calls the MouseMove function for each object
	for (vector<OGLBody*>::iterator it = main.m_body.begin(); it != end(main.m_body); it++)
	{
		Listener *plistener = static_cast<Listener*>(*it);
		plistener->MouseMove(mouseX, mouseY);
	}

	//std::cout << "//Frame buffer// mouse coordinates: (x, y) = " << mouseX << ", " << mouseY << ")\n";
	//std::cout << "---------------------------------------\n";

	// Terminal test
	//cout << "testMOVE" << endl;

	return TRUE;
}