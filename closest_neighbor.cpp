#include "closest_neighbor.h"
#include <cmath>

namespace
{
    GridFunction alghoritm(const GridFunction& current_grid, float k)
    {
        const float current_h = current_grid.getStep();
        const float new_h = current_h * k;

        const size_t current_size = current_grid.getSize();
        const size_t new_size = static_cast<size_t>(std::ceil(current_size / k));

        std::vector<double> new_grid(new_size);

        size_t j = 0;
        for (size_t i = 0; i < new_size; ++i)
        {
            const float pos = i * new_h;

            while (abs(j * current_h - pos) > current_h && j != current_size - 1)
            {
                ++j;
            }

            if (j == current_size - 1)
            {
                new_grid[i] = current_grid[j];
                continue;
            }

            const double distance_left = abs(j * current_h - pos);
            const double distance_right = abs((j + 1) * current_h - pos);

            new_grid[i] = distance_left <= distance_right ? current_grid[j] : current_grid[j + 1];
        }

        return GridFunction(new_h, new_grid);
    }
}

GridFunction ClosestNeighbor::Upscale(const GridFunction& initial_grid, float k)
{
    return alghoritm(initial_grid, k);
}

GridFunction ClosestNeighbor::Downscale(const GridFunction& initial_grid, float k)
{
    return alghoritm(initial_grid, 1 / k);
}