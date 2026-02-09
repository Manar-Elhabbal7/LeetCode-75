class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (auto value : nums) {
            pq.push(value);
        }

        k--;
        while (k--) {
            pq.pop();
        }
        return pq.top();
    }
};
