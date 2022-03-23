#pragma once

#include "topology.h"

class CheckersTopology : public Topology {
public:
    CheckersTopology(const FieldBody& field);
    std::vector<Point> GetNeighbours(const Point& point) const override;

private:
    void FindNeighbours(const Point& point, std::unordered_set<Point>& neighbours, bool first_step) const;
};