#ifndef LIB_HASH_H_
#define LIB_HASH_H_

#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
public:
  int num;
  struct Node *next;
};

class HashTable {
private:
  int size;
  Node **table;

public:
  HashTable(int n);
  void insert(int num);
  int lookup(int num);
  void print();
};

#endif
