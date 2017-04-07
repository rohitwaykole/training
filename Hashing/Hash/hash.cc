#include "hash.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

HashTable::HashTable(int n) {
  size = n;
  table = (struct Node **)malloc(size * sizeof(struct Node *));
  for (int i = 0; i < size; i++) {
    table[i] = NULL;
  }
}

void HashTable::insert(int num) {
  int loc = num % size;
  cout << "loc: " << loc << endl;
  struct Node *p = table[loc];
  if (p == NULL) {
    p = (struct Node *)malloc(sizeof(struct Node));
    p->num = num;
    p->next = NULL;
  } else {
    while (p->next != NULL) {
      cout << "This should not happen..";
      p = p->next;
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->num = num;
    p->next = NULL;
  }
  cout << "num=" << num << endl;
}

void HashTable::print() {
  struct Node *temp;
  cout << "printing..." << endl;
  for (int i = 0; i < size; i++) {
    if (table[i] != NULL) {
      cout << "num=" << table[i]->num << endl;
      while (temp->next != NULL) {
        cout << "num=" << temp->num << endl;
        temp = temp->next;
      }
    }
  }
}

int HashTable::lookup(int num) {
  int loc = num % size;
  int index;
  if (table[loc]->num == 0)
    cout << "Element not found" << endl;
  else if (table[loc]->num == num)
    cout << "Found at index location" << loc + 1 << endl;

  return 0;
}
