_Pragma("once")
#include <stdint.h>
#include "circle_queue_iterator.hpp"

template<typename T>
class CircleQueue {
private:
    uint32_t _capcity = 100;
    uint32_t _front = 0;
    uint32_t _rear = 0;
    T* _buffer = nullptr;

    inline void update_index();

public:
    typedef CircleQueueIterator<T> Iterator;

    CircleQueue();

    CircleQueue(uint32_t capcity);

    void resize(uint32_t capcity);

    inline bool pop_front(T &value);

    T& back();

    inline bool pop_front();

    inline void push_back(const T &value);

    inline void clear();

    inline bool empty();

    Iterator begin();

    Iterator end();

    virtual ~CircleQueue();
};

#include "circle_queue.inl"
