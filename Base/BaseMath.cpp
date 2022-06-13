#include "BaseMath.h"

namespace kg
{
	namespace math
	{
		extern const float pi = 3.1415f;

		const float RadianToDegree(const float fRadian) noexcept
		{
			return fRadian / math::pi * 180.f;
		}

		const float DegreeToRadian(const float fDegree) noexcept
		{
			return fDegree / 180.f * math::pi;
		}
	}
}