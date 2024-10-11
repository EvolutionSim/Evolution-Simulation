#pragma once

struct Pose2D {
    int x_{};
    int y_{};

    bool operator==(const Pose2D &other) const {
        return (x_ == other.x_ && y_ == other.y_);
    }
};