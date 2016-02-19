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
	string(const string& s); // copy constructor
	string(const char* s); // c-string constructor
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
	char* c_str();
	void clear();
	void resize(size_t);
	void reserve(size_t length);
//======================================================================
//             PUBLIC OPERATORS
//======================================================================
	const string& operator = (const char c);
	const string& operator = (const char* s);
	const string& operator = (const string& s);
	void operator + (const char c);
	void operator + (const char* s);
	void operator + (const string s);
private:
//======================================================================
//             PRIVATE ATTRIBUTES
//======================================================================
	static size_t _max_size;
	size_t _size;
	size_t _capacity;
	char* _str;
};

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
