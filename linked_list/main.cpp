#include <iostream>
#include "linkedlist.h"
int main() {
  Linkedlist myList;
  myList.remove_last();
  myList.remove_front();
  myList.get_size();
  myList.find_value(15);
  myList.print_list();
  myList.add_front(1);
  std::cout << "The smallest number is: " << myList.find_smallest() << std::endl;
  myList.remove_last();
  myList.add_front(10);
  myList.remove_last();
  myList.add_front(15);
  myList.add_front(13);
  myList.add_front(122);
  myList.print_list();
  std::cout << "The smallest number is: " << myList.find_smallest() << std::endl;
  myList.remove_last();
  myList.remove_front();
  myList.find_value(15);
  myList.find_value(1024);
  myList.get_size();
  myList.print_list();
  myList.~Linkedlist();//*/
  return 0;
}
