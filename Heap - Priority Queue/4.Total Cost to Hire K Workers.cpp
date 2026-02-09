#define ll long long

class Solution {
public:
    ll totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> top, bottom;

        int n = costs.size();

        for (int i = 0; i < candidates; i++) {
            top.push(costs[i]);
        }

        for (int i = max(candidates, n - candidates); i < n; i++) {
            bottom.push(costs[i]);
        }

        ll cost = 0;
        int nextTop = candidates, nextBottom = n - 1 - candidates;

        for (int i = 0; i < k; i++) {
            if (bottom.empty() or
                (!top.empty() and top.top() <= bottom.top())) {

                cost += top.top();
                top.pop();

                if (nextTop <= nextBottom) {
                    top.push(costs[nextTop]);
                    nextTop++;
                }
            } else {
                cost += bottom.top();
                bottom.pop();

                if (nextTop <= nextBottom) {
                    bottom.push(costs[nextBottom]);
                    nextBottom--;
                }
            }
        }

        return cost;
    }
};
