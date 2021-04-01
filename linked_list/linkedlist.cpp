#include "linkedlist.h"
Linkedlist::~Linkedlist() {
  // TODO: Destructor needs to deallocate all heap memory (delete the nodes)
  while (head != NULL) {
    remove_front();
  }
}

void Linkedlist::add_front(int num) {
  // TODO: Add the num to a new node and insert it at the front of the list
  Node *tmp = new Node;
  tmp->data = num;
  tmp->next = head;
  head = tmp;
}

int Linkedlist::find_smallest() {
  // TODO: Return the smallest number in the list. If the list is empty, return
  // -1.
  if (head == NULL) {
    return -1;
  }
  int min = head->data;
  while (head != NULL) {
    if (min > head->data)
      min = head->data;

    head = head->next;
  }
  return min;
}

void Linkedlist::print_list() {
  // TODO: Print each value in the list to the console as shown below:
  // Ex:
  //     The list contains the values: 1 2 5 7 33 57
  Node *temp = head;
  std::cout << "The list contains the values:";
  while (temp != NULL) {
    std::cout << temp->data << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}

void Linkedlist::remove_last() {
  // TODO: Remove the last node in the list
  Node *ptr;
  Node *prev;
  if (head == NULL) {
    std::cout << "list empty\n";
  } else if (head->next == NULL) {
    ptr = head;
    head = NULL;
    free(ptr);
  } else {
    ptr = head;
    while (ptr->next != NULL) {
      prev = ptr;
      ptr = ptr->next;
    }
  }
}

bool Linkedlist::find_value(int num) {
  // TODO: Search and return true if num is in the linked list, else return
  // false
  Node *cur = head;
  while (cur != NULL) {
    if (cur->data == num)
      return true;
    cur = cur->next;
  }
  return false;
}

void Linkedlist::remove_front() {
  // TODO: Remove the first node at the front of the list
  if (head == NULL) {
    std::cout << "empty list\n";
  } else {
    Node *old = head;
    head = old->next;
    delete old;
  }
}

int Linkedlist::get_size() {
  // TODO: Return a count of the total number of nodes in the list. Use a loop
  // to count it inside this function, do not store a value in the class.
  int count = 0;
  Node *cur = head;
  while (cur != NULL) {
    count++;
    cur = cur->next;
  }
  std::cout << "size of linked list: " << count << std::endl;
  return count;
}
