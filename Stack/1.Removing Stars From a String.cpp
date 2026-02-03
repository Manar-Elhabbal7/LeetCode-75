class Solution {
public:
    string removeStars(string s) {
        string res = "";
        stack<char> st;

        for (int i =s.size() - 1; i >= 0; i--) {
             st.push(s[i]);
        }

        while (!st.empty()) {
            char t = st.top();
            if (t == '*') {
                res.pop_back();
                st.pop();
            } else {
                res += st.top();
                st.pop();
            }
        }

        return res;
    }
};
