#include "pch.h"
#include "mat4.h"

using namespace mo3d;

const float mat4::identity[4][4]
{
			{1,0,0,0},
			{0,1,0,0},
			{0,0,1,0},
			{0,0,0,1}
};

mat4::mat4(float _mat[4][4])
{
	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			mat[_i][_j] = _mat[_i][_j];
		}
	}
}

mat4::mat4(const float _mat[4][4])
{

	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			mat[_i][_j] = _mat[_i][_j];
		}
	}
}

mat4::mat4(const mat4& _mat)
{
	
}

void mat4::Transpose()
{
	if (this == nullptr) return;
	
	mat4 _temp = mat4(this->mat);

	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			this->mat[_j][_i] = _temp.mat[_i][_j];
		}
	}
}

float mat4::Determinant()
{
	float _det = 0;
	
	for (int _i=0; _i < 4; _i++)
		_det += mat[0][_i % 4] * mat[1][(_i + 1 )% 4] * mat[2][(_i + 2) % 4] * mat[3][(_i + 3) % 4];

	for (int _i = 3; _i > 1; _i--)
		_det -= mat[0][_i % 4] * mat[1][(_i - 1 )% 4] * mat[2][(_i - 2 )% 4] * mat[3][(_i -  3) % 4];

	/**/
	for (int i = 0; i < 4; i++)
	{
		_det += mat[i][0] * mat[(i + 1) % 4][1] * mat[(i + 2) % 4][2] * mat[(i + 3) % 4][3];
		_det -= mat[i][3] * mat[(i + 1) % 4][2] * mat[(i + 2) % 4][1] * mat[(i + 3) % 4][0];
	}
	
	return _det;
 }

mat4 mat4::Identity()
{
	return mat4(identity);
	
	return {identity};
}

mat4 mat4::Transpose(mat4 _mat)
{
	mat4 _temp = mat4(_mat);

	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			_temp.mat[_j][_i] = _mat.mat[_i][_j];
		}
	}
	return _temp;
}
