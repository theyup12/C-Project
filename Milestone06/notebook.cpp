#include "notebook.hpp"
#include <fstream>
#include <iostream>

Note *create_note() {
  std::string title, body;
  std::cout << "\nPlease enter the note's title: ";
  getline(std::cin, title);
  std::cout << "Please enter the note: ";
  getline(std::cin, body);
  std::cout << "\n";
  Note *ptr_new_note = new Note(title, body);
  std::cout << "Note added!\n\n";
  return ptr_new_note;
}
EncryptedNote *create_encrypted_note() {
  std::string title, body, password;
  std::cout << "\nPlease enter the note's title: ";
  getline(std::cin, title);
  std::cout << "Please enter the note: ";
  getline(std::cin, body);
  std::cout << "Please enter the password: ";
  getline(std::cin, password);
  std::cout << "\n";
  EncryptedNote *ptr_new_note = new EncryptedNote(title, body, password);
  std::cout << "\nEncrypted Note added!\n\n";
  return ptr_new_note;
}
void Notebook::list() const {
  if (size_ == 0) {
    std::cout << "\nNo notes have been added.\n\n";
  } else {
    std::cout << "\nNotes\n";
    for (unsigned int i = 0; i < size_; i++) {
      std::cout << i + 1 << ". " << notes_[i]->title() << "\n";
    }
    std::cout << "\n";
  }
}

void Notebook::view() const {
  list();
  if (size_ > 0) {
    unsigned int index = 0;
    std::cout << "Please input note index: ";
    std::cin >> index;
    std::cin.ignore();
    if (index - 1 >= size_) {
      std::cout << "\nInvalid note index.\n\n";
    } else {
      std::cout << "\n";
      notes_[index - 1]->display();
    }
  }
}

void Notebook::save(const std::string &filename) const {
  std::ofstream save_file;
  save_file.open(filename);
  save_file << size_ << "\n";
  for (int i = 0; i < size_; i++) {
    save_file << "[Note]\n";
    save_file << notes_[i]->serialize() << "\n";
  }
  save_file.close();
  std::cout << "Notes saved!\n\n";
}

void Notebook::load(const std::string &filename) {
  size_ = 0;
  std::ifstream load_file;
  load_file.open(filename);
  load_file >> size_;
  load_file.ignore();

  std::string temp;
  for (int i = 0; i < size_; i++) {
    getline(load_file, temp);
    getline(load_file, temp);
    notes_[i]->set_title(temp);
    getline(load_file, temp);
    notes_[i]->set_body(temp);
    if (type == "[Note]"){
Note create_note(temp);
      Note *ptr_temp_note = &create_note;
      add(ptr_temp_note);
    }else{
    getline(in_file, temp);
    EncryptedNote create_encrypted_note(temp);
    EncryptedNote *ptr_temp_encnote = &create_encrypted_noteEncryptedNote;
    add(ptr_temp_encnote);
      }
    }

  load_file.close();
  std::cout << "Notes loaded!\n\n";
}
