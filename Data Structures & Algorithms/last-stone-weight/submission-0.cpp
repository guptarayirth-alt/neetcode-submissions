class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; // max-heap, default
        int n = stones.size();

        // Step 1: load ALL stones first (separate from smashing logic)
        for (int i = 0; i < n; i++) {
            pq.push(stones[i]);
        }

        // Step 2: smash the two heaviest repeatedly until <= 1 stone remains
        while (pq.size() > 1) {
            int x = pq.top(); pq.pop(); // heaviest
            int y = pq.top(); pq.pop(); // second heaviest
            int diff = x - y;           // x >= y always, since x popped first from max-heap
            if (diff > 0) {
                pq.push(diff);          // only push back if stones didn't fully cancel
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};
