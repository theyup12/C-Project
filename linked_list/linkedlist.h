#include <iostream>
struct Node {
  int data;
  Node* next;
};

class Linkedlist {
private:
  Node* head;
public:
  Linkedlist() : head(nullptr) {}
  ~Linkedlist();
  void add_front(int num);
  int find_smallest();
  void print_list();
  void remove_last();
  bool find_value(int num);
  void remove_front();
  int get_size();
};
