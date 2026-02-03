class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for (int i = 0; i < asteroids.size(); i++) {
            int asteroid = asteroids[i];
            
            bool destroyed = false;

            while (!st.empty() && asteroid < 0 && st.top() > 0) {
                if (st.top() < -asteroid) {
                    st.pop(); 
                    continue;
                } 
                else if (st.top() == -asteroid) {
                    st.pop(); 
                }
                destroyed = true; 
                break;
            }
            
            if (!destroyed) {
                st.push(asteroid);
            }
        }

        
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
