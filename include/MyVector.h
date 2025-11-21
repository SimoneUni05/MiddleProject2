#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <algorithm>
#include <initializer_list>

template<typename T>
class MyVector{
  public :
    
    MyVector(int size = 1);
    
    explicit MyVector(std::initializer_list<T> lst);
    
    
    MyVector(const MyVector& v);
    
    //Move Constructor
    MyVector(MyVector&& v);
    
    void push_back(T d);
    
    //Copy Assignment
    MyVector& operator=(const MyVector& v);
    
    //Move Assignment
    MyVector& operator=(MyVector&& v);
    
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const MyVector<U>& v);
    
    
     const T& operator[](int index) const;
     
    T& operator[](int index);
     
     ~MyVector();
      
  private :
    void resize();
    int sz_ {};
    int capacity_;
    T* elem_;
};

template<typename U>
std::ostream& operator<<(std::ostream& os, const MyVector<U>& v) {
    os << "[ ";
    for (int i = 0; i < v.sz_; ++i) {
        os << v.elem_[i] << " ";
    }
    os << "]";
    return os;
}

#include "MyVector.hpp"


#endif
