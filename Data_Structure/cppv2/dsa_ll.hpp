#ifndef HZCC_DSA_LINKED_LIST_HPP
#define HZCC_DSA_LINKED_LIST_HPP

#include <iostream>

namespace hzcc {

    template<typename Type>
    class dsa_ll {
    protected:
            class _node {
            public:
                    Type    _data;
                    _node    *next;

            public:
                    explicit _node()
                            : next(nullptr)
                    {}

                    explicit _node(Type arg_data, _node *arg_next = nullptr)
                            : _data(arg_data), next(arg_next)
                    {}
            };

    private:
            _node   *_head;
            int     _size;

    public:
            explicit dsa_ll()
                    : _size(0)
            {
                    _head = new _node();
            }

            ~dsa_ll()
            {
                    _node *cur = _head, *next;
                    while (cur != nullptr) {
                            next = cur->next;
                            delete cur;
                            if (next == nullptr)
                                    break;
                            cur = next;
                    }
            }

    public:
            int size() const
            {
                    return _size;
            }

            bool empty() const
            {
                    return _size == 0;
            }

            /* 使用前插法添加结点 */
            void add(Type elem)
            {
                    auto cur = new _node(elem, _head->next);
                    _head->next = cur;
                    _size++;
            }

            Type rm()
            {
                    if (_head->next == nullptr) {
                            delete _head;
                            _size--;
                            return nullptr;
                    }
                    _node *rm_node = _head->next;
                    Type ret = rm_node->_data;
                    _head->next = rm_node->next;
                    delete rm_node;
                    _size--;
                    return ret;
            }

            Type get()
            {
                    return _head->next->_data;
            }

            void print_info()
            {
                    if (_head == nullptr || _head->next == nullptr)
                            return;
                    std::cout << "dsa_ll Info:[ ";
                    for (_node *cur = _head->next; cur->next != nullptr; cur = cur->next) {
                            std::cout << cur->_data;
                            if (cur->next != nullptr)
                                    std::cout << "->";
                    }
                    std::cout << "]" << std::endl;
            }

    };

}

#endif //MYCC_LIST_HPP
