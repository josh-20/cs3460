#pragma once
#include <iostream>
namespace usu
{
    template <typename T>
    class shared_ptr
    {
      public:
        // overloaded constructor
        shared_ptr(T* ptr);
        // copy constructor
        shared_ptr(const shared_ptr& ptr);
        // move constructor
        shared_ptr(shared_ptr&& ptr);
        // destructor
        ~shared_ptr();
        // Operators
        T* operator->() { return m_pointer; }
        T& operator*() { return *m_pointer; }
        shared_ptr& operator=(const shared_ptr& ptr);
        shared_ptr& operator=(shared_ptr&& ptr);
        // normal methods
        unsigned int use_count() { return *m_referenceCount; }
        T* get() { return m_pointer; }

      private:
        T* m_pointer;
        unsigned int* m_referenceCount;
    };
    template <typename T>
    shared_ptr<T>::shared_ptr(T* ptr) :
        m_pointer(ptr),
        m_referenceCount(new unsigned int(1))
    {
    }
    // Copy constructor
    template <typename T>
    shared_ptr<T>::shared_ptr(const shared_ptr& ptr)
    {
        m_pointer = ptr.m_pointer;
        m_referenceCount = ptr.m_referenceCount;
        (*m_referenceCount)++;
    }
    // Move constructor
    template <typename T>
    shared_ptr<T>::shared_ptr(shared_ptr&& ptr)
    {
        m_pointer = ptr.m_pointer;
        m_referenceCount = ptr.m_referenceCount;
        ptr.m_pointer = nullptr;
    }
    template <typename T, typename... Args>
    shared_ptr<T> make_shared(Args&&... args)
    {
        return shared_ptr<T>(new T(std::forward<Args>(args)...));
    }
    // copy operator
    template <typename T>
    shared_ptr<T>& shared_ptr<T>::operator=(const shared_ptr& ptr)
    {
        (*m_referenceCount)--;
        if (use_count() == 0)
        {
            delete m_pointer;
            delete m_referenceCount;
            this->m_pointer = nullptr;
            this->m_referenceCount = nullptr;
        }
        this->m_pointer = ptr.m_pointer;
        this->m_referenceCount = ptr.m_referenceCount;
        (*m_referenceCount)++;
        return *this;
    }
    // move operator
    template <typename T>
    shared_ptr<T>& shared_ptr<T>::operator=(shared_ptr&& ptr)
    {
        if (this != &ptr)
        {
            std::swap(m_pointer, ptr.m_pointer);
            std::swap(m_referenceCount, ptr.m_referenceCount);
        }
        return *this;
    }
    // Destructor
    template <typename T>
    shared_ptr<T>::~shared_ptr()
    {
        if (this->m_pointer != nullptr)
        {
            (*m_referenceCount)--;
            if (use_count() == 0)
            {
                delete m_pointer;
                delete m_referenceCount;
                m_pointer = nullptr;
                m_referenceCount = nullptr;
            }
        }
    }
    template <typename T>
    class shared_ptr<T[]>
    {
      public:
        shared_ptr(T* ptr, int num);
        shared_ptr(const shared_ptr& ptr);
        shared_ptr(shared_ptr&& ptr);
        ~shared_ptr();
        T& operator[](const int index) { return m_pointer[index]; }
        shared_ptr& operator=(const shared_ptr& ptr);
        shared_ptr& operator=(shared_ptr&& ptr);
        unsigned int size() { return m_size; }
        unsigned int use_count() { return *m_referenceCount; }

      private:
        T* m_pointer;
        unsigned int* m_referenceCount;
        int m_size;
    };
    template <typename T>
    shared_ptr<T[]>::shared_ptr(T* ptr, int num) :
        m_pointer(ptr),
        m_referenceCount(new unsigned int(1)),
        m_size(num)
    {
    }
    // copy constructor
    template <typename T>
    shared_ptr<T[]>::shared_ptr(const shared_ptr& ptr)
    {
        m_pointer = ptr.m_pointer;
        m_referenceCount = ptr.m_referenceCount;
        m_size = ptr.m_size;
        (*m_referenceCount)++;
    }
    // move constructor
    template <typename T>
    shared_ptr<T[]>::shared_ptr(shared_ptr&& ptr)
    {
        m_pointer = ptr.m_pointer;
        m_referenceCount = ptr.m_referenceCount;
        m_size = ptr.m_size;
        ptr.m_pointer = nullptr;
    }
    // copy operator
    template <typename T>
    shared_ptr<T[]>& shared_ptr<T[]>::operator=(const shared_ptr& ptr)
    {
        (*m_referenceCount)--;
        if (use_count() == 0)
        {
            delete[] m_pointer;
            delete m_referenceCount;
            m_size = 0;
            this->m_pointer = nullptr;
            this->m_referenceCount = nullptr;
        }
        this->m_pointer = ptr.m_pointer;
        this->m_referenceCount = ptr.m_referenceCount;
        this->m_size = ptr.m_size;
        (*m_referenceCount)++;
        return *this;
    }
    // move operator
    template <typename T>
    shared_ptr<T[]>& shared_ptr<T[]>::operator=(shared_ptr&& ptr)
    {
        if (this != &ptr)
        {
            std::swap(m_pointer, ptr.m_pointer);
            std::swap(m_referenceCount, ptr.m_referenceCount);
            std::swap(m_size, ptr.m_size);
        }
        return *this;
    }
    // Destructor
    template <typename T>
    shared_ptr<T[]>::~shared_ptr()
    {
        if (m_pointer != nullptr)
        {
            (*m_referenceCount)--;
            if (use_count() == 0)
            {
                delete[] m_pointer;
                delete m_referenceCount;
                m_size = 0;
                m_pointer = nullptr;
                m_referenceCount = nullptr;
            }
        }
    }
    template <typename T, unsigned int N>
    shared_ptr<T[]> make_shared_array()
    {
        return shared_ptr<T[]>(new T[N], N);
    }
}; // namespace usu