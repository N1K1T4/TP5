#include <cstdio>
#include <cstdlib>
#include "String.h"

int main()
{
  String s0 = String();
  String s1 = String(5);
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
