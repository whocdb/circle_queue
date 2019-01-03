
template <typename T>
CircleQueueIterator<T>::CircleQueueIterator(T* index, T* start, T* end) :
        _index(index),
        _start(start),
        _end(end) {}

template <typename T>
T& CircleQueueIterator<T>::operator*() const {
    return *_index;
}

template <typename T>
bool CircleQueueIterator<T>::operator!=(const CircleQueueIterator& iter) const {
    return this->_index != iter._index;
}

template <typename T>
const CircleQueueIterator<T>& CircleQueueIterator<T>::operator++() {
    ++_index;
    if (_index > _end) {
        _index = _start;
    }
    return *this;
}