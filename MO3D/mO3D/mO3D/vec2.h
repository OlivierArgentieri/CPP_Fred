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

		vec2(float _x = 0, float _y = 0);
		vec2(const vec2& _vec2);
		float Dot(vec2 _vec);

		static float Dot(vec2 _vec, vec2 _vec2);
	};

}
