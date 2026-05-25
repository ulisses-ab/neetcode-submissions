class Solution {
public:
    struct Car {
        int position;
        int speed;

        double raw_time(int target) {
            return double(target - position) / speed;
        }
    };

    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<Car> cars;

        for (int i = 0; i < n; i++) {
            cars.push_back(Car{position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), [](Car& a, Car& b) { return a.position < b.position; });

        vector<double> ans(n);

        ans[n-1] = cars.back().raw_time(target);

        for (int i = n-2; i >= 0; i--) {
            double time = cars[i].raw_time(target);

            if (time > ans[i+1]) {
                ans[i] = time;
            }
            else {
                ans[i] = ans[i+1];
            }
        }

        set<double> times;
        int count = 0;

        for (auto t : ans) {
            times.insert(t);
        }

        return times.size();
    }
};
