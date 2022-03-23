#include "topology.h"

#include <queue>
#include <cstdint>
const Topology::Distance Topology::UNREACHABLE = -1;

std::vector<Point> Topology::GetNeighbours(const Point& point) const {
    return {};
};

Topology::Topology(const FieldBody& field) : field_(field) {
}

Topology::Distance Topology::MeasureDistance(const Point& from, const Point& to) const {
    if (from == to) {
        return 0;
    }
    auto field = std::vector<std::vector<Topology::Distance>>(
        field_.GetHeight(), std::vector<Topology::Distance>(field_.GetWidth(), Topology::UNREACHABLE));
    std::queue<Point> queue;
    queue.push(to);
    field[to.y][to.x] = 0;
    while (!queue.empty()) {
        auto point = queue.front();
        queue.pop();
        auto neighbours = GetNeighbours(point);
        for (const auto& neighbour : neighbours) {
            if (neighbour == from) {
                return field[point.y][point.x] + 1;
            }
            if (field[neighbour.y][neighbour.x] == Topology::UNREACHABLE) {
                field[neighbour.y][neighbour.x] = field[point.y][point.x] + 1;
                queue.push(neighbour);
            }
        }
    }
    return Topology::UNREACHABLE;
}

Topology::Field::Field(const FieldBody& field) : field_(field) {
}
bool Topology::Field::IsObstacle(int64_t x, int64_t y) const {
    return (x < static_cast<int64_t>(field_[0].size()) && x >= 0 && y < static_cast<int64_t>(field_.size()) && y >= 0);
}
bool Topology::Field::IsBomb(int64_t x, int64_t y) const {
    return field_[y][x];
}
size_t Topology::Field::GetHeight() const {
    return field_.size();
}
size_t Topology::Field::GetWidth() const {
    return field_[0].size();
}