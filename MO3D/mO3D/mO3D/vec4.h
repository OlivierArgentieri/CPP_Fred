#pragma once
#include <cmath>

namespace mo3d
{
	struct vec4
	{
		union
		{
			struct { float x; float y; float z; float w; };
			struct { float r; float g; float b; float a; };
		};


		static const vec4 zero;		
		static const vec4 one;
		
		static float Magnitude(vec4 _vec);
		static vec4 Normalize(vec4 _vec);
		static float Dot(vec4 _vec1, vec4 _vec2);
		static float Distance(vec4 _vec1, vec4 _vec2);
		
		
		vec4(float _x = 0, float _y = 0, float _z = 0, float _w = 0);
		vec4(const vec4& _vec4);

		float Magnitude() const;		
		vec4& Normalize();
		float Dot(vec4 _vec) const;
		float Distance(vec4 _vec) const;

		vec4 operator/(float _value) const;
		vec4 operator/(const vec4& _vec) const;
		vec4 operator+(const vec4& _vec) const;
		vec4 operator-(const vec4& _vec) const;
		vec4 operator*(const vec4& _vec) const;

		bool operator<(const vec4&  _vec) const;
		bool operator<=(const vec4&  _vec) const;
		bool operator>(const vec4& _vec) const;
		bool operator>=(const vec4& _vec) const;
		bool operator==(const vec4& _vec) const;
		bool operator!=(const vec4& _vec) const;
		
		vec4& operator=(const vec4& _vec);
		vec4& operator+=(const vec4& _vec);
		vec4& operator-=(const vec4& _vec);
		vec4& operator*=(const vec4& _vec);
		vec4& operator/=(const vec4& _vec);
	};
}