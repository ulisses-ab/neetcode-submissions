class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> pref(n);
        vector<int> suff(n);

        for (int i = 0; i < n; i++) {
            pref[i] = nums[i];

            if (i > 0) {
                pref[i] *= pref[i-1];
            }
        }

        for (int i = n-1; i >= 0; i--) {
            suff[i] = nums[i];

            if (i < n-1) {
                suff[i] *= suff[i+1];
            }
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = 1;

            if (i > 0) {
                ans[i] *= pref[i-1];
            }

            if (i < n-1) {
                ans[i] *= suff[i+1];
            }
        }

        return ans;
    }
};

