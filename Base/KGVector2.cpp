#include "KGVector2.h"
#include <DirectXMath.h>

namespace kg
{
	Vector2f::Vector2f(const XMVECTOR& xmvec) : Vector2f()
	{
		XMStoreFloat2((XMFLOAT2*)this, xmvec);
	}

	Vector2f::Vector2f(const XMFLOAT2& xmvec)
	{
		x = xmvec.x;
		y = xmvec.y;
	}

	Vector2f::Vector2f(const float arrValue[2])
	{
		x = arrValue[0];
		y = arrValue[1];
	}

	Vector2f::Vector2f(const int arrValue[2])
	{
		x = (float)arrValue[0];
		y = (float)arrValue[1];
	}

	float& Vector2f::operator[](unsigned int idx)
	{
		switch (idx)
		{
		case 0:
			return x;
		case 1:
			return y;
		}

		assert(false);

		return x;
	}
	
	Vector2f& Vector2f::operator=(const Vector2f& v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}

	Vector2f& Vector2f::operator=(const XMVECTOR& v)
	{
		XMStoreFloat2((XMFLOAT2*)this, v);
		return *this;
	}

	Vector2f& Vector2f::operator=(const XMFLOAT2& v)
	{
		x = v.x;
		y = v.y;
		return *this;
	}

	Vector2f& Vector2f::operator=(const float* const f)
	{
		x = f[0];
		y = f[1];
		return *this;
	}

	Vector2f& Vector2f::operator=(const int* const i)
	{
		x = static_cast<float>(i[0]);
		y = static_cast<float>(i[1]);
		return *this;
	}

	const Vector2f Vector2f::operator+(const Vector2f& v) const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv2 = XMLoadFloat2((XMFLOAT2*)&v);

		tv = tv1 + tv2;
		return Vector2f(tv);
	}

	const Vector2f Vector2f::operator+(const XMVECTOR& v)const
	{
		XMVECTOR tv, tv1;
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv = tv1 + v;
		return Vector2f(tv);
	}

	const Vector2f Vector2f::operator+(const XMFLOAT2& v)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv2 = XMLoadFloat2(&v);
		tv = tv1 + tv2;
		return Vector2f(tv);
	}

	const Vector2f Vector2f::operator+(const float* const f)const
	{
		XMVECTOR tv, tv1, tv2;
		XMFLOAT2 xmf2(f);
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv2 = XMLoadFloat2(&xmf2);

		tv = tv1 + tv2;
		return Vector2f(tv);
	}

	const Vector2f Vector2f::operator+(const int* const i)const
	{
		XMVECTOR tv, tv1, tv2;
		Vector2f xmf2(i);
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv2 = XMLoadFloat2((XMFLOAT2*)&xmf2);

		tv = tv1 + tv2;
		return Vector2f(tv);
	}

	Vector2f& Vector2f::operator+=(const Vector2f& v)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat2((XMFLOAT2*)this);
		v2 = XMLoadFloat2((XMFLOAT2*)&v);

		v1 += v2;
		Convert(v1);
		return *this;
	}

	Vector2f& Vector2f::operator+=(const XMVECTOR& v)
	{
		XMVECTOR v1;
		v1 = XMLoadFloat2((XMFLOAT2*)this);

		v1 += v;
		Convert(v1);
		return *this;
	}

	Vector2f& Vector2f::operator+=(const XMFLOAT2& v)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat2((XMFLOAT2*)this);
		v2 = XMLoadFloat2(&v);

		v1 += v2;
		Convert(v1);
		return *this;
	}

	Vector2f& Vector2f::operator+=(const float* const f)
	{
		XMVECTOR v1, v2;
		XMFLOAT2 xmf2(f);
		v1 = XMLoadFloat2((XMFLOAT2*)this);
		v2 = XMLoadFloat2(&xmf2);

		v1 += v2;
		Convert(v1);
		return *this;
	}

	Vector2f& Vector2f::operator+=(const int* const i)
	{
		XMVECTOR v1, v2;
		Vector2f xmf2(i);
		v1 = XMLoadFloat2((XMFLOAT2*)this);
		v2 = XMLoadFloat2((XMFLOAT2*)&xmf2);

		v1 += v2;
		Convert(v1);
		return *this;
	}


	const Vector2f Vector2f::operator-(const Vector2f& v)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv2 = XMLoadFloat2((XMFLOAT2*)&v);

		tv = tv1 - tv2;
		return Vector2f(tv);
	}

	const Vector2f Vector2f::operator-(const XMVECTOR& v)const
	{
		XMVECTOR tv, tv1;
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv = tv1 - v;
		return Vector2f(tv);
	}

	const Vector2f Vector2f::operator-(const XMFLOAT2& v)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv2 = XMLoadFloat2(&v);
		tv = tv1 - tv2;
		return Vector2f(tv);
	}

	const Vector2f Vector2f::operator-(const float* const f)const
	{
		XMVECTOR tv, tv1, tv2;
		XMFLOAT2 xmf2(f);
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv2 = XMLoadFloat2(&xmf2);

		tv = tv1 - tv2;
		return Vector2f(tv);
	}

	const Vector2f Vector2f::operator-(const int* const i)const
	{
		XMVECTOR tv, tv1, tv2;
		Vector2f xmf2(i);
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv2 = XMLoadFloat2((XMFLOAT2*)&xmf2);

		tv = tv1 - tv2;
		return Vector2f(tv);
	}

	Vector2f& Vector2f::operator-=(const Vector2f& v)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat2((XMFLOAT2*)this);
		v2 = XMLoadFloat2((XMFLOAT2*)&v);

		v1 -= v2;
		Convert(v1);
		return *this;
	}

	Vector2f& Vector2f::operator-=(const XMVECTOR& v)
	{
		XMVECTOR v1;
		v1 = XMLoadFloat2((XMFLOAT2*)this);

		v1 -= v;
		Convert(v1);
		return *this;
	}

	Vector2f& Vector2f::operator-=(const XMFLOAT2& v)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat2((XMFLOAT2*)this);
		v2 = XMLoadFloat2(&v);

		v1 -= v2;
		Convert(v1);
		return *this;
	}

	Vector2f& Vector2f::operator-=(const float* const f)
	{
		XMVECTOR v1, v2;
		XMFLOAT2 xmf2(f);
		v1 = XMLoadFloat2((XMFLOAT2*)this);
		v2 = XMLoadFloat2(&xmf2);

		v1 -= v2;
		Convert(v1);
		return *this;
	}

	Vector2f& Vector2f::operator-=(const int* const i)
	{
		XMVECTOR v1, v2;
		Vector2f xmf2(i);
		v1 = XMLoadFloat2((XMFLOAT2*)this);
		v2 = XMLoadFloat2((XMFLOAT2*)&xmf2);

		v1 -= v2;
		Convert(v1);
		return *this;
	}


	const Vector2f Vector2f::operator*(const Vector2f& v)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv2 = XMLoadFloat2((XMFLOAT2*)&v);

		tv = tv1 * tv2;
		return Vector2f(tv);
	}

	const Vector2f Vector2f::operator*(const XMVECTOR& v)const
	{
		XMVECTOR tv, tv1;
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv = tv1 * v;
		return Vector2f(tv);
	}

	const Vector2f Vector2f::operator*(const XMFLOAT2& v)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv2 = XMLoadFloat2(&v);
		tv = tv1 * tv2;
		return Vector2f(tv);
	}

	const Vector2f Vector2f::operator*(const float* const f)const
	{
		XMVECTOR tv, tv1, tv2;
		XMFLOAT2 xmf2(f);
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv2 = XMLoadFloat2(&xmf2);

		tv = tv1 * tv2;
		return Vector2f(tv);
	}

	const Vector2f Vector2f::operator*(const int* const i)const
	{
		XMVECTOR tv, tv1, tv2;
		Vector2f xmf2(i);
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv2 = XMLoadFloat2((XMFLOAT2*)&xmf2);

		tv = tv1 * tv2;
		return Vector2f(tv);
	}

	Vector2f& Vector2f::operator*=(const Vector2f& v)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat2((XMFLOAT2*)this);
		v2 = XMLoadFloat2((XMFLOAT2*)&v);

		v1 *= v2;
		Convert(v1);
		return *this;
	}

	Vector2f& Vector2f::operator*=(const XMVECTOR& v)
	{
		XMVECTOR v1;
		v1 = XMLoadFloat2((XMFLOAT2*)this);

		v1 *= v;
		Convert(v1);
		return *this;
	}

	Vector2f& Vector2f::operator*=(const XMFLOAT2& v)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat2((XMFLOAT2*)this);
		v2 = XMLoadFloat2(&v);

		v1 *= v2;
		Convert(v1);
		return *this;
	}

	Vector2f& Vector2f::operator*=(const float* const f)
	{
		XMVECTOR v1, v2;
		XMFLOAT2 xmf2(f);
		v1 = XMLoadFloat2((XMFLOAT2*)this);
		v2 = XMLoadFloat2(&xmf2);

		v1 *= v2;
		Convert(v1);
		return *this;
	}

	Vector2f& Vector2f::operator*=(const int* const i)
	{
		XMVECTOR v1, v2;
		Vector2f xmf2(i);
		v1 = XMLoadFloat2((XMFLOAT2*)this);
		v2 = XMLoadFloat2((XMFLOAT2*)&xmf2);

		v1 *= v2;
		Convert(v1);
		return *this;
	}


	Vector2f Vector2f::operator/(const Vector2f& v)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv2 = XMLoadFloat2((XMFLOAT2*)&v);

		tv = tv1 / tv2;
		return Vector2f(tv);
	}

	Vector2f Vector2f::operator/(const XMVECTOR& v)const
	{
		XMVECTOR tv, tv1;
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv = tv1 / v;
		return Vector2f(tv);
	}

	Vector2f Vector2f::operator/(const XMFLOAT2& v)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv2 = XMLoadFloat2(&v);
		tv = tv1 / tv2;
		return Vector2f(tv);
	}

	Vector2f Vector2f::operator/(const float* const f)const
	{
		XMVECTOR tv, tv1, tv2;
		XMFLOAT2 xmf2(f);
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv2 = XMLoadFloat2(&xmf2);

		tv = tv1 / tv2;
		return Vector2f(tv);
	}

	Vector2f Vector2f::operator/(const int* const i)const
	{
		XMVECTOR tv, tv1, tv2;
		Vector2f xmf2(i);
		tv1 = XMLoadFloat2((XMFLOAT2*)this);
		tv2 = XMLoadFloat2((XMFLOAT2*)&xmf2);

		tv = tv1 / tv2;
		return Vector2f(tv);
	}

	Vector2f& Vector2f::operator/=(const Vector2f& v)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat2((XMFLOAT2*)this);
		v2 = XMLoadFloat2((XMFLOAT2*)&v);

		v1 /= v2;
		Convert(v1);
		return *this;
	}

	Vector2f& Vector2f::operator/=(const XMVECTOR& v)
	{
		XMVECTOR v1;
		v1 = XMLoadFloat2((XMFLOAT2*)this);

		v1 /= v;
		Convert(v1);
		return *this;
	}

	Vector2f& Vector2f::operator/=(const XMFLOAT2& v)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat2((XMFLOAT2*)this);
		v2 = XMLoadFloat2(&v);

		v1 /= v2;
		Convert(v1);
		return *this;
	}

	Vector2f& Vector2f::operator/=(const float* const f)
	{
		XMVECTOR v1, v2;
		XMFLOAT2 xmf2(f);
		v1 = XMLoadFloat2((XMFLOAT2*)this);
		v2 = XMLoadFloat2(&xmf2);

		v1 /= v2;
		Convert(v1);
		return *this;
	}

	Vector2f& Vector2f::operator/=(const int* const i)
	{
		XMVECTOR v1, v2;
		Vector2f xmf2(i);
		v1 = XMLoadFloat2((XMFLOAT2*)this);
		v2 = XMLoadFloat2((XMFLOAT2*)&xmf2);

		v1 /= v2;
		Convert(v1);
		return *this;
	}

	bool Vector2f::operator==(const Vector2f& vec)const
	{
		return x == vec.x && y == vec.y;
	}

	bool Vector2f::operator==(const float arrValue[2])const
	{
		return x == arrValue[0] && y == arrValue[1];
	}

	bool Vector2f::operator==(const int arrValue[2])const
	{
		return x == (float)arrValue[0] && y == (float)arrValue[1];
	}

	bool Vector2f::operator==(const XMVECTOR& xmvec)const
	{
		Vector2f vec(xmvec);
		return x == vec.x && y == vec.y;
	}

	bool Vector2f::operator==(const XMFLOAT2& xmvec)const
	{
		return x == xmvec.x && y == xmvec.y;
	}

	bool Vector2f::operator!=(const Vector2f& vec)const
	{
		return x != vec.x || y != vec.y;
	}

	bool Vector2f::operator!=(const float arrValue[2])const
	{
		return x != arrValue[0] || y != arrValue[1];
	}

	bool Vector2f::operator!=(const int arrValue[2])const
	{
		return x != (float)arrValue[0] || y != (float)arrValue[1];
	}

	bool Vector2f::operator!=(const XMVECTOR& xmvec)const
	{
		Vector2f vec(xmvec);
		return x != vec.x || y != vec.y;
	}

	bool Vector2f::operator!=(const XMFLOAT2& xmvec)const
	{
		return x != xmvec.x || y != xmvec.y;
	}



	float Vector2f::Length() const
	{
		XMVECTOR v = Convert();
		return XMVectorGetX(XMVector2Length(v));
	}

	float Vector2f::Distance(const Vector2f& v) const
	{
		return (*this - v).Length();
	}

	void Vector2f::Normalize()
	{
		XMVECTOR	v = Convert();
		*this = XMVector2Normalize(v);
	}

	Vector2f Vector2f::Normalize(const Vector2f& v)
	{
		XMVECTOR tv = v.Convert();
		return Vector2f(XMVector4Normalize(tv));
	}

	XMVECTOR Vector2f::Convert() const
	{
		return XMLoadFloat2((XMFLOAT2*)this);
	}

	void Vector2f::Convert(const XMVECTOR& v)
	{
		XMStoreFloat3((XMFLOAT3*)this, v);
	}
}
