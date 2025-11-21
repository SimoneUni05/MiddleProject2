#ifndef MISURA_H
#define MISURA_H

#include "../include/Lettura.h"
#include <ostream>

class Misura
{
public:

    Lettura letture_[17]; // array C-style

    Misura(){}

    Lettura& operator[](int index) {
        return letture_[index];
    }

    const Lettura& operator[](int index) const {
        return letture_[index];
    }

    // overload of operator<<, only for output
    // ATTENTION : requires operator<< defined for Lettura
    friend std::ostream& operator<<(std::ostream& os, const Misura& m) {
        for (int i = 0; i < 17; ++i) {
            os << "Sensore " << i << ": " << m.letture_[i] << "\n";
        }
        return os;
    }

};

#endif // MISURA_H
