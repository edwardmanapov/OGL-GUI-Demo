// Instruction for compiler to use the library only once
// during the compiling
#pragma once

// This is an abstract class
// It cannot be instantiated without being inherited by a concrete class
class Renderable
{
	public:

		// This is a pure virtual function
		virtual void			Render() = 0;
};