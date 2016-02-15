
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

  inline size_t size() const;
  inline size_t capacity() const;  

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





#endif
