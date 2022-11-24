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
            // normal methods
            std::uint16_t use_count();
            T* get();
            private:
                std::uint16_t m_referenceCount = 0;
                T* m_pointer;
    };
    template<typename T>
    shared_ptr<T>::shared_ptr(T* ptr) :
        m_pointer(ptr),
        m_referenceCount(1)
    {
    }
    
    template <typename T, typename... Args>
    shared_ptr<T> make_shared(Args&&... args)
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
    usu::shared_ptr<T>::shared_ptr(T* ptr){
    
    }

};