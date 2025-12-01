1class Solution {
2public:
3    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
4        
5        int n = candies.size();
6        int mx = *max_element(candies.begin(), candies.end());
7        vector<bool> ans(n, false);
8
9
10        for (int i = 0; i < n; i++) {
11            if (candies[i] == mx or candies[i] + extraCandies >= mx) {
12                ans[i] = true;
13            }
14        }
15        return ans;
16    }
17};