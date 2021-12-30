#pragma once
#include "Model2D.h"

class IModel2DReader
{
public:
	virtual ~IModel2DReader() {}

	virtual Model2D Read2DModel() = 0;
};