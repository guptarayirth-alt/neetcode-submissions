class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        
        // Step 1: Store tasks as {enqueueTime, processingTime, originalIndex}
        vector<vector<long long>> sortedTasks(n, vector<long long>(3));
        for (int i = 0; i < n; ++i) {
            sortedTasks[i] = {tasks[i][0], tasks[i][1], i};
        }
        
        // Sort tasks primarily by their enqueue time
        sort(sortedTasks.begin(), sortedTasks.end(), [](const vector<long long>& a, const vector<long long>& b) {
            return a[0] < b[0];
        });
        
        vector<int> result;
        // Min-heap stores: {processingTime, originalIndex}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        long long currentTime = 0;
        int taskIndex = 0;
        
        // Step 2 & 3: Process tasks until all are executed
        while (taskIndex < n || !pq.empty()) {
            // If the CPU is idle and no tasks have arrived yet, 
            // fast-forward time to the next available task's enqueue time.
            if (pq.empty() && currentTime < sortedTasks[taskIndex][0]) {
                currentTime = sortedTasks[taskIndex][0];
            }
            
            // Push all tasks that have arrived by the current time into the min-heap
            while (taskIndex < n && sortedTasks[taskIndex][0] <= currentTime) {
                pq.push({sortedTasks[taskIndex][1], (int)sortedTasks[taskIndex][2]});
                taskIndex++;
            }
            
            // Pop the optimal task from the min-heap
            auto [processingTime, originalIndex] = pq.top();
            pq.pop();
            
            // Execute the task
            result.push_back(originalIndex);
            currentTime += processingTime;
        }
        
        return result;
    }
};