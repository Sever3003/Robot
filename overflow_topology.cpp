#include "overflow_topology.h"

OverflowTopology::OverflowTopology(const FieldBody& field) : Topology(field) {
}

std::vector<Point> OverflowTopology::GetNeighbours(const Point& point) const {
    std::vector<Point> answer;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (abs(i) + abs(j) == 1) {
                int64_t rel_y = (point.y + i + field_.GetHeight()) % field_.GetHeight();
                int64_t rel_x = (point.x + j + field_.GetWidth()) % field_.GetWidth();
                if (field_.IsObstacle(rel_x, rel_y) && !field_.IsBomb(rel_x, rel_y)) {
                    answer.push_back({static_cast<size_t>(rel_x), static_cast<size_t>(rel_y)});
                }
            }
        }
    }
    return answer;
}