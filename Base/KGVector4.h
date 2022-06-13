#pragma once
#include "BaseMath.h"

namespace kg
{
	union Vector4f
	{
		struct
		{
			float x, y, z, w;
		};

		Vector4f() : x(), y(), z(), w() {__noop; };
		Vector4f(const float x, const float y, const float z, const float w) : x(x), y(y), z(z), w(w) { __noop; };
		Vector4f(const Vector4f& vec) : x(vec.x), y(vec.y), z(vec.z), w(vec.w) { __noop; };
		Vector4f(const float arrValue[4]);
		Vector4f(const int arrValue[4]);
		Vector4f(const XMVECTOR& xmvec);
		Vector4f(const XMFLOAT4& xmvec);
		// operator
		// []
		float& operator[](unsigned int idx);

		// =
		Vector4f& operator=(const Vector4f& vec);
		Vector4f& operator=(const float arrValue[4]);
		Vector4f& operator=(const int arrValue[4]);
		Vector4f& operator=(const XMVECTOR& xmvec);
		Vector4f& operator=(const XMFLOAT4& xmvec);

		// +
		Vector4f operator+(const Vector4f& vec)const;
		Vector4f operator+(const float arrValue[4])const;
		Vector4f operator+(const int arrValue[4])const;
		Vector4f operator+(const XMVECTOR& xmvec)const;
		Vector4f operator+(const XMFLOAT4& xmvec)const;

		// +=
		Vector4f& operator+=(const Vector4f& vec);
		Vector4f& operator+=(const float arrValue[4]);
		Vector4f& operator+=(const int arrValue[4]);
		Vector4f& operator+=(const XMVECTOR& xmvec);
		Vector4f& operator+=(const XMFLOAT4& xmvec);

		// -
		Vector4f operator-(const Vector4f& vec)const;
		Vector4f operator-(const float arrValue[4])const;
		Vector4f operator-(const int arrValue[4])const;
		Vector4f operator-(const XMVECTOR& xmvec)const;
		Vector4f operator-(const XMFLOAT4& xmvec)const;

		// -=
		Vector4f& operator-=(const Vector4f& vec);
		Vector4f& operator-=(const float arrValue[4]);
		Vector4f& operator-=(const int arrValue[4]);
		Vector4f& operator-=(const XMVECTOR& xmvec);
		Vector4f& operator-=(const XMFLOAT4& xmvec);

		// *
		Vector4f operator*(const Vector4f& vec)const;
		Vector4f operator*(const float arrValue[4])const;
		Vector4f operator*(const int arrValue[4])const;
		Vector4f operator*(const XMVECTOR& xmvec)const;
		Vector4f operator*(const XMFLOAT4& xmvec)const;

		// *=
		Vector4f& operator*=(const Vector4f& vec);
		Vector4f& operator*=(const float arrValue[4]);
		Vector4f& operator*=(const int arrValue[4]);
		Vector4f& operator*=(const XMVECTOR& xmvec);
		Vector4f& operator*=(const XMFLOAT4& xmvec);

		// /(Div)
		Vector4f operator/(const Vector4f& vec)const;
		Vector4f operator/(const float arrValue[4])const;
		Vector4f operator/(const int arrValue[4])const;
		Vector4f operator/(const XMVECTOR& xmvec)const;
		Vector4f operator/(const XMFLOAT4& xmvec)const;

		// /=
		Vector4f& operator/=(const Vector4f& vec);
		Vector4f& operator/=(const float arrValue[4]);
		Vector4f& operator/=(const int arrValue[4]);
		Vector4f& operator/=(const XMVECTOR& xmvec);
		Vector4f& operator/=(const XMFLOAT4& xmvec);

		// ==
		bool operator==(const Vector4f& vec)const;
		bool operator==(const float arrValue[4])const;
		bool operator==(const int arrValue[4])const;
		bool operator==(const XMVECTOR& xmvec)const;
		bool operator==(const XMFLOAT4& xmvec)const;

		// !=
		bool operator!=(const Vector4f& vec)const;
		bool operator!=(const float arrValue[4])const;
		bool operator!=(const int arrValue[4])const;
		bool operator!=(const XMVECTOR& xmvec)const;
		bool operator!=(const XMFLOAT4& xmvec)const;
		//function
		XMVECTOR Convert() const;
		void Convert(const XMVECTOR& _v);
		void Normalize();
		static Vector4f Normalize(const Vector4f& _v);
	};
}