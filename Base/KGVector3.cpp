#include "KGVector3.h"

namespace kg
{

	Vector3f::Vector3f(const XMVECTOR& xmvec) : Vector3f()
	{
		XMStoreFloat3((XMFLOAT3*)this, xmvec);
	}

	Vector3f::Vector3f(const XMFLOAT3& xmvec) : x(xmvec.x), y(xmvec.y), z(xmvec.z)
	{
	}

	Vector3f::Vector3f(const float arrValue[3]) : x(arrValue[0]), y(arrValue[1]), z(arrValue[2])
	{
	}

	Vector3f::Vector3f(const int arrValue[3]) : x((float)arrValue[0]), y((float)arrValue[1]), z((float)arrValue[2])
	{
	}

	float& Vector3f::operator[](unsigned int idx)
	{
		switch (idx)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		}

		assert(false);

		return x;
	}

	Vector3f& Vector3f::operator=(const Vector3f& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	Vector3f& Vector3f::operator=(const XMVECTOR& v)
	{
		XMStoreFloat3((XMFLOAT3*)this, v);
		return *this;
	}

	Vector3f& Vector3f::operator=(const XMFLOAT3& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	Vector3f& Vector3f::operator=(float f[3])
	{
		x = f[0];
		y = f[1];
		z = f[2];
		return *this;
	}

	Vector3f& Vector3f::operator=(int i[3])
	{
		x = (float)i[0];
		y = (float)i[1];
		z = (float)i[2];
		return *this;
	}

	Vector3f Vector3f::operator+(const Vector3f& v) const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv2 = XMLoadFloat3((XMFLOAT3*)&v);

		tv = tv1 + tv2;
		return Vector3f(tv);
	}

	Vector3f Vector3f::operator+(const XMVECTOR& v)const
	{
		XMVECTOR tv, tv1;
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv = tv1 + v;
		return Vector3f(tv);
	}

	Vector3f Vector3f::operator+(const XMFLOAT3& v)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv2 = XMLoadFloat3(&v);
		tv = tv1 + tv2;
		return Vector3f(tv);
	}

	Vector3f Vector3f::operator+(float f[3])const
	{
		XMVECTOR tv, tv1, tv2;
		XMFLOAT3 xmf3(f);
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv2 = XMLoadFloat3(&xmf3);

		tv = tv1 + tv2;
		return Vector3f(tv);
	}

	Vector3f Vector3f::operator+(int i[3])const
	{
		XMVECTOR tv, tv1, tv2;
		Vector3f xmf3(i);
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv2 = XMLoadFloat3((XMFLOAT3*)&xmf3);

		tv = tv1 + tv2;
		return Vector3f(tv);
	}

	Vector3f& Vector3f::operator+=(const Vector3f& v)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat3((XMFLOAT3*)this);
		v2 = XMLoadFloat3((XMFLOAT3*)&v);

		v1 += v2;
		Convert(v1);
		return *this;
	}

	Vector3f& Vector3f::operator+=(const XMVECTOR& v)
	{
		XMVECTOR v1;
		v1 = XMLoadFloat3((XMFLOAT3*)this);

		v1 += v;
		Convert(v1);
		return *this;
	}

	Vector3f& Vector3f::operator+=(const XMFLOAT3& v)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat3((XMFLOAT3*)this);
		v2 = XMLoadFloat3(&v);

		v1 += v2;
		Convert(v1);
		return *this;
	}

	Vector3f& Vector3f::operator+=(float f[3])
	{
		XMVECTOR v1, v2;
		XMFLOAT3 xmf3(f);
		v1 = XMLoadFloat3((XMFLOAT3*)this);
		v2 = XMLoadFloat3(&xmf3);

		v1 += v2;
		Convert(v1);
		return *this;
	}

	Vector3f& Vector3f::operator+=(int i[3])
	{
		XMVECTOR v1, v2;
		Vector3f xmf3(i);
		v1 = XMLoadFloat3((XMFLOAT3*)this);
		v2 = XMLoadFloat3((XMFLOAT3*)&xmf3);

		v1 += v2;
		Convert(v1);
		return *this;
	}


	Vector3f Vector3f::operator-(const Vector3f& v)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv2 = XMLoadFloat3((XMFLOAT3*)&v);

		tv = tv1 - tv2;
		return Vector3f(tv);
	}

	Vector3f Vector3f::operator-(const XMVECTOR& v)const
	{
		XMVECTOR tv, tv1;
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv = tv1 - v;
		return Vector3f(tv);
	}

	Vector3f Vector3f::operator-(const XMFLOAT3& v)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv2 = XMLoadFloat3(&v);
		tv = tv1 - tv2;
		return Vector3f(tv);
	}

	Vector3f Vector3f::operator-(float f[3])const
	{
		XMVECTOR tv, tv1, tv2;
		XMFLOAT3 xmf3(f);
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv2 = XMLoadFloat3(&xmf3);

		tv = tv1 - tv2;
		return Vector3f(tv);
	}

	Vector3f Vector3f::operator-(int i[3])const
	{
		XMVECTOR tv, tv1, tv2;
		Vector3f xmf3(i);
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv2 = XMLoadFloat3((XMFLOAT3*)&xmf3);

		tv = tv1 - tv2;
		return Vector3f(tv);
	}

	Vector3f& Vector3f::operator-=(const Vector3f& v)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat3((XMFLOAT3*)this);
		v2 = XMLoadFloat3((XMFLOAT3*)&v);

		v1 -= v2;
		Convert(v1);
		return *this;
	}

	Vector3f& Vector3f::operator-=(const XMVECTOR& v)
	{
		XMVECTOR v1;
		v1 = XMLoadFloat3((XMFLOAT3*)this);

		v1 -= v;
		Convert(v1);
		return *this;
	}

	Vector3f& Vector3f::operator-=(const XMFLOAT3& v)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat3((XMFLOAT3*)this);
		v2 = XMLoadFloat3(&v);

		v1 -= v2;
		Convert(v1);
		return *this;
	}

	Vector3f& Vector3f::operator-=(float f[3])
	{
		XMVECTOR v1, v2;
		XMFLOAT3 xmf3(f);
		v1 = XMLoadFloat3((XMFLOAT3*)this);
		v2 = XMLoadFloat3(&xmf3);

		v1 -= v2;
		Convert(v1);
		return *this;
	}

	Vector3f& Vector3f::operator-=(int i[3])
	{
		XMVECTOR v1, v2;
		Vector3f xmf3(i);
		v1 = XMLoadFloat3((XMFLOAT3*)this);
		v2 = XMLoadFloat3((XMFLOAT3*)&xmf3);

		v1 -= v2;
		Convert(v1);
		return *this;
	}


	Vector3f Vector3f::operator*(const Vector3f& v)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv2 = XMLoadFloat3((XMFLOAT3*)&v);

		tv = tv1 * tv2;
		return Vector3f(tv);
	}

	Vector3f Vector3f::operator*(const XMVECTOR& v)const
	{
		XMVECTOR tv, tv1;
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv = tv1 * v;
		return Vector3f(tv);
	}

	Vector3f Vector3f::operator*(const XMFLOAT3& v)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv2 = XMLoadFloat3(&v);
		tv = tv1 * tv2;
		return Vector3f(tv);
	}

	Vector3f Vector3f::operator*(float f[3])const
	{
		XMVECTOR tv, tv1, tv2;
		XMFLOAT3 xmf3(f);
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv2 = XMLoadFloat3(&xmf3);

		tv = tv1 * tv2;
		return Vector3f(tv);
	}

	Vector3f Vector3f::operator*(int i[3])const
	{
		XMVECTOR tv, tv1, tv2;
		Vector3f xmf3(i);
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv2 = XMLoadFloat3((XMFLOAT3*)&xmf3);

		tv = tv1 * tv2;
		return Vector3f(tv);
	}

	Vector3f& Vector3f::operator*=(const Vector3f& v)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat3((XMFLOAT3*)this);
		v2 = XMLoadFloat3((XMFLOAT3*)&v);

		v1 *= v2;
		Convert(v1);
		return *this;
	}

	Vector3f& Vector3f::operator*=(const XMVECTOR& v)
	{
		XMVECTOR v1;
		v1 = XMLoadFloat3((XMFLOAT3*)this);

		v1 *= v;
		Convert(v1);
		return *this;
	}

	Vector3f& Vector3f::operator*=(const XMFLOAT3& v)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat3((XMFLOAT3*)this);
		v2 = XMLoadFloat3(&v);

		v1 *= v2;
		Convert(v1);
		return *this;
	}

	Vector3f& Vector3f::operator*=(float f[3])
	{
		XMVECTOR v1, v2;
		XMFLOAT3 xmf3(f);
		v1 = XMLoadFloat3((XMFLOAT3*)this);
		v2 = XMLoadFloat3(&xmf3);

		v1 *= v2;
		Convert(v1);
		return *this;
	}

	Vector3f& Vector3f::operator*=(int i[3])
	{
		XMVECTOR v1, v2;
		Vector3f xmf3(i);
		v1 = XMLoadFloat3((XMFLOAT3*)this);
		v2 = XMLoadFloat3((XMFLOAT3*)&xmf3);

		v1 *= v2;
		Convert(v1);
		return *this;
	}


	Vector3f Vector3f::operator/(const Vector3f& v)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv2 = XMLoadFloat3((XMFLOAT3*)&v);

		tv = tv1 / tv2;
		return Vector3f(tv);
	}

	Vector3f Vector3f::operator/(const XMVECTOR& v)const
	{
		XMVECTOR tv, tv1;
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv = tv1 / v;
		return Vector3f(tv);
	}

	Vector3f Vector3f::operator/(const XMFLOAT3& v)const
	{
		XMVECTOR tv, tv1, tv2;
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv2 = XMLoadFloat3(&v);
		tv = tv1 / tv2;
		return Vector3f(tv);
	}

	Vector3f Vector3f::operator/(float f[3])const
	{
		XMVECTOR tv, tv1, tv2;
		XMFLOAT3 xmf3(f);
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv2 = XMLoadFloat3(&xmf3);

		tv = tv1 / tv2;
		return Vector3f(tv);
	}

	Vector3f Vector3f::operator/(int i[3])const
	{
		XMVECTOR tv, tv1, tv2;
		Vector3f xmf3(i);
		tv1 = XMLoadFloat3((XMFLOAT3*)this);
		tv2 = XMLoadFloat3((XMFLOAT3*)&xmf3);

		tv = tv1 / tv2;
		return Vector3f(tv);
	}

	Vector3f& Vector3f::operator/=(const Vector3f& v)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat3((XMFLOAT3*)this);
		v2 = XMLoadFloat3((XMFLOAT3*)&v);

		v1 /= v2;
		Convert(v1);
		return *this;
	}

	Vector3f& Vector3f::operator/=(const XMVECTOR& v)
	{
		XMVECTOR v1;
		v1 = XMLoadFloat3((XMFLOAT3*)this);

		v1 /= v;
		Convert(v1);
		return *this;
	}

	Vector3f& Vector3f::operator/=(const XMFLOAT3& v)
	{
		XMVECTOR v1, v2;
		v1 = XMLoadFloat3((XMFLOAT3*)this);
		v2 = XMLoadFloat3(&v);

		v1 /= v2;
		Convert(v1);
		return *this;
	}

	Vector3f& Vector3f::operator/=(float f[3])
	{
		XMVECTOR v1, v2;
		XMFLOAT3 xmf3(f);
		v1 = XMLoadFloat3((XMFLOAT3*)this);
		v2 = XMLoadFloat3(&xmf3);

		v1 /= v2;
		Convert(v1);
		return *this;
	}

	Vector3f& Vector3f::operator/=(int i[3])
	{
		XMVECTOR v1, v2;
		Vector3f xmf3(i);
		v1 = XMLoadFloat3((XMFLOAT3*)this);
		v2 = XMLoadFloat3((XMFLOAT3*)&xmf3);

		v1 /= v2;
		Convert(v1);
		return *this;
	}

	bool Vector3f::operator==(const Vector3f& vec)const
	{
		return x == vec.x && y == vec.y && z == vec.z;
	}

	bool Vector3f::operator==(const float arrValue[3])const
	{
		return x == arrValue[0] && y == arrValue[1] && z == arrValue[2];
	}

	bool Vector3f::operator==(const int arrValue[3])const
	{
		return x == (float)arrValue[0] && y == (float)arrValue[1] && z == (float)arrValue[2];
	}

	bool Vector3f::operator==(const XMVECTOR& xmvec)const
	{
		Vector3f vec(xmvec);
		return x == vec.x && y == vec.y && z == vec.z;
	}

	bool Vector3f::operator==(const XMFLOAT3& xmvec)const
	{
		return x == xmvec.x && y == xmvec.y && z == xmvec.z;
	}

	bool Vector3f::operator!=(const Vector3f& vec)const
	{
		return x != vec.x || y != vec.y || z != vec.z;
	}

	bool Vector3f::operator!=(const float arrValue[3])const
	{
		return x != arrValue[0] || y != arrValue[1] || z != arrValue[2];
	}

	bool Vector3f::operator!=(const int arrValue[3])const
	{
		return x != (float)arrValue[0] || y != (float)arrValue[1] || z != (float)arrValue[2];
	}

	bool Vector3f::operator!=(const XMVECTOR& xmvec)const
	{
		Vector3f vec(xmvec);
		return x != vec.x || y != vec.y || z != vec.z;
	}

	bool Vector3f::operator!=(const XMFLOAT3& xmvec)const
	{
		return x != xmvec.x || y != xmvec.y || z != xmvec.z;
	}


	float Vector3f::Length() const
	{
		XMVECTOR	v = Convert();
		return XMVectorGetX(XMVector3Length(v));
	}

	float Vector3f::Distance(const Vector3f& v) const
	{
		return (*this - v).Length();
	}

	void Vector3f::Normalize()
	{
		XMVECTOR	v = Convert();
		*this = XMVector3Normalize(v);
	}

	Vector3f Vector3f::Normalize(const Vector3f& v)
	{
		XMVECTOR tv = v.Convert();
		return Vector3f(XMVector4Normalize(tv));
	}

	float Vector3f::Dot(const Vector3f& v) const
	{
		return Dot(v.Convert());
	}

	float Vector3f::Dot(const XMVECTOR& v) const
	{
		return XMVectorGetX(XMVector3Dot(Convert(), v));
	}

	float Vector3f::Dot(const XMFLOAT3& v) const
	{
		return Dot(XMLoadFloat3(&v));
	}

	float Vector3f::Dot(float f[3]) const
	{
		Vector3f	v(f);
		return Dot(v.Convert());
	}

	float Vector3f::Dot(int i[3]) const
	{
		Vector3f	v(i);
		return Dot(v.Convert());
	}

	Vector3f Vector3f::Cross(const Vector3f& v) const
	{
		return Cross(v.Convert());
	}

	Vector3f Vector3f::Cross(const XMVECTOR& v) const
	{
		Vector3f _v = Vector3f(XMVector3Cross(Convert(), v));

		if (isnan(_v.x) || isnan(_v.y) || isnan(_v.z))
			return Vector3f();

		return _v;
	}

	Vector3f Vector3f::Cross(const XMFLOAT3& v) const
	{
		return Cross(XMLoadFloat3(&v));
	}

	Vector3f Vector3f::Cross(float f[3]) const
	{
		Vector3f	v(f);
		return Cross(v.Convert());
	}

	Vector3f Vector3f::Cross(int i[3]) const
	{
		Vector3f	v(i);
		return Cross(v.Convert());
	}

	float Vector3f::Angle(const Vector3f& v) const
	{
		Vector3f	v1 = Normalize(*this);
		Vector3f	v2 = Normalize(v);

		return kg::math::RadianToDegree(acosf(v1.Dot(v2)));
	}

	float Vector3f::Angle(const XMVECTOR& v) const
	{
		Vector3f	v1 = Normalize(*this);
		Vector3f	v2 = Normalize(v);

		return kg::math::RadianToDegree(acosf(v1.Dot(v2)));
	}

	float Vector3f::Angle(const XMFLOAT3& v) const
	{
		Vector3f	v1 = Normalize(*this);
		Vector3f	v2 = Normalize(v);

		return kg::math::RadianToDegree(acosf(v1.Dot(v2)));
	}

	float Vector3f::Angle(float f[3]) const
	{
		Vector3f	v1 = Normalize(*this);
		Vector3f	v2 = Normalize(f);

		return kg::math::RadianToDegree(acosf(v1.Dot(v2)));
	}

	float Vector3f::Angle(int i[3]) const
	{
		Vector3f	v1 = Normalize(*this);
		Vector3f	v2 = Normalize(i);

		return kg::math::RadianToDegree(acosf(v1.Dot(v2)));
	}

	// 22.06.13 matrix 备泅饶 贸府秦具窃
	/*Vector3f Vector3f::TransformNormal(const _tagMatrix& m)
	{
		return Vector3f(XMVector3TransformNormal(Convert(), m.m));
	}

	Vector3f Vector3f::TransformNormal(const XMMATRIX& m)
	{
		return Vector3f(XMVector3TransformNormal(Convert(), m));
	}

	Vector3f Vector3f::TransformCoord(const _tagMatrix& m)
	{
		return Vector3f(XMVector3TransformCoord(Convert(), m.m));
	}

	Vector3f Vector3f::TransformCoord(const XMMATRIX& m)
	{
		return Vector3f(XMVector3TransformCoord(Convert(), m));
	}*/

	XMVECTOR Vector3f::Convert() const
	{
		return XMLoadFloat3((XMFLOAT3*)this);
	}

	void Vector3f::Convert(const XMVECTOR& v)
	{
		XMStoreFloat3((XMFLOAT3*)this, v);
	}
}