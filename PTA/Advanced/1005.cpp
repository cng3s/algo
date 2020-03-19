#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<int, string> num_eng;
    num_eng[0] = "zero", num_eng[1] = "one", num_eng[2] = "two", num_eng[3] = "three";
    num_eng[4] = "four", num_eng[5] = "five", num_eng[6] = "six", num_eng[7] = "seven";
    num_eng[8] = "eight", num_eng[9] = "nine";

    string input;
    int digit;
    long sum = 0;

    cin >> input;

    for (auto it : input) {
        sum += (it-'0');
    }

	string res = num_eng[sum%10];
	sum /= 10;
    while (sum != 0) {
        digit = sum % 10;
        sum /= 10;
       	res = num_eng[digit] + " " + res;
    }
    cout << res;
    return 0;
}