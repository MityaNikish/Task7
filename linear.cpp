#include "linear.h"

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
            while (abs(j * current_h - i * new_h) > current_h && j != current_size - 1)
            {
                ++j;
            }

            if (j == current_size - 1)
            {
                new_grid[i] = current_grid[j];
                continue;
            }

            const double part = abs(j * current_h - i * new_h);
            const double delta_f = current_grid[j + 1] - current_grid[j];

            new_grid[i] = current_grid[j] + delta_f / current_h * part;
        }

        return GridFunction(new_h, new_grid);
    }
}

GridFunction Linear::Upscale(const GridFunction& initial_grid, float k)
{
    return alghoritm(initial_grid, k);
}

GridFunction Linear::Downscale(const GridFunction& initial_grid, float k)
{
    return alghoritm(initial_grid, 1 / k);
}