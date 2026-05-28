class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> count;

        for (auto h : hand) {
            count[h]++;
        }

        int start = 0;
        while (start <= 1000) {
            if (count[start] == 0) {
                start++;
                continue;
            }

            for (int i = start; i < start+groupSize; i++) {
                if (count[i]-- == 0) {
                    return false;
                }
            }
        }

        return true;
    }
};
