#ifndef HZCC_DSA_MAP_ENTRY_HPP
#define HZCC_DSA_MAP_ENTRY_HPP

#include <functional>

namespace {

    template<typename K, typename V, typename Compare = std::less<K>>
    class _entry {
    public:
            K _k;
            V _v;

    public:
            explicit _entry(K k = K(), V v = V())
                    : _k(k), _v(v)
            {}

            explicit _entry(const _entry<K, V> &e)
                    : _k(e._k), _v(e._v)
            {}

    public:
            bool operator<(const _entry<K, V> &e)
            {
                    return _k < e._k;
            }

            bool operator>(const _entry<K, V> &e)
            {
                    return _k > e._k;
            }

            bool operator==(const _entry<K, V> &e)
            {
                    return _k == e._k;
            }

            bool operator!=(const _entry<K, V> &e)
            {
                    return _k != e._k;
            }
    };
}

#endif //HZCC_DSA_MAP_ENTRY_HPP
