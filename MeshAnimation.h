/*
Part of Newcastle University's Game Engineering source code.

Use as you see fit!

Comments and queries to: richard-gordon.davison AT ncl.ac.uk
https://research.ncl.ac.uk/game/
*/
#pragma once
#include "Vector.h"
#include "Matrix.h"

namespace NCL::Rendering {
	using UniqueMeshAnim = std::unique_ptr<class MeshAnimation>;
	using SharedMeshAnim = std::shared_ptr<class MeshAnimation>;

	class MeshAnimation	{
	public:
		MeshAnimation();
		MeshAnimation(size_t jointCount, size_t frameCount, float frameRate, std::vector<Maths::Matrix4>& worldFrames, std::vector<Maths::Matrix4>& localFrames, const std::vector<std::string>& jointNames = {});
		MeshAnimation(const std::string& filename);

		virtual ~MeshAnimation();

		size_t GetJointCount() const {
			return m_jointCount;
		}

		size_t GetFrameCount() const {
			return m_frameCount;
		}

		float GetFrameRate() const {
			return m_frameRate;
		}

		float GetFrameTime() const {
			return 1.0f / m_frameRate;
		}

		float GetAnimationTime() const {
			return m_frameCount / (float)m_frameRate;
		}

		std::span<const Maths::Matrix4> GetWorldMatrices(size_t frame) const;
		std::span<const Maths::Matrix4> GetLocalMatrices(size_t frame) const;

	protected:
		size_t		m_jointCount;
		size_t		m_frameCount;
		float		m_frameRate;

		std::vector<Maths::Matrix4>		m_worldJoints;
		std::vector<Maths::Matrix4>		m_localJoints;

		std::vector<std::string>		m_jointNames;
		std::vector<int>				m_jointParents;
	};
}

