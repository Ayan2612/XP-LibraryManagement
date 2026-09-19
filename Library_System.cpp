#include <iostream>
#include <vector>
using namespace std;

struct Book {
    int id;
    string title;
    bool available;
};

// Display all books
void displayBooks(const vector<Book>& books) {

    cout << "\n========== LIBRARY BOOKS ==========\n";

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

    cout << "===================================\n";
}

// Issue a book
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

    cout << "\nInvalid Book ID."
         << endl;
}

// Return a book
void returnBook(vector<Book>& books, int bookId) {

    for (Book& book : books) {

        if (book.id == bookId) {

            if (!book.available) {

                book.available = true;

                cout << "\nBook returned successfully!"
                     << endl;
            }
            else {

                cout << "\nThis book is already available."
                     << endl;
            }

            return;
        }
    }

    cout << "\nInvalid Book ID."
         << endl;
}

int main() {

    vector<Book> books = {

        {101, "The C++ Programming Language", true},

        {102, "Data Structures and Algorithms", true},

        {103, "Operating System Concepts", true},

        {104, "Database Management Systems", true},

        {105, "Computer Networks", true}
    };

    int choice;
    int bookId;

    do {

        cout << "\n\n===== LIBRARY MANAGEMENT SYSTEM =====\n";

        cout << "1. Display Books\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:

                displayBooks(books);

                break;

            case 2:

                cout << "Enter Book ID to issue: ";
                cin >> bookId;

                issueBook(books, bookId);

                break;

            case 3:

                cout << "Enter Book ID to return: ";
                cin >> bookId;

                returnBook(books, bookId);

                break;

            case 4:

                cout << "\nExiting Library System..."
                     << endl;

                break;

            default:

                cout << "\nInvalid choice. "
                     << "Please try again."
                     << endl;
        }

    } while (choice != 4);

    return 0;
}