#ifndef STRING_H__
#define STRING_H__

#include <cstdlib>

class string
{
public:
//======================================================================
//             CONSTRUCTORS & DESTRUCTOR
//======================================================================
	string();
	string(size_t capacity);
	string(size_t capacity, char c);
	string(const string& s);
	string(const char* s);
	~string();
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
	const char* c_str() const;
	void clear();
	void resize(size_t length);
	void reserve(size_t length);
//======================================================================
//             PUBLIC OPERATORS
//======================================================================
	char operator () (int i) const;
	char& operator [] (int i);
	const char& operator [] (int i) const;
	const string& operator = (const char c);
	const string& operator = (const char* s);
	const string& operator = (const string& s);
  
private:
//======================================================================
//             PRIVATE ATTRIBUTES
//======================================================================
	static size_t _max_size;
	size_t _size;
	size_t _capacity;
	char* _str;
};

//======================================================================
//             EXTERN METHODS
//======================================================================
// Les opérateurs + doivent être externes à la classe et prendre deux
// éléments en argument (2 string, un char + un string...)
string operator + (const string& lhs, const char rhs);
string operator + (const string& lhs, const char* rhs);
string operator + (const string& lhs, const string& rhs);
//======================================================================
//             INLINE METHODS
//======================================================================

inline size_t string::capacity() const
{
	return _capacity;
}

inline size_t string::length() const
{
	return _size;
}

inline size_t string::max_size() const
{
	return _max_size;
}

inline size_t string::size() const
{
	return _size;
}

#endif
