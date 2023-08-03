/*
Part of Newcastle University's Game Engineering source code.

Use as you see fit!

Comments and queries to: richard-gordon.davison AT ncl.ac.uk
https://research.ncl.ac.uk/game/
*/
#pragma once

namespace NCL {
	namespace Maths {
		class Matrix4;
	}

	class MeshAnimation	{
	public:
		MeshAnimation();

		MeshAnimation(size_t jointCount, size_t frameCount, float frameRate, std::vector<Maths::Matrix4>& frames);

		MeshAnimation(const std::string& filename);
		virtual ~MeshAnimation();

		size_t GetJointCount() const {
			return jointCount;
		}

		size_t GetFrameCount() const {
			return frameCount;
		}

		float GetFrameTime() const {
			return frameTime;
		}

		const Maths::Matrix4* GetJointData(size_t frame) const;

	protected:
		size_t	jointCount;
		size_t	frameCount;
		float			frameTime;

		std::vector<Maths::Matrix4>		allJoints;
	};
}

