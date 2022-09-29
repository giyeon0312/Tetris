#pragma once
#include "Shape.h"

class CShapeGun :
    public CShape
{
public:
    virtual bool Init();
    virtual void Rotation();
};

