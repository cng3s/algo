class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (const auto d : nums) cout << d << ',';
        cout << endl << endl;

        for (int first = 0; first < n - 3; ++first) {
            while (first > 0 && nums[first] == nums[first-1]) ++ first;

            for (int fourth = n-1;  fourth > first + 2; --fourth) {

                while (fourth < n-1 && fourth > first + 2 && nums[fourth] == nums[fourth+1]) -- fourth;
                if (fourth <= first + 2) { break; }


                // cout << nums[first] << ',' << nums[second] << ',' << nums[third] << ',' << nums[fourth] << endl;
                int second = first + 1, third = fourth - 1;
                while (second < third) {
                    // if (nums[first] == -1)
                        // cout << nums[first] << ',' << nums[second] << ',' << nums[third] << ',' << nums[fourth] << endl;
                    int64_t sum = nums[first] + nums[second];  
                    sum += nums[third];
                    sum += nums[fourth];

                    if (sum > target) {
                        int prev = nums[third];
                        while (second < third && nums[third] == prev) -- third;
                    } else if (sum < target) {
                        int prev = nums[second];
                        while (second < third && nums[second] == prev) ++ second;
                    } else if (sum == target) {
                        // if (fourth == third) 
                            // cout << "fuck2:" << nums[first] << ',' << nums[second] << ',' << nums[third] << ',' << nums[fourth] << endl;
                        ans.push_back({nums[first], nums[second], nums[third], nums[fourth]});

                        int prev_second = nums[second];
                        while (second < third && nums[second] == prev_second) ++ second;
                        int prev_third = nums[third];
                        while (third > second && nums[third] == prev_third) -- third;
                    }
                }
            }
        }

        return ans;
    }
};