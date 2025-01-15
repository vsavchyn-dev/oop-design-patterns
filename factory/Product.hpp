#pragma once
#include <string>

class Product {
public:
    virtual ~Product() = default;
    virtual std::string Operation() const = 0;
};

class ConcreteProduct1 : public Product {
public:
    std::string Operation() const { return "Result of concrete product 1"; }
};

class ConcreteProduct2 : public Product {
public:
    std::string Operation() const { return "Result of concrete product 2"; }
};
