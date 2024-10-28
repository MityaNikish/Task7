#include "grid_function.h"
#include <fstream>

GridFunction::GridFunction(float step, size_t node_number) :
	_step(step),
	_node_number(node_number),
	_grid_values(node_number) {}

GridFunction::GridFunction(float step, const std::vector<double>& grid_values) :
	_step(step),
	_grid_values(grid_values),
	_node_number(grid_values.size()) {};

GridFunction::GridFunction(float step, size_t node_number, const std::filesystem::path& path) : GridFunction(step, node_number) {
	std::ifstream fin(path, std::ios::binary);
	fin.read((char*)_grid_values.data(), sizeof(double) * _node_number);
	fin.close();
}

GridFunction::GridFunction(float step, size_t node_number, const std::function<float(float)>& init_function) : GridFunction(step, node_number) {
	for (size_t i = 0; i < _node_number; ++i) {
		_grid_values[i] = init_function(i * _step);
	}
}

float GridFunction::operator[](size_t index) const
{
	return _grid_values[index];
}

void GridFunction::writeInFile(const std::filesystem::path& path)
{
	std::ofstream fout(path, std::ios::trunc | std::ios::binary);
	fout.write((char*)_grid_values.data(), sizeof(double) * _grid_values.size());
}

size_t GridFunction::getSize() const
{
	return _node_number;
}

float GridFunction::getStep() const
{
	return _step;
}
