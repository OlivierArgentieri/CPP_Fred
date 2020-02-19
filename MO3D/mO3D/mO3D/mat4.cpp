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

double mat4::DeterminantMat4(const float _mat[4][4])
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

mat4 mat4::Transpose() const
{
	mat4 _temp = mat4(this->mat);
	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			_temp.mat[_j][_i] = mat[_i][_j];
		}
	}
	return _temp;
}

double mat4::Determinant() const
{
	return mat4::DeterminantMat4(mat);
}
double mat4::DeterminantMat3(float _mat3[3][3]) 
{
	/*
	 * | a b c |
	 * | d e f |
	 * | g h i |
	 *
	 * aei - afh + bfg - bdi + cdh - ceg
	 *
	 */
	
	return (_mat3[0][0] * _mat3[1][1] * _mat3[2][2]) // aei
	- (_mat3[0][0] * _mat3[1][2] * _mat3[2][1]) // afh
	+ (_mat3[0][1] * _mat3[1][2] * _mat3[2][0]) // bfg
	- (_mat3[0][1] * _mat3[1][0] * _mat3[2][2]) // bdi
	+ (_mat3[0][2] * _mat3[1][0] * _mat3[2][1]) // cdh
	- (_mat3[0][2] * _mat3[1][1] * _mat3[2][0]) // ceg
	;
}


std::array<double, 4> mat4::GetRowDetAdj(float _mat34[3][4]) const 
{

	/*
	 * split matrix 34 to 4 3*3 matrix
	 * 
	 * -- schema -
	 *	| a b c d | 
	 *	| e f g h |
	 *	| i j k l |
	 *
	 *      | b c d |      | a c d |      | a b d |     | a b c |
	 *  a = | f g h |  b = | e g h |  c = | e f h | d = | e f g |
	 *      | j k l |      | i k l |      | i j l |     | i j k |
	 *
	 * Return det(a) det(b) det(c) det(d)
	 * 
	 */

	float _a[3][3]
	{
		{_mat34[0][1],_mat34[0][2],_mat34[0][3]},
		{_mat34[1][1],_mat34[1][2],_mat34[1][3]},
		{_mat34[2][1],_mat34[2][2],_mat34[2][3]},
	};

	float _b[3][3]
	{
		{_mat34[0][0],_mat34[0][2],_mat34[0][3]},
		{_mat34[1][0],_mat34[1][2],_mat34[1][3]},
		{_mat34[2][0],_mat34[2][2],_mat34[2][3]},
	};

	float _c[3][3]
	{
		{_mat34[0][0],_mat34[0][1],_mat34[0][3]},
		{_mat34[1][0],_mat34[1][1],_mat34[1][3]},
		{_mat34[2][0],_mat34[2][1],_mat34[2][3]},
	};

	float _d[3][3]
	{
		{_mat34[0][0],_mat34[0][1],_mat34[0][2]},
		{_mat34[1][0],_mat34[1][1],_mat34[1][2]},
		{_mat34[2][0],_mat34[2][1],_mat34[2][2]},
	};

	std::array<double, 4> _toReturn = 
	{
		DeterminantMat3(_a),
		DeterminantMat3(_b),
		DeterminantMat3(_c),
		DeterminantMat3(_d)
	};
	
	return _toReturn;
}

mat4 mat4::Adjacent() const
{
	
	/*
	* return matrix 4*4 of determinant for each mat 3*4
	*
	*  --schema--
	*			     _a	  _b   _c   _d	 	
	* | a b c d |   |  | |<-| |<-| |<-|  
	* | e f g h |   |<-| |  | |<-| |<-|  
	* | i j k l |   |<-| |<-| |  | |<-|   
	* | m n o p |   |<-| |<-| |<-| |  |  
	*
	*/

	mat4 _mat = Transpose();

	float _a[3][4]
	{
		{ _mat.mat[1][0], _mat.mat[1][1], _mat.mat[1][2], _mat.mat[1][3] },
		{ _mat.mat[2][0], _mat.mat[2][1], _mat.mat[2][2], _mat.mat[2][3] },
		{ _mat.mat[3][0], _mat.mat[3][1], _mat.mat[3][2], _mat.mat[3][3] }
	};

	float _b[3][4]
	{
		{ _mat.mat[0][0], _mat.mat[0][1], _mat.mat[0][2], _mat.mat[0][3] },
		{ _mat.mat[2][0], _mat.mat[2][1], _mat.mat[2][2], _mat.mat[2][3] },
		{ _mat.mat[3][0], _mat.mat[3][1], _mat.mat[3][2], _mat.mat[3][3] }
	};


	float _c[3][4]
	{
		{ _mat.mat[0][0], _mat.mat[0][1], _mat.mat[0][2], _mat.mat[0][3] },
		{ _mat.mat[1][0], _mat.mat[1][1], _mat.mat[1][2], _mat.mat[1][3] },
		{ _mat.mat[3][0], _mat.mat[3][1], _mat.mat[3][2], _mat.mat[3][3] }
	};


	float _d[3][4]
	{
		{ _mat.mat[0][0], _mat.mat[0][1], _mat.mat[0][2], _mat.mat[0][3] },
		{ _mat.mat[1][0], _mat.mat[1][1], _mat.mat[1][2], _mat.mat[1][3] },
		{ _mat.mat[2][0], _mat.mat[2][1], _mat.mat[2][2], _mat.mat[2][3] }
	};


	std::array<double, 4> _firstRowDet = GetRowDetAdj(_a);
	std::array<double, 4>  _secondRowDet = GetRowDetAdj(_b);
	std::array<double, 4>  _thirdRowDet = GetRowDetAdj(_c);
	std::array<double, 4>  _fourthRowDet = GetRowDetAdj(_d);

	
	float _toReturn[4][4]
	{
		{_firstRowDet[0], -_firstRowDet[1], _firstRowDet[2], -_firstRowDet[3] },
		{-_secondRowDet[0], _secondRowDet[1], -_secondRowDet[2], _secondRowDet[3] },
		{_thirdRowDet[0], -_thirdRowDet[1], _thirdRowDet[2], -_thirdRowDet[3] },
		{-_fourthRowDet[0], _fourthRowDet[1], -_fourthRowDet[2], _fourthRowDet[3] }
	//	
	};

	
	mat4 _t = mat4(_toReturn);
	return _t;
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

mat4 mat4::operator*(const double& _value) const
{
	float _res[4][4];
	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			_res[_i][_j] = mat[_i][_j] * _value;
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

mat4 mat4::Inverse(const mat4& _mat)
{
	mat4 _adj = _mat.Adjacent();
	mat4 t = _adj * (1 / _mat.Determinant());

	return t;
}

mat4 mat4::operator/(const mat4& _mat) const
{

	
	
	/*
	float _res[4][4];
	for (int _i = 0; _i < 4; _i++)
	{
		for (int _j = 0; _j < 4; _j++)
		{
			if (_mat.mat[0][_j] == 0 || _mat.mat[1][_j] == 0 || _mat.mat[2][_j] == 0 || _mat.mat[3][_j] == 0) return
				mat4(mat4::zero);
			_res[_i][_j] = (mat[0][_i] / _mat.mat[_j][0]) + (mat[1][_i] / _mat.mat[_j][1]) + mat[2][_i] / _mat.mat[_j][2] +
				mat[3][_i] / _mat.mat[_j][3];
		}
	}
	return mat4(_res);*/

	return mat;
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
	*this = *this + _mat;
	return  *this;
}

mat4& mat4::operator-=(const mat4& _mat)
{
	*this = *this - _mat;
	return  *this;
}

mat4& mat4::operator*=(const mat4& _mat)
{
	*this = *this * _mat;
	return  *this;
}

mat4& mat4::operator/=(const mat4& _mat)
{
	*this = *this / _mat;
	return  *this;
}

bool mat4::operator==(const mat4& _mat) const
{
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