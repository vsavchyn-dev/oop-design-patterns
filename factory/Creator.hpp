#pragma once
#include <string>
#include "Product.hpp"

class Creator {
public:
    virtual ~Creator() = default;
    virtual Product* FactoryMethod() const = 0;

    std::string SomeOperation() const {
        Product* product = this->FactoryMethod();

        std::string result =
            "Creator: The same creator's code started working with " +
            product->Operation();
        delete product;
        return result;
    }
};

class ConcreteCreator1 : public Creator {
public:
    Product* FactoryMethod() const override { return new ConcreteProduct1(); }
};

class ConcreteCreator2 : public Creator {
public:
    Product* FactoryMethod() const override { return new ConcreteProduct2(); }
};
