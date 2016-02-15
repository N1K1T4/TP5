#include "String.h"


int main(){
  String s0 = String();
  String s1 = String(5);
  printf("%lu \n",s1.size());
  printf("%lu \n",s1.length());
  printf("%lu \n",s1.max_size());
}
