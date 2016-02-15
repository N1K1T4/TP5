
#ifndef STRING_H__
#define STRING_H__

class String{
public:
//======================================================================
//             CONSTRUCTEURS & DESTRUCTEUR
//======================================================================
  String();
  String(int capacity);
  String(int capacity, char c);
  String(const String& str);
  ~String(); 

//======================================================================
//             PUBLIC METHODS
//======================================================================

  inline int size() const;
  inline int capacity() const;  

protected:
  static int size_max;
  int _size;
  int _capacity;
  char* _str;
};

inline int String::size() const{
	return _size;
}

inline int String::capacity() const{
	return _capacity;
}

#endif
