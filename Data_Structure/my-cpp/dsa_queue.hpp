#ifndef HZCC_DSA_QUEUE_HPP
#define HZCC_DSA_QUEUE_HPP

#include "dsa_list.hpp"

namespace hzcc {

template <typename T>
class dsa_queue : public dsa_list<T> {
protected:
        using dsa_list<T>::first;
        using dsa_list<T>::rm;
        using dsa_list<T>::insert_last;

public:
        explicit dsa_queue()
                : dsa_list<T>()
        {}

public:
        void enqueue(const T &e)
        {
                insert_last(e);
        }

        T dequeue()
        {
                return rm(first());
        }

        T& front()
        {
                return first()->data;
        }
};

}


#endif //HZCC_DSA_QUEUE_HPP
