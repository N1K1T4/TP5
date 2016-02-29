// ===========================================================================
//                                  Includes
// ===========================================================================
#include "string.h"

// ===========================================================================
//                       Definition of static attributes
// ===========================================================================
size_t string::_max_size = 100;

// ===========================================================================
//                                Constructors
// ===========================================================================
string::string()
{ //constructeur par defaut
	_capacity = 0;
	_size = 0;
	_str = new char[_capacity + 1];
	_str[_size] = '\0';
}

string::string(size_t capacity)
{//constructeur qui initialise un tableau de capacite "capacity"
	_capacity = capacity;
	_size = 0;
	_str = new char[_capacity + 1];
	_str[_size] = '\0';
}

string::string(size_t capacity, char c)
{/*constructeur qui initialise un tableau de capacite "capacity" 
 contenant uniquement le caractere "c"*/
	_capacity = capacity;
	_size = _capacity;
	_str = new char[_capacity + 1];
	for (int i = 0; i < (int)_size; i++)
	{
		_str[i] = c;
	}
	_str[_size] = '\0';
}

string::string(const string& s)
{//constructeur par copie
	_capacity = s.capacity();
	_size = s.size();
	_str = new char[_capacity + 1];
	for (int i = 0; i < (int)_size; i++)
	{
		_str[i] = s(i);
	}
	_str[_size] = '\0';
}

string::string(const char* s)
{//constructeur par copie a partir d'un pointeur sur un tableau de caracteres
	int i = 0;

	while (s[i])
	{
		i++;
	}
	_size = i;
	_capacity = i;
	_str = new char[_capacity + 1];
	for (int i = 0; i < (int)_size; i++)
	{
		_str[i] = s[i];
	}
	_str[_size] = '\0';
}

// ===========================================================================
//                                 Destructor
// ===========================================================================
string::~string()
{
	delete[] _str;
	_str = 0;
}

// ===========================================================================
//                               Public Methods
// ===========================================================================
bool string::empty() const
{//retourne si le tableau est vide ou non
	return _size == 0;
}

const char* string::c_str() const
{//conversion d'une string en c_string
	char* str = new char[_size + 1];
	for (int i = 0; i < (int)_size + 1; i++)
	{
		str[i] = _str[i];
	}
	return str;
}

void string::clear()
{//vide le tableau
	delete[] _str;
	_str = new char[_capacity + 1];
	_size = 0;
	_str[_size] = '\0';
}

void string::reserve(size_t length)
{
  if (length > _max_size)
  {
    printf("Attention Attention, des individus mal intentionnés essaient "
      "de créer un string de taille supérieure au maximum\n");
  }
	else if (length > _capacity)
	{//augemente la capacite du tableau
		char* newstr = new char[length + 1];
		for (int i = 0; i < (int)_size; i++)
		{
			newstr[i] = _str[i];
		}
		delete[] _str;
		_str = newstr;
		_capacity = length; 
	}/*si la capacite rentree est inferieure a la capacite actuelle, on ne 
   fait rien*/
}

void string::resize(size_t length)
{//on adapte la taille du tableau
	if (length > _max_size)
  {
    printf("Attention Attention, des individus mal intentionnés essaient"
       " de créer un string de taille supérieure au maximum\n");
  }
  else if(length > _capacity)
	{//capacity insuffisante, on cree une nouvelle chaine
		char *tmp = new char[length + 1];
		for (int i = 0; i < (int)_size; i++)
		{
			tmp[i] = _str[i];
		}
		for (int i = _size; i < (int)length; i++)
		{
			tmp[i] = 0;
		}
		delete _str;
		_str = tmp;
		_capacity = length;
		_size = length;
	}
	else if (length > _size)
	{//agrandir la chaine, capacité suffisante pas besoin de reallouer
		for (int i = _size; i < (int)length; i++)
		{
			_str[i] = 0;
		}
		_size = length;
	}  
  else
	{// couper la chaine
		_str[length] = 0;
		_size = length;
	}
}

void string::resize(size_t length, char c)
{//on adapte la taille du tableau
  	if (length > _max_size)
  {
    printf("Attention Attention, des individus mal intentionnés essaient"
      " de créer un string de taille supérieure au maximum\n");
  }
	else if (length > _capacity)
	{//capacity insuffisante, on cree une nouvelle chaine
		char *tmp = new char[length + 1];
		for (int i = 0; i < (int)_size; i++)
		{
			tmp[i] = _str[i];
		}
		for (int i = _size; i < (int)length; i++)
		{
			tmp[i] = c;
		}
		delete _str;
		_str = tmp;
		_capacity = length;
		_size = length;
	}
	else if (length > _size)
	{//agrandir la chaine, capacity suffisante pas besoin de reallouer
		for (int i = _size; i < (int)length; i++)
		{
			_str[i] = c;
		}
		_size = length;
		_str[_size] = '\0';
	}
	else
	{// couper la chaine
		_str[length] = 0;
		_size = length;
	}
}

// ===========================================================================
//                              Operators
// ===========================================================================
char string::operator() (int i) const
{//permet la lecture du caractere i du tableau
	return _str[i%(_size + 1)];
}

char& string::operator[] (int i)
{//acces a la case i du tableau en ecriture et en lecture
	return _str[i%(_capacity + 1)];
}

const char& string::operator[] (int i) const
{//acces a la case i du tableau en lecture seulement
	return _str[i%(_capacity + 1)];
}

const string& string::operator= (const char c)
{//assigne un caractere seulement au tableau
	(*this).resize(1);
	_str[0] = c;
	return *this;
}

const string& string::operator= (const char* s)
{//initialise un tableau avec le tableau pointe par s 
	size_t length = 0;
	while (s[length] != 0)
	{
		length++;
	}
	_size = _capacity = length;
	delete[] _str;
	_str = new char[length++];
	for (size_t i = 0; i < length; i++)
	{
		_str[i] = s[i];
	}
	return *this;
}

const string& string::operator= (const string& s)
{//assigne toutes les valeurs de s a this
	if (&s != this)
	{
		_capacity = s.capacity();
		_size = s.size();
		delete[] _str;
		_str = new char[_capacity + 1];
		for (int i = 0; i < (int)_size; i++)
		{
			_str[i] = s(i);
		}
		_str[_size] = '\0';
	}
	return *this;
}

string operator+ (const string& lhs, const char rhs)
{//concatenation entre lhs(string) et rhs(un caractere)
	string s(lhs.size() + 1);
	for (int i = 0; i < (int)lhs.size(); i++)
	{
		s[i] = lhs(i);
	}
	s[lhs.size()] = rhs;
	s.resize(lhs.size() + 1);
	return s;
}

string operator+ (const string& lhs, const char* rhs)
{//concatenation entre lhs(string) et rhs(c_string)
	int i = 0;

	while (rhs[i])
	{
		i++;
	}
	string s;
	s.resize(lhs.size() + i);
	for (unsigned int j = 0; j < lhs.size(); j++)
	{
		s[j] = lhs[j];
	}
	for (int j = 0; j < i; j++)
	{
		s[j + lhs.size()] = rhs[j];
	}
	return s;
}

string operator+ (const string& lhs, const string& rhs)
{//concatenation de deux string
	size_t capacity = lhs.capacity() + rhs.capacity();
	size_t size = lhs.size() + rhs.size();
	string s = string(capacity);
	s.resize(size);
	for (int i = 0; i < int(lhs.size()); i++){
		s[i] = lhs[i];
	}
	for (int i = int(lhs.size()); i < int(capacity); i++)
	{
		s[i] = rhs[i];
	}
	return s;
}
