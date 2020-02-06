#pragma once


namespace mo3d
{
	class vec3
	{
	public:
		union
		{
			struct { float x; float y; float z; };
			struct { float r; float g; float b; };
		};


		vec3(float _x = 0, float _y = 0, float _z = 0);
		vec3(const vec3& _vec2);
	};
}