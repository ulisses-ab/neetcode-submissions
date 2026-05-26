class Solution {
public:
    bool bs(vector<int>& v, int target) {
        int lo = 0, hi = v.size()-1;

        while (lo <= hi) {
            int m = (lo+hi) / 2;

            if (v[m] == target) {
                return true;
            }
            else if (v[m] > target) {
                hi = m-1;
            }
            else {
                lo = m+1;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0, hi = matrix.size()-1;

        while (lo <= hi) {
            int m = (lo + hi) / 2;

            if (matrix[m][0] <= target && target <= matrix[m].back()) {
                return bs(matrix[m], target);
            }
            else if (target < matrix[m][0]) {
                hi = m-1;
            }
            else {
                lo = m+1;
            }
        } 

        return false;
    }
};
