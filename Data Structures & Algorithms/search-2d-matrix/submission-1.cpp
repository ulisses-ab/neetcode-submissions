class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0, hi = matrix.size()*matrix[0].size()-1;

        while (lo <= hi) {
            int m = (lo + hi) / 2;

            int i = m / matrix[0].size();
            int j = m % matrix[0].size();

            if (matrix[i][j] == target) {
                return true;
            }
            else if (target < matrix[i][j]) {
                hi = m-1;
            }
            else {
                lo = m+1;
            }
        } 

        return false;
    }
};
