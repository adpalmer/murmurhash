#include <iostream>
#include "murmurhash.h"

struct Point {
  int x, y;
};

int main() {
  // hash string
  std::string tmp = "String to Hash";
  
  uint32_t out = murmur3_32(&tmp, tmp.length(), 0);
  std::cout << "String hashed with seed(0): " << out << std::endl;
  out = murmur3_32(&tmp, tmp.length(), 1);
  std::cout << "String hashed with seed(1): " << out << std::endl;

  // hash object
  Point pt;
  pt.x = 10;
  pt.y = 10;
  
  out = murmur3_32(&pt, sizeof(pt), 0);
  std::cout << "Point struct hashed with seed(0): " << out << std::endl;
  out = murmur3_32(&pt, sizeof(pt), 1);
  std::cout << "Point struct hashed with seed(1): " << out << std::endl;

  return 0;
}
