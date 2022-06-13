#include "KGVector4.h"

namespace kg
{
	Vector4f::Vector4f(const float arrValue[4]) : x(arrValue[0]), y(arrValue[1]), z(arrValue[2]), w(arrValue[3])
	{
		__noop;
	}

	Vector4f::Vector4f(const int arrValue[4]) : x((float)arrValue[0]), y((float)arrValue[1]), z((float)arrValue[2]), w((float)arrValue[3])
	{
		__noop;
	}

	Vector4f::Vector4f(const XMVECTOR& xmvec) : Vector4f()
	{
		XMStoreFloat4((XMFLOAT4*)this, xmvec);
	}

	Vector4f::Vector4f(const XMFLOAT4& xmvec) : x(xmvec.x), y(xmvec.y), z(xmvec.z), w(xmvec.w)
	{
		__noop;
	}
	////////// operator [] //////////
	float& Vector4f::operator[](unsigned int idx)
	{
		switch (idx)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		}
		assert(false && "idx value is out of range.");
		return x;
	}
	////////// operator =//////////
	Vector4f& Vector4f::operator=(const Vector4f& vec)
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;
		w = vec.w;

		return *this;
	}

	Vector4f& Vector4f::operator=(const float arrValue[4])
	{
		x = arrValue[0];
		y = arrValue[1];
		z = arrValue[2];
		w = arrValue[3];

		return *this;
	}

	Vector4f& Vector4f::operator=(const int arrValue[4])
	{
		x = (float)arrValue[0];
		y = (float)arrValue[1];
		z = (float)arrValue[2];
		w = (float)arrValue[3];

		return *this;
	}

	Vector4f& Vector4f::operator=(const XMVECTOR& xmvec)
	{
		XMStoreFloat4((XMFLOAT4*)this, xmvec);
		return *this;
	}

	Vector4f& Vector4f::operator=(const XMFLOAT4& xmvec)
	{
		x = xmvec.x;
		y = xmvec.y;
		z = xmvec.z;
		w = xmvec.w;

		return *this;
	}

	////////// operator +//////////
	Vector4f Vector4f::operator+(const Vector4f& vec)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat4((XMFLOAT4*)this);
		tv2 = XMLoadFloat4((XMFLOAT4*)&vec);

		tv = tv1 + tv2;
		return Vector4f(tv);
	}

	Vector4f Vector4f::operator+(const float arrValue[4])const
	{
		XMVECTOR tv, tv1, tv2;
		XMFLOAT4 xmf4(arrValue);
		tv1 = XMLoadFloat4((XMFLOAT4*)this);
		tv2 = XMLoadFloat4(&xmf4);

		tv = tv1 + tv2;
		return Vector4f(tv);
	}

	Vector4f Vector4f::operator+(const int arrValue[4])const
	{
		XMVECTOR tv, tv1, tv2;
		Vector4f xmf4(arrValue);
		tv1 = XMLoadFloat4((XMFLOAT4*)this);
		tv2 = XMLoadFloat4((XMFLOAT4*)&xmf4);

		tv = tv1 + tv2;
		return Vector4f(tv);
	}

	Vector4f Vector4f::operator+(const XMVECTOR& xmvec)const
	{
		XMVECTOR tv, tv1;
		tv1 = XMLoadFloat4((XMFLOAT4*)this);
		tv = tv1 + xmvec;
		return Vector4f(tv);
	}

	Vector4f Vector4f::operator+(const XMFLOAT4& xmvec)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat4((XMFLOAT4*)this);
		tv2 = XMLoadFloat4(&xmvec);
		tv = tv1 + tv2;
		return Vector4f(tv);
	}

	////////// operator +=//////////
	Vector4f& Vector4f::operator+=(const Vector4f& vec)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat4((XMFLOAT4*)this);
		v2 = XMLoadFloat4((XMFLOAT4*)&vec);

		v1 += v2;
		Convert(v1);
		return *this;
	}

	Vector4f& Vector4f::operator+=(const float arrValue[4])
	{
		XMVECTOR v1, v2;
		XMFLOAT4 xmf4(arrValue);
		v1 = XMLoadFloat4((XMFLOAT4*)this);
		v2 = XMLoadFloat4(&xmf4);

		v1 += v2;
		Convert(v1);
		return *this;
	}

	Vector4f& Vector4f::operator+=(const int arrValue[4])
	{
		XMVECTOR v1, v2;
		Vector4f xmf4(arrValue);
		v1 = XMLoadFloat4((XMFLOAT4*)this);
		v2 = XMLoadFloat4((XMFLOAT4*)&xmf4);

		v1 += v2;
		Convert(v1);
		return *this;
	}

	Vector4f& Vector4f::operator+=(const XMVECTOR& xmvec)
	{
		XMVECTOR v1;
		v1 = XMLoadFloat4((XMFLOAT4*)this);

		v1 += xmvec;
		Convert(v1);
		return *this;
	}

	Vector4f& Vector4f::operator+=(const XMFLOAT4& xmvec)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat4((XMFLOAT4*)this);
		v2 = XMLoadFloat4(&xmvec);

		v1 += v2;
		Convert(v1);
		return *this;
	}
	////////// operator -//////////
	Vector4f Vector4f::operator-(const Vector4f& vec)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat4((XMFLOAT4*)this);
		tv2 = XMLoadFloat4((XMFLOAT4*)&vec);

		tv = tv1 - tv2;
		return Vector4f(tv);
	}

	Vector4f Vector4f::operator-(const float arrValue[4])const
	{
		XMVECTOR tv, tv1, tv2;
		XMFLOAT4 xmf4(arrValue);
		tv1 = XMLoadFloat4((XMFLOAT4*)this);
		tv2 = XMLoadFloat4(&xmf4);

		tv = tv1 - tv2;
		return Vector4f(tv);
	}

	Vector4f Vector4f::operator-(const int arrValue[4])const
	{
		XMVECTOR tv, tv1, tv2;
		Vector4f xmf4(arrValue);
		tv1 = XMLoadFloat4((XMFLOAT4*)this);
		tv2 = XMLoadFloat4((XMFLOAT4*)&xmf4);

		tv = tv1 - tv2;
		return Vector4f(tv);
	}

	Vector4f Vector4f::operator-(const XMVECTOR& xmvec)const
	{
		XMVECTOR tv, tv1;
		tv1 = XMLoadFloat4((XMFLOAT4*)this);
		tv = tv1 - xmvec;
		return Vector4f(tv);
	}

	Vector4f Vector4f::operator-(const XMFLOAT4& xmvec)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat4((XMFLOAT4*)this);
		tv2 = XMLoadFloat4(&xmvec);
		tv = tv1 - tv2;
		return Vector4f(tv);
	}

	////////// operator -=//////////
	Vector4f& Vector4f::operator-=(const Vector4f& vec)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat4((XMFLOAT4*)this);
		v2 = XMLoadFloat4((XMFLOAT4*)&vec);

		v1 -= v2;
		Convert(v1);
		return *this;
	}

	Vector4f& Vector4f::operator-=(const float arrValue[4])
	{
		XMVECTOR v1, v2;
		XMFLOAT4 xmf4(arrValue);
		v1 = XMLoadFloat4((XMFLOAT4*)this);
		v2 = XMLoadFloat4(&xmf4);

		v1 -= v2;
		Convert(v1);
		return *this;
	}

	Vector4f& Vector4f::operator-=(const int arrValue[4])
	{
		XMVECTOR v1, v2;
		Vector4f xmf4(arrValue);
		v1 = XMLoadFloat4((XMFLOAT4*)this);
		v2 = XMLoadFloat4((XMFLOAT4*)&xmf4);

		v1 -= v2;
		Convert(v1);
		return *this;
	}

	Vector4f& Vector4f::operator-=(const XMVECTOR& xmvec)
	{
		XMVECTOR v1;
		v1 = XMLoadFloat4((XMFLOAT4*)this);

		v1 -= xmvec;
		Convert(v1);
		return *this;
	}

	Vector4f& Vector4f::operator-=(const XMFLOAT4& xmvec)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat4((XMFLOAT4*)this);
		v2 = XMLoadFloat4(&xmvec);

		v1 -= v2;
		Convert(v1);
		return *this;
	}

	////////// operator *//////////
	Vector4f Vector4f::operator*(const Vector4f& vec)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat4((XMFLOAT4*)this);
		tv2 = XMLoadFloat4((XMFLOAT4*)&vec);

		tv = tv1 * tv2;
		return Vector4f(tv);
	}

	Vector4f Vector4f::operator*(const float arrValue[4])const
	{
		XMVECTOR tv, tv1, tv2;
		XMFLOAT4 xmf4(arrValue);
		tv1 = XMLoadFloat4((XMFLOAT4*)this);
		tv2 = XMLoadFloat4(&xmf4);

		tv = tv1 * tv2;
		return Vector4f(tv);
	}

	Vector4f Vector4f::operator*(const int arrValue[4])const
	{
		XMVECTOR tv, tv1, tv2;
		Vector4f xmf4(arrValue);
		tv1 = XMLoadFloat4((XMFLOAT4*)this);
		tv2 = XMLoadFloat4((XMFLOAT4*)&xmf4);

		tv = tv1 * tv2;
		return Vector4f(tv);
	}

	Vector4f Vector4f::operator*(const XMVECTOR& xmvec)const
	{
		XMVECTOR tv, tv1;
		tv1 = XMLoadFloat4((XMFLOAT4*)this);
		tv = tv1 * xmvec;
		return Vector4f(tv);
	}

	Vector4f Vector4f::operator*(const XMFLOAT4& xmvec)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat4((XMFLOAT4*)this);
		tv2 = XMLoadFloat4(&xmvec);
		tv = tv1 * tv2;
		return Vector4f(tv);
	}

	////////// operator *=//////////
	Vector4f& Vector4f::operator*=(const Vector4f& vec)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat4((XMFLOAT4*)this);
		v2 = XMLoadFloat4((XMFLOAT4*)&vec);

		v1 *= v2;
		Convert(v1);
		return *this;
	}

	Vector4f& Vector4f::operator*=(const float arrValue[4])
	{
		XMVECTOR v1, v2;
		XMFLOAT4 xmf4(arrValue);
		v1 = XMLoadFloat4((XMFLOAT4*)this);
		v2 = XMLoadFloat4(&xmf4);

		v1 *= v2;
		Convert(v1);
		return *this;
	}

	Vector4f& Vector4f::operator*=(const int arrValue[4])
	{
		XMVECTOR v1, v2;
		Vector4f xmf4(arrValue);
		v1 = XMLoadFloat4((XMFLOAT4*)this);
		v2 = XMLoadFloat4((XMFLOAT4*)&xmf4);

		v1 *= v2;
		Convert(v1);
		return *this;
	}

	Vector4f& Vector4f::operator*=(const XMVECTOR& xmvec)
	{
		XMVECTOR v1;
		v1 = XMLoadFloat4((XMFLOAT4*)this);

		v1 *= xmvec;
		Convert(v1);
		return *this;
	}

	Vector4f& Vector4f::operator*=(const XMFLOAT4& xmvec)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat4((XMFLOAT4*)this);
		v2 = XMLoadFloat4(&xmvec);

		v1 *= v2;
		Convert(v1);
		return *this;
	}


	////////// operator/   //////////
	Vector4f Vector4f::operator/(const Vector4f& vec)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat4((XMFLOAT4*)this);;
		tv2 = XMLoadFloat4((XMFLOAT4*)&vec);

		tv = tv1 / tv2;
		return Vector4f(tv);
	}

	Vector4f Vector4f::operator/(const float arrValue[4])const
	{
		XMVECTOR tv, tv1, tv2;
		XMFLOAT4 xmf4(arrValue);
		tv1 = XMLoadFloat4((XMFLOAT4*)this);;
		tv2 = XMLoadFloat4(&xmf4);

		tv = tv1 / tv2;
		return Vector4f(tv);
	}

	Vector4f Vector4f::operator/(const int arrValue[4])const
	{
		XMVECTOR tv, tv1, tv2;
		Vector4f xmf4(arrValue);
		tv1 = XMLoadFloat4((XMFLOAT4*)this);;
		tv2 = XMLoadFloat4((XMFLOAT4*)&xmf4);

		tv = tv1 / tv2;
		return Vector4f(tv);
	}

	Vector4f Vector4f::operator/(const XMVECTOR& xmvec)const
	{
		XMVECTOR tv, tv1;
		tv1 = XMLoadFloat4((XMFLOAT4*)this);;
		tv = tv1 / xmvec;
		return Vector4f(tv);
	}

	Vector4f Vector4f::operator/(const XMFLOAT4& xmvec)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat4((XMFLOAT4*)this);;
		tv2 = XMLoadFloat4(&xmvec);
		tv = tv1 / tv2;
		return Vector4f(tv);
	}
	////////// operator /=   //////////
	Vector4f& Vector4f::operator/=(const Vector4f& vec)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat4((XMFLOAT4*)this);
		v2 = XMLoadFloat4((XMFLOAT4*)&vec);

		v1 /= v2;
		Convert(v1);
		return *this;
	}

	Vector4f& Vector4f::operator/=(const float arrValue[4])
	{
		XMVECTOR v1, v2;
		XMFLOAT4 xmf4(arrValue);
		v1 = XMLoadFloat4((XMFLOAT4*)this);
		v2 = XMLoadFloat4(&xmf4);

		v1 /= v2;
		Convert(v1);
		return *this;
	}

	Vector4f& Vector4f::operator/=(const int arrValue[4])
	{
		XMVECTOR v1, v2;
		Vector4f xmf4(arrValue);
		v1 = XMLoadFloat4((XMFLOAT4*)this);
		v2 = XMLoadFloat4((XMFLOAT4*)&xmf4);

		v1 /= v2;
		Convert(v1);
		return *this;
	}

	Vector4f& Vector4f::operator/=(const XMVECTOR& xmvec)
	{
		XMVECTOR v1;
		v1 = XMLoadFloat4((XMFLOAT4*)this);

		v1 /= xmvec;
		Convert(v1);
		return *this;
	}

	Vector4f& Vector4f::operator/=(const XMFLOAT4& xmvec)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat4((XMFLOAT4*)this);
		v2 = XMLoadFloat4(&xmvec);

		v1 /= v2;
		Convert(v1);
		return *this;
	}

	bool Vector4f::operator==(const Vector4f& vec)const
	{
		return x == vec.x && y == vec.y && z == vec.z && w == vec.w;
	}

	bool Vector4f::operator==(const float arrValue[4])const
	{
		return x == arrValue[0] && y == arrValue[1] && z == arrValue[2] && w == arrValue[3];
	}

	bool Vector4f::operator==(const int arrValue[4])const
	{
		return x == (float)arrValue[0] && y == (float)arrValue[1] && z == (float)arrValue[2] && w == (float)arrValue[3];
	}

	bool Vector4f::operator==(const XMVECTOR& xmvec)const
	{
		Vector4f vec(xmvec);
		return x == vec.x && y == vec.y && z == vec.z && w == vec.w;
	}

	bool Vector4f::operator==(const XMFLOAT4& xmvec)const
	{
		return x == xmvec.x && y == xmvec.y && z == xmvec.z && w == xmvec.w;
	}

	bool Vector4f::operator!=(const Vector4f& vec)const
	{
		return x != vec.x || y != vec.y || z != vec.z || w != vec.w;
	}

	bool Vector4f::operator!=(const float arrValue[4])const
	{
		return x != arrValue[0] || y != arrValue[1] || z != arrValue[2] || w != arrValue[3];
	}

	bool Vector4f::operator!=(const int arrValue[4])const
	{
		return x != (float)arrValue[0] || y != (float)arrValue[1] || z != (float)arrValue[2] || w != (float)arrValue[3];
	}

	bool Vector4f::operator!=(const XMVECTOR& xmvec)const
	{
		Vector4f vec(xmvec);
		return x != vec.x || y != vec.y || z != vec.z || w != vec.w;
	}

	bool Vector4f::operator!=(const XMFLOAT4& xmvec)const
	{
		return x != xmvec.x || y != xmvec.y || z != xmvec.z || w != xmvec.w;
	}

	XMVECTOR Vector4f::Convert() const
	{
		return XMLoadFloat4((XMFLOAT4*)this);
	}

	void Vector4f::Convert(const XMVECTOR& _v)
	{
		XMStoreFloat4((XMFLOAT4*)this, _v);
	}

	void Vector4f::Normalize()
	{
		XMVECTOR tv = Convert();
		*this = XMVector4Normalize(tv);
	}

	Vector4f Vector4f::Normalize(const Vector4f& _v)
	{
		XMVECTOR tv = _v.Convert();
		return Vector4f(XMVector4Normalize(tv));
	}
}