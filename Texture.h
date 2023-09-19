/*
Part of Newcastle University's Game Engineering source code.

Use as you see fit!

Comments and queries to: richard-gordon.davison AT ncl.ac.uk
https://research.ncl.ac.uk/game/
*/
#pragma once
#include "Vector2i.h"

namespace NCL::Rendering {
	using namespace Maths;

	using UniqueTexture = std::unique_ptr<class Texture>;
	using SharedTexture = std::shared_ptr<class Texture>;

	class Texture	{
	public:
		virtual ~Texture();

		Vector2i GetDimensions() const {
			return dimensions;
		}

	protected:
		Texture();

		Vector2i dimensions;
	};
}