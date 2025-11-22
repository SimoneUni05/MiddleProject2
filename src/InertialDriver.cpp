#include "../include/InertialDriver.h"
//Implementazione costruttore
InertialDriver::InertialDriver(): buffer_ {MyVector<Measure>()}, head_ {0}, tail_ {0}, size_{0} {};

// Implementazione dell'operator <<
std::ostream& operator<<(std::ostream& os, const InertialDriver& v) {
	  for (int i=v.head_;i>v.tail_;i--){ //scorrimento del buffer con le misure dalla più recente alla più vecchia
		    os << v.head_-i + 1 << " measure:" << buffer[i] << '\n';
	  }
	  os <<'\n';
  }
  return os;
};


