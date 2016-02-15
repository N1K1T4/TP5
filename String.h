
#ifndef STRING_H__
#define STRING_H__

#include <stdio.h>
#include <cstdlib>



class String{
public:
//======================================================================
//             CONSTRUCTEURS & DESTRUCTEUR
//======================================================================
  String();
  String(size_t capacity);
  String(size_t capacity, char c);
  String(const String& str); //par copie
  String(const char* s); //cstring
  ~String(); 

//======================================================================
//             PUBLIC METHODS
//======================================================================
  void resize(size_t);
  inline size_t size() const;
  inline size_t capacity() const;  
  inline size_t length() const;
  inline size_t max_size() const;

protected:
  static size_t size_max;
  size_t _size;
  size_t _capacity;
  char* _str;
};

inline size_t String::size() const{
	return _size;
}

inline size_t String::capacity() const{
	return _capacity;
}

inline size_t String::length() const{
  return _size;
}

inline size_t String::max_size() const{
  return size_max;
}



#endif
