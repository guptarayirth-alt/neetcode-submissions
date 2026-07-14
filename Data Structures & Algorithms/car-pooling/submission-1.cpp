class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 1. Sort trips ascending by start location
        std::sort(trips.begin(), trips.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1]; 
        });
        
        // Min-heap to track drop-offs: {end_location, passengers}
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        
        int current_passengers = 0;
        
        for (int i = 0; i < trips.size(); i++) {
            
            // Step A: Process all valid drop-offs before picking up new passengers
            while (!pq.empty() && pq.top().first <= trips[i][1]) {
                current_passengers -= pq.top().second; // Remove passengers from car
                pq.pop(); // Remove the event from the queue
            }
            
            // Step B: Pick up the new passengers
            current_passengers += trips[i][0];
            
            // Step C: Check if we violated the capacity rule
            if (current_passengers > capacity) {
                return false;
            }
            
            // Step D: Record this trip's drop-off event for the future
            pq.push({trips[i][2], trips[i][0]});
        }
        
        return true;
    }
};