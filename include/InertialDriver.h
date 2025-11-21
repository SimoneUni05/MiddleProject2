#ifndef INERTIALDRIVER_H
#define INERTIALDRIVER_H

#include "MyVector.h"
#include "Misura.h"
#include "Lettura.h"

#include <ostream> 


class InertialDriver{

  public: 

    //constructor
    InertialDriver();
    
    void push_back(const Misura& measure);
    Misura pop_front();
    void clear_buffer();

    //get the SensorData at i = index of the last Measure added
    Lettura get_reading(int index);

    friend std::ostream& operator<<(std::ostream& os, const InertialDriver& v);

  private:
    MyVector<Misura> buffer_;
    static const int BUFFER_DIM = 10;

    int head_ {};
    int tail_ {};
    int size_ {};
};

#endif 
