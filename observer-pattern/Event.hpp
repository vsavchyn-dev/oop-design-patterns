#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void Update(const std::string& message_from_subject) = 0;
};

class ISubject {
public:
    virtual ~ISubject() = default;
    virtual void Attach(IObserver* observer) = 0;
    virtual void Detach(IObserver* observer) = 0;
    virtual void Notify() = 0;
};

class Subject : public ISubject {
    std::vector<IObserver*> m_list_observer;
    std::string m_message;

public:
    virtual ~Subject() { std::cout << "I was the subject.\n"; }

    virtual void Attach(IObserver* observer) override {
        m_list_observer.push_back(observer);
    }

    virtual void Detach(IObserver* observer) override {
        m_list_observer.erase(std::remove(m_list_observer.begin(),
                                          m_list_observer.end(), observer),
                              m_list_observer.end());
    }

    virtual void Notify() override {
        std::cout << "There are " << m_list_observer.size()
                  << " observers in the list.\n";

        for (auto observer : m_list_observer) {
            observer->Update(m_message);
        }
    }

    void CreateMessage(const std::string& message = "Empty") {
        this->m_message = message;
        Notify();
    }

    void BusinessLogic() {
        this->m_message = "some message";
        Notify();
        std::cout << "I'm about to do something\n";
    }
};

class Observer : public IObserver {
    std::string m_message_from_subj;
    Subject& m_subject;
    static int m_static_num;
    int m_number;

public:
    Observer(Subject& subject) : m_subject(subject) {
        this->m_subject.Attach(this);
        std::cout << "Hi, I'm observer number " << ++Observer::m_static_num
                  << "\n";
        this->m_number = Observer::m_static_num;
    }

    virtual ~Observer() {
        std::cout << "Bye, I was observer no: " << m_number << "\n";
    }

    void Update(const std::string& message_from_subject) override {
        m_message_from_subj = message_from_subject;
        PrintInfo();
    }

    void RemoveMeFromTheList() {
        m_subject.Detach(this);
        std::cout << "Observer \"" << m_number << "\" removed from the list.\n";
    }

    void PrintInfo() {
        std::cout << "Observer \"" << m_number
                  << "\": a new message is available --> "
                  << m_message_from_subj << "\n";
    }
};

int Observer::m_static_num = 0;
