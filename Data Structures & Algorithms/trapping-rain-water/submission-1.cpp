class Solution {
public:
    int get_half_ans(vector<int>& height) {
        int current_h = 0;
        int to_add = 0;
        int total = 0;
        
        for (auto h : height) {
            if (h >= current_h) {
                current_h = h;

                total += to_add;
                to_add = 0;

                continue;
            }

            to_add += current_h - h;
        }


        return total;
    }

    int trap(vector<int>& height) {
        int max_h = 0;
        int max_i = -1;

        for (int i = 0; i < height.size(); i++) {
            if (height[i] >= max_h) {
                max_h = height[i];
                max_i = i; 
            }
        }

        vector a(height.begin(), height.begin()+max_i+1);
        vector b(height.begin()+max_i, height.end());
        reverse(b.begin(), b.end());

        return get_half_ans(a) + get_half_ans(b);
    }
};
