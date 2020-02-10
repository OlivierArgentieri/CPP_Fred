#pragma once

namespace mo3d
{
	class vec2
	{
	public:
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

		vec2(float _x = 0, float _y = 0);
		vec2(const vec2& _vec2);

		
		float Dot(vec2 _vec);
		float Magnitude();
		vec2 Normalize();

		vec2 operator/(float _value);

		vec2 operator/(vec2 _value);
		bool operator==(vec2 _vec);
		bool operator!=(vec2 _vec);
		vec2* operator=(vec2* _value);
	};
}
