#ifndef HZCC_DSA_HASH_TABLE_HPP
#define HZCC_DSA_HASH_TABLE_HPP

#include "dsa_pair.hpp"
#include "dsa_bitmap.hpp"
#include "_share/release.h"
#include <cstdlib>

namespace hzcc {

    template <typename K, typename V>
    class dsa_hash_tbl {
    private:
            _entry<K, V> **_tbl;
            unsigned int _capacity, _size;
            bitmap *_lazy_tbl;          // 懒惰删除标记
#define _is_lazily_rm(x)        (_lazy_tbl->test(x))
#define _mark_as_rm(x)          (_lazy_tbl->set(x))

    public:
            explicit dsa_hash_tbl(unsigned int c = 64)
            {
                    _capacity = prime_NLT(c, 1048576, "../_input/prime-1048576-bitmap.txt");
                    _size = 0;
                    _tbl = new _entry<K, V>*[_capacity];
                    std::memset(_tbl, 0, sizeof(_entry<K, V>*)*_capacity);
                    _lazy_tbl = new bitmap(_capacity);
            }

            ~dsa_hash_tbl()
            {
                    for (int i = 0; i < _capacity; i++) {
                            if (_tbl)
                                    release(_tbl[i]);
                    }
                    release(_tbl);
                    release(_lazy_tbl);
            }

    public:
            inline unsigned int size() const
            {
                    return _size;
            }

            bool put(K k, V v)
            {
                    if (_tbl[probe_hit(k)])
                            return false;
                    int r = probe_free(k);
                    _tbl[r] = new _entry<K, V>(k, v);
                    ++_size;
                    if ((_size << 1) > _capacity)
                            rehash();
                    return true;
            }

            V* get(K k)
            {
                    int r = probe_hit(k);
                    return _tbl[r] ? &(_tbl[r]->_v) : nullptr;
            }

            bool rm(K k)
            {
                    int r = probe_hit(k);
                    if (!_tbl[r])
                            return false;
                    release(_tbl[r]);
                    _tbl[r] = nullptr;
                    _mark_as_rm(r);
                    _size--;
                    return true;
            }

    protected:
            /* 查找到与key匹配的，否则-1 */
            unsigned int probe_hit(const K &k)
            {
                    unsigned int r = (unsigned int)hash(k) % _capacity;
                    while ((_tbl[r] && (k != _tbl[r]->_k)) ||
                            (!_tbl[r] && _is_lazily_rm(r)))
                            r = (r + 1) % _capacity;
                    return r;
            }

            /* 查找首个可用的 */
            unsigned int probe_free(const K &k)
            {
                unsigned int r = (unsigned int)hash(k) % _capacity;
                while ((_tbl[r] && (k != _tbl[r]->_k)) ||
                        (!_tbl[r] && _is_lazily_rm(r)))
                        r = (r + 1) % _capacity;
                return r;
            }

            void rehash()
            {
                unsigned int old_capacity = _capacity;
                _entry<K, V> **old_tbl = _tbl;
                _capacity = prime_NLT(_capacity << 1, 1048576, "../_input/prime-1048576-bitmap.txt");
                _size = 0;
                _tbl = new _entry<K, V>*[_capacity];
                memset(_tbl, 0, sizeof(_entry<K, V>*) * _capacity);
                release(_lazy_tbl);
                _lazy_tbl = new bitmap(_capacity);
                for (int i = 0; i < old_capacity; i++) {
                        if (old_tbl[i])
                                put(old_tbl[i]->_k, old_tbl[i]->_v);
                }
                release(old_tbl);
            }

            unsigned int prime_NLT(unsigned int c, unsigned int n, char *file)
            {
                    bitmap bm(file, n);
                    while (c < n) {
                            if (bm.test(c))
                                    c++;
                            else
                                    return c;
                    }
                    return c;
            }

    };

    static size_t hash(char c)
    {
            return (size_t)c;
    }

    static size_t hash(int i)
    {
            return (size_t)i;
    }

    static size_t hash(long long l)
    {
            return (size_t)((l >> 32) + (int)l);
    }

    static size_t hash(char s[])
    {
            int h = 0;
            for (size_t n = strlen(s), i = 0; i < n; i++) {
                    h = (h << 5) | (h >> 27);
                    h += (int)s[i];
            }
            return (size_t)h;
    }

}

#endif //MYCC_HASHTABLE_HPP