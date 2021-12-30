#pragma once
#include "Model3D.h"

class IModel3DReader
{
public:
	virtual ~IModel3DReader() {}

	virtual Model3D Read3DModel() = 0;
};