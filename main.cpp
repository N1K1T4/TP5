#include "String.h"


int main(){
  String s0 = String();
  String s1 = String(5);
  printf("%d \n",s0.size());
  printf("%d \n",s1.size());
  printf("%d \n",s1.capacity());
}
