#include "String.h"

int main(){
  String s0 = String();
  String s1 = String(5);
  printf("La longueur de s1 est %d \n", s1.size());
  printf("La capacité de s1 est %d\n", s1.capacity());
}
