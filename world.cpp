#include "world.h"

World::World(const Topology& topology, Point start, Point end)
    : topology_(topology), start_position_(start), end_position_(end), now_position_(start) {
}

std::unordered_map<Point, Topology::Distance> World::Lookup() const {
    auto now = topology_.GetNeighbours(now_position_);
    std::unordered_map<Point, Topology::Distance> result;
    for (const auto& point : now) {
        result[point] = topology_.MeasureDistance(point, end_position_);
    }
    return result;
}
const Point& World::GetStart() const {
    return start_position_;
}

const Point& World::GetEnd() const {
    return end_position_;
}
const Point& World::GetCurrentPosition() const {
    return now_position_;
}

void World::Move(const Point& to) {
    auto neighbours = topology_.GetNeighbours(now_position_);
    for (const auto& neighbour : neighbours) {
        if (neighbour == to) {
            now_position_ = to;
            return;
        }
    }
    throw IllegalMoveException();
}