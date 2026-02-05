class StockSpanner {
public:
    stack<pair<int, int>> st;//price, num of spans
    StockSpanner() {}

    int next(int price) {
        //intialized to one as it self counted
        int span = 1;
        
        while (!st.empty() and st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }
};
//read this : https://www.geeksforgeeks.org/dsa/introduction-to-monotonic-stack-2/
//also read this : https://www.geeksforgeeks.org/dsa/the-stock-span-problem/

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
