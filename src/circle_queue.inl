#include <stdint.h>
template <typename T>
void CircleQueue<T>::update_index() {
    _rear = (_rear + 1 ) % _capcity;
    if (_rear <= _front) {
        _front = (_front + 1 ) % _capcity;
    }
}

template <typename T>
CircleQueue<T>::CircleQueue() {
    _buffer = new T[_capcity + 1];
}

template <typename T>
CircleQueue<T>::CircleQueue(uint32_t capcity) : _capcity(capcity + 1) {
    _buffer = new T[_capcity];
}

template <typename T>
void CircleQueue<T>::resize(uint32_t capcity) {
    if (_buffer) {
        delete []_buffer;
    }
    _capcity = capcity + 1;
    _buffer = new T[_capcity];
}

template <typename T>
T& CircleQueue<T>::back() {
    return _rear == 0 ? _buffer[_capcity - 1]: _buffer[_rear - 1];
}

template <typename T>
void CircleQueue<T>::push_back(const T &value) {
        _buffer[_rear] = value;
        update_index();
    }

template <typename T>
bool CircleQueue<T>::pop_front(T &value) {
    value = _buffer[_front];
    return pop_front();
}

template <typename T>
bool CircleQueue<T>::pop_front() {
    if (empty()) {
        return false;
    }
    _front = (_front + 1 ) % _capcity;
    return true;
}

template <typename T>
void CircleQueue<T>::clear() {
    _front = 0;
    _rear = 0;
}

template <typename T>
bool CircleQueue<T>::empty() {
    return _front == _rear;
}

template <typename T>
CircleQueueIterator<T> CircleQueue<T>::begin() {
    return CircleQueueIterator<T>(&_buffer[_front], &_buffer[0], &_buffer[_capcity - 1]);
}

template <typename T>
CircleQueueIterator<T> CircleQueue<T>::end() {
    return CircleQueueIterator<T>(&_buffer[_rear], &_buffer[0], &_buffer[_capcity - 1]);
}

template <typename T>
CircleQueue<T>::~CircleQueue() {
    if (_buffer) {
        delete []_buffer;
        _buffer = nullptr;
    }
}