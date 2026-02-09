//Solution without Trie ^_^
class Solution {
public:
    bool startsWith(string word, string prefix) {
        int sz = prefix.size(), n = word.size();
        if (sz > n)
            return false;

        for (int i = 0; i < sz; i++) {
            if (prefix[i] != word[i])
                return false;
        }
        return true;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {
                                                
        sort(products.begin(),products.end());
        vector<vector<string>> ans;
        string pref = "";

        for (auto c : searchWord) {
            vector<string> tmp;
            pref += c;

            for (auto st : products) {
                if (startsWith(st, pref)) {
                    tmp.push_back(st);
                    if(tmp.size() == 3) break;
                }
            }
            ans.push_back(tmp);
        }
        
        return ans;
    }
};
