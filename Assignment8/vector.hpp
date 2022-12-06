#pragma once
#include <exception>
#include <initializer_list>
#include <iterator>
#include <functional>
#include <memory>
#include <algorithm>
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
                    T* operator->();
                    iterator& operator=(const iterator& rhs);
                    iterator& operator=(iterator&& rhs);
                    reference operator*();
                    bool operator==(const iterator& rhs);
                    bool operator!=(const iterator& rhs);
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
            size_type DEFAULT_INITIAL_CAPACITY = 10;
            size_type m_size;
            size_type m_capacity;       
            pointer m_data;    
            resize_type m_resize = [](size_type currentCapacity) -> size_type {return currentCapacity * 2;};
            
    };
    // default constructor
    template<typename T>
    vector<T>::vector() :
        m_size(0),
        m_capacity(10)
    {
        m_data = std::make_shared<T[]>(m_capacity);
    }

    // default constructor creates empty vector of size size;
    template<typename T>
    vector<T>::vector(size_type size) :
        m_size(size),
        m_capacity(DEFAULT_INITIAL_CAPACITY)
    {
        if(m_capacity < size){
           m_capacity = m_resize(size);
        }
        m_data = std::make_shared<T[]>(m_capacity);
    }

    //
    template<typename T>
    vector<T>::vector(resize_type resize):
        m_size(0),
        m_capacity(10)
    {
        m_resize = resize;
        m_capacity = m_resize(m_capacity);
        m_data = std::make_shared<T[]>(m_capacity);

    }

    template<typename T>
    vector<T>::vector(size_type size, resize_type resize) :
        m_size(size),
        m_capacity(10)
    {
        this->m_resize = resize;
        this->m_capacity = m_resize(this->m_capacity);
        this->m_data = make_shared<T[]>(this->m_capacity);
    }

    template<typename T>
    vector<T>::vector(std::initializer_list<T> list) :
        m_size(0),
        m_capacity(10)
    {
        m_data = std::make_shared<T[]>(m_capacity);

        for(auto i = list.begin(); i != list.end(); i++){
            add(*i);
        }
    }
    // UserResize
    template<typename T>
    vector<T>::vector(std::initializer_list<T> list, resize_type resize) :
        m_size(0),
        m_capacity(10)
    {
        m_resize = resize;
        m_data = std::make_shared<T[]>(this->m_capacity);
        for (auto i = list.begin(); i != list.end(); i++)
        {
            add(*i);
        }
        
    }

    template<typename T>
    typename vector<T>::reference vector<T>::operator[](size_type index){
        return this->m_data[index];
    }   
    // add value to the vector
    template<typename T>
    void vector<T>::add(T value)
    {
        if(size() == capacity()){
            pointer temp = this->m_data;
            this->m_capacity = this->m_resize(this->m_capacity);
            this->m_data = std::make_shared<T[]>(this->m_capacity);
            for (auto i = 0; i < this->m_size; i++){
                m_data[i] = temp[i];
            }
        }
        this->m_size++;
        m_data[this->m_size] = value;
    }

    //insert value at location shift everything right
    template<typename T>
    void vector<T>::insert(size_type index, T value)
    {
        pointer temp = m_data;
        if (index > m_capacity || index < 0){
            throw new std::exception("Invalid Index");
        }else{
            for (auto i = 0; i <= this->m_size; i++){
                if(i == index){
                    temp[i] = value;
                }else if (i > index){
                    temp[i] = m_data[i - 1];
                }else{
                    temp[i] = this->m_data[i];
                }
            }
            this->m_data = temp;
            this->m_size++;
        }
    }

    // remove value at location shift everything down.
    template<typename T>
    void vector<T>::remove(size_type index){
        pointer temp = m_data;
        if (index > m_capacity || index < 0){
            throw new std::exception("Invalid Index");
        }else{
            for (auto i = 0; i < this->m_size; i++){
                if (i >= index){
                    temp[i] = m_data[i + 1];
                }else{
                    temp[i] = this->m_data[i];
                }
            }
            this->m_data = temp;
            this->m_size++;
        }
    }

    template<typename T>
    typename vector<T>::iterator vector<T>::begin() {return iterator(this->m_data);}

    template<typename T>
    typename vector<T>::iterator vector<T>::end() {return iterator(this->m_size, this->m_data);}

    template<typename T>
    void vector<T>::clear(){
        this->m_size = 0;
    }
    template<typename T>
    size_t vector<T>::size(){
        return this->m_size;
    }
    template<typename T>
    typename vector<T>::size_type vector<T>::capacity()
    {
        return this->m_capacity;
    }

    template<typename T>
    vector<T>::iterator::iterator(size_type pos, pointer ptr) :
        m_pos(pos),
        m_data(ptr)
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
    T* vector<T>::iterator::operator->()
    {
        return &this->m_data[this->m_pos];
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
    template<typename T>
    bool vector<T>::iterator::operator==(const iterator& rhs)
    {
        return (m_data = rhs.m_data) && (m_pos = rhs.m_pos);
    }
    template<typename T>
    bool vector<T>::iterator::operator!=(const iterator& rhs)
    {
        return !(*this == rhs);
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