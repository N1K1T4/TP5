
#include "String.h"

int String::size_max = 0;

String::String(){
  _size = 0;
  _capacity = 0;
  _str = nullptr;
}

String::String(int capacity){
  _size = capacity;
  _capacity = capacity;
  _str = new char[_capacity+1];
}

String::~String(){
  delete[] _str;
  _str = nullptr;
}
