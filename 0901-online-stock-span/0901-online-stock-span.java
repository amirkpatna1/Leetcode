class StockSpanner {

    static class Pair {
        int val;
        int cnt;
        Pair(int val, int cnt) {
            this.val = val;
            this.cnt = cnt;
        }
    }
    
    Stack<Pair> st;
    public StockSpanner() {
        st = new Stack<>();
    }
    
    public int next(int price) {
        int cnt = 1;
        while(!st.isEmpty() && st.peek().val <= price) {
            Pair p = st.pop();
            cnt += p.cnt;
        }
        st.add(new Pair(price, cnt));
        return cnt;
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */