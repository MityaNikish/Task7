#include "file_manager.h"
#include <fstream>

std::vector<double> read_grid(const std::filesystem::path& file_path)
{
	std::ifstream fin(file_path, std::ios::binary);

	fin.seekg(0,std::ios::end);
	std::streamsize file_size = fin.tellg();
	fin.seekg(0,std::ios::beg);

	std::vector<double> grid(file_size / sizeof(double));

	fin.read((char*)grid.data(), file_size);
	return grid;
}

void write_grid(const std::filesystem::path& file_path, const std::vector<double>& grid)
{
	std::ofstream fout(file_path, std::ios::trunc | std::ios::binary);
	fout.write((char*)grid.data(), sizeof(double) * grid.size());
}
