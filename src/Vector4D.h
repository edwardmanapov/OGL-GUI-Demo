// Instruction for compiler to use the library only once
// during the compiling
#pragma once

#include <string>
#include <vector>
using namespace std;

class Vector4D
{
	public:
		Vector4D(void);
		Vector4D(float x1, float x2, float y1, float y2);
		Vector4D(const Vector4D& v);
		~Vector4D(void);

		float GetX1(void) const;
		void SetX1(float x1);
		float GetX2(void) const;
		void SetX2(float x2);
		float GetY1(void) const;
		void SetY1(float y1);
		float GetY2(void) const;
		void SetY2(float y2);
		Vector4D GetAll(void) const;
		void SetAll(float x1, float x2, float y1, float y2);

		Vector4D& operator= (const Vector4D &rhs);
		const Vector4D operator+(const Vector4D &other) const;
		const Vector4D operator-(const Vector4D &other) const;

	private:
		float _x1;
		float _y1;
		float _x2;
		float _y2;

		void Init(float x1, float x2, float y1, float y2);
		void Copy(const Vector4D& v);
};


