#include "Assets.h"

#include <iostream>
#include <fstream>
#include <filesystem>

using namespace NCL;

bool Assets::ReadTextFile(const std::string &filepath, std::string& result) {
	std::ifstream file(filepath, std::ios::in);
	if (file) {
		std::ostringstream stream;

		stream << file.rdbuf();

		result = stream.str();

		return true;
	}
	else {
		std::cout << __FUNCTION__ << " can't read file " << filepath << "\n";
		return false;
	}
}

bool	Assets::ReadBinaryFile(const std::string& filename, char** into, size_t& size) {
	std::ifstream file(filename, std::ios::binary);

	std::filesystem::path inputFilePath{ filename };
	uintmax_t length = std::filesystem::file_size(inputFilePath);

	if (length == 0) {
		std::cout << __FUNCTION__ << ": Failed to read binary file " << filename << "\n";
		return false;
	}
	char* data = new char[length];

	file.read(data, length);

	file.close();

	*into	= data;
	size	= length;

	return data != NULL ? true : false;
}