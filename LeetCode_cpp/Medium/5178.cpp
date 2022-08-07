class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (auto it : nums) {
            int cnt = 0, lim = sqrt(it), tmp = 0;
            for (int i = 1; i <= lim; ++i) {
                if (it % i == 0) {
                    int divnum = it / i;
                    if (divnum == i) {
                        cnt += 1;
                    } else {
                        cnt += 2;
                    }
                    if (cnt > 4) {
                        break;
                    }
                    tmp += i + (it / i);
                }
            }
            
            if (cnt == 4) {
                sum += tmp;
                //cout << it << " " << tmp << " " << sum << endl;
            }
        }
        return sum;
    }
};