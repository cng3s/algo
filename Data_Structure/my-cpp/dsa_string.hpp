#ifndef HZCC_DSA_STRING_HPP
#define HZCC_DSA_STRING_HPP

#include <cstddef>
#include <cassert>
#include <iostream>
#include <stack>

namespace hzcc {
    class t_string {
    protected:
            char            *data;
            size_t          size;

    public:
            explicit t_string(const char *str = nullptr)
            {
                    if (!str) {
                            size = 0;
                            data = new char[1];
                            *data = '\0';
                    }
                    else {
                            size = strlen(str);
                            data = new char[size+1];
                            strcpy(data, str);
                    }
            }

            /* 深拷贝 */
            t_string(const t_string &str)
            {
                    size = str.getSize();
                    data = new char[size+1];
                    strcpy(data, str.c_str());
            }

            ~t_string()
            {
                    delete[] data;
            }

    public:
            inline size_t getSize() const
            {
                    return size;
            }

            friend std::istream &operator>>(std::istream &is, t_string &str);
            friend std::ostream &operator<<(std::ostream &out, t_string &str);


    public:
            t_string operator+(const t_string &str) const
            {
                    t_string newString;
                    newString.size = size + str.getSize();
                    newString.data = new char[newString.size + 1];
                    strcpy(newString.data, data);
                    strcat(newString.data, str.data);
                    return newString;
            }

            t_string& operator=(const t_string &str)
            {
                    if (this == &str)
                            return *this;
                    delete[] data;
                    size = str.getSize();
                    data = new char[size+1];
                    strcpy(data, str.c_str());
                    return *this;
            }

            t_string& operator+=(const t_string &str)
            {
                    size += str.getSize();
                    char *newData = new char[size+1];
                    strcpy(newData, data);
                    strcat(newData, str.c_str());
                    delete[] data;
                    data = newData;
                    return *this;
            }

            inline bool operator==(const t_string &str)
            {
                    return size != str.getSize() ? false : strcmp(data, str.data) == 0;
            }

            inline char& operator[](int n) const
            {
                    return n < 0 ? data[size+n] : data[n];
            }


    protected:
            size_t strlen(const char *s) const
            {
                    const char *sc = s;
                    for (; *sc != '\0'; ++sc)
                            ;
                    return sc - s;
            }

            char* strcpy(char *des, const char *src) const
            {
                    char *r = des;
                    assert((des != nullptr) && (src != nullptr));
                    while ((*r++ = *src++) != '\0')
                            ;
                    return r;
            }

            char* strcat(char *des, const char *src) const
            {
                    char *p = des;
                    const char *q = src;
                    while (*p != '\0')  p++;
                    while (*q != '\0')  *p++ = *q++;
                    *p = '\0';
                    return p;
            }

            int strcmp(const char *str1, const char *str2) const
            {
                    assert(str1 != nullptr && str2 != nullptr);
                    while (*str1 == *str2) {
                            if (*str1 == '\0')
                                    return 0;
                            str1++;
                            str2++;
                    }
                    return *str1 - *str2;
            }

            inline const char *c_str() const
            {
                    return data;
            }
    };
}

#endif //MYCC_STRING_HPP
