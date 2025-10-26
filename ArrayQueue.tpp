#include "ArrayQueue.hpp"
template <typename T>
ArrayQueue<T>::ArrayQueue(int i) {
    // TODO
    buffer = new T[i];
    frontIndex = 0;
    backIndex = 0;
    maxSize = i;
    this->length = 0;
}

template <typename T>
ArrayQueue<T>::ArrayQueue(const ArrayQueue<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
ArrayQueue<T>& ArrayQueue<T>::operator=(const ArrayQueue<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
ArrayQueue<T>::~ArrayQueue() {
    clear();
}

template <typename T>
T ArrayQueue<T>::back() const {
    // TODO

    if (this->length == 0){
         throw string("back: error, queue is empty, cannot access the back");
    }
    return buffer[backIndex];


}

template <typename T>
void ArrayQueue<T>::clear() {
    // TODO
    this->length = 0;
    frontIndex = 0;
    backIndex = 0;
}

template <typename T>
void ArrayQueue<T>::copy(const ArrayQueue<T>& copyObj) {
    // TODO

   if (copyObj.length == 0) throw string("Error: Queue is empty");

    maxSize = copyObj.maxSize;
    this->length = copyObj.length;
    this->buffer = new T[maxSize];
    for (int i = 0; i < this->length; i++)
    {
        this->buffer[i] = copyObj.buffer[i];
    }
    frontIndex = copyObj.frontIndex;

    backIndex = copyObj.backIndex;



}

template <typename T>
void ArrayQueue<T>::dequeue() {
    // TODO
    if (this->length == 0) {
        throw string("dequeue: error, queue is empty");
    }
    frontIndex = (frontIndex + 1);
    this->length--;
    if (this->length == 0) {
        frontIndex = 0;
        backIndex = 0;
    }

}

template <typename T>
void ArrayQueue<T>::enqueue(const T& elem) {
    // TODO
    if (this->isFull()) {
        throw string("enqueue: error, queue is full");
    }

    if (this->isEmpty()) {
        frontIndex = 0;
        backIndex = 0;
        buffer[backIndex] = elem;
    } else {
        backIndex = (backIndex + 1) % maxSize;
        buffer[backIndex] = elem;
    }

    this->length++;

}

template <typename T>
T ArrayQueue<T>::front() const {
    // TODO
    if (this->length == 0){
         throw string("front: error, queue is empty, cannot access the front");
    }
    return buffer[frontIndex];
}

template <typename T>
int ArrayQueue<T>::getLength() const {
    return this->length;
}

template <typename T>
int ArrayQueue<T>::getMaxSize() const {
    return maxSize;
}

template <typename T>
bool ArrayQueue<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
bool ArrayQueue<T>::isFull() const {
    return this->length == maxSize;
}
