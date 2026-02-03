class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> freq;
        for (auto num : arr) {
            freq[num]++;
        }
        
        vector<int> v;
        set<int> s;
        for (auto p : freq) {
            v.push_back(p.second);
            s.insert(p.second);
        }
        return (v.size() == s.size());
    }
};
