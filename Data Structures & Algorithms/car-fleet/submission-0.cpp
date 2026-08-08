class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>> cars(n);

        for(int i = 0; i < n; ++i){
            cars[i] = {position[i], speed[i]};
        }

        sort(cars.rbegin(), cars.rend()); // Fixed 'car' to 'cars'
        int fleet = 0;
        double maxtime = 0.0;

        for(const auto& car : cars){
            double time = (double)(target - car.first) / car.second;
            if(time > maxtime){
                fleet++;
                maxtime = time;
            }
        }
        return fleet;
    }
};