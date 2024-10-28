//#include "file_manager.h"
#include "grid_function.h"

#include "closest_neighbor.h"
#include "linear.h"

#include <string>

int main()
{
	//	Инициализация путей
	std::filesystem::path path_file_read_1 = std::filesystem::current_path() / "grid1.raw";
	std::filesystem::path path_file_read_2 = std::filesystem::current_path() / "grid2.raw";
	std::filesystem::path path_file_save = std::filesystem::current_path() / "Result";

	//	Считывание сетки
	//GridFunction grid(0.2, 50, path_file_read_1);
	GridFunction grid(0.35, 750, path_file_read_2);
	//GridFunction grid(0.1, 1000, std::function<float(float)>([](float arg) { return 10 * sin(arg) + sin(10 * arg); }));

	//	Инициализация "конвеера" операций 
	ClosestNeighbor method1;
	Linear method2;
	std::vector<GridInterpolation*> grid_interpolation;
	grid_interpolation.emplace_back(&method1);
	grid_interpolation.emplace_back(&method2);

	size_t i = 1;
	for (auto& method : grid_interpolation)
	{
		//	Увеличиваем ШАГ сетки
		GridFunction grid_upscale = method->Upscale(grid, 2);
		//	Усеньшаем ШАГ сетки
		GridFunction grid_downscale = method->Downscale(grid, 2);

		grid_upscale.writeInFile(path_file_save / ("grid_upscale_method-" + std::to_string(i) + ".raw"));
		grid_downscale.writeInFile(path_file_save / ("grid_downscale_method-" + std::to_string(i) + ".raw"));
		++i;
	}

	return 0;
}