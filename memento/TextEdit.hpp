#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

class Memento {
public:
    virtual ~Memento() = default;
    virtual std::string GetName() const = 0;
    virtual std::string date() const = 0;
    virtual std::string state() const = 0;
};

class TextMemento : public Memento {
private:
    std::string m_text;
    std::string m_date;

public:
    TextMemento(std::string text)
        : m_text(text),
          m_date(std::to_string(std::chrono::system_clock::to_time_t(
              std::chrono::system_clock::now()))) {}

    std::string GetName() const override {
        return this->m_date + " / (" + this->m_text.substr(0, 9) + "...)";
    }

    std::string state() const override { return this->m_text; }

    std::string date() const override { return this->m_date; }
};

class Text {
private:
    std::string m_text;

    std::string GenerateRandomString(int length = 10) {
        const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        int stringLength = sizeof(alphanum) - 1;

        std::string random_string;
        for (int i = 0; i < length; i++) {
            random_string += alphanum[std::rand() % stringLength];
        }
        return random_string;
    }

public:
    Text(std::string text) : m_text(text) {
        std::cout << "Originator: My initial state is: " << this->m_text
                  << "\n";
    }

    void DoSomething() {
        std::cout << "Originator: I'm doing something important.\n";
        this->m_text = this->GenerateRandomString(30);
        std::cout << "Originator: and my state has changed to: " << this->m_text
                  << "\n";
    }

    Memento* Save() { return new TextMemento(this->m_text); }

    void Restore(Memento* memento) {
        this->m_text = memento->state();
        std::cout << "Originator: My state has changed to: " << this->m_text
                  << "\n";
    }
};

class Caretaker {
private:
    std::vector<Memento*> m_mementos;
    Text* m_originator;

public:
    Caretaker(Text* originator) : m_originator(originator) {}

    ~Caretaker() {
        for (auto memento : m_mementos) {
            delete memento;
        }
    }

    void Backup() {
        std::cout << "\nCaretaker: Saving Originator\'s state...\n";
        this->m_mementos.push_back(this->m_originator->Save());
    }

    void Undo() {
        if (!this->m_mementos.size()) {
            return;
        }

        Memento* memento = this->m_mementos.back();
        this->m_mementos.pop_back();

        std::cout << "Caretaker: Restoring state to: " << memento->GetName()
                  << "\n";

        try {
            this->m_originator->Restore(memento);
        } catch (...) {
            this->Undo();
        }
    }

    void ShowHistory() {
        std::cout << "Caretaker: Here\'s list of mementos:\n";
        for (Memento* memento : this->m_mementos) {
            std::cout << memento->GetName() << "\n";
        }
    }
};
