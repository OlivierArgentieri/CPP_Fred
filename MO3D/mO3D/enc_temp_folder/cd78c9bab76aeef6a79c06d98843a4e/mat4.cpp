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

const float mat4::zero[4][4] = { {0} };


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

	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			this->mat[_i][_j] = _mat.mat[_i][_j];
		}
	}
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

	float a[3][3] // 0,0
	{
		mat[1][1], mat[1][2], mat[1][3],
		mat[2][1], mat[2][2], mat[2][3],
		mat[3][1], mat[3][2], mat[3][3]
	};

	float b[3][3] // 0,1
	{
		mat[1][0], mat[1][2], mat[1][3],
		mat[2][0], mat[2][2], mat[2][3],
		mat[3][0], mat[3][2], mat[3][3]
	};

	float c[3][3] // 0,2
	{
		mat[1][0], mat[1][1], mat[1][3],
		mat[2][0], mat[2][1], mat[2][3],
		mat[3][0], mat[3][1], mat[3][3]
	};
	
	float d[3][3] // 0,3
	{
		mat[1][0], mat[1][1], mat[1][2],
		mat[2][0], mat[2][1], mat[2][2],
		mat[3][0], mat[3][1], mat[3][2]
	};
 

	
	/*
	for (int _i=0; _i < 3; _i++)
	{
		_det += a[0][_i % 3] * a[1][(_i + 1) % 3] * a[2][(_i + 2) % 3];
		_det += b[0][_i % 3] * b[1][(_i + 1) % 3] * b[2][(_i + 2) % 3];
		_det += c[0][_i % 3] * c[1][(_i + 1) % 3] * c[2][(_i + 2) % 3];
		_det += d[0][_i % 3] * d[1][(_i + 1) % 3] * d[2][(_i + 2) % 3];
	}

	for (int _i = 2; _i < 5; _i++)
	{
		_det += a[0][_i % 3] * a[1][(_i - 1) % 3] * a[2][(_i - 2) % 3];
		_det += b[0][_i % 3] * b[1][(_i - 1) % 3] * b[2][(_i - 2) % 3];
		_det += c[0][_i % 3] * c[1][(_i - 1) % 3] * c[2][(_i - 2) % 3];
		_det += d[0][_i % 3] * d[1][(_i - 1) % 3] * d[2][(_i - 2) % 3];
	}*/

	
	float _osef = 0;
	for (int _i = 0; _i < 3; _i++)
		_osef += a[0][_i % 3] * a[1][(_i + 1) % 3] * a[2][(_i + 2) % 3];
	
	for (int _i = 2; _i < 5; _i++)
		_osef -= a[0][_i % 3] * a[1][(_i - 1) % 3] * a[2][(_i - 2) % 3];
	
	_det += _osef * mat[0][0];

	
	//
	_osef = 0;
	for (int _i = 0; _i < 3; _i++)
		_osef += b[0][_i % 3] * b[1][(_i + 1) % 3] * b[2][(_i + 2) % 3];

	for (int _i = 2; _i < 5; _i++)
		_osef -= b[0][_i % 3] * b[1][(_i - 1) % 3] * b[2][(_i - 2) % 3];

	_det += -_osef * mat[0][1];

	
	//
	_osef = 0;
	for (int _i = 0; _i < 3; _i++)
		_osef += c[0][_i % 3] * c[1][(_i + 1) % 3] * c[2][(_i + 2) % 3];

	for (int _i = 2; _i < 5; _i++)
		_osef -= c[0][_i % 3] * c[1][(_i - 1) % 3] * c[2][(_i - 2) % 3];

	_det += _osef * mat[0][2];

	
	//
	/**/
	_osef = 0;
	for (int _i = 0; _i < 3; _i++)
		_osef += d[0][_i % 3] * d[1][(_i + 1) % 3] * d[2][(_i + 2) % 3];

	for (int _i = 2; _i < 5; _i++)
		_osef -= d[0][_i % 3] * d[1][(_i - 1) % 3] * d[2][(_i - 2) % 3];

	_det += -_osef * mat[0][3];

	
	/*
	for (int _i = 0; _i < 3; _i++)
	{
		_det += a[_i][0] * a[(_i + 1) % 3][1] * a[(_i + 2) % 3][2];
		_det -= a[_i][2] * a[(_i + 1) % 3][1] * a[(_i + 2) % 3][0];
	}

	for (int _i = 0; _i < 3; _i++)
	{
		_det -= b[_i][0] * b[(_i + 1) % 3][1] * b[(_i + 2) % 3][2];
		_det += b[_i][2] * b[(_i + 1) % 3][1] * b[(_i + 2) % 3][0];
	}

	for (int _i = 0; _i < 3; _i++)
	{
		_det += c[_i][0] * c[(_i + 1) % 3][1] * c[(_i + 2) % 3][2];
		_det -= c[_i][2] * c[(_i + 1) % 3][1] * c[(_i + 2) % 3][0];
	}

	for (int _i = 0; _i < 3; _i++)
	{
		_det -= d[_i][0] * d[(_i + 1) % 3][1] * d[(_i + 2) % 3][2];
		_det += d[_i][2] * d[(_i + 1) % 3][1] * d[(_i + 2) % 3][0];
	}*/

	return _det;
 }

mat4 mat4::operator*(mat4 _mat) const
{
	float _res[4][4];
	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4 ;_j++)
		{
			_res[_i][_j] = mat[_i][0] * _mat.mat[0][_j] + mat[_i][1] * _mat.mat[1][_j] + mat[_i][2] * _mat.mat[2][_j] + mat[_i][3] * _mat.mat[3][_j];
		}
	}
	return mat4(_res);
}

mat4 mat4::operator-(mat4 _mat) const
{

	float _res[4][4];
	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			_res[_i][_j] = mat[_i][_j] - _mat.mat[_i][_j];
		}
	}

	return mat4(_res);
}

mat4 mat4::operator/(mat4 _mat) const
{
	float _res[4][4];
	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			if (_mat.mat[0][_j] == 0 || _mat.mat[1][_j] == 0 || _mat.mat[2][_j] == 0 || _mat.mat[3][_j] == 0) return mat4(mat4::zero);
			_res[_i][_j] = mat[_i][0] / _mat.mat[0][_j] + mat[_i][1] / _mat.mat[1][_j] + mat[_i][2] / _mat.mat[2][_j] + mat[_i][3] / _mat.mat[3][_j];
		}
	}
	return mat4(_res);
}

mat4 mat4::operator+(mat4 _mat) const
{
	float _res[4][4];
	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			_res[_i][_j] = mat[_i][_j] + _mat.mat[_i][_j];
		}
	}

	return mat4(_res);
}
mat4 mat4::Identity()
{
	return {identity};
}

mat4 mat4::Zero()
{
	return  { zero };
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
