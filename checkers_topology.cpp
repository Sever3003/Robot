#include "checkers_topology.h"

CheckersTopology::CheckersTopology(const FieldBody& field) : Topology(field){};

void CheckersTopology::FindNeighbours(const Point& point, std::unordered_set<Point>& neighbours,
                                      bool first_step) const {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (abs(i) + abs(j) == 2) {
                int64_t rel_y = point.y + i;
                int64_t rel_x = point.x + j;
                if (field_.IsObstacle(rel_x, rel_y)) {
                    if (!field_.IsBomb(rel_x, rel_y) && first_step &&
                        neighbours.find({static_cast<size_t>(rel_x), static_cast<size_t>(rel_y)}) == neighbours.end()) {
                        neighbours.insert({static_cast<size_t>(rel_x), static_cast<size_t>(rel_y)});
                    } else {
                        int64_t rel2_y = point.y + 2 * i;
                        int64_t rel2_x = point.x + 2 * j;
                        if (field_.IsObstacle(rel2_x, rel2_y)) {
                            if (!field_.IsBomb(rel2_x, rel2_y) &&
                                neighbours.find({static_cast<size_t>(rel2_x), static_cast<size_t>(rel2_y)}) ==
                                    neighbours.end()) {
                                neighbours.insert({static_cast<size_t>(rel2_x), static_cast<size_t>(rel2_y)});
                                FindNeighbours({static_cast<size_t>(rel2_x), static_cast<size_t>(rel2_y)}, neighbours,
                                               false);
                            }
                        }
                    }
                }
            }
        }
    }
}

std::vector<Point> CheckersTopology::GetNeighbours(const Point& point) const {
    std::vector<Point> answer;
    std::unordered_set<Point> neighbours;
    FindNeighbours(point, neighbours, true);
    for (const auto& neighbour : neighbours) {
        answer.push_back(neighbour);
    }
    return answer;
}