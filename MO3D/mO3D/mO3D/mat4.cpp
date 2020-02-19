#include "pch.h"
#include "mat4.h"
using namespace mo3d;

const float mat4::identity[4][4]
{
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}
};

const float mat4::zero[4][4] = {{0}};


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

double mat4::DeterminantMat4(float _mat[4][4])
{
	
	/*
	 * -- schema --
	 * 
	 *	| a b c d |		a = _test[0,0]  
	 *	| e f g h |		b = _test[0,1]   
	 *	| i j k l |		c = _test[0,2] 
	 *	| m n o p |		d = _test[0,3]  
	 *
	 *   a( fkp − flo − gjp + gln + hjo − hkn )
	 * - b( ekp − elo − gip + glm + hio − hkm )
	 * + c( ejp − eln − fip + flm + hin − hjm )
	 * − d( ejo − ekn − fio + fkm + gin − gjm )
	 */

	double _a = _mat[0][0];
	double _b = _mat[0][1];
	double _c = _mat[0][2];
	double _d = _mat[0][3];
	double _result;
	
	//					f			k			p					f			l			o					g			j			p				g			l			n			h			j			o					h			k			n
	_result =  _a * ((_mat[1][1] * _mat[2][2] * _mat[3][3]) - (_mat[1][1] * _mat[2][3] * _mat[3][2]) - (_mat[1][2] * _mat[2][1] * _mat[3][3]) + (_mat[1][2] * _mat[2][3] * _mat[3][1]) + (_mat[1][3] * _mat[2][1] * _mat[3][2]) - (_mat[1][3] * _mat[2][2] * _mat[3][1]));

	//			   		e			k			p					e			l			o					g			i			p				g			l			m			h			i			o					h			k			m
	_result -= _b * ((_mat[1][0] * _mat[2][2] * _mat[3][3]) - (_mat[1][0] * _mat[2][3] * _mat[3][2]) - (_mat[1][2] * _mat[2][0] * _mat[3][3]) + (_mat[1][2] * _mat[2][3] * _mat[3][0]) + (_mat[1][3] * _mat[2][0] * _mat[3][2]) - (_mat[1][3] * _mat[2][2] * _mat[3][0]));

	//			   		e			j			p					e			l			n					f			i			p				f			l			m			h			i			n					h			j			m
	_result += _c * ((_mat[1][0] * _mat[2][1] * _mat[3][3]) - (_mat[1][0] * _mat[2][3] * _mat[3][1]) - (_mat[1][1] * _mat[2][0] * _mat[3][3]) + (_mat[1][1] * _mat[2][3] * _mat[3][0]) + (_mat[1][3] * _mat[2][0] * _mat[3][1]) - (_mat[1][3] * _mat[2][1] * _mat[3][0]));

	//			   		e			j			o					e			k			n					f			i			o				f			k			m			g			i			n					g			j			m
	_result -= _d * ((_mat[1][0] * _mat[2][1] * _mat[3][2]) - (_mat[1][0] * _mat[2][2] * _mat[3][1]) - (_mat[1][1] * _mat[2][0] * _mat[3][2]) + (_mat[1][1] * _mat[2][2] * _mat[3][0]) + (_mat[1][2] * _mat[2][0] * _mat[3][1]) - (_mat[1][2] * _mat[2][1] * _mat[3][0]));

	return _result;
}

mat4::mat4(const mat4& _mat)
{
	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			mat[_i][_j] = _mat.mat[_i][_j];
		}
	}
}

mat4& mat4::Transpose()
{
	mat4 _temp = mat4(this->mat);
	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			this->mat[_j][_i] = _temp.mat[_i][_j];
		}
	}
	return *this;
}

double mat4::Determinant()
{
	return mat4::DeterminantMat4(mat);
}


float mat4::ReviewDet()
{
	float _test[4][4]
	{
		{ -10, 1, 2, 3},
		{ 4, 5, 6, 7 },
		{ 8,9, 10, 11 },
		{ 12, 13, 14, 20}
	};

	return 0;
}

mat4 mat4::operator*(const mat4& _mat) const
{
	float _res[4][4];
	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			_res[_i][_j] = mat[_i][0] * _mat.mat[0][_j] + mat[_i][1] * _mat.mat[1][_j] + mat[_i][2] * _mat.mat[2][_j] +
				mat[_i][3] * _mat.mat[3][_j];
		}
	}
	return mat4(_res);
}

mat4 mat4::operator+(const mat4& _mat) const
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

mat4 mat4::operator-(const mat4& _mat) const
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

mat4 mat4::operator/(const mat4& _mat) const
{
	float _res[4][4];
	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			if (_mat.mat[0][_j] == 0 || _mat.mat[1][_j] == 0 || _mat.mat[2][_j] == 0 || _mat.mat[3][_j] == 0) return
				mat4(mat4::zero);
			_res[_i][_j] = mat[_i][0] / _mat.mat[0][_j] + mat[_i][1] / _mat.mat[1][_j] + mat[_i][2] / _mat.mat[2][_j] +
				mat[_i][3] / _mat.mat[3][_j];
		}
	}
	return mat4(_res);
}


mat4& mat4::operator=(const mat4& _mat)
{
	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			mat[_i][_j] = _mat.mat[_i][_j];
		}
	}
	return  *this;
}

mat4& mat4::operator+=(const mat4& _mat)
{
	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			mat[_i][_j] += _mat.mat[_i][_j];
		}
	}
	return  *this;
}

mat4& mat4::operator-=(const mat4& _mat)
{
	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			mat[_i][_j] -= _mat.mat[_i][_j];
		}
	}
	return  *this;
}

mat4& mat4::operator*=(const mat4& _mat)
{
	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			mat[_i][_j] = mat[_i][0] * _mat.mat[0][_j] + mat[_i][1] * _mat.mat[1][_j] + mat[_i][2] * _mat.mat[2][_j] +
				mat[_i][3] * _mat.mat[3][_j];
		}
	}
	return  *this;
}

mat4& mat4::operator/=(const mat4& _mat)
{
	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			if (_mat.mat[_i][_j] == 0) continue;
			mat[_i][_j] /=  _mat.mat[_i][_j];
		}
	}
	return  *this;
}

bool mat4::operator==(const mat4& _mat) const
{
	//return memcmp(mat, _mat.mat, sizeof(float) * 16);
	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			if (mat[_i][_j] != _mat.mat[_i][_j])
				return false;
		}
	}
	return true;
}

bool mat4::operator!=(const mat4& _mat) const
{
	return !(mat == _mat.mat);
}


mat4 mat4::Identity()
{
	return {identity};
}

mat4 mat4::Zero()
{
	return {zero};
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