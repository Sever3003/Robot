#pragma once

#include "topology.h"

class PlanarTopology : public Topology {
public:
    PlanarTopology(const FieldBody& field);
    std::vector<Point> GetNeighbours(const Point& point) const override;
};