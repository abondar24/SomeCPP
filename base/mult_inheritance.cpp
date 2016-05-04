//
// Created by abondar on 04.05.16.
//

#include <iostream>

using namespace std;

class Animal{
public:
    virtual void move() =0;
    virtual void sleep(){ cout<<"zzzz..."<<endl;}
};

class Dog: public virtual Animal {
public:
    virtual void bark() { cout << "Woof!" << endl; }

    virtual void eat() { cout << "The dog has eaten." << endl; }
    virtual void move() { cout << "The dog has moved." << endl; }

};

class Bird: public virtual Animal {
public:
    virtual void chirp() { cout << "Chirp!" << endl; }
    virtual void eat() { cout << "The bird has eaten." << endl; }
    virtual void move() { cout << "The bird has moved." << endl; }

};

class DogBird : public Dog, public Bird {
public:
    virtual void move(){
        Bird::move();
    }
};

int main() {
    DogBird strangeAnimal;
    strangeAnimal.bark();
    strangeAnimal.chirp();
    strangeAnimal.Dog::eat();
    static_cast<Bird>(strangeAnimal).eat();
    strangeAnimal.move();
    strangeAnimal.sleep();
    return 0;
}
