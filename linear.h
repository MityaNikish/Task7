#pragma once
#include "grid_interpolation.h"

class Linear final : public GridInterpolation
{
	GridFunction Upscale(const GridFunction& initial_grid, float k) override;
	GridFunction Downscale(const GridFunction& initial_grid, float k) override;
};