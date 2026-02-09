#define ll long long

class Solution {
public:
    ll maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> pairs(n);

        for (int i = 0; i < n; ++i) {
            pairs[i] = {nums2[i], nums1[i]};
        }
        
        sort(pairs.rbegin(), pairs.rend());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        ll sum = 0;
        ll maxScore = 0;

        for (int i = 0; i < n; ++i) {
            sum += pairs[i].second;
            minHeap.push(pairs[i].second);

            if (minHeap.size() > k) {
                sum -= minHeap.top();
                minHeap.pop();
            }

            if (minHeap.size() == k) {
                maxScore = max(maxScore, sum * pairs[i].first);
            }
        }

        return maxScore;
    }
};
