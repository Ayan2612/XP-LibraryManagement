#include <iostream>
#include <vector>
using namespace std;

struct Book {
    int id;
    string title;
    bool available;
};

void displayBooks(const vector<Book>& books) {
    cout << "\n===== LIBRARY BOOKS =====\n";

    for (const Book& book : books) {
        cout << "ID: " << book.id
             << " | Title: " << book.title
             << " | Status: ";

        if (book.available)
            cout << "Available";
        else
            cout << "Issued";

        cout << endl;
    }
}
void issueBook(vector<Book>& books, int bookId) {

    for (Book& book : books) {

        if (book.id == bookId) {

            if (book.available) {
                book.available = false;

                cout << "\nBook issued successfully!"
                     << endl;
            }
            else {
                cout << "\nBook is already issued."
                     << endl;
            }

            return;
        }
    }

    cout << "\nBook not found." << endl;
}
void returnBook(vector<Book>& books, int bookId) {

    for (Book& book : books) {

        if (book.id == bookId) {

            if (!book.available) {
                book.available = true;

                cout << "\nBook returned successfully!"
                     << endl;
            }
            else {
                cout << "\nBook was not issued."
                     << endl;
            }

            return;
        }
    }

    cout << "\nBook not found." << endl;
}
int main() {

    vector<Book> books = {
        {101, "The C++ Programming Language", true},
        {102, "Data Structures and Algorithms", true},
        {103, "Operating System Concepts", true},
        {104, "Database Management Systems", true},
        {105, "Computer Networks", true}
    };

    // Display all books
    displayBooks(books);

    int bookId;

    // Issue a book
    cout << "\nEnter Book ID to issue: ";
    cin >> bookId;

    issueBook(books, bookId);

    // Display books after issuing
    displayBooks(books);

    // Return a book
    cout << "\nEnter Book ID to return: ";
    cin >> bookId;

    returnBook(books, bookId);

    // Display books after returning
    displayBooks(books);

    return 0;
}