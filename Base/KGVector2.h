#pragma once
#include "BaseMath.h"

namespace kg
{
	union Vector2f
	{
		struct
		{
			float x;
			float y;
		};

		Vector2f() : x(0), y(0) {}
		Vector2f(const float _x,const  float _y) : x(_x), y(_y) { __noop; }
		Vector2f(const int _x, const int _y) : x(static_cast<float>(_x)), y(static_cast<float>(_y)) { __noop; }
		Vector2f(const Vector2f& other) : x(other.x), y(other.y) { __noop; }
		Vector2f(const DirectX::XMVECTOR& xmvec);
		Vector2f(const DirectX::XMFLOAT2& xmvec);
		Vector2f(const float arrValue[2]);
		Vector2f(const int arrValue[2]);

		// operator
		float& operator [] (unsigned int idx);
		Vector2f& operator = (const Vector2f& v);
		Vector2f& operator = (const XMVECTOR& v);
		Vector2f& operator = (const XMFLOAT2& v);
		Vector2f& operator = (const float* const f);
		Vector2f& operator = (const int* const i);

		const Vector2f operator + (const Vector2f& v) const;
		const Vector2f operator + (const XMVECTOR& v)const;
		const Vector2f operator + (const XMFLOAT2& v)const;
		const Vector2f operator + (const float* const f)const;
		const Vector2f operator + (const int* const i)const;

		Vector2f& operator += (const Vector2f& v);
		Vector2f& operator += (const XMVECTOR& v);
		Vector2f& operator += (const XMFLOAT2& v);
		Vector2f& operator += (const float* const f);
		Vector2f& operator += (const int* const i);

		const Vector2f operator - (const Vector2f& v)const;
		const Vector2f operator - (const XMVECTOR& v)const;
		const Vector2f operator - (const XMFLOAT2& v)const;
		const Vector2f operator - (const float* const f)const;
		const Vector2f operator - (const int* const i)const;

		Vector2f& operator -= (const Vector2f& v);
		Vector2f& operator -= (const XMVECTOR& v);
		Vector2f& operator -= (const XMFLOAT2& v);
		Vector2f& operator -= (const float*const f);
		Vector2f& operator -= (const int* const i);

		const Vector2f operator * (const Vector2f& v)const;
		const Vector2f operator * (const XMVECTOR& v)const;
		const Vector2f operator * (const XMFLOAT2& v)const;
		const Vector2f operator * (const float *const f)const;
		const Vector2f operator * (const int* const i)const;

		Vector2f& operator *= (const Vector2f& v);
		Vector2f& operator *= (const XMVECTOR& v);
		Vector2f& operator *= (const XMFLOAT2& v);
		Vector2f& operator *= (const float*const f);
		Vector2f& operator *= (const int* const i);

		const Vector2f operator / (const Vector2f& v)const;
		const Vector2f operator / (const XMVECTOR& v)const;
		const Vector2f operator / (const XMFLOAT2& v)const;
		const Vector2f operator / (const float*const f)const;
		const Vector2f operator / (const int* const i)const;

		Vector2f& operator /= (const Vector2f& v);
		Vector2f& operator /= (const XMVECTOR& v);
		Vector2f& operator /= (const XMFLOAT2& v);
		Vector2f& operator /= (const float*const f);
		Vector2f& operator /= (const int* const i);

		// ==
		const bool operator==(const Vector2f& vec)const;
		const bool operator==(const float* const arrValue)const;
		const bool operator==(const int* const arrValue)const;
		const bool operator==(const XMVECTOR& xmvec)const;
		const bool operator==(const XMFLOAT2& xmvec)const;

		// !=
		const bool operator!=(const Vector2f& vec)const;
		const bool operator!=(const float* const arrValue)const;
		const bool operator!=(const int* const arrValue)const;
		const bool operator!=(const XMVECTOR& xmvec)const;
		const bool operator!=(const XMFLOAT2& xmvec)const;
		// Function
		const float Length()	const;
		const float Distance(const Vector2f& v)	const;
		void Normalize();
		static const Vector2f Normalize(const Vector2f& v);

		const XMVECTOR Convert()	const;
		void Convert(const XMVECTOR& v);

	};
}

