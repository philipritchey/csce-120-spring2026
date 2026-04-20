#include <iostream>
using std::cout, std::endl;

#include <string>
using std::string;

class Animal {
 public:
    virtual string talk() const { return "<animal noises>"; }
};

class Pig : public Animal {
 public:
    string talk() const override { return "oink"; }
};

class Duck : public Animal {
 public:
    string talk() const override { return "quack"; }
};

class Horse : public Animal {
 public:
    string talk() const override { return "neigh"; }
};

string talk_to(Animal const& animal) {
    return animal.talk();
}

int main() {
    Pig pig;
    Duck duck;
    Horse horse;

    cout << "The pig says: " << talk_to(pig) << endl;
    cout << "The duck says: " << talk_to(duck) << endl;
    cout << "The horse says: " << talk_to(horse) << endl;
}
