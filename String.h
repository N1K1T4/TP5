#ifndef STRING_H__
#define STRING_H__

#include <cstdlib>

class String
{
public:
//======================================================================
//             CONSTRUCTORS & DESTRUCTOR
//======================================================================
  String();
  String(size_t capacity);
  String(size_t capacity, char c);
  String(const String& s); // copy constructor
  String(const char* s); // c-string constructor
  ~String();
//======================================================================
//             GETTERS
//======================================================================
  inline size_t capacity() const;
  inline size_t length() const;
  inline size_t max_size() const;
  inline size_t size() const;
//======================================================================
//             PUBLIC METHODS
//======================================================================
  bool empty();
	char* c_str();
	void clear();
  void resize(size_t);
  void reserve(size_t length);
//======================================================================
//             PUBLIC OPERATORS
//======================================================================
	const String& operator = (const char c);
  const String& operator = (const char* s);
	const String& operator = (const String& s);
	void operator + (const char c);
	void operator + (const char* s);
	void operator + (const String s);
private:
//======================================================================
//             PRIVATE ATTRIBUTES
//======================================================================
  static size_t _max_size;
  size_t _size;
  size_t _capacity;
  char* _str;
};

inline size_t String::capacity() const
{
	return _capacity;
}

inline size_t String::length() const
{
  return _size;
}

inline size_t String::max_size() const
{
  return _max_size;
}

inline size_t String::size() const
{
	return _size;
}

#endif
