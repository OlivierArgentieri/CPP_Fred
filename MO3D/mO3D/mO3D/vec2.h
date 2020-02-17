#pragma once
#include <cmath>

namespace mo3d
{
	struct vec2
	{
		union
		{
			struct { float x; float y; };
			struct { float uv1; float uv2; };
		};

		static const vec2 zero;
		static const vec2 one;
		static const vec2 up;
		static const vec2 down;
		static const vec2 left;
		static const vec2 right;

		static float Dot(vec2 _vec, vec2 _vec2);
		static float Magnitude(vec2 _vec); 
		static vec2 Normalize(vec2 _vec);
		static float Distance(vec2 _vec1, vec2 _vec2);

		
		vec2(float _x = 0, float _y = 0);
		vec2(const vec2& _vec2);

		
		float Dot(vec2 _vec) const;
		float Magnitude() const;
		vec2 Normalize();
		float Distance(vec2 _vec) const;
		
		vec2 operator/(float _value) const;
		vec2 operator/(vec2 _vec) const;
		vec2 operator*(vec2 _vec) const;
		vec2 operator+(vec2 _vec) const;
		vec2 operator-(vec2 _vec) const;

		bool operator==(vec2 _vec) const;
		bool operator!=(vec2 _vec) const;
		
		vec2& operator=(const vec2& _vec);
		vec2& operator+=(const vec2& _vec);
		vec2& operator-=(const vec2& _vec);
		vec2& operator*=(const vec2& _vec);
		vec2& operator/=(const vec2& _vec);
	};
}
