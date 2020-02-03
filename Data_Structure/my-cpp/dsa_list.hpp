#ifndef HZCC_DSA_LIST_HPP
#define HZCC_DSA_LIST_HPP

namespace hzcc {

template<typename T>
class dsa_list_node {
public:
        T data;
        dsa_list_node<T> *prev;
        dsa_list_node<T> *next;

public:
        dsa_list_node() = default;

        explicit dsa_list_node(T e, dsa_list_node<T> *p = nullptr, dsa_list_node<T> *n = nullptr)
                : data(e), prev(p), next(n)
        {}

        dsa_list_node<T> *insert_prev(const T &e)
        {
                auto x = new dsa_list_node(e, prev, this);
                prev->next = x;
                prev = x;
                return x;
        }

        dsa_list_node<T> *insert_next(const T &e)
        {
                auto x = new dsa_list_node(e, this, next);
                next->prev = x;
                next = x;
                return x;
        }

};

template<typename T>
class dsa_list {
private:
        int _size;
        dsa_list_node<T> *head;
        dsa_list_node<T> *tail;

protected:
        void init()
        {
                head = new dsa_list_node<T>;
                tail = new dsa_list_node<T>;
                head->next = tail;
                head->prev = nullptr;
                tail->prev = head;
                tail->next = nullptr;
                _size = 0;
        }

        int clear()
        {
                int old_sz = _size;
                while (0 < _size)
                        rm(head->next);
                return old_sz;
        }

        void cp_nodes(dsa_list_node<T> *start, int len)
        {
                init();
                while (len--) {
                        insert_last(start->data);
                        start = start->next;
                }
        }

public:
        explicit dsa_list()
        {
                init();
        }

        explicit dsa_list(const dsa_list<T> &ls)
        {
                cp_nodes(ls.first(), ls._size);
        }

        explicit dsa_list(const dsa_list<T> &ls, int start_pos, int len)
        {
                cp_nodes(ls[start_pos], len);
        }

        explicit dsa_list(dsa_list_node<T> *start, int len)
        {
                cp_nodes(start, len);
        }


        ~dsa_list()
        {
                clear();
                delete head;
                delete tail;
        }

public:
        int size() const
        {
                return _size;
        }

        bool empty() const
        {
                return _size <= 0;
        }

        T &operator[](int r) const
        {
                dsa_list_node<T> *p = first();
                while (0 < r--)
                        p = p->next;
                return p->data;
        }

        dsa_list_node<T>* first() const
        {
                return head->next;
        }

        dsa_list_node<T>* last() const
        {
                return tail->prev;
        }

        bool valid(dsa_list_node<T> *p)
        {
                return p && (tail != p) && (head != p); // head and tail is nullptr
        }

        dsa_list_node<T> *search(const T &e, dsa_list_node<T> *start, int len) const
        {
                while (0 <= len--) {
                        if ((start = start->prev)->data <= e)
                                break;
                }
                return start;
        }

        dsa_list_node<T> *select_max(dsa_list_node<T> *start, int len)
        {
                dsa_list_node<T> *max = start;
                for (dsa_list_node<T> *cur = start; 1 < len; len--) {
                        if ((cur = cur->next)->data >= max->data)
                                max = cur;
                }
                return max;
        }

        dsa_list_node<T> *select_max()
        {
                return select_max(head->next, _size);
        }

        dsa_list_node<T> *insert_first(const T &e)
        {
                _size++;
                return head->insert_next(e);
        }

        dsa_list_node<T> *insert_last(const T &e)
        {
                _size++;
                return tail->insert_prev(e);
        }

        dsa_list_node<T> *insert_after(const T &e, dsa_list_node<T> *node)
        {
                _size++;
                return node->insert_next(e);
        }

        dsa_list_node<T> *insert_before(const T &e, dsa_list_node<T> *node)
        {
                _size++;
                return node->insert_prev(e);
        }

        T rm(dsa_list_node<T> *del_node)
        {
                T ret = del_node->data;
                del_node->prev->next = del_node->next;
                del_node->next->prev = del_node->prev;
                delete del_node;
                --_size;
                return ret;
        }

        void merge(dsa_list<T> &ls)
        {
                merge(first(), _size, ls, ls.first(), ls._size);
        }

        int deduplicate()
        {
                if (_size < 2)
                        return 0;
                int old_sz = _size;
                dsa_list_node<T> *p = head;
                int r = 0;
                while (tail != (p = p->next)) {
                        dsa_list_node<T> *q = find(p->data, r, p);
                        q ? rm(q) : r++;
                }
                return old_sz - _size;
        }

        int uniquify()
        {
                if (_size < 2)
                        return 0;
                int old_sz = _size;
                dsa_list_node<T> *p = first();
                dsa_list_node<T> *q;
                while (tail != (q = p->next)) {
                        if (p->data != q->data)
                                p = q;
                        else
                                rm(q);
                }
                return old_sz - _size;
        }

        void traverse(void (*visit)(T &arg))
        {
                for (dsa_list_node<T> *p = head->next; p != tail; p = p->next)
                        visit(p->data);
        }

        template<typename VST>
        void traverse(VST &visit)
        {
                for (dsa_list_node<T> *p = head->next; p != tail; p = p->next)
                        visit(p->data);
        }
};

}
#endif //HZCC_DSA_LIST_HPP
