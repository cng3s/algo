/*******************************************************************
 * release.h
 * 释放成员对象占用的空间
 * *****************************************************************/

#ifndef HZCC_RELEASE_H
#define HZCC_RELEASE_H

#include <typeinfo>


namespace hzcc {
    template <typename T>
    class cleaner {
    public:
            static void clean(T x)
            {
#ifdef _DEBUG
                    static int n = 0;
                    if (7 > strlen(typeid(T).name())) {
                            printf("\t<%s>[%d]=", typeid(T).name(), ++n);
                            print(x);
                            printf(" purged\n");
                    }
#endif
            }
    };

    template <typename T>
    class cleaner<T*> {
    public:
            static void clean(T *x) {
                    if (x)
                            delete x;
#ifdef _DEBUG
                    static int n = 0;
                    printf("\t<%s>[%d] released\n", typeid(T*).name(), ++n);
#endif
            }
    };

    template <typename T>
    void release(T x)
    {
            cleaner<T>::clean(x);
    }

}

#endif //HZCC_RELEASE_H
