#ifndef HZCC_DSA_DICT_HPP
#define HZCC_DSA_DICT_HPP

namespace hzcc {
    template <typename K, typename V>
    struct dsa_dict {
            virtual int     size() const = 0;
            virtual bool    put(K k, V v) = 0;
            virtual V*      get(K k) = 0;
            virtual bool    rm(K k) = 0;
    };
}

#endif //MYCC_DSA_DICT_HPP