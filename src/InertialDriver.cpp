#include "../include/InertialDriver.h"
//Implementazione costruttore
InertialDriver::InertialDriver()
    : buffer_(), head_(0), tail_(0), size_(0)
{
    // riempiamo il MyVector con BUFFER_DIM Misura "vuote"
    for (int i = 0; i < BUFFER_DIM; ++i) {
        buffer_.push_back(Misura{});
    }
}

// Implementazione dell'operator <<
std::ostream& operator<<(std::ostream& os, const InertialDriver& v) 
{
    for (int i = v.head_; i > v.tail_; i--) { 
        os << v.head_ - i + 1 << " measure: " << v.buffer_[i] << '\n';
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
    if (size_ == 0)
        return Misura{};

    Misura oldMeasure = buffer_[head_];

    head_++;
    if (head_ == BUFFER_DIM)
        head_ = 0;

    size_--;

    return oldMeasure;
}



//to implement
Lettura InertialDriver::get_reading(int index)
{
    

    return Lettura{};
}





