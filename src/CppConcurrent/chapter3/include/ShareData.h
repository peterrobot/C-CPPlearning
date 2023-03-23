#pragma once
#include <exception>
#include <mutex>

struct empty_stack : std::exception
{
    const char* what() const throw();
};

struct full_stack : std::exception
{
    const char* what() const throw();
};

template <typename T>
class ThreadSafetyStack
{
private:
    const uint32_t m_kMaxSize;
    uint32_t m_size;
    T* m_data;
    std::mutex m_mutex;
public:
    ThreadSafetyStack(const uint32_t max_size)
     : m_kMaxSize(max_size), m_size(0), m_data(new T[max_size])
    {}

    ~ThreadSafetyStack()
    {
        delete[] m_data;
    }

    ThreadSafetyStack& operator=(const ThreadSafetyStack& other)
    {
        if(this == &other) return *this;
        std::lock(m_mutex, other.m_mutex);
        std::lock_guard lock1(m_mutex, std::adopt_lock);
        std::lock_guard lock2(other.m_mutex, std::adopt_lock);
        delete[] m_data;
        auto ptr = const_cast<uint32_t*>(&m_kMaxSize);
        *ptr = other.m_kMaxSize;
        m_data = new T[m_kMaxSize];
        m_size = 0;
    }

    void Push(const T& ele)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        if(m_size == m_kMaxSize) throw full_stack{};

        m_data[m_size++] = ele;
    }

    T&& Pop()
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        if(m_size == 0) throw empty_stack{};

        m_size--;
        return std::move(m_data[m_size]);
    }

    bool Empty() noexcept
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        return !m_size;
    }
};

void testShareData();