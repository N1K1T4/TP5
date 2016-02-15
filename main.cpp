#include "String.h"
#include <iostream>

int main(){
  String s0 = String();
  String s1 = String(5);
  std::cout << s0.size() << std::endl;
  std::cout << s1.size() << std::endl;
  std::cout << s1.capacity() << std::endl;
}
