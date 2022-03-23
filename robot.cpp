#include "robot.h"

robot::Path robot::FindPath(World& world) {
    if (world.GetStart() == world.GetEnd()) {
        return {world.GetStart()};
    }
    robot::Path result;
    while (world.GetCurrentPosition() != world.GetEnd()) {
        Point best_point;
        Topology::Distance best_distance = Topology::UNREACHABLE;
        auto neighbours = world.Lookup();
        best_distance = Topology::UNREACHABLE;
        for (const auto& neighbour : neighbours) {
            if (best_distance == Topology::UNREACHABLE || (best_distance > neighbour.second)) {
                best_point = neighbour.first;
                best_distance = neighbour.second;
            }
        }
        if (best_distance == Topology::UNREACHABLE) {
            return {};
        }
        result.push_back(world.GetCurrentPosition());
        world.Move(best_point);
    }
    result.push_back(world.GetEnd());
    return result;
}