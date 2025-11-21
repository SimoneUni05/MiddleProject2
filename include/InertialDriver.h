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

//for readability
using Measure = std::array<SensorData, 17>;


class InertialDriver{

  public : 

    //constructor
    InertialDriver();
    
    void push_back(const Measure& measure);
    Measure pop_front();
    void clear_buffer();

    //get the SensorData at i = index of the last Measure added
    SensorData get_reading(int index);

    friend std::ostream& operator<<(std::ostream& os, const InertialDriver& v);

  private:
    MyVector<Measure> buffer_;
    static const int BUFFER_DIM = 10;
};

#endif 
