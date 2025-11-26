#include "../include/InertialDriver.h"
#include <stdexcept>
//Implementazione costruttore
InertialDriver::InertialDriver()
    : buffer_{BUFFER_DIM}, head_(0), tail_(0), size_(0)
{
}

// Implementazione dell'operator <<
std::ostream& operator<<(std::ostream& os, const InertialDriver& v) 
{
    for (int i = 0; i <  v.size_; i++) { 
        os << i + 1 << " measure: " << v.buffer_[(v.head_+i) % v.BUFFER_DIM] << '\n';
    }

    os << '\n';
    return os;
}



//if the measure fitt in the BUFFER I insert it
//otherwise I delete the oldest measure
void InertialDriver::push_back(const Misura& measure)
{
		buffer_[tail_] = measure; 
	
		if(size_ < BUFFER_DIM) // then i've got space
		{
			
			tail_ = (tail_ + 1) % BUFFER_DIM; //in this way if the increment is equal tail_ comes to 0
			size_++;
		}
		else //no space -> circular array
		{
			
			tail_ = (tail_ + 1) % BUFFER_DIM;
			head_ = (head_ + 1) % BUFFER_DIM; // the oldest moves forward
			// the BUFFER_DIM remains the same
			
		}
		
}


//La funzione pop_front che fornisce in output un array stile C contenente la misura più
//vecchia e la rimuove dal buffer

Misura InertialDriver::pop_front()
{
    if (InertialDriver::isEmpty())
        throw std::runtime_error("buffer is empty");

    Misura oldMeasure = buffer_[head_];

    head_ = (head_ + 1) % BUFFER_DIM;

    size_--;

    return oldMeasure;
}



//get the SensorData at i = index of the last Measure added
Lettura InertialDriver::get_reading(int index)
{
    if (index < 0 || index > 16)
        throw std::invalid_argument("index out of bound: must be between 0 and 16");
    if (InertialDriver::isEmpty())
        throw std::runtime_error("buffer is empty");
    
    int lastMeasureIndex = (tail_ + BUFFER_DIM - 1) % BUFFER_DIM;

    Misura lastMeasure = buffer_[lastMeasureIndex];
    return lastMeasure[index]; //operator [] for Measure is defined 
}


bool InertialDriver::isEmpty() {return size_ == 0;}


void InertialDriver::clear_buffer(){
    size_ = 0;
    head_ = 0;
    tail_ = 0;
    
    //For additional safety we could also clear the old saved value.
    //for (int i = 0; i < BUFFER_DIM; ++i) {
    //    buffer_[i] = Misura{}; 
    //}
}
