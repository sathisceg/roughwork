#include <iostream>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <cstring>
#include <stdexcept>
#include <utility> // for std::swap

using namespace std;

template <typename T> class MyVector {
public:
  T *data;
  size_t size;
  size_t capacity;

  MyVector() : data(nullptr), size(0), capacity(0) {}

  ~MyVector() { delete[] data; }

  void resize(size_t new_size) {

    T *new_data = new T[new_size];

    for (int i = 0; i < size; ++i) {
      new_data[i] = data[i];
    }

    delete[] data;
    data = new_data;
    capacity = new_size;
  }

  void push_back(T &val) {

    if (size == capacity) {

      if (capacity == 0) {
        capacity = 1;
        resize(capacity);
      } else {
        resize(capacity * 2);
      }
    }

    data[size] = val;
    size++;
  }

  void pop_back() {

    if (size >= 0) {
      size--;
    }
  }

  T &operator[](size_t index) {

    if (index >= size) {
      throw out_of_range("index out of range");
    }

    return data[index];
  }
};

int main() {

  MyVector<int> vec;

  cout << "adding " << endl;
  for (int i = 0; i < 5; ++i) {
    vec.push_back(i);
  }

  cout << "printing " << endl;
  for (int i = 0; i < 5; ++i) {
    cout << vec[i] << " ";
  }

  // cout<<vec[6];

  cout << endl;

  return 0;
}

/*
template<typename T>
MyVector<T>::MyVector(){
        data=nullptr;
        size=0;
        capacity=0;
}

template<typename T>
MyVector<T>::MyVector():data(nullptr),size(0),capacity(1){}

template<typename T>
void MyVector<T>::resize(size_t new_size){

        T* new_data=new T[new_size];

        for (int i = 0; i < size; ++i)
        {
                new_data[i]=data[i];
        }

        delete[] data;
        data=new_data;
        capacity=new_size;

}

template<typename T>
void MyVector<T>::push_back(T val){

        if(size==capacity){
                resize(capacity*2);
        }

        data[size]=val;
        // cout<<data[size];
        size++;
}

template<typename T>
void MyVector<T>::pop_back(){

        if(size>=0){
                size--;
        }
}

template<typename T>
T& MyVector<T>::operator[](size_t index){
        return data[index];
}

template<typename T>
MyVector<T>::~MyVector(){
        delete[] data;
}

*/

/*

#include <iostream>
#include <stdexcept>

template <typename T>
class MyVector {
private:
    T* data;
    size_t _size;
    size_t _capacity;

    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < _size; ++i)
            new_data[i] = data[i];

        delete[] data;
        data = new_data;
        _capacity = new_capacity;
    }

public:
    MyVector() : data(nullptr), _size(0), _capacity(0) {}

    ~MyVector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (_size == _capacity) {
            size_t new_capacity = (_capacity == 0) ? 1 : _capacity * 2;
            resize(new_capacity);
        }
        data[_size++] = value;
    }

    void pop_back() {
        if (_size > 0)
            --_size;
    }

    size_t size() const { return _size; }

    size_t capacity() const { return _capacity; }

    bool empty() const { return _size == 0; }

    T& operator[](size_t index) {
        if (index >= _size)
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= _size)
            throw std::out_of_range("Index out of range");
        return data[index];
    }
};

// ------------------- Demo -------------------
int main() {
    MyVector<int> vec;

    std::cout << "Pushing values: ";
    for (int i = 1; i <= 5; ++i) {
        vec.push_back(i);
        std::cout << i << " ";
    }

    std::cout << "\nSize: " << vec.size();
    std::cout << "\nCapacity: " << vec.capacity();

    std::cout << "\nElements: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";

    vec.pop_back();
    std::cout << "\nAfter pop_back(), size: " << vec.size();
    std::cout << "\nAfter pop_back(), capacity: " << vec.capacity();
    std::cout << std::endl;
    return 0;
}


*/