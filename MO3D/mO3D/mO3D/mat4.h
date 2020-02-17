#pragma once


namespace mo3d
{
	struct mat4
	{
	private :
		static const float identity[4][4];
		static const float zero[4][4];
		
		mat4(const float _mat[4][4]);

	public:
		static mat4 Transpose(mat4 _mat);
		static mat4 Identity();
		static mat4 Zero();
		
		float mat[4][4];

		
		mat4(float _mat[4][4]);
		mat4(const mat4& _mat);

		mat4& Transpose();
		double Determinant();
		float ReviewDet();

		mat4 operator*(const mat4& _mat) const;
		mat4 operator+(const mat4& _mat) const;
		mat4 operator-(const mat4& _mat) const;
		mat4 operator/(const mat4& _mat) const;
		
		bool operator==(mat4 _mat) const;
		bool operator!=(mat4 _mat) const;

		mat4& operator=(const mat4& _mat);
		mat4& operator+=(const mat4& _mat);
		mat4& operator-=(const mat4& _mat);
		mat4& operator*=(const mat4& _mat);
		mat4& operator/=(const mat4& _mat);
	};
}