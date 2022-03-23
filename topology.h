#pragma once
#include "point.h"

#include <vector>
#include <cstdint>

class Topology {
public:
    using FieldBody = std::vector<std::vector<bool>>;
    using Distance = ssize_t;

    Topology(const FieldBody& field);
    virtual std::vector<Point> GetNeighbours(const Point& point) const = 0;
    Distance MeasureDistance(const Point& from, const Point& to) const;
    static const Distance UNREACHABLE;

protected:
    class Field {
    public:
        Field(const FieldBody& field);
        bool IsObstacle(int64_t x, int64_t y) const;
        bool IsBomb(int64_t x, int64_t y) const;
        size_t GetHeight() const;
        size_t GetWidth() const;
    private:
        FieldBody field_;
    };
    Field field_;
};