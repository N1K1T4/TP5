
#include "String.h"

int String::size_max = 0;

String::String(){
  _size = 0;
  _capacity = 0;
  _str = nullptr;
}

String::String(int capacity){
  _size = capacity;
  _capacity = capacity + 1;
  _str = new char[_capacity];
}

String::~String(){
  delete[] _str;
  _str = nullptr;
}
