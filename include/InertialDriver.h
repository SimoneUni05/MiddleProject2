#ifndef INERTIALDRIVER_H
#define INERTIALDRIVER_H

#include "MyVector.h"

struct SensorData {
    double yaw_velocity;
    double yaw_acceleration;
    double pitch_velocity;
    double pitch_acceleration;
    double roll_velocity;
    double roll_acceleration;
};

//for readibility
using Measure = std::array<SensorData, 17>;


class InertialDriver{

  public : 

    InertialDriver();
    // (Letture) = SensorData: std::array<double, 6>
    // Measure : std::array<std::array<double, 6>, 17>
    
    void push_back(const Measure& measure);
    Measure pop_front();
    void clear_buffer();
    SensorData get_reading(int index);
    
    friend std::ostream& operator<<(std::ostream& os, const InertialDriver& v);

  private:
    MyVector<Measure> buffer_;
    static const int BUFFER_DIM = 10;
};

#endif 
