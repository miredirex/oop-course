#pragma once

#include "shape/IShape.h"

class ISolidShape : public IShape
{
public:
    virtual uint32_t GetFillColor() const = 0;
};