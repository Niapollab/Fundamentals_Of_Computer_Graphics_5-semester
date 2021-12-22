#pragma once
#include "Model2D.h"

class IModelReader
{
public:
	virtual ~IModelReader() {}

	virtual Model2D Read2DModel() = 0;
};