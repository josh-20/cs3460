#pragma once
#include <iostream>
namespace usu {
    template <typename T>
    class shared_ptr {
        public:
            //overloaded constructor
            shared_ptr(T* pointer);
            // copy constructor
            shared_ptr(const shared_ptr& pointer);
            //move constructor
            shared_ptr(shared_pointer&& pointer);
            // destructor
            ~shared_ptr();
            // Operators           
            // normal methods
            shared_ptr<T> make_shared(Args&&... args);
            std::uint8_t use_count();
            T* get();
            private:
                std::uint16_t m_referenceCount = 0;
                T m_pointer;
    };
    template<typename T>
    shared_ptr<T>::shared_ptr(T* pointer) :
        m_pointer(pointer)
        m_referenceCount(1)
    {
    }
    
    template <typename T, typename... Args>
    usu::shared_ptr<T> make_shared(Args&&... args)
    {
        return shared_ptr<T>(new T(std::forward<Args>(args)...));
    }


    template<typename T>
    usu::shared_ptr<T> use_count(){
        return m_referenceCount;
    }

    template<typename T>
    usu::shared_ptr<T> get(){

    }

    template <typename T>
    usu::shared_ptr<T>::shared_ptr(T* pointer){
    
    }

};