#include "dsa_string.hpp"
#include <cstring>

namespace hzcc {

    std::istream &operator>>(std::istream &is, hzcc::t_string &str)
    {
            char tmp[1000];
            is >> tmp;
            str.size = strlen(tmp);
            str.data = new char[str.getSize() + 1];
            strcpy(str.data, tmp);
            return is;
    }

    std::ostream &operator<<(std::ostream &out, t_string &str)
    {
            out << str.data;
            return out;
    }

}