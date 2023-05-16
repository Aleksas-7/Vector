#ifndef MANOVECTOR_H
#define MANOVECTOR_H

#include <iostream>

template <class T> class Vector {
private:

    // Size
    int s;
    // Capacity
    int cap;
    // Elements
    T *el;

public:

    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;

    Vector(int prad_dydis = 1)
    {
        s = 0;
        cap = prad_dydis;
        el = new T[cap];
    }

    ~Vector()
    {
        delete[] el;
        s = 0;
        cap = 1;
    }
    

    inline int capacity () const { return cap;}
    inline int size() const { return s;}


    T& at (int i)
    {
        if (i < 0 || i > cap){
            throw std::out_of_range("Vector out of range");
        }
        return el[i];
    }

    T& front ()
    {
        return el[0];
    }

    T& back ()
    {
        return el[s-1];
    }

    T* begin() {return el;}

    T* end() {return &el[s];}

    T* begin() const {return el;}

    T* end() const {return &el[s];}

    void pop_back() {
        if (s != 0){
            s--;
        }
    }

    void push_back (const T& element) 
    {
        if (s == cap){
            resize(cap * 2);
        }

        if (s < cap){
            el[s] = element;
            s++;
        }
    }

    void resize (size_type new_cap)
    {
        if (new_cap > max_size()) {throw std::out_of_range("Out of range");}
        
        if (new_cap == cap){
            return;
        }

        if (new_cap < s){
            T *temp = new T[new_cap];
            std::copy(el, el+new_cap, temp);
            delete[] el;
            //for (size_t i = 0 ; i < new_cap ; ++i){temp[i] = el[i];}
            el = temp;
            cap = new_cap;
            s = cap;
        }
        else if (new_cap > cap){
            T* temp = new T[s];
            for (size_t i = 0 ; i < s ; ++i){temp[i] = el[i];}
            delete[] el;
            el = new T[new_cap];
            for (size_t i = 0 ; i < s ; ++i){el[i] = temp[i];}
            cap = new_cap;
        }
        
    }

    int max_size ()
    {//        100_000_001
        return 100000001;
    }

    void reserve(size_t new_cap)
    {
        if (new_cap > max_size()) {throw std::length_error("length_error");}

        if (new_cap <= cap){
            return;
        }
        //std::cout << "HHHHHH base: "<< s << " " << cap << " " << new_cap << std::endl;

        T* temp = new T[s];
        for (size_t i = 0 ; i < s ; ++i){temp[i] = el[i];}
        delete[] el;
        el = new T[new_cap];
        for (size_t i = 0 ; i < s ; ++i){el[i] = temp[i];}
        cap = new_cap;        
    }

    bool empty () {
        return s == 0;
    }

    void clear () {
        s = 0;
    }

    T& operator[](size_t index){return el[index];}
    const T& operator[](size_t index)const {return el[index];}

    // rule of 5 ====================================================================

    // Copy constructor
    Vector(const Vector& k) {
        s = k.s;

        cap = k.cap;

        delete[] el;
        el = new T[cap];
        for (size_t i = 0 ; i < s ; ++i){el[i] = k.el[i];}
    }

    // Copy assignment operator
    Vector& operator=(const Vector& k){
        if (this != &k){

            delete[] el;

            s = k.s;

            cap = k.cap;

            
            el = new T[cap];

            for (size_t i = 0 ; i < s ; ++i){el[i] = k.el[i];}
        }
        return *this;
    }

    // Move constructor
    Vector(Vector&& k) {
        s = k.s;
        k.s = 0;

        cap = k.cap;
        k.cap = 0;

        delete[] el;
        el = k.el;
        k.el = nullptr;
    }

    // Move assignment operator
    Vector& operator=(Vector&& k) {
        if (this != &k){
            s = k.s;
            k.s = 0;

            cap = k.cap;
            k.cap = 0;

            delete[] el;
            el = k.el;
            k.el = nullptr;
        }
        return *this;
    }
};

#endif