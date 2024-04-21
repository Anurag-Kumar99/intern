#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Book {
    string title;
    string author;
    string ISBN;
    bool available;
};

struct Borrower {
    string name;
    int borrowerID;
};


struct Transaction {
    int transactionID;
    int borrowerID;
    string ISBN;
    bool returned;
};

class Library {
private:
    vector<Book> books;
    vector<Borrower> borrowers;
    vector<Transaction> transactions;
public:
    void addBook(string title, string author, string ISBN) {
        Book newBook;
        newBook.title = title;
        newBook.author = author;
        newBook.ISBN = ISBN;
        newBook.available = true;
        books.push_back(newBook);
    }

    void searchBook(string keyword) {
        for (const auto& book : books) {
            if (book.title == keyword || book.author == keyword || book.ISBN == keyword) {
                cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.ISBN << endl;
            }
        }
    }

    void checkoutBook(int borrowerID, string ISBN) {
        for (auto& book : books) {
            if (book.ISBN == ISBN && book.available) {
                book.available = false;
                Transaction newTransaction;
                newTransaction.transactionID = transactions.size() + 1;
                newTransaction.borrowerID = borrowerID;
                newTransaction.ISBN = ISBN;
                newTransaction.returned = false;
                transactions.push_back(newTransaction);
                cout << "Book checked out successfully!" << endl;
                return;
            }
        }
        cout << "Book not available for checkout." << endl;
    }

    void returnBook(int transactionID) {
        for (auto& transaction : transactions) {
            if (transaction.transactionID == transactionID) {
                for (auto& book : books) {
                    if (book.ISBN == transaction.ISBN) {
                        book.available = true;
                        transaction.returned = true;
                        cout << "Book returned successfully!" << endl;
                        return;
                    }
                }
            }
        }
        cout << "Invalid transaction ID." << endl;
    }

    float calculateFine(int transactionID) {
        return 0.0; 
    }
};

int main() {

    Library library;

    library.addBook("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565");
    library.addBook("To Kill a Mockingbird", "Harper Lee", "9780061120084");

    cout << "Search Results:" << endl;
    library.searchBook("F. Scott Fitzgerald");

    library.checkoutBook(1, "9780743273565");
    library.returnBook(1);

    return 0;
}