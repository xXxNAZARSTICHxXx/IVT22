#include <iostream>

// Базовый класс
class Animal {
public:
    Animal(const std::string& name) : name(name) {}

    void eat() const {
        std::cout << name << " is eating." << std::endl;
    }

    void sleep() const {
        std::cout << name << " is sleeping." << std::endl;
    }

private:
    std::string name;
};

// Производный класс 1
class Dog : public Animal {
public:
    Dog(const std::string& name, const std::string& breed)
        : Animal(name), breed(breed) {}

    void bark() const {
        std::cout << "Woof! Woof!" << std::endl; 
    }

private:
    std::string breed;
};

// Производный класс 2
class Cat : public Animal {
public:
    Cat(const std::string& name, bool hasWhiskers)
        : Animal(name), hasWhiskers(hasWhiskers) {}

    void meow() const {
        std::cout << "Meow!" << std::endl;
    }

private:
    bool hasWhiskers;
};

// Производный класс 3
class Bird : public Animal {
public:
    Bird(const std::string& name, const std::string& species)
        : Animal(name), species(species) {}

    void sing() const {
        std::cout << "Tweet! Tweet!" << std::endl;
    }

private:
    std::string species;
};

int main() {
    Dog myDog("Buddy", "Golden Retriever");
    Cat myCat("Whiskers", true);
    Bird myBird("Tweetie", "Canary");

    myDog.eat();
    myDog.bark();

    myCat.sleep();
    myCat.meow();

    myBird.eat();
    myBird.sing();

    return 0;
}