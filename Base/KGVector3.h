#pragma once
#include "BaseMath.h"

namespace kg
{
	union Vector3f
	{
		struct 
		{
			float x;
			float y;
			float z;
		};

		Vector3f() : x(), y(), z() { __noop; };
		Vector3f(const float x, const float y, const float z) : x(x), y(y), z(z) { __noop; };
		Vector3f(const Vector3f& vec) : x(vec.x), y(vec.y), z(vec.z) { __noop; };
		Vector3f(const XMVECTOR& xmvec);
		Vector3f(const XMFLOAT3& xmvec);
		Vector3f(const float arrValue[3]);
		Vector3f(const int arrValue[3]);


		// operator
		float& operator [] (unsigned int idx);
		Vector3f& operator = (const Vector3f& v);
		Vector3f& operator = (const XMVECTOR& v);
		Vector3f& operator = (const XMFLOAT3& v);
		Vector3f& operator = (float f[3]);
		Vector3f& operator = (int i[3]);

		Vector3f operator + (const Vector3f& v) const;
		Vector3f operator + (const XMVECTOR& v)const;
		Vector3f operator + (const XMFLOAT3& v)const;
		Vector3f operator + (float f[3])const;
		Vector3f operator + (int i[3])const;

		Vector3f& operator += (const Vector3f& v);
		Vector3f& operator += (const XMVECTOR& v);
		Vector3f& operator += (const XMFLOAT3& v);
		Vector3f& operator += (float f[3]);
		Vector3f& operator += (int i[3]);

		Vector3f operator - (const Vector3f& v)const;
		Vector3f operator - (const XMVECTOR& v)const;
		Vector3f operator - (const XMFLOAT3& v)const;
		Vector3f operator - (float f[3])const;
		Vector3f operator - (int i[3])const;

		Vector3f& operator -= (const Vector3f& v);
		Vector3f& operator -= (const XMVECTOR& v);
		Vector3f& operator -= (const XMFLOAT3& v);
		Vector3f& operator -= (float f[3]);
		Vector3f& operator -= (int i[3]);

		Vector3f operator * (const Vector3f& v)const;
		Vector3f operator * (const XMVECTOR& v)const;
		Vector3f operator * (const XMFLOAT3& v)const;
		Vector3f operator * (float f[3])const;
		Vector3f operator * (int i[3])const;

		Vector3f& operator *= (const Vector3f& v);
		Vector3f& operator *= (const XMVECTOR& v);
		Vector3f& operator *= (const XMFLOAT3& v);
		Vector3f& operator *= (float f[3]);
		Vector3f& operator *= (int i[3]);

		Vector3f operator / (const Vector3f& v)const;
		Vector3f operator / (const XMVECTOR& v)const;
		Vector3f operator / (const XMFLOAT3& v)const;
		Vector3f operator / (float f[3])const;
		Vector3f operator / (int i[3])const;

		Vector3f& operator /= (const Vector3f& v);
		Vector3f& operator /= (const XMVECTOR& v);
		Vector3f& operator /= (const XMFLOAT3& v);
		Vector3f& operator /= (float f[3]);
		Vector3f& operator /= (int i[3]);

		// ==
		bool operator==(const Vector3f& vec)const;
		bool operator==(const float arrValue[3])const;
		bool operator==(const int arrValue[3])const;
		bool operator==(const XMVECTOR& xmvec)const;
		bool operator==(const XMFLOAT3& xmvec)const;

		// !=
		bool operator!=(const Vector3f& vec)const;
		bool operator!=(const float arrValue[3])const;
		bool operator!=(const int arrValue[3])const;
		bool operator!=(const XMVECTOR& xmvec)const;
		bool operator!=(const XMFLOAT3& xmvec)const;

		// Function
		float Length()	const;
		float Distance(const Vector3f& v)	const;
		void Normalize();
		static Vector3f Normalize(const Vector3f& v);

		float Dot(const Vector3f& v)	const;
		float Dot(const XMVECTOR& v)	const;
		float Dot(const XMFLOAT3& v)	const;
		float Dot(float f[3])	const;
		float Dot(int i[3])	const;
		Vector3f Cross(const Vector3f& v)	const;
		Vector3f Cross(const XMVECTOR& v)	const;
		Vector3f Cross(const XMFLOAT3& v)	const;
		Vector3f Cross(float f[3])	const;
		Vector3f Cross(int i[3])	const;
		float Angle(const Vector3f& v)	const;
		float Angle(const XMVECTOR& v)	const;
		float Angle(const XMFLOAT3& v)	const;
		float Angle(float f[3])	const;
		float Angle(int i[3])	const;

		// 22.06.13 matrix 备泅饶 贸府秦具窃
		/*Vector3f TransformNormal(const union _tagMatrix& m);
		Vector3f TransformNormal(const XMMATRIX& m);
		Vector3f TransformCoord(const union _tagMatrix& m);
		Vector3f TransformCoord(const XMMATRIX& m);*/

		XMVECTOR Convert()	const;
		void Convert(const XMVECTOR& v);
	};
}