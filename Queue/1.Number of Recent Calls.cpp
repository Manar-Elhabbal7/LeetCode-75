class RecentCounter {
public:
    int cnt = 0;
    RecentCounter() {}
    queue<int> q;
    int ping(int t) {
        q.emplace(t);
        int l = t - 3000;
        while (!q.empty() && q.front() < l) {
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
