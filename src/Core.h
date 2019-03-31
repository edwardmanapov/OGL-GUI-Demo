#pragma once

#include "Renderable.h"
#include "Listener.h"

// This is an abstract class with no implementation.
// Inherits from both "Renderable" and "Listener" classes
// Purpose of creation: Holding all events of both classes
// in one core class
class Core : public	Renderable, public Listener{
};