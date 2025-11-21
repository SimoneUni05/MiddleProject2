#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include "MyVector.h"

template<typename T>
MyVector<T>::MyVector(int s){
  capacity_ = s;
  if (s <= 0) elem_ = nullptr;
  else elem_ = new T[capacity_];
}

template<typename T>
MyVector<T>::MyVector(std::initializer_list<T> lst){
  sz_ = lst.size();
  capacity_ = lst.size();
  elem_ = new T[sz_];
  
  std::copy(lst.begin(), lst.end(), elem_);
}

// Copy Constructor
template<typename T>
MyVector<T>::MyVector(const MyVector& v){
  sz_ = v.sz_;
  capacity_ = v.capacity_;
  elem_ = new T[sz_];
  
  std::copy(v.elem_, v.elem_ + v.sz_, elem_);
}

// Move Constructor
template<typename T>
MyVector<T>::MyVector(MyVector&& v){
  sz_ = v.sz_;
  capacity_ = v.capacity_;
  elem_ = v.elem_;
  
  v.sz_ = 0;
  v.capacity_ = 0;
  v.elem_ = nullptr;
}

template<typename T>
void MyVector<T>::push_back(T d){
  if( sz_ >= capacity_) resize();
  
  *(elem_ + sz_) = d;
  sz_ ++;
}

// Copy Assignment
template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector& v){
  if (this == &v) return *this;
  T* p = new T[v.sz_];
  std::copy(v.elem_, v.elem_ + v.sz_, p);
  
  delete[] elem_; // de-allocating the old space
  
  sz_ = v.sz_;
  capacity_ = v.capacity_;
  elem_ = p;
  
  return *this;
}

// Move Assignment
template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector&& v){
  if (this == &v) return *this;
  delete[] elem_;
  
  elem_ = v.elem_;
  sz_ = v.sz_;
  capacity_ = v.capacity_;
  
  v.sz_ = 0;
  v.capacity_ = 0;
  v.elem_ = nullptr;
  
  return *this;
}

template<typename T>
const T& MyVector<T>::operator[](int index) const{
  if (index >= sz_ || index < 0) std::cout << "Out Of Bound\n";
  return *(elem_ + index);
}

template<typename T>
T& MyVector<T>::operator[](int index) {
  if (index >= sz_ || index < 0) std::cout << "Out Of Bound\n";
  return *(elem_ + index);
}

template<typename T>
MyVector<T>::~MyVector(){ delete[] elem_; }

template<typename T>
void MyVector<T>::resize(){
  capacity_ *= 2;
  T* temp = new T[capacity_];
  
  for (int i{}; i < sz_; i++){
    *(temp + i) = *(elem_ + i);
  }
  
  delete[] elem_;
  elem_ = temp;
}


#endif
