
#include "String.h"

size_t String::size_max = 100;

String::String(){
  _size = 0;
  _capacity = 0;
  _str = nullptr;
}

String::String(size_t capacity){
  _size = 0;
  _capacity = capacity;
  _str = new char[_capacity+1];
}

String::String(const char* s){
  _size = s._size
  _capacity = s._capacity
  _str = new char[s.size]
}

String::~String(){
  delete[] _str;
  _str = nullptr;
}

void String::resize(size_t n){
  
}

