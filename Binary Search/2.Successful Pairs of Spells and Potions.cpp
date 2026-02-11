#define ll long long

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, ll success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        int m = potions.size();
        for (int& v : spells) {
            int i = lower_bound(potions.begin(), potions.end(), success * 1.0 / v) - potions.begin();
            ans.push_back(m - i);
        }
        return ans;
    }
};
