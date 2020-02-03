#ifndef HZCC_DSA_BITMAP_HPP
#define HZCC_DSA_BITMAP_HPP

#include <memory.h>
#include <cstdio>
#include <cstring>
#include <iostream>

namespace hzcc {

    class bitmap {
#define DSA_BITMAP_DEFAULT_CAPACITY 1024
    protected:
            char    *M;     // 比特图存放空间M
            int     N;      // capacity = N * sizeof(char)*8bit

    protected:
            void init(int n)
            {
                M = new char[N = (n + 7) >> 3];
                memset(M, 0, size_t(N));
            }

    public:
            explicit bitmap(int n = DSA_BITMAP_DEFAULT_CAPACITY)
            {
                    init(n);
            }

            explicit bitmap(char *file, int n = DSA_BITMAP_DEFAULT_CAPACITY)
            {
                    init(n);
                    FILE *fp = fopen(file, "r");
                    fread(M, sizeof(char), size_t(N), fp);
                    fclose(fp);
            }

            ~bitmap()
            {
                    delete[] M;
                    M = nullptr;
            }

    public:
            /* insert
             * 1) 这里SHIFT = 3.0x07有3个bit位,即2^3=8
             * 2) k & 0x07: 0x07 = 7(0000 0111), k & 0x07既是保留最后3位bit位，相当于k % 8
             * 3) 0x80 >> (k & 0x07): 0x80 = 128(1000 0000), a[k / 8].bits[i % 8] = 1
             * 4) 这个实现则是从开始到结束对应的是从左向右的
             * 5) expand(k) 函数作用是当空间不够用时扩容使用的
             * */
            void set(int k)
            {
                    expand(k);
                    M[k >> 3] |= (0x80 >> (k & 0x07));
            }

            /* delete */
            void clear(int k)
            {
                    expand(k);
                    M[k >> 3] &= ~(0x80 >> (k & 0x07));
            }

            /* test */
            bool test(int k)
            {
                    expand(k);
                    return bool(M[k >> 3] & (0x80 >> (k & 0x07)));
            }

            /* dump bitmap to file */
            void dump(char *file)
            {
                    FILE *fp = fopen(file, "w");
                    fwrite(M, sizeof(char), size_t(N), fp);
                    fclose(fp);
            }

            char* bits2str(int n)
            {
                    expand(n - 1);
                    char *s = new char[n + 1];
                    s[n] = '\0';
                    for (int i = 0; i < n; i++)
                            s[i] = test(i) ? '1' : '0';
                    return s;
            }

            void print(int n)
            {
                    expand(n);
                    for (int i = 0; i < n; i++) {
                            if (test(i))
                                    std::cout << "1";
                            else
                                    std::cout << "0";
                    }
            }

    protected:
            void expand(int k)
            {
                if (k < (N << 3))
                        return;
                int oldN = N;
                char *oldM = M;
                init(k << 1);
                std::memcpy(M, oldM, size_t(N));
                delete[] oldM;
            }
    };

}

#endif //HZCC_DSA_BITMAP_HPP
