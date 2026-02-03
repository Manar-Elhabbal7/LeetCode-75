class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        set<int> s1,s2;
        for(auto value : nums1) s1.insert(value);
        for(auto value : nums2) s2.insert(value);

        vector<int> v1, v2;
        for (auto it : s1) {
            if (s2.find(it) == s2.end()) {
                v1.push_back(it);
            }
        }

        for (auto it : s2) {
            if (s1.find(it) == s1.end()) {
                v2.push_back(it);
            }
        }
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};
