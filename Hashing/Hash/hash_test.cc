#include "hash.h"
#include <iostream>
#include <stdlib.h>

int main() {
  HashTable H(10);
  H.insert(0);
  H.insert(1);
  H.insert(2);
  H.insert(3);
  H.insert(9);
  H.insert(12);
  H.print();

  return 0;
}
