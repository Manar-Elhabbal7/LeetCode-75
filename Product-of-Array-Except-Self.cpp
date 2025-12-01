1class Solution {
2public:
3    vector<int> productExceptSelf(vector<int>& nums) {
4        long long mul = 1;
5        int cnt0 = 0;
6        bool findZero = false, allZero = true;
7        ;
8        for (auto value : nums) {
9
10            if (value != 0) {
11                mul *= value;
12                allZero = false;
13            } else {
14                findZero = true;
15                cnt0++;
16            }
17        }
18
19        if (allZero or cnt0 > 1) {
20            for (int i = 0; i < nums.size(); i++)
21                nums[i] = 0;
22            return nums;
23        }
24
25        for (int i = 0; i < (int)nums.size(); i++) {
26            if (findZero) {
27                if (nums[i] == 0)
28                    nums[i] = mul;
29                else
30                    nums[i] = 0;
31            } else {
32                if (nums[i] == 0)
33                    nums[i] = mul;
34                else
35                    nums[i] = mul / nums[i];
36            }
37        }
38        return nums;
39    }
40};