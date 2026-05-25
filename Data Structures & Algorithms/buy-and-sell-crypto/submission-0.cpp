class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int s = 0;
        int best = 0;

        for (int e = 0; e < prices.size(); e++) {
            if (prices[e] < prices[s]) {
                s = e;
            }

            best = max(best, prices[e]-prices[s]);
        } 

        return best;
    }
};
