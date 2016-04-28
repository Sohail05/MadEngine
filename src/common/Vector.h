#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include <glm/glm.hpp>
/**************************************************
*
*	Abstraction class is not needed here
*	Using GLM::tvecX as MAD::vectorX
*
**************************************************/

namespace MAD
{
	template <typename T>
	using vec2 = glm::tvec2<T>;

	template <typename T>
	using vec3 = glm::tvec3<T>;

	template <typename T>
	using vec4 = glm::tvec4<T>;


};


#endif
