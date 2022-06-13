#pragma once

#include<DirectXMath.h>
#include<DirectXPackedVector.h>

using namespace DirectX;
using namespace DirectX::PackedVector;

namespace kg
{
	namespace math
	{
		extern const float pi;
		const float RadianToDegree(const float fRadian) noexcept;
		const float DegreeToRadian(const float fDegree) noexcept;
	}
}

