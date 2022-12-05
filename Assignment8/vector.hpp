#pragma once
#include <exception>
#include <initializer_list>
#include <iterator>
#include <memory>

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
                    iterator operator->() {return *m_data;};
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
            pointer m_data;    
            
    };

    template<typename T>
    vector<T>::vector() :
        m_size(10),
        m_nOfElements(0),
        m_data(std::make_shared<T[]>(10))
    {
    }
    template<typename T>
    vector<T>::vector(size_type size) :
        m_size([](size_type currentCapacity) -> size_type
        {
            return currentCapacity * 2;
        }),
        m_nOfElements(0),
        m_data(std::make_shared<T[]>(m_size))
    {
    }
    template<typename T>
    vector<T>::vector(resize_type size) :
        m_size(size_type(size) -> size_type
        {
            if (m_size < size)
        }),
        m_nOfElements(0),
        m_data(std::make_shared<T[]>(m_size))
    {
    }

    // copy constructor for iterator
    template<typename T>
    vector<T>::iterator::iterator(const iterator& obj)
    {
        m_pos = obj.m_pos;
        m_data = obj.m_data;
    }
    // move constructor for iterator
    template<typename T>
    vector<T>::iterator::iterator(iterator&& obj) noexcept
    {
        this->m_pos = obj.m_pos;
        this->m_data = obj.m_data;
        obj.m_pos = 0;
        obj.m_data = nullptr;
    }
    // Operators for -- and ++
    template<typename T>
     typename vector<T>::iterator vector<T>::iterator::operator--()
    {
        m_pos--;
        return *this;
    }
    template <typename T>
    typename vector<T>::iterator vector<T>::iterator::operator--(int)
    {
        iterator i = *this;
        m_pos--;
        return i;
    }

    template<typename T>
    typename vector<T>::iterator vector<T>::iterator::operator++()
    {
        m_pos++;
        return *this;
    }
    template <typename T>
    typename vector<T>::iterator vector<T>::iterator::operator++(int)
    {
        iterator i = *this;
        m_pos++;
        return i;
    }

    // 
    template <typename T>
    typename vector<T>::iterator& vector<T>::iterator::operator=(const iterator& rhs)
    {
        this->m_pos = rhs.m_pos;
        this->m_data = rhs.m_data;
        return *this;
    }

    template <typename T>
    typename vector<T>::iterator& vector<T>::iterator::operator=(const iterator&& rhs)
    {
        if (this != &rhs)
        {
            std::swap(this->m_pos, rhs.m_pos);
            std::swap(this->m_data, rhs.m_data);
        }
        return *this;
    }
}