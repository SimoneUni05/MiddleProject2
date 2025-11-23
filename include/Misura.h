#ifndef MISURA_H
#define MISURA_H

#include "../include/Lettura.h"
#include <ostream>

class Misura
{
public:

    Lettura letture_[17]; // array C-style

    Misura() = default;

    Lettura& operator[](int index);

    const Lettura& operator[](int index) const;
    // overload of operator<<, only for output
    // ATTENTION : requires operator<< defined for Lettura
    friend std::ostream& operator<<(std::ostream& os, const Misura& m);

};

#endif // MISURA_H
