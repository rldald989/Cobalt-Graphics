#pragma once

#include "Shader.h"
#include <glm/glm.hpp>

namespace Cobalt {
	struct Light
	{
	public:
		glm::vec3 light_position;
		glm::vec3 light_color;

		void Update(Shader* shader);
	};
}