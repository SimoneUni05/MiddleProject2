#include "../include/Misura.h"



// non-const operator[]
Lettura& Misura::operator[](int index) {
    return letture_[index];
}

// const operator[]
const Lettura& Misura::operator[](int index) const {
    return letture_[index];
}


std::ostream& operator<<(std::ostream& os, const Misura& m) {
        for (int i = 0; i < 17; ++i) {
            os << "Sensore " << i << ": " << m.letture_[i] << "\n";
        }
        return os;
}

