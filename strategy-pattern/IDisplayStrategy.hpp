#include <iostream>

class IDisplayStrategy {
public:
    virtual void display() = 0;
    virtual ~IDisplayStrategy() = default;
};

class DefaultDisplay : public IDisplayStrategy {
public:
    void display() { std::cout << "Displaying something!\n"; }
};
