#include "knight_topology.h"

KnightTopology::KnightTopology(const FieldBody& field) : Topology(field) {
}

std::vector<Point> KnightTopology::GetNeighbours(const Point& point) const {
    std::vector<Point> answer;

    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (abs(i) + abs(j) == 3) {
                int64_t rel_y = point.y + i;
                int64_t rel_x = point.x + j;
                if (field_.IsObstacle(rel_x, rel_y) && !field_.IsBomb(rel_x, rel_y)) {
                    answer.push_back({static_cast<size_t>(rel_x), static_cast<size_t>(rel_y)});
                }
            }
        }
    }
    return answer;
}