#pragma warning(disable : 4996)
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<char> ops;
	vector<double> nums;
	double num1, num2;
	char op;

	scanf("%lf", &num1);
	nums.push_back(num1);
	while (1) {
		cin >> op;
		if (op == '0')
			break;
		scanf("%lf", &num2);
		
		switch (op) {
		case '*':
			num1 = nums.back();
			nums.pop_back();
			nums.push_back(num1 * num2);
			break;
		case '/':
			num1 = nums.back();
			nums.pop_back();
			nums.push_back(num1 / num2);
			break;
		case '+':
			ops.push_back('+');
			nums.push_back(num2);
			break;
		case '-':
			ops.push_back('-');
			nums.push_back(num2);
			break;
		}
	}
	double res = nums[0];
	int idx = 1;
	for (auto it : ops) {
		switch (it) {
		case '+':
			res += nums[idx++];
			break;
		case '-':
			res -= nums[idx++];
			break;
		}
	}
	printf("%.2lf", res);

	return 0;
}