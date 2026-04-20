#include <iostream>
using std::cout, std::endl;

#include <list>
using std::list;

#include <string>
using std::string;

class Animal {
    string kind_;
 public:
    Animal(string kind) : kind_{kind} {}
    virtual string talk() const { return "<animal noises>"; }
    string kind() const { return kind_; }
};

class Pig : public Animal {
 public:
    Pig() : Animal("pig") {}
    string talk() const override { return "oink"; }
};

class Duck : public Animal {
 public:
    Duck() : Animal("duck") {}
    string talk() const override { return "quack"; }
};

class Horse : public Animal {
 public:
    Horse() : Animal("horse") {}
    string talk() const override { return "neigh"; }
};


int main() {
    list<Animal*> animals;
    animals.push_back(new Pig);
    animals.push_back(new Duck);
    animals.push_back(new Horse);

    for (Animal const* animal : animals) {
        cout <<
        "Old MacDonald had a farm, E-I-E-I-O.\n"
        "And on that farm he had a " << animal->kind() << ". E-I-E-I-O.\n"
        "With a " << animal->talk() << ' ' << animal->talk() << " here.\n"
        "And a " << animal->talk() << ' ' << animal->talk() << " there.\n"
        "Here a " << animal->talk() << ".\n"
        "There a " << animal->talk() << ".\n"
        "Everywhere a " << animal->talk() << ' ' << animal->talk() << ".\n"
        "Old MacDonald had a farm, E-I-E-I-O.\n"
        << endl;
    }
}
