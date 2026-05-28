class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff;

        for (int i = 0; i < gas.size(); i++) {
            diff.push_back(gas[i]-cost[i]);
        }

        int current = 0;
        int start = 0;

        for (int i = 0; i < diff.size(); i++) {
            if (current < 0) {
                current = 0;
                start = i;
            }
            
            current += diff[i];
        }

        bool ok = true;
        current = 0;
        for (int i = start; i < start+diff.size(); i++) {
            current += diff[i%diff.size()];

            if (current < 0) {
                ok = false;
                break;
            }
        }

        return ok ? start : -1;
    }
};

