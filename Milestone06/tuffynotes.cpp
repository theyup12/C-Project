
#include "notebook.hpp"
#include <iostream>

int main() {
  char choice;
  std::string filename;
  Notebook tuffynotes;

  std::cout << "Welcome to TuffyNotes!\n\n";
  do {
    std::cout << "[C] Create a note\n";
    std::cout << "[N] Create an encrypted note\n";
    std::cout << "[L] List notes\n";
    std::cout << "[V] View note\n";
    std::cout << "[S] Save notes\n";
    std::cout << "[O] Load notes\n";
    std::cout << "[E] Exit\n";
    std::cout << "Choice: ";
    std::cin >> choice;
    std::cin.ignore();
    Note temp;
    switch (choice) {
    case 'c':
    case 'C':
      temp = *create_note();
      tuffynotes.add(&temp);
      break;
    case 'n':
    case 'N':
      temp = *create_encrypted_note();
      tuffynotes.add(&temp);
      break;
    case 'l':
    case 'L':
      tuffynotes.list();
      break;
    case 'e':
    case 'E':
      std::cout << "\nThank you for using TuffyNotes!\n";
      break;
    case 'v':
    case 'V':
      tuffynotes.view();
      break;
    case 's':
    case 'S':
      std::cout << "\nPlease enter filename: ";
      getline(std::cin, filename);
      tuffynotes.save(filename);
      break;
    case 'o':
    case 'O':
      std::cout << "\nPlease enter filename: ";
      getline(std::cin, filename);
      tuffynotes.load(filename);
      break;
    default:
      std::cout << "\nInvalid choice. Please try again.\n\n";
    }
  } while (choice != 'e' && choice != 'E');

  return 0;
}
