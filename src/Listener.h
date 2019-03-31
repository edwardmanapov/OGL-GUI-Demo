// Instruction for compiler to use the library only once
// during the compiling
#pragma once

// Class Listener is the class which is inheritable by every object,
// which interact with the user through these three functions of mouse:
// mouse movement, mouse left button pressed down and mouse left button release
class Listener
{
	public:
		virtual bool MouseMove ( int x, int y ) = 0;
		virtual bool MouseLBDown ( int x, int y ) = 0;
		virtual bool MouseLBUp ( int x, int y ) = 0;
};