class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for(char it : tasks) mp[it]++;
        
        // Max-heap to keep track of highest frequencies
        priority_queue<int> pq;
        for(auto it : mp) pq.push(it.second);
        
        int turns = 0;
        int cycle = n + 1;
        
        while(!pq.empty()) {
            vector<int> temp;
            int task_count = 0;
            
            // Pop up to (n + 1) tasks from the heap
            for(int i = 0; i < cycle; i++) {
                if(!pq.empty()) {
                    temp.push_back(pq.top() - 1);
                    pq.pop();
                    task_count++;
                }
            }
            
            // Put remaining tasks back into the heap if they still have frequency > 0
            for(int count : temp) {
                if(count > 0) pq.push(count);
            }
            
            // Accumulate intervals
            turns += pq.empty() ? task_count : cycle;
        }
        
        return turns;
    }
};