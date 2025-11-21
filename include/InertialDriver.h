#ifndef INERTIALDRIVER_H
#define INERTIALDRIVER_H

class InertialDriver{

  public : 
  
    void push_back(std::array[17]);
    std::array[17] pop_front();
    void clear_buffer();
    std::array[6] get_reading(int index);
    
    std::ostream& operator<<(std::ostream& os, const InertialDriver& v);

  private:
    MyVector<Measure> buffer_;
    const int BUFFER_DIM = 10;
}
#endif 

