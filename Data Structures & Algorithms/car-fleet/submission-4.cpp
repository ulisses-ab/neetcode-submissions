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
        vector<Car> cars(n);

        for (int i = 0; i < n; i++) {
            cars[i] = Car{position[i], speed[i]};
        }

        sort(cars.begin(), cars.end(), [](Car& a, Car& b) { return a.position < b.position; });

        double last = cars.back().raw_time(target);

        int count = 1;

        for (int i = n-2; i >= 0; i--) {
            double time = cars[i].raw_time(target);

            if (time > last) {
                last = time;
                count++;
            }
        }

        return count;
    }
};
