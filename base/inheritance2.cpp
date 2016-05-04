//
// Created by abondar on 04.05.16.
//

#include <iostream>

using namespace std;

class Book {
public:
    virtual string getDesciption() { return "Book"; }

    virtual int getHeight() { return 120; }
};

class PaperBack : public Book {
public:
    virtual string getDesciption() {
        return "Paperback " + Book::getDesciption();
    }

};

class Romance : public PaperBack {
public:
    virtual string getDesciption() {
        return "Romance " + PaperBack::getDesciption();
    }
    virtual int getHeight() { return PaperBack::getHeight()/2; }
};

class Technical : public Book {
public:
    virtual string getDesciption() {
        return "Technical " + Book::getDesciption();
    }

};


int main() {
    Romance novel;
    Book book;

    cout<< novel.getDesciption()<<endl;
    cout<< book.getDesciption()<<endl;
    cout<< novel.getHeight()<<endl;
    cout<< book.getHeight()<<endl;

    return 0;
}
