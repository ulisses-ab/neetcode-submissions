class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0, j = heights.size() - 1;

        int best = -1;

        while (i < j) {
            int area = min(heights[i], heights[j]) * (j-i);

            best = max(best, area);

            if (heights[i] < heights[j]) {
                i++;
            }
            else {
                j--;
            }
        }

        return best;
    }
};
