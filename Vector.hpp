//
// Created by toi on 30/03/2020.
//

#ifndef ___MYSPACE_VECTOR_HPP___
#define ___MYSPACE_VECTOR_HPP___

#include <ostream>
//for: ostream

/**
 * @class Vector
 * @tparam T
 */
template<typename T>
class Vector {
    T* m_list;
    unsigned m_size;
    unsigned m_limit;
    bool m_resizable;
public:
    ///default constructor and constructor with arguments limit (and resizable)
    Vector(unsigned limit = 2, bool resizable = true);

    /// constructor with arguments other, size (and resizable)
    Vector(T const* other, unsigned size, bool resizable = true);

    /// copy constructor
    Vector(Vector<T> const& other);

    /// operator =
    Vector& operator=(Vector<T> const& other);

    ///destructor; calls clear() method
    ~Vector();

    /**
     * add in the beginning the new item
     * @param item
     * @return false if full and cannot resize
     */
    bool shift(T const& item);

    /**
     * remove the first element and return it
     * @return the first element or the "empty" element if list is empty
     */
    T unshift();

    /**
     * add at the end the new item
     * @param item
     * @return false if full and cannot resize
     */
    bool push(T const& item);

    /**
     * remove the last element and return it
     * @return the last element or the "empty" element if list is empty
     */
    T pop();

    /**
     * remove the element at position index
     * @param index - processed by normalizeIndex() method
     */
    void remove(int index);

    /// @return true if m_size is 0
    bool empty() const;

    /// @return true if m_size is equal to m_limit
    bool full() const;

    /// @return m_size
    unsigned size() const;

    /// @return m_limit - m_size
    unsigned free() const;

    /// @return m_limit
    unsigned capacity() const;

    /// @return !m_resizable
    bool fixed() const;// fixed size = !resizable

    /**
     * get the element at position index
     * critical if list is empty
     * @param index - processed by normalizeIndex() method
     * @return the element at position index
     */
    T& at(int index);

    /**
     * get the element at position index
     * critical if list is empty
     * @param index - processed by normalizeIndex() method
     * @return the element at position index
     */
    T& operator[](int index);

    /**
     * get the element at position index
     * critical if list is empty
     * @param index - processed by normalizeIndex() method
     * @return the element at position index
     */
    T const& at(int index) const;

    /**
     * get the element at position index
     * critical if list is empty
     * @param index - processed by normalizeIndex() method
     * @return the element at position index
     */
    T const& operator[](int index) const;

protected:
    /// @return m_list
    T*& list();

    /// @return m_list
    T const* list() const;

private:
    /**
     * set the index in bounders between 0 and m_size-1
     * @param index - if is negative, then counts from the end; and if is positive, then counts from the begining
     * @return the remainder when divided by m_size
     */
    unsigned normalizeIndex(int index) const;

    /// free the memory and set m_list to nullptr
    void clear();

    /**
     * copy other into this
     * @param other
     */
    void copy(Vector<T> const& other);

    /**
     * try to resize the list
     * @return false on fail (if is fixed size)
     */
    bool resize();
};

template<typename T>
std::ostream& operator<<(std::ostream& out, Vector<T> const& obj);

template<typename T>
Vector<T>::Vector(unsigned limit, bool resizable)
    : m_list(nullptr), m_size(0), m_limit(limit), m_resizable(resizable) {
    m_list = new T[m_limit];
}

template<typename T>
Vector<T>::Vector(T const* other, unsigned size, bool resizable)
    : m_list(nullptr), m_size(size), m_limit(size), m_resizable(resizable) {
    m_list = new T[m_limit];
    if(other != nullptr){
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
    return m_size == 0;
}

template<typename T>
bool Vector<T>::full() const {
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
    return m_list;
}

template<typename T>
T const* Vector<T>::list() const {
    return m_list;
}

template<typename T>
unsigned Vector<T>::normalizeIndex(int index) const {
    if(m_size == 1){
        return 0;
    }
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
    m_resizable = other.m_resizable;
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
std::ostream& operator<<(std::ostream& out, Vector<T> const& obj){
    for(unsigned i = 0; i < obj.size(); i++){
        out << obj[i];
    }
    return out;
}

#endif //___MYSPACE_VECTOR_HPP___
