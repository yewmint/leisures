#include <iostream>

template<typename T>
T add(T first){
  return first;
}

template<typename T, typename ...ARGS>
T add(T first, ARGS... addends){
  return first + add(addends...);
}

int main(){
  std::cout << add(1.1, 2) << std::endl;
}
