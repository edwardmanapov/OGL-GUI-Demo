#include "Vector4D.h"


#pragma region Constructors

Vector4D::Vector4D(void)
{
	Init(0.0f, 0.0f, 0.0f, 0.0f);
}

Vector4D::Vector4D(float x1, float x2, float y1, float y2)
{
	Init(x1, x2, y1, y2);
}

Vector4D::Vector4D(const Vector4D& v)
{
	Copy(v);
}

Vector4D::~Vector4D(void)
{
}

#pragma endregion


#pragma region Accessors and mutators

float Vector4D::GetX1(void) const
{
	return _x1;
}

void Vector4D::SetX1(float x1)
{
	_x1 = x1;
}

float Vector4D::GetX2(void) const
{
	return _x2;
}

void Vector4D::SetX2(float x2)
{
	_x2 = x2;
}

float Vector4D::GetY1(void) const
{
	return _y1;
}

void Vector4D::SetY1(float y1)
{
	_y1 = y1;
}

float Vector4D::GetY2(void) const
{
	return _y2;
}

void Vector4D::SetY2(float y2)
{
	_y2 = y2;
}

Vector4D Vector4D::GetAll(void) const
{
	Vector4D location;
	location.SetX1(_x1);
	location.SetX2(_x2);
	location.SetY1(_y1);
	location.SetY2(_y2);
	return location;
}

void Vector4D::SetAll(float x1, float x2, float y1, float y2)
{
	_x1 = x1;
	_x2 = x2;
	_y1 = y1;
	_y2 = y2;
}


#pragma endregion


#pragma region Operator overloads

Vector4D& Vector4D::operator= (const Vector4D &rhs)
{
	if (this != &rhs)
	{
		// Only copy if we are not assigning to ourselves.
		// (remember that a = b is the same as a.operator=(b))
		Copy(rhs);
	}
	return *this;
}

const Vector4D Vector4D::operator+(const Vector4D &other) const
{
	Vector4D result;
	result.SetX1(_x1 + other.GetX1());
	result.SetX2(_x2 + other.GetX2());
	result.SetY1(_y1 + other.GetY1());
	result.SetY2(_y2 + other.GetY2());
	return result;
}

const Vector4D Vector4D::operator-(const Vector4D &other) const
{
	Vector4D result;
	result.SetX1(_x1 - other.GetX1());
	result.SetX2(_x2 - other.GetX2());
	result.SetY1(_y1 - other.GetY1());
	result.SetY2(_y2 - other.GetY2());
	return result;
}

#pragma endregion


#pragma region Private methods

void Vector4D::Init(float x1, float x2, float y1, float y2)
{
	_x1 = x1;
	_x2 = x2;
	_y1 = y1;
	_y2 = y2;
}

void Vector4D::Copy(const Vector4D& v)
{
	_x1 = v.GetX1();
	_x2 = v.GetX2();
	_y1 = v.GetY1();
	_y2 = v.GetY2();
}

#pragma endregion