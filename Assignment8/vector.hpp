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
                    iterator();
                    iterator(pointer ptr);
                    iterator(size_type pos, pointer ptr);
                    iterator(const iterator& obj); 
                    iterator(iterator&& obj) noexcept;
                    iterator operator++();
                    iterator operator++(int);
                    iterator operator--();
                    iterator operator--(int);
                    iterator operator->();
                    iterator& operator=(const iterator& rhs);
                    iterator& operator=(iterator&& rhs);
                    reference operator*();
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
            reference operator[](size_type index);
            void add (T value);
            void insert(size_type index, T value);
            void remove(size_type index);
            void clear();
            size_type size();
            size_type capacity();
            iterator begin();
            iterator end();
        private:
            size_type m_size;
            size_type m_capacity;       
            pointer m_data;    
            resize_type m_resize = [](size_type currentCapacity) -> size_type {return currentCapacity * 2;}
            
    };
    
    template<typename T>
    vector<T>::vector() :
        m_capacity(10)
    {
        m_data = std::make_shared<T[]>(m_capacity);
    }
    template<typename T>
    vector<T>::vector(size_type size) :
        m_size(size),
        m_capacity(10)
    {
        if(m_capacity < size){
            m_resize(size);
        }
        m_data = std::make_shared<T[]>(m_capacity);
    }
    template<typename T>
    vector<T>::vector(resize_type resize) :
        m_capacity(10)
    {
        m_resize = resize;
        m_capacity = m_resize(m_capacity);
        m_data = std::make_shared<T[]>(m_capacity)

    }

    template<typename T>
    vector<T>::vector(std::initializer_list<T> list) :
        m_capacity(10)
    {
        m_data = std::make_shared<T[]>(m_capacity);
        for(T i = list.begin; i != list.end; i++){
            add(*i);
        }
    }
    template<typename T>
    vector<T>::vector(std::initializer_list<T> list, resize_type resize) : 
        m_capacity(10)
    {
        m_data = std::make_shared<T[]>(m_capacity);
        for(T)
    }

    template<typename T>
    typename vector<T>::reference vector<T>::operator[](size_type index){
        return &m_data[index];
    }   
    // add value to the vector
    template<typename T>
    void vector<T>::add(T value)
    {
        if(size() == capacity()){
            pointer temp = m_data;
            m_capacity = resize(m_capacity);
            m_data = std::make_shared<T[]>(capacity);
            for (size_type i = 0; i < size; i++){
                m_data[i] = temp[i];
            }
        }
        m_data[size] = value;
        size++;
    }
    template<typename T>
    typename vector<T>::iterator vector<T>::begin(){return iterator(m_data);}

    template<typename T>
    typename vector<T>::iterator vector<T>::end(){return iterator(m_size, m_data);}

    template<typename T>
    void vector<T>::clear(){
        m_size = 0;
    }
    template<typename T>
    size_t vector<T>::size(){
        return m_size;
    }
    template<typename T>
    typename vector<T>::size_type vector<T>::capacity()
    {
        return m_capacity;
    }

    template<typename T>
    vector<T>::iterator::iterator(size_type pos, pointer ptr) :
        m_pos(ptr),
        m_data(m_data)
    {
    }

    template<typename T>
    vector<T>::iterator::iterator(pointer ptr) : 
        m_data(ptr),
        m_pos(0)
    {
    }


    template<typename T>
    vector<T>::iterator::iterator() :
        iterator(nullptr)
    {    
    }
    
    template<typename T>
    typename vector<T>::reference vector<T>::iterator::operator*()
    {
        return m_data[m_pos];
    }
    template<typename T>
    typename vector<T>::iterator vector<T>::iterator::operator->()
    {
        return &m_data[m_pos];
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
    typename vector<T>::iterator& vector<T>::iterator::operator=(iterator&& rhs)
    {
        if (this != &rhs)
        {
            std::swap(this->m_pos, rhs.m_pos);
            std::swap(this->m_data, rhs.m_data);
        }
        return *this;
    }
}