class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double current_sum = 0;
        for (int i = 0; i < k; i++) {
            current_sum += nums[i];
        }
        double mx_sum = current_sum;
        for (int i = k; i < n; i++) {
            current_sum += nums[i] - nums[i - k];
            mx_sum = max(mx_sum, current_sum);
        }
        return mx_sum / k;
    }
};
