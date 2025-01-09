#include <memory>
#include "IDisplayStrategy.hpp"
#include "IFlyStrategy.hpp"
#include "IQuackStrategy.hpp"

class Duck {
    std::unique_ptr<IDisplayStrategy> m_displayStrat;
    std::unique_ptr<IFlyStrategy> m_flyStrat;
    std::unique_ptr<IQuackStrategy> m_quackStrat;

public:
    Duck() {
        m_displayStrat = std::make_unique<DefaultDisplay>();
        m_flyStrat = std::make_unique<DefaultFly>();
        m_quackStrat = std::make_unique<DefaultQuack>();
    }

    Duck(std::unique_ptr<IDisplayStrategy>&& displayStrat,
         std::unique_ptr<IFlyStrategy>&& flyStrat,
         std::unique_ptr<IQuackStrategy>&& quackStrat) {
        this->m_displayStrat = std::move(displayStrat);
        this->m_flyStrat = std::move(flyStrat);
        this->m_quackStrat = std::move(quackStrat);
    }

    void setDisplayStrat(std::unique_ptr<IDisplayStrategy>&& displayStrat) {
        m_displayStrat = std::move(displayStrat);
    }

    void setFlyStrat(std::unique_ptr<IFlyStrategy>&& flyStrat) {
        m_flyStrat = std::move(flyStrat);
    }

    void setQuackStrat(std::unique_ptr<IQuackStrategy>&& quackStrat) {
        m_quackStrat = std::move(quackStrat);
    }

    void display() { m_displayStrat->display(); }

    void fly() { m_flyStrat->fly(); }

    void quack() { m_quackStrat->quack(); }

    ~Duck() = default;
};
