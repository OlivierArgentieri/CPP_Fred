#pragma once
#include <cmath>


namespace mo3d
{
	struct vec3
	{
		union
		{
			struct { float x; float y; float z; };
			struct { float r; float g; float b; };
		};

		static const vec3 zero;
		static const vec3 one;
		static const vec3 forward;
		static const vec3 up;
		static const vec3 down;
		static const vec3 right;
		static const vec3 left;
		
		static float Dot(vec3 _vec1, vec3 _vec2);
		static vec3 Cross(vec3 _vec1, vec3 _vec2);
		static float Distance(vec3 _vec1, vec3 _vec2);
		
		static float Magnitude(vec3 _vec);
		static vec3 Normalize(vec3 _vec);


		vec3(float _x = 0, float _y = 0, float _z = 0);
		vec3(const vec3& _vec2);

		float Magnitude() const;
		vec3 Normalize();
		float Dot(vec3 _vec) const;
		vec3 Cross(vec3 _vec) const;
		float Distance(vec3 _vec)const;

		vec3 operator/(float _value) const;
		vec3 operator/(vec3 _vec) const;
		bool operator==(vec3 _vec) const;
		bool operator!=(vec3 _vec) const;
		vec3 operator-(vec3 _vec) const;
		vec3 operator+(vec3 _vec) const;

		vec3& operator=(const vec3& _vec);
		vec3& operator+=(const vec3& _vec);
		vec3& operator-=(const vec3& _vec);
		vec3& operator*=(const vec3& _vec);
		vec3& operator/=(const vec3& _vec);
	};

}