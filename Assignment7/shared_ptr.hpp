pragma once
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
            // normal methods
            std::uint8_t user_count();
            pointer* get();
            private:
                std::uint8_t referenceCount = 0;
    };

}