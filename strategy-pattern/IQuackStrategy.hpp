#include <iostream>

class IQuackStrategy {
public:
    virtual void quack() = 0;
    virtual ~IQuackStrategy() = default;
};

class DefaultQuack : public IQuackStrategy {
public:
    void quack() { std::cout << "Quack!\n"; }
};
