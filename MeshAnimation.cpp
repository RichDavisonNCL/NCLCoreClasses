#include "MeshAnimation.h"
#include "Matrix.h"
#include "Assets.h"

using namespace NCL;
using namespace Rendering;
using namespace Maths;

MeshAnimation::MeshAnimation() {
	m_jointCount	= 0;
	m_frameCount	= 0;
	m_frameRate	= 0.0f;
}

MeshAnimation::MeshAnimation(size_t jointCount, size_t frameCount, float frameRate, std::vector<Matrix4>& worldJoints, std::vector<Matrix4>& localJoints, const std::vector<std::string>& jointNames) {
	m_jointCount	= jointCount;
	m_frameCount	= frameCount;
	m_frameRate		= frameRate;
	m_worldJoints	= worldJoints;
	m_localJoints	= localJoints;
	m_jointNames	= jointNames;
}

MeshAnimation::MeshAnimation(const std::string& filename) : MeshAnimation() {
	std::ifstream file(Assets::MESHDIR + filename);

	std::string filetype;
	int fileVersion;

	file >> filetype;

	if (filetype != "MeshAnim") {
		std::cout << __FUNCTION__ << " File is not a MeshAnim file!\n";
		return;
	}
	file >> fileVersion;
	file >> m_frameCount;
	file >> m_jointCount;
	file >> m_frameRate;

	m_worldJoints.reserve((size_t)m_frameCount * m_jointCount);

	for (unsigned int frame = 0; frame < m_frameCount; ++frame) {
		for (unsigned int joint = 0; joint < m_jointCount; ++joint) {
			Matrix4 mat;
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 4; ++j) {
					file >> mat.array[i][j];
				}
			}
			m_worldJoints.emplace_back(mat);
		}
	}
}

MeshAnimation::~MeshAnimation() {

}

const Matrix4* MeshAnimation::GetWorldMatrices(size_t frame) const {
	if (frame >= m_frameCount) {
		return nullptr;
	}
	int matStart = frame * m_jointCount;

	Matrix4* dataStart = (Matrix4*)m_worldJoints.data();

	return dataStart + matStart;
}

const Matrix4* MeshAnimation::GetLocalMatrices(size_t frame) const {
	if (frame >= m_frameCount) {
		return nullptr;
	}
	int matStart = frame * m_jointCount;

	Matrix4* dataStart = (Matrix4*)m_localJoints.data();

	return dataStart + matStart;
}