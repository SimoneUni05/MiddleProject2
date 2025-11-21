#ifndef INERTIALDRIVER_H
#define INERTIALDRIVER_H


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
    const int BUFFER_DIM = 10;
}
#endif 


