#pragma once

namespace mo3d
{
	class vec4
	{
	public:
		union
		{
			struct { float x; float y; float z; float w; };
			struct { float r; float g; float b; float a; };
		};

		
		vec4(float _x = 0, float _y = 0, float _z = 0, float _w = 0);
		vec4(const vec4& _vec4);
	};
}
