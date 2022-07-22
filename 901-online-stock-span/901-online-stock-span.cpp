class StockSpanner {
public:
    stack<pair<int,int>> st;
	
    int next(int currPrice) {
        int currStreak=1;
        while (!st.empty() && st.top().first<=currPrice){
            currStreak+=st.top().second;
            st.pop();
        }
        st.push({currPrice,currStreak});
        return currStreak;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */