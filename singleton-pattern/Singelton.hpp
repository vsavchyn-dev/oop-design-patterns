#include <iostream>
#include <mutex>
#include <string>

class Singleton {
    static Singleton* m_pinstance;
    static std::mutex m_mutex;

protected:
    std::string m_value;

    Singleton(const std::string value) : m_value(value) {}

    ~Singleton() = default;

public:
    Singleton(Singleton& other) = delete;
    void operator=(const Singleton& other) = delete;

    static Singleton* GetInstance(const std::string& value) {
        std::lock_guard<std::mutex> lock(m_mutex);
        if (m_pinstance == nullptr) {
            m_pinstance = new Singleton(value);
        }
        return m_pinstance;
    }

    void SomeBuisenesLogic() {}

    std::string value() const { return m_value; }
};

Singleton* Singleton::m_pinstance{nullptr};
std::mutex Singleton::m_mutex;
