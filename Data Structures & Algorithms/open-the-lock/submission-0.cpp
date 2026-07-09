class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        std::unordered_set<std::string> visited(deadends.begin(), deadends.end());
        
        // Edge case: If the starting point or target is a deadend, it's impossible
        if (visited.count("0000") || visited.count(target)) {
            return -1;
        }
        
        // BFS queue storing pairs of {current_combination, turns_taken}
        std::queue<std::pair<std::string, int>> q;
        q.push({"0000", 0});
        visited.insert("0000"); // Mark starting node as visited
        
        while (!q.empty()) {
            auto [curr, turns] = q.front();
            q.pop();
            
            // If we reached the target, return the minimum turns
            if (curr == target) {
                return turns;
            }
            
            // Explore all 8 possible combinations from the current state
            for (int i = 0; i < 4; ++i) {
                char original_char = curr[i];
                
                // Spin wheel up (+1) and down (-1)
                for (int move : {-1, 1}) {
                    // Calculate the new digit with wrap-around (0-9)
                    // Adding 10 handles the negative modulo wrap-around smoothly in C++
                    int next_digit = (original_char - '0' + move + 10) % 10;
                    curr[i] = next_digit + '0';
                    
                    // If this combination hasn't been visited (or isn't a deadend)
                    if (!visited.count(curr)) {
                        visited.insert(curr);
                        q.push({curr, turns + 1});
                    }
                }
                // Restore the character before moving to the next wheel slot
                curr[i] = original_char;
            }
        }
        
        // Target is unreachable
        return -1;
    }
};