
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

String::~String(){
  delete[] _str;
  _str = nullptr;
}

bool String::empty(){
  if (_size == 0){
	  return true;
  }
  return false;
}

void String::reserve(size_t length){
  if (length > _capacity){
	  char* newstr = new char[length+1];
	  for (int i=0; i<(int)(_size); i++){
		  newstr[i] = _str[i];
	  }
	  delete[] _str;
	  _str = newstr;
	  _capacity = length; 
  }
}
