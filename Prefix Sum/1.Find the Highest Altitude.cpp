class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> prefix_sum(n, 0);
        prefix_sum[0] = gain[0];
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + gain[i];
        }
        int mx = max(0, *max_element(prefix_sum.begin(), prefix_sum.end()));
        return mx;
    }
};
