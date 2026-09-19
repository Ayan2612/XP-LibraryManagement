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

int main() {

    vector<Book> books = {
        {101, "The C++ Programming Language", true},
        {102, "Data Structures and Algorithms", true},
        {103, "Operating System Concepts", true},
        {104, "Database Management Systems", true},
        {105, "Computer Networks", true}
    };

    displayBooks(books);

    return 0;
}