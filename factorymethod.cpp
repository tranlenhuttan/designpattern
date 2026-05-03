#include <iostream>
using namespace std;

// Interface
class IAnimal {
public:
    virtual void makeSound() = 0;
};

// Concrete classes
class Dog : public IAnimal {
public:
    void makeSound() {
        cout << "I am Dog" << endl;
    }
};

class Cat : public IAnimal {
public:
    void makeSound() {
        cout << "I am Cat" << endl;
    }
};

// Factory Method
class AnimalFactory {
public:
    static IAnimal* create(string type) {
        if (type == "dog") {
            return new Dog();
        } else if (type == "cat") {
            return new Cat();
        } else {
            return NULL;
        }
    }
};

int main() {
    IAnimal* dog = AnimalFactory::create("dog");
    IAnimal* cat = AnimalFactory::create("cat");

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    return 0;
}