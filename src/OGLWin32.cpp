// OGLWin32.cpp : Defines the entry point for the application.

#include "OGLWin32.h"
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "OGLApplication.h"

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib, "glu32.lib")

int APIENTRY wWinMain(HINSTANCE hInstance,
					 HINSTANCE hPrevInstance,
					 LPTSTR    lpCmdLine,
					 int       nCmdShow)
{
	int exitcode = 0;
	// Allocate a console window
	// so that messages can be redirected to stdout
	AllocConsole();

	HANDLE handle_out = GetStdHandle( STD_OUTPUT_HANDLE);
	int hCrt = _open_osfhandle( (long) handle_out, _O_TEXT );
	FILE* hf_out = _fdopen(hCrt, "w");
	setvbuf(hf_out, NULL, _IONBF, 1);
	*stdout = *hf_out;

	// Create the application instance
	OGLApplication* myapp = OGLApplication::CreateApplication(hInstance);

	exitcode = myapp->Run();

	myapp->DestroyApplication();
	// Free the console window
	FreeConsole();

	ExitProcess(0);

	return exitcode;
}
