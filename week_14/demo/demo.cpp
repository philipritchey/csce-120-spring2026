#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

class Animal {
 public:
    virtual string talk() const { return "<animal noises>"; }
};

class Pig : public Animal {};
class Duck : public Animal {};
class Horse : public Animal {};

int main() {
    Pig pig;
    Duck duck;
    Horse horse;

    cout << "The pig says: " << pig.talk() << endl;
    cout << "The duck says: " << duck.talk() << endl;
    cout << "The horse says: " << horse.talk() << endl;
}
