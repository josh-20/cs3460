#pragma once
#include <exception>
#include <initializer_list>
#include <iterator>

namespace usu{
    template<typename T>
    class vector
    {
        public:
        // Constructors
            using size_type = std::size_t;
            using reference = T&;
            using pointer = std::shared_ptr<T[]>;
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
                    iterator(pointer ptr) :
                        m_data(ptr),
                        m_pos(0)
                    {
                    }
                    iterator(size_type pos, pointer ptr):
                        m_pos(ptr),
                        m_data(m_data)
                    {
                    }
                    iterator(const iterator& obj); 
                    iterator(iterator&& obj) noexcept;
                    iterator operator++();
                    iterator operator++(int);
                    iterator operator--();
                    iterator operator--(int);
                    iterator& operator=(const iterator& rhs);
                    iterator& operator=(iterator&& rhs);
                    reference operator*()
                    {
                        return m_data[m_pos];
                    }
                    bool operator==(const iterator& rhs)
                    {
                        return (m_data = rhs.m_data) && (m_pos = rhs.m_pos);
                    }
                    bool operator!=(const iterator& rhs)
                    {
                        return !(*this == rhs);
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

            void remove(size_type index);
            void clear() {m_size == 0;}
            size_type size(){return m_nOfElements;}
            size_type capacity(){return m_size;}
            iterator begin() {return iterator(m_data)}
            iterator end(){return iterator(m_size, m_data);}
        private:
            size_type m_size;
            size_type m_nOfElements;       
            T m_data;    
            
    };

    // //resize
    // [](size_type currentCapacity) -> size_type
    // {
    //     return currentCapacity * 2;
    // };

}