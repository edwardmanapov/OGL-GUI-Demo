// Instruction for compiler to use the library only once
// during the compiling
#pragma once

#include "GUIRenderer.h"
#include <Windows.h>
#include "OGLText.h"


class OGLWindow
{
	private:
		HWND		m_hwnd;				// Handle to a window
		HDC			m_hdc;				// Handle to a device conwindowText
		HGLRC		m_hglrc;			// Handle to a GL rendering conwindowText

		int			m_width;
		int			m_height;


	protected:

		HGLRC CreateOGLContext (HDC hdc);
		BOOL DestroyOGLContext();
		BOOL InitWindow(HINSTANCE hInstance, int width, int height);
		void InitOGLState();


	public:
					OGLWindow();
					OGLWindow(HINSTANCE hInstance, int width, int height);
					~OGLWindow();

		void		Render();
		void		Resize( int width, int height );
		void		SetVisible( BOOL visible );
		void		DestroyOGLWindow();

		BOOL		MouseLBDown ( int x, int y );
		BOOL		MouseLBUp ( int x, int y );
		BOOL		MouseMove(int x, int y);
};