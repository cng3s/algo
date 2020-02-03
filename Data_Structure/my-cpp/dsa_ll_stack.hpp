#ifndef HZCC_DSA_LL_STACK_HPP
#define HZCC_DSA_LL_STACK_HPP

#include "dsa_ll.hpp"
#include <iostream>

namespace hzcc {
    template <typename T>
    class dsa_ll_stack : public dsa_ll<T> {
    protected:
            using dsa_ll<T>::rm_first;
            using dsa_ll<T>::get_first;
            using dsa_ll<T>::add_first;

    public:
            dsa_ll_stack()
                : dsa_ll<T>()
            {}

    public:
            void push(T &elem)
            {
                    add_first(elem);
            }

            T pop()
            {
                    return rm_first();
            }

            T top()
            {
                    return get_first();
            }
    };
}

#endif //MYCC_STACK_HPP
