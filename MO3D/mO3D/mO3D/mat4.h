#pragma once


namespace mo3d
{
	struct mat4
	{
	private :
		static const float identity[4][4];
		mat4(const float _mat[4][4]);

	public:
		static mat4 Transpose(mat4 _mat);
		static mat4 Identity();

		float mat[4][4];

		
		mat4(float _mat[4][4]);
		mat4(const mat4& _mat);

		void Transpose();

		float Determinant();
		mat4 operator*(mat4 _mat);
	};
}