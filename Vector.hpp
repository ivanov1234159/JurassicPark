//
// Created by toi on 30/03/2020.
//

#ifndef ___MYSPACE_VECTOR_HPP___
#define ___MYSPACE_VECTOR_HPP___

#include <ostream>
//for: ostream

template<typename T>
class Vector {
    T* m_list;
    unsigned m_size;
    unsigned m_limit;
    bool m_resizable;
public:
    Vector(unsigned limit = 2, bool resizable = true);
    Vector(T const* other, unsigned size, bool resizable = true);
    Vector(Vector<T> const& other);
    Vector& operator=(Vector<T> const& other);
    ~Vector();

    bool shift(T const& item);
    T unshift();
    bool push(T const& item);
    T pop();
    void remove(int index);

    bool empty() const;
    bool full() const;
    unsigned size() const;
    unsigned free() const;
    unsigned capacity() const;
    bool fixed() const;// fixed size = !resizable

    T& at(int index);
    T& operator[](int index);

    T const& at(int index) const;
    T const& operator[](int index) const;

protected:
    T*& list();
    T const*& list() const;

private:
    unsigned normalizeIndex(int index) const;
    void clear();
    void copy(Vector<T> const& other);
    bool resize();
    bool reserveMemory() const;// reserve the memory here instead in a constructor
};

template<typename T>
std::ostream& operator<<(std::ostream& out, Vector<T> const& obj);

template<typename T>
Vector<T>::Vector(unsigned limit, bool resizable)
    : m_list(nullptr), m_size(0), m_limit(limit), m_resizable(resizable) {
    //m_list = new T[m_limit]; // !!! for this reason I use reserveMemory() method
}

template<typename T>
Vector<T>::Vector(T const* other, unsigned size, bool resizable)
    : m_list(nullptr), m_size(size), m_limit(size), m_resizable(resizable) {
    //m_list = new T[m_limit];
    if(other != nullptr){
        m_list = new T[m_limit];
        for(unsigned i = 0; i < m_size; i++){
            m_list[i] = other[i];
        }
    }
}

template<typename T>
Vector<T>::Vector(Vector<T> const &other): m_list(nullptr) {
    copy(other);
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const &other) {
    if(this != &other){
        clear();
        copy(other);
    }
    return *this;
}

template<typename T>
Vector<T>::~Vector() {
    clear();
}

template<typename T>
bool Vector<T>::shift(const T &item) {
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
T Vector<T>::unshift() {
    if(empty()){
        return T();
    }
    T temp = at(0);
    remove(0);
    return temp;
}

template<typename T>
bool Vector<T>::push(T const &item) {
    if(full() && !resize()){
        return false;
    }
    m_list[m_size] = item;
    m_size++;
    return true;
}

template<typename T>
T Vector<T>::pop() {
    if(empty()){
        return T();
    }
    T temp = at(-1);
    remove(-1);
    return temp;
}

template<typename T>
void Vector<T>::remove(int index) {
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
bool Vector<T>::empty() const {
    static char temp = reserveMemory();
    return m_size == 0;
}

template<typename T>
bool Vector<T>::full() const {
    static char temp = reserveMemory();
    return m_size == m_limit;
}

template<typename T>
unsigned Vector<T>::free() const {
    return m_limit - m_size;
}

template<typename T>
unsigned Vector<T>::capacity() const {
    return m_limit;
}

template<typename T>
unsigned Vector<T>::size() const {
    return m_size;
}

template <typename T>
bool Vector<T>::fixed() const {
    return !m_resizable;
}

template<typename T>
T& Vector<T>::at(int index) {
    return m_list[normalizeIndex(index)];
}

template<typename T>
T& Vector<T>::operator[](int index) {
    return at(index);
}

template<typename T>
T const& Vector<T>::at(int index) const {
    return m_list[normalizeIndex(index)];
}

template<typename T>
T const& Vector<T>::operator[](int index) const {
    return at(index);
}

template<typename T>
T*& Vector<T>::list() {
    static char temp = reserveMemory();
    return m_list;
}

template<typename T>
T const*& Vector<T>::list() const {
    static T const* tempList = reserveMemory() ? m_list : nullptr;
    return tempList;// !!! reserveMemory() MUST return true; normally it does
}

template<typename T>
unsigned Vector<T>::normalizeIndex(int index) const {
    static char temp = reserveMemory();
    if(index < 0){
        return m_size - ((-index) % m_size);
    }
    return index % m_size;
}

template<typename T>
void Vector<T>::clear() {
    if(m_list != nullptr){
        delete[] m_list;
        m_list = nullptr;
    }
}

template<typename T>
void Vector<T>::copy(Vector<T> const& other){
    m_size = other.m_size;
    m_limit = other.m_limit;
    m_list = new T[m_limit];
    for(unsigned i = 0; i < m_size; i++){
        m_list[i] = other.m_list[i];
    }
}

template<typename T>
bool Vector<T>::resize(){
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
bool Vector<T>::reserveMemory() const {
    if(m_list == nullptr){
        Vector<T>* self = const_cast<Vector<T>*>(this);
        // !!! To use reserveMemory() in a "const" methods like:
        //      normalizeIndex(int), empty(), full(), list()
        self->m_list = new T[m_limit];
    }
    return true;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, Vector<T> const& obj){
    for(unsigned i = 0; i < obj.size(); i++){
        out << obj[i];
    }
    return out;
}

#endif //___MYSPACE_VECTOR_HPP___
