#ifndef INERTIALDRIVER_H
#define INERTIALDRIVER_H

class InertialDriver{

  public : 
  
    // Reading: std::array<double, 6>
    // Measure : std::array<std::array<double, 6>, 17>
    
    void push_back(const std::array<std::array<double, 6>, 17>& measure);
    std::array<std::array<double, 6>, 17> pop_front();
    void clear_buffer();
    std::array<double, 6> get_reading(int index);
    
    std::ostream& operator<<(std::ostream& os, const InertialDriver& v);

  private:
    MyVector<Measure> buffer_;
    const int BUFFER_DIM = 10;
}
#endif 


