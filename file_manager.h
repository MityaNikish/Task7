#pragma once
#include <vector>
#include <filesystem>

std::vector<double> read_grid(const std::filesystem::path& file_path);
void write_grid(const std::filesystem::path& file_path, const std::vector<double>& grid);
