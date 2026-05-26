class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int lo = 0, hi = nums2.size();

        int k = (nums1.size()+nums2.size()+1) / 2;

        while (lo <= hi) {
            int k2 = (lo+hi) / 2;

            int k1 = k - k2;

            if (k1 < 0) {
                hi = k2-1;
                continue;
            } 
            if (k1 > nums1.size()) {
                lo = k2+1;
                continue;
            }

            int sm1 = k1 > 0 ? nums1[k1-1] : -1e9;
            int sm2 = k2 > 0 ? nums2[k2-1] : -1e9;

            int sm = max(sm1, sm2);

            int bg1 = k1 < nums1.size() ? nums1[k1] : 1e9;
            int bg2 = k2 < nums2.size() ? nums2[k2] : 1e9;

            int bg = min(bg1, bg2);

            if (sm <= bg) {
                double ans = (nums1.size()+nums2.size()) & 1 ? sm : (double(sm+bg)/2);

                return ans;
            } 

            if (sm1 > bg2) {
                lo = k2 + 1;
            }
            else if (sm2 > bg1) {
                hi = k2 - 1; 
            }
        }

        return -1;
    }
};

