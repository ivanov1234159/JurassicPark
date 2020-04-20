//
// Created by toi on 30/03/2020.
//

#ifndef ___MYSPACE_ARRAY_HPP___
#define ___MYSPACE_ARRAY_HPP___

#include <ostream>
//for: ostream

template<typename T>
class Array {
    T* m_list;
    unsigned m_size;
    unsigned m_limit;
    bool m_resizable;
public:
    Array(unsigned limit = 2, bool resizable = true);
    Array(Array<T> const& other);
    Array& operator=(Array<T> const& other);
    ~Array();

    bool shift(T const& item);
    T unshift();
    bool push(T const& item);
    T pop();
    void remove(int index);

    bool empty() const;
    bool full() const;
    unsigned size() const;
    unsigned free() const;
    bool fixed() const;// fixed size = !resizable

    T& at(int index);
    T& operator[](int index);

    T const& at(int index) const;
    T const& operator[](int index) const;

private:
    unsigned normalizeIndex(int index) const;
    void clear();
    void copy(Array<T> const& other);
    bool resize();
};

template<typename T>
std::ostream& operator<<(std::ostream& out, Array<T> const& obj);

template<typename T>
Array<T>::Array(unsigned limit, bool resizable): m_list(nullptr), m_size(0), m_limit(limit), m_resizable(resizable) {
    m_list = new T[m_limit];
}

template<typename T>
Array<T>::Array(Array<T> const &other): m_list(nullptr) {
    copy(other);
}

template<typename T>
Array<T>& Array<T>::operator=(Array<T> const &other) {
    if(this != &other){
        clear();
        copy(other);
    }
    return *this;
}

template<typename T>
Array<T>::~Array() {
    clear();
}

template<typename T>
bool Array<T>::shift(const T &item) {
    if(full() && !resize()){
        return false;
    }
    m_size++;
    T* first = &at(0);
    T* last = &at(-1);
    while (first < last){
        *last = *(last-1);
        last--;
    }
    *first = item;
    return true;
}

template<typename T>
T Array<T>::unshift() {
    if(empty()){
        return T();
    }
    T temp = at(0);
    remove(0);
    return temp;
}

template<typename T>
bool Array<T>::push(T const &item) {
    if(full() && !resize()){
        return false;
    }
    m_list[m_size] = item;
    m_size++;
    return true;
}

template<typename T>
T Array<T>::pop() {
    if(empty()){
        return T();
    }
    T temp = at(-1);
    remove(-1);
    return temp;
}

template<typename T>
void Array<T>::remove(int index) {
    if(empty()){
        return;
    }
    T* temp = &at(index);
    T* last = &at(-1);
    while (temp < last){
        *temp = *(temp+1);
        temp++;
    }
    *last = T();
    m_size--;
}

template<typename T>
bool Array<T>::empty() const {
    return m_size == 0;
}

template<typename T>
bool Array<T>::full() const {
    return m_size == m_limit;
}

template<typename T>
unsigned Array<T>::free() const {
    return m_limit - m_size;
}

template<typename T>
unsigned Array<T>::size() const {
    return m_size;
}

template <typename T>
bool Array<T>::fixed() const {
    return !m_resizable;
}

template<typename T>
T& Array<T>::at(int index) {
    return m_list[normalizeIndex(index)];
}

template<typename T>
T& Array<T>::operator[](int index) {
    return at(index);
}

template<typename T>
T const& Array<T>::at(int index) const {
    return m_list[normalizeIndex(index)];
}

template<typename T>
T const& Array<T>::operator[](int index) const {
    return at(index);
}

template<typename T>
unsigned Array<T>::normalizeIndex(int index) const {
    if(index < 0){
        return m_size - ((-index) % m_size);
    }
    return index % m_size;
}

template<typename T>
void Array<T>::clear() {
    if(m_list != nullptr){
        delete[] m_list;
        m_list = nullptr;
    }
}

template<typename T>
void Array<T>::copy(Array<T> const& other){
    m_size = other.m_size;
    m_limit = other.m_limit;
    m_list = new T[m_limit];
    for(unsigned i = 0; i < m_size; i++){
        m_list[i] = other.m_list[i];
    }
}

template<typename T>
bool Array<T>::resize(){
    if(fixed()){
        return false;
    }
    m_limit *= 2;
    T* temp = m_list;
    m_list = new T[m_limit];
    for(unsigned i = 0; i < m_size; i++){
        m_list[i] = temp[i];
    }
    delete[] temp;
    return true;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, Array<T> const& obj){
    for(unsigned i = 0; i < obj.size(); i++){
        out << obj[i];
    }
    return out;
}

#endif //___MYSPACE_ARRAY_HPP___
