#pragma once
#include "grid_function.h"

class GridInterpolation
{
public:
	virtual GridFunction Upscale(const GridFunction& initial_grid, float k) = 0;
	virtual GridFunction Downscale(const GridFunction& initial_grid, float k) = 0;
};

