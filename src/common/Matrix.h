#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <glm/glm.hpp>

/**************************************************
*
*	Using GLM::tmatXxX as MAD::matXxX
*
**************************************************/

namespace MAD
{
	template <typename T>
	using mat2x2 = glm::tmat2x2<T>;

	template <typename T>
	using mat3x3 = glm::tmat3x3<T>;

	template <typename T>
	using mat4x4 = glm::tmat4x4<T>;

};


#endif