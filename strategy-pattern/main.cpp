#include "Duck.hpp"

class NonDefaultQuack : public IQuackStrategy {
public:
    void quack() { std::cout << "ME QUACK NON DEFAULT!\n"; }
};

int main(void) {
    Duck duckA;
    duckA.quack();
    duckA.setQuackStrat(std::make_unique<NonDefaultQuack>());
    duckA.quack();
}
