#include <cstdio>
#include "string.h"

int main()
{
	string s0 = string();
	string s1 = string(5);
	printf("%lu \n",s0.size());
	printf("%lu \n",s1.size());
	printf("%lu \n",s1.capacity());
	s1.reserve(10);
	printf("La capacité de s1 est %lu \n", s1.capacity());
	printf("La taille de s1 est %lu \n", s1.size());
	printf("%lu \n",s1.size());
	printf("%lu \n",s1.length());
	printf("%lu \n",s1.max_size());
}
