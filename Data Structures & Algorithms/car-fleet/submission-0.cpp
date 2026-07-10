class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        int n = position.size();
        if (n == 0) return 0;

        // Pair up (position, speed) so we can sort them together
        std::vector<std::pair<int, int>> cars(n);
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], speed[i]};
        }

        // Sort cars by position in descending order (closest to target first)
        std::sort(cars.begin(), cars.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        int fleets = 0;
        double max_time = 0.0; // Tracks the arrival time of the current fleet leader

        for (int i = 0; i < n; ++i) {
            // Calculate time taken to reach target as a double to avoid integer division truncation
            double current_time = static_cast<double>(target - cars[i].first) / cars[i].second;

            // If this car takes strictly longer than the fleet ahead, 
            // it cannot catch up. It forms a new fleet.
            if (current_time > max_time) {
                fleets++;
                max_time = current_time; // This car is now the leader of the new fleet
            }
            // If current_time <= max_time, it merges into the existing fleet (do nothing)
        }

        return fleets;
    }
};