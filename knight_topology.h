#pragma once

#include "topology.h"

class KnightTopology : public Topology {
public:
    KnightTopology(const FieldBody& field);
    std::vector<Point> GetNeighbours(const Point& point) const override;
};