#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
  int bookID;
  string title;
  string author;
  bool isIssued;

public:
  Book(int id, string title, string author)
      : bookID(id), title(title), author(author), isIssued(false) {}

  int getBookID() { return bookID; }
  string getTitle() { return title; }
  string getAuthor() { return author; }
  bool isBookIssued() { return isIssued; }
  void setBookIssued(bool issued) { isIssued = issued; }
  void setTitle(string newTitle) { title = newTitle; }
  void setAuthor(string newAuthor) { author = newAuthor; }
};

class Student {
private:
  int studentID;
  string name;
  vector<int> issuedBooks;

public:
  Student(int id, string name) : studentID(id), name(name) {}
  int getStudentID() { return studentID; }
  string getName() { return name; }
  vector<int> getIssuedBooks() { return issuedBooks; }
  void addIssuedBook(int bookID) { issuedBooks.push_back(bookID); }
  void returnBook(int bookID) {
    issuedBooks.erase(remove(issuedBooks.begin(), issuedBooks.end(), bookID),
                      issuedBooks.end());
  }
  void setName(string newName) { name = newName; }
};

class Library {
private:
  vector<Book> books;
  vector<Student> students;
  string bookFileName;
  string studentFileName;

public:
  Library(string bookFile, string studentFile)
      : bookFileName(bookFile), studentFileName(studentFile) {
    loadBooksFromFile();
    loadStudentsFromFile();
  }

  ~Library() {
    saveBooksToFile();
    saveStudentsToFile();
  }

  bool bookIDExists(int bookID) {
    for (auto &book : books) {
      if (book.getBookID() == bookID) {
        return true;
      }
    }
    return false;
  }

  bool studentIDExists(int studentID) {
    for (auto &student : students) {
      if (student.getStudentID() == studentID) {
        return true;
      }
    }
    return false;
  }

  void addBook(Book book) {
    if (bookIDExists(book.getBookID())) {
      cout << "Book ID already exists. Cannot add book." << endl;
      return;
    }
    books.push_back(book);
    saveBooksToFile();
  }

  void addStudent(Student student) {
    if (studentIDExists(student.getStudentID())) {
      cout << "Student ID already exists. Cannot add student." << endl;
      return;
    }
    students.push_back(student);
    saveStudentsToFile();
  }

  Book *findBookByID(int bookID) {
    for (auto &book : books) {
      if (book.getBookID() == bookID) {
        return &book;
      }
    }
    return nullptr;
  }

  Student *findStudentByID(int studentID) {
    for (auto &student : students) {
      if (student.getStudentID() == studentID) {
        return &student;
      }
    }
    return nullptr;
  }

  void issueBook(int studentID, int bookID) {
    Student *student = findStudentByID(studentID);
    Book *book = findBookByID(bookID);

    if (student && book && !book->isBookIssued()) {
      student->addIssuedBook(bookID);
      book->setBookIssued(true);
      cout << "Book issued successfully." << endl;
    } else {
      cout << "Book not found or already issued." << endl;
    }
  }

  void returnBook(int studentID, int bookID) {
    Student *student = findStudentByID(studentID);
    Book *book = findBookByID(bookID);

    if (student && book && book->isBookIssued()) {
      student->returnBook(bookID);
      book->setBookIssued(false);
      cout << "Book returned successfully." << endl;
    } else {
      cout << "Book not found or not issued." << endl;
    }
  }

  void loadBooksFromFile() {
    std::ifstream file(bookFileName);
    if (file.is_open()) {
      int id;
      std::string title;
      std::string author;

      while (file >> id) {
        file.ignore();                  // Ignore the whitespace after the ID
        std::getline(file, title, ';'); // Read until the semicolon delimiter
        std::getline(file, author);     // Read until the end of the line
        books.push_back(Book(id, title, author));
      }
      file.close();
    } else {
      std::cerr << "Unable to open books file." << std::endl;
    }
  }

  void loadStudentsFromFile() {
    std::ifstream file(studentFileName);
    if (file.is_open()) {
      int id;
      std::string name;

      while (file >> id) {
        file.ignore();            // Ignore the whitespace after the ID
        std::getline(file, name); // Read until the end of the line
        students.push_back(Student(id, name));
      }
      file.close();
    } else {
      std::cerr << "Unable to open students file." << std::endl;
    }
  }

  void saveBooksToFile() {
    std::ofstream file(bookFileName);
    if (file.is_open()) {
      for (auto &book : books) {
        file << book.getBookID() << " " << book.getTitle() << ";"
             << book.getAuthor() << "\n";
      }
      file.close();
    } else {
      std::cerr << "Unable to open books file for writing." << std::endl;
    }
  }

  void saveStudentsToFile() {
    std::ofstream file(studentFileName);
    if (file.is_open()) {
      for (auto &student : students) {
        file << student.getStudentID() << " " << student.getName() << "\n";
      }
      file.close();
    } else {
      std::cerr << "Unable to open students file for writing." << std::endl;
    }
  }

  void displayBooks() {
    const int idWidth = 10;
    const int titleWidth = 30;
    const int authorWidth = 30;
    const int issuedWidth = 10;

    std::cout << std::left << std::setw(idWidth) << "ID"
              << std::setw(titleWidth) << "Title" << std::setw(authorWidth)
              << "Author" << std::setw(issuedWidth) << "Issued"
              << "\n";
    std::cout << std::string(idWidth + titleWidth + authorWidth + issuedWidth,
                             '-')
              << "\n";

    for (auto &book : books) {
      std::string title = book.getTitle();
      if (title.length() > titleWidth - 1)
        title = title.substr(0, titleWidth - 4) + "...";

      std::string author = book.getAuthor();
      if (author.length() > authorWidth - 1)
        author = author.substr(0, authorWidth - 4) + "...";

      std::cout << std::left << std::setw(idWidth) << book.getBookID()
                << std::setw(titleWidth) << title << std::setw(authorWidth)
                << author << std::setw(issuedWidth)
                << (book.isBookIssued() ? "Yes" : "No") << "\n";
    }
  }

  void displayStudents() {
    const int idWidth = 10;
    const int nameWidth = 30;
    const int issuedBooksWidth = 30;

    std::cout << std::left << std::setw(idWidth) << "ID" << std::setw(nameWidth)
              << "Name" << std::setw(issuedBooksWidth) << "Issued Books"
              << "\n";
    std::cout << std::string(idWidth + nameWidth + issuedBooksWidth, '-')
              << "\n";

    for (auto &student : students) {
      std::string name = student.getName();
      if (name.length() > nameWidth - 1)
        name = name.substr(0, nameWidth - 4) + "...";

      std::vector<int> issuedBooks = student.getIssuedBooks();
      std::ostringstream oss;
      for (size_t i = 0; i < issuedBooks.size(); ++i) {
        oss << issuedBooks[i];
        if (i != issuedBooks.size() - 1) {
          oss << ", ";
        }
      }
      std::string issuedBooksStr = oss.str();
      if (issuedBooksStr.length() > issuedBooksWidth - 1)
        issuedBooksStr = issuedBooksStr.substr(0, issuedBooksWidth - 4) + "...";

      std::cout << std::left << std::setw(idWidth) << student.getStudentID()
                << std::setw(nameWidth) << name << std::setw(issuedBooksWidth)
                << issuedBooksStr << "\n";
    }
  }

  void editBook(int bookID) {
    Book *book = findBookByID(bookID);
    if (book) {
      string newTitle, newAuthor;
      cout << "Enter new title: ";
      cin.ignore();
      getline(cin, newTitle);
      cout << "Enter new author: ";
      getline(cin, newAuthor);
      book->setTitle(newTitle);
      book->setAuthor(newAuthor);
      saveBooksToFile();
      cout << "Book edited successfully." << endl;
    } else {
      cout << "Book not found." << endl;
    }
  }
  void editStudent(int studentID) {
    Student *student = findStudentByID(studentID);
    if (student) {
      string newName;
      cout << "Enter new name: ";
      cin.ignore();
      getline(cin, newName);
      student->setName(newName);
      saveStudentsToFile();
      cout << "Student edited successfully." << endl;
    } else {
      cout << "Student not found." << endl;
    }
  }
};

void displayMenu() {
  cout << "\nLibrary Management System\n";
  cout << "1. Add Book\n";
  cout << "2. Add Student\n";
  cout << "3. Issue Book\n";
  cout << "4. Return Book\n";
  cout << "5. Display All Books\n";
  cout << "6. Display All Students\n";
  cout << "7. Edit Book\n";
  cout << "8. Edit Student\n";
  cout << "0. Exit\n";
  cout << "Enter your choice: ";
}

int main() {
  Library library("books.txt", "students.txt");
  int choice;

  do {
    displayMenu();
    cin >> choice;

    switch (choice) {
    case 1: {
      int id;
      string title, author;
      cout << "Enter Book ID: ";
      cin >> id;
      cin.ignore();
      cout << "Enter Book Title: ";
      getline(cin, title);
      cout << "Enter Book Author: ";
      getline(cin, author);
      library.addBook(Book(id, title, author));
      break;
    }
    case 2: {
      int id;
      string name;
      cout << "Enter Student ID: ";
      cin >> id;
      cin.ignore(); // to ignore the newline character left in the buffer
      cout << "Enter Student Name: ";
      getline(cin, name);
      library.addStudent(Student(id, name));
      break;
    }
    case 3: {
      int studentID, bookID;
      cout << "Enter Student ID: ";
      cin >> studentID;
      cout << "Enter Book ID: ";
      cin >> bookID;
      library.issueBook(studentID, bookID);
      break;
    }
    case 4: {
      int studentID, bookID;
      cout << "Enter Student ID: ";
      cin >> studentID;
      cout << "Enter Book ID: ";
      cin >> bookID;
      library.returnBook(studentID, bookID);
      break;
    }
    case 5: {
      library.displayBooks();
      break;
    }
    case 6: {
      library.displayStudents();
      break;
    }
    case 7: {
      int bookID;
      cout << "Enter Book ID to edit: ";
      cin >> bookID;
      library.editBook(bookID);
      break;
    }
    case 8: {
      int studentID;
      cout << "Enter Student ID to edit: ";
      cin >> studentID;
      library.editStudent(studentID);
      break;
    }
    case 0: {
      cout << "Exiting...\n";
      break;
    }
    default: {
      cout << "Invalid choice! Please try again.\n";
      break;
    }
    }
  } while (choice != 0);

  return 0;
}
