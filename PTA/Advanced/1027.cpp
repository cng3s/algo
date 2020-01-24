#pragma warning(disable : 4996)
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string covert_table[13] = {
    "0", "1", "2", "3", "4",
    "5", "6", "7", "8", "9",
    "A", "B", "C" };

string covert(int dec)
{
    int a = dec / 13, b = dec % 13;
    string stra = (a == 0 ? "0" : covert_table[a]), strb = covert_table[b];
    return stra + strb;
}

int main()
{
    int tmp, i;
    string tmpstr = "";

    for (i = 0; i < 3; ++i) {
        scanf("%d", &tmp);
        tmpstr += covert(tmp);
    }

    cout << "#" << tmpstr;

    return 0;
}