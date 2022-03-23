#pragma once

#include "topology.h"

class OverflowTopology : public Topology {
public:
    OverflowTopology(const FieldBody& field);
    std::vector<Point> GetNeighbours(const Point& point) const override;
};