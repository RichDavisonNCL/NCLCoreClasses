#include "MeshMaterial.h"
#include "Assets.h"

using namespace NCL;
using namespace NCL::Rendering;

#include <fstream>
#include <iostream>
#include <string>

MeshMaterial::MeshMaterial(const std::string& filename) {
	std::ifstream file(Assets::MESHDIR + filename);

	std::string dataType;
	file >> dataType;

	if (dataType != "MeshMat") {
		std::cout << __FUNCTION__ << " File " << filename << " is not a MeshMaterial!\n";
		return;
	}
	int version;
	file >> version;

	if (version != 1) {
		std::cout << __FUNCTION__ << " File " << filename << " has incompatible version " << version << "!\n";
		return;
	}

	int matCount;
	int meshCount;
	file >> matCount;
	file >> meshCount;

	materialLayers.resize(matCount);

	for (int i = 0; i < matCount; ++i) {
		std::string name;
		int count;
		file >> name;
		file >> count;

		for (int j = 0; j < count; ++j) {
			std::string entryData;
			file >> entryData;
			std::string channel;
			std::string file;
			size_t split = entryData.find_first_of(':');
			channel = entryData.substr(0, split);
			file = entryData.substr(split + 1);

			materialLayers[i].entries.insert(std::make_pair(channel, std::make_pair(file, nullptr)));
		}
	}

	for (int i = 0; i < meshCount; ++i) {
		int entry;
		file >> entry;
		meshLayers.emplace_back(&materialLayers[entry]);
	}
}

const MeshMaterialEntry* MeshMaterial::GetMaterialForLayer(int i) const {
	if (i < 0 || i >= meshLayers.size()) {
		return nullptr;
	}
	return meshLayers[i];
}

void MeshMaterial::LoadTextures() {
	for(auto& i : meshLayers) {
		i->LoadTextures();
	}
}

void MeshMaterialEntry::LoadTextures() {
	for (auto& i : entries) {
		std::string filename = Assets::TEXTUREDIR + i.second.first;

		//Texture* t = TextureLoader::LoadAPITexture(filename);

		//i.second.second = t;
	}
}