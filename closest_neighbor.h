#pragma once
#include "grid_interpolation.h"

class ClosestNeighbor final : public GridInterpolation
{
public:
	GridFunction Upscale(const GridFunction& initial_grid, float k) override;
	GridFunction Downscale(const GridFunction& initial_grid, float k) override;
};