#include <iostream>
#include "Creator.hpp"
#include "Product.hpp"

void ClientCode(const Creator& creator) {
    std::cout << "Client: I work even though idk what creator I have lol\n" +
                     creator.SomeOperation()
              << "\n";
}

int main(void) {
    std::cout << "App: Launched with the ConcreteCreator1.\n";
    Creator* creator = new ConcreteCreator1();
    ClientCode(*creator);
    std::cout << std::endl;
    std::cout << "App: Launched with the ConcreteCreator2.\n";
    Creator* creator2 = new ConcreteCreator2();
    ClientCode(*creator2);

    delete creator;
    delete creator2;
}
