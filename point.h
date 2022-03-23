#pragma once

#include <cstddef>
#include <unordered_set>

struct Point {
    size_t x = 0;
    size_t y = 0;
    bool operator==(const Point& other) const = default;
    bool operator!=(const Point& other) const = default;
};
namespace std {

template <>
class hash<Point> {
public:
    size_t operator()(const Point& point) const {
        return 7 * point.x + 2 * point.y + point.x * point.y;
    }
};
}  // namespace std
