class Solution {
public:
    vector<int> memo;
    int picker(vector<int>& nums, int n) {
        if (n <= 0)
            return 0;

        if (n == 1)
            return nums[0];

        if (memo[n] != -1)
            return memo[n];

        int pick = nums[n - 1] + picker(nums, n - 2);
        int leave = picker(nums, n - 1);
        
        memo[n] = max(pick, leave);
        return memo[n];
    }
    int rob(vector<int>& nums) {
        // pick or leave with memo
        memo.resize((int)nums.size() + 1, -1);
        return picker(nums, (int)nums.size());
    }
};
