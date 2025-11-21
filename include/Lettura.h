#ifndef LETTURA_H
#define LETTURA_H

#include <ostream>

struct Lettura {
    double yaw_v;
    double yaw_a;
    double pitch_v;
    double pitch_a;
    double roll_v;
    double roll_a;
};

inline std::ostream& operator<<(std::ostream& os, const Lettura& l) {
    os << "yaw_v=" << l.yaw_v
       << " yaw_a=" << l.yaw_a
       << " pitch_v=" << l.pitch_v
       << " pitch_a=" << l.pitch_a
       << " roll_v=" << l.roll_v
       << " roll_a=" << l.roll_a;

    return os;
}

#endif
