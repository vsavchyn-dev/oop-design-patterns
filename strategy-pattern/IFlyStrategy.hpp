#include <iostream>

class IFlyStrategy {
public:
    virtual void fly() = 0;
    virtual ~IFlyStrategy() = default;
};

class DefaultFly : public IFlyStrategy {
public:
    void fly() { std::cout << "I just flied!\n"; }
};
