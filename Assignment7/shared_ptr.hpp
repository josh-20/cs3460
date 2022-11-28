#pragma once
#include <iostream>
namespace usu {
    template <typename T>
    class shared_ptr {
        public:
            //overloaded constructor
            shared_ptr(T* ptr);
            // copy constructor
            shared_ptr(const shared_ptr& ptr);
            //move constructor
            shared_ptr(shared_pointer&& ptr);
            // destructor
            ~shared_ptr();
            // Operators 
            shared_ptr& operator->();
            shared_ptr& operator*();           
            // normal methods

            std::uint16_t use_count();
            T* get();
            private:
                unsigned int m_referenceCount = 0;
                T* m_pointer;
    };
    template<typename T>
    shared_ptr<T>::shared_ptr(T* ptr) :
        m_pointer(ptr),
        m_referenceCount(1)
    {
    }

    // Copy constructor 
    template<typename T>
    shared_ptr<T>::shared_ptr(const shared_ptr& ptr)
    {
        m_pointer = ptr.m_pointer;
        m_referenceCount = ptr.m_referenceCount;
        m_referenceCount += 1;
    }
    
    // Move constructor
    template <typename T, typename... Args>
    shared_ptr<T> make_shared(Args&&... args)
    {
        return shared_ptr<T>(new T(std::forward<Args>(args)...));
    }

    // use count 
    template<typename T>
    usu::shared_ptr<T> use_count(){
        return m_referenceCount;
    }

    // get 
    template<typename T>
    usu::shared_ptr<T> get(){
        return         
    }
    template<typename T>
    shared_ptr<T>::~shared_ptr(){
        m_referenceCount -= 1;
        if(m_referenceCount == 0){
            delete m_pointer;
        }
    }

    // Overloaded operators



    template <typename T, unsigned int N>
    shared_ptr<T[]> make_shared_array()
    {
        return shared_ptr<T[]>(new T[N], N);
    }

};