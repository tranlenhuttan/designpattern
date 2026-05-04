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
    enum AnimalType { DOG, CAT };

    static IAnimal* create(AnimalType type) {
        if (type == DOG) {
            return new Dog();
        } else if (type == CAT) {
            return new Cat();
        } else {
            return NULL;
        }
    }
};

int main() {
    IAnimal* dog = AnimalFactory::create(AnimalFactory::DOG);
    IAnimal* cat = AnimalFactory::create(AnimalFactory::CAT);

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    return 0;
}