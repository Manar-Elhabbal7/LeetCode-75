1class Solution {
2public:
3    bool increasingTriplet(vector<int>& nums) {
4        // KISS
5        // Keep It Simple Stupid
6
7        int first = INT_MAX, second = INT_MAX;
8        int n = nums.size();
9        if (n < 3)
10            return false;
11
12        for (auto& num : nums) {
13            if (num <= first) {
14                first = num;
15            } else if (num <= second) {
16                second = num;
17            } else {
18                return true;
19            }
20        }
21        return false;
22    }
23};