#pragma once
#include <vector>
#include <filesystem>
#include <functional>

class GridFunction
{
	float _step = 0;
	size_t _node_number = 0;
	std::vector<double> _grid_values;

public:
	GridFunction() = default;
	GridFunction(float step, size_t node_number);
	GridFunction(float step, const std::vector<double>& grid_values);
	GridFunction(float step, size_t node_number, const std::filesystem::path& path);
	GridFunction(float step, size_t node_number, const std::function<float(float)>& init_function);

	float operator[](size_t index) const;

	void writeInFile(const std::filesystem::path& path);

	size_t getSize() const;
	float getStep() const;
};