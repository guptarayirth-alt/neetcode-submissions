class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalSum = 0;
        int tank = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            totalSum += diff;
            tank += diff;

            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        return totalSum >= 0 ? start : -1;
    }
};
