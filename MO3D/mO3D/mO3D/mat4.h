#pragma once
#include <cstring>
#include <array>


namespace mo3d
{
	struct mat4
	{
	private :
		static const float identity[4][4];
		static const float zero[4][4];
		mat4(const float _mat[4][4]);
		static double DeterminantMat4(const float _mat[4][4]);

	public:
		static double DeterminantMat3(float _mat3[3][3]);
		std::array<double, 4> GetRowDetAdj(float _mat34[3][4]) const;
		static mat4 Transpose(mat4 _mat);
		static mat4 Identity();
		static mat4 Zero();
		static mat4 Inverse(const mat4& _mat);

		float mat[4][4];

		
		mat4(float _mat[4][4]);
		mat4(const mat4& _mat);

		mat4 Transpose() const;
		double Determinant() const;
		mat4 Adjacent() const;
		mat4 ClampEpsilon() const;
		
		mat4 operator*(const mat4& _mat) const;
		mat4 operator*(const double& _value) const;
		mat4 operator+(const mat4& _mat) const;
		mat4 operator-(const mat4& _mat) const;
		mat4 operator/(const mat4& _mat) const;
		
		bool operator==(const mat4& _mat) const;
		bool operator!=(const mat4& _mat) const;

		mat4& operator=(const mat4& _mat);
		mat4& operator+=(const mat4& _mat);
		mat4& operator-=(const mat4& _mat);
		mat4& operator*=(const mat4& _mat);
		mat4& operator/=(const mat4& _mat);
	};
}
