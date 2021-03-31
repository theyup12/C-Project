#include <iostream>

class Note {
private:
  std::string title_, body_;

public:
  Note() : Note("Untitled", "") {}
  Note(const std::string &title, const std::string &body)
      : title_(title), body_(body) {}

  void set_title(const std::string &title) { title_ = title; }
  void set_body(const std::string &body) { body_ = body; }
  std::string title() const { return title_; }
  std::string body() const { return body_; }

  // Displays the title and body of the note using the format
  virtual void display() const {
    std::cout << "[" << title_ << "]\n" << body_ << "\n\n";
  }
  virtual std::string serialize() {
    return "[Note]\n" + title_ + "\n" + body_ + "\n";
  }
};
class EncryptedNote : public Note {
private:
  std::string password_;

public:
  EncryptedNote() : EncryptedNote("", "", "") {}
  EncryptedNote(const std::string &title, const std::string &body,
                const std::string &password)
      : Note(title, body), password_(password) {}
   void display()const override  {
    std::string old_password;
    std::cout << "Please enter password to view note: ";
    getline(std::cin, old_password);
    if (password_ == old_password) {
      std::cout << "[" << title() << "]\n" << body() << "\n\n";
    } else {
      std::cout << "Sorry, you do not have the permission to view note.\n\n";
    }
  }
  std::string serialize()override {
    return "[EncNote]\n" + title() + "\n" + body() + password_ + "\n";
  }
};
// Representation of a notebook that contains and manages notes
class Notebook {
private:
  int size_, capacity_;
  Note* *notes_;

public:
  Notebook() : Notebook(100) {}

  // The constructor dynamically creates an array of Note objects to store notes
  // added to the Notebook
  Notebook(int capacity)
      : size_(0), capacity_(capacity), notes_(new Note* [capacity]) {}

  // The destructor deletes the dynamically allocated Note array created during
  // object construction
  ~Notebook() {
    delete[] *notes_;
    *notes_ = nullptr;
  }
  int capacity() const { return capacity_; }
  int size() const { return size_; }
  // Adds a note object to the notebook. Take note that the notebook's size
  // increases everytime a Note is added
  void add(Note *new_note) { notes_[size_++] = new_note; }
  // Lists all note titles according to the size parameter provided
  void list() const;
  // Retrieves the Note object in the specified index. Take note that indices
  // start at 0
  Note *get(int index) const { return notes_[index]; }
  // Displays all note objects then asks the user to provide the Note index to
  // show. Displays an error message when the selected index is outside the
  // range of the note array's indeices
  void view() const;
  // Stores size number objects to a file named filename.
  void save(const std::string &filename) const;
  // Loads all note objects stored in a file and update the size int* so that it
  // contains the total number of note objects loaded
  void load(const std::string &filename);
};

// Asks the user to create a note with it's title and body then returns a Note
// object containing the user-provided values
Note *create_note();
EncryptedNote *create_encrypted_note();
