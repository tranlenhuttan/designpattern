#include <iostream>
#include <string>
#include <memory>

// Interface
class IAnimal {
public:
    virtual void speak() const = 0;
    virtual ~IAnimal() = default;
};

// Concrete classes
class Dog : public IAnimal {
public:
    void speak() const override {
        std::cout << "I am Dog" << std::endl;
    }
};

class Cat : public IAnimal {
public:
    void speak() const override {
        std::cout << "I am Cat" << std::endl;
    }
};

// Factory Method
class AnimalFactory {
public:
    enum class AnimalType { DOG, CAT };

    static std::unique_ptr<IAnimal> create(AnimalType type) {
        switch (type) {
            case AnimalType::DOG: return std::make_unique<Dog>();
            case AnimalType::CAT: return std::make_unique<Cat>();
            default: return nullptr;
        }
    }
};

int main() {
    auto dog = AnimalFactory::create(AnimalFactory::AnimalType::DOG);
    auto cat = AnimalFactory::create(AnimalFactory::AnimalType::CAT);

    dog->speak();
    cat->speak();

    return 0;
}