class Solution {
public:
    bool possible(vector<int>& piles, int h, int k) {
        cout << k << endl;
        int time = 0;
        
        for (auto pile : piles) {
            time += (pile+k-1) / k;
        }

        if (time > h) return false;

        return true;
    } 

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = 1e9;

        while (lo < hi) {
            int m = (lo+hi) / 2;

            if (possible(piles, h, m)) {
                hi = m;
            }
            else {
                lo = m + 1;
            }
        }   

        return lo;     
    }
};
