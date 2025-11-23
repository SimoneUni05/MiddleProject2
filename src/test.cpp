#include <iostream>
#include "../include/Lettura.h"
#include "../include/Misura.h"
#include "../include/InertialDriver.h"
#include "../include/MyVector.h"

// this is to create Measure for testing
Misura make_measure(int id) {
    Misura m;
    for (int i = 0; i < 17; ++i) {
        // each Lettura has 6 doubles: set them so we recognize the measure id
        m.letture_[i].yaw_v   = id * 100 + i;
        m.letture_[i].yaw_a   = id * 100 + i + 0.1;
        m.letture_[i].pitch_v = id * 100 + i + 0.2;
        m.letture_[i].pitch_a = id * 100 + i + 0.3;
        m.letture_[i].roll_v  = id * 100 + i + 0.4;
        m.letture_[i].roll_a  = id * 100 + i + 0.5;
    }
    return m;
}

int main() {
    InertialDriver driver;

    std::cout << "=== TEST 1: push_back and operator<< ===\n";

    Misura m1 = make_measure(1);
    Misura m2 = make_measure(2);

// PUSH BACK
    driver.push_back(m1);
    driver.push_back(m2);


    std::cout << "Last measure saved in driver (should be measure 2):\n";
    std::cout << driver << "\n";  // uses InertialDriver::operator<<

// POP FRONT
    std::cout << "=== TEST 2: pop_front oldest measure ===\n";
    Misura oldest = driver.pop_front();
    std::cout << "Oldest measure removed (should be measure 1):\n";
    std::cout << oldest << "\n";

    std::cout << "Buffer now contains only measure 2:\n";
    std::cout << driver << "\n";

    std::cout << "=== TEST 4: circular behaviour ===\n";
    // Push more than BUFFER_DIM times to force overwrite
    for (int id = 3; id < 3 + 12; ++id) {
        driver.push_back(make_measure(id));
    }

    
    std::cout << "RESULT \n";
    std::cout << driver << "\n";

    return 0;
}
