#pragma once
#include <exception>
#include <initializer_list>
#include <iterator>

using namespace usu{
    template<typename T>
    class vector (){
        public:
        // Constructors
            using size_type = std::size_t;
            using reference = t&;
            using pointer = std::shared_ptr<T[]>
            using value_type = T;
            using resize_type = std::function<size_type(size_type)>;
            class iterator
            {
                public:
                    using iterator_category = std::bidirectional_iterator_tag;
                    iterator() :
                        iterator(nullptr)
                    {
                    }
                    iterator(size_type pos, pointer ptr):
                        m_pos(ptr),
                        m_data(m_data)
                    {
                    }

                private:
                    size_type m_pos;
                    pointer m_data;
            };

            vector(); // Default constructor that initializes an empty vector, with an initial capacity of 10
            vector(size_type size); //Overloaded constructor that takes a size_type and creates a vecotr of that size
            vector(resize_type resize); 
            vector(size_type size, resize_type resize);
            vector(std::initializer_list<T> list);
            vector(std::initializer_list<T> list, resize_type resize);
        private:
            size_t m_size;           
            
    };

    template<typename T>
    vector() :
    si

//resize
[](size_type currentCapacity) -> size_type
{
    return currentCapacity * 2;
};
    



}