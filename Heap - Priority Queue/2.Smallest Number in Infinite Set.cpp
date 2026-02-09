class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_set<int> added;
    int cur;

    SmallestInfiniteSet() { cur = 1; }

    int popSmallest() {
        if (!minHeap.empty()) {
            int x = minHeap.top();
            minHeap.pop();
            added.erase(x);
            return x;
        }
        return cur++;
    }

    void addBack(int num) {
        if (num < cur and added.find(num) == added.end()) {
            minHeap.push(num);
            added.insert(num);
        }
    }
};
