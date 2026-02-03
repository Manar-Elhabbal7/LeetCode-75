class Solution {
public:
    int ans = INT_MIN;
    int longestOnes(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int left = 0, right = left;

        int zeros = 0;
        auto window = [&](int l, int r) {
            while (r < n and (zeros < k or (zeros == k and nums[r] == 1))) {
                if (nums[r] == 0)
                    zeros++;
                r++;
            }
            ans = max(ans, r - l);
            right = r;
        };

        window(0, right);

        for (left = 1; left <= n - k; left++) {
            if (nums[left - 1] == 0)
                zeros--;
            window(left, right);
        }
        return ans;
    }
};
