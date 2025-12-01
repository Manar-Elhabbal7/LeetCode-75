class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long mul = 1;
        int cnt0 = 0;
        bool findZero = false, allZero = true;
        
        for (auto value : nums) {
            if (value != 0) {
                mul *= value;
                allZero = false;
            } else {
                findZero = true;
                cnt0++;
            }
        }

        if (allZero or cnt0 > 1) {
            for (int i = 0; i < nums.size(); i++)
                nums[i] = 0;
            return nums;
        }

        for (int i = 0; i < (int)nums.size(); i++) {
            if (findZero) {
                if (nums[i] == 0)
                    nums[i] = mul;
                else
                    nums[i] = 0;
            } else {
                if (nums[i] == 0)
                    nums[i] = mul;
                else
                    nums[i] = mul / nums[i];
            }
        }
        return nums;
    }
};
