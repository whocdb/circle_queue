_Pragma("once")
template <typename T>
class CircleQueueIterator {
public:
    CircleQueueIterator(T* index, T* start, T* end);

    T& operator*() const;

    bool operator!=(const CircleQueueIterator& iter) const;

    const CircleQueueIterator& operator++();

private:
    T* _index;
    T* _start;
    T* _end;
};

#include "circle_queue_iterator.inl"