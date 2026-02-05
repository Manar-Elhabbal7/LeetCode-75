class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        stack<int> st;
        vector<int> ans(a.size(), 0);

        for (int i = 0; i < a.size(); i++) {
            while (!st.empty() and a[i] > a[st.top()]) {
                int idx = st.top();
                st.pop();
                ans[idx] = i - idx;
            }
            st.push(i);
        }
        return ans;
    }
};
