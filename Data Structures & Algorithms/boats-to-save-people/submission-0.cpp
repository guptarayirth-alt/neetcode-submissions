#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // 1. Sort the array first so the two-pointer approach works
        sort(people.begin(), people.end()); 
        
        int left = 0;
        int right = people.size() - 1; // 2. Fix out of bounds (size() - 1)
        int count = 0;
        
        while (left <= right) // 3. Change != to <= to include the middle person
        {
            // 4. Check if they are less than OR equal to the limit
            if (people[left] + people[right] <= limit) 
            {
                left++; // The lightest person fits, move left pointer
            }
            
            // 5. The heaviest person always gets a boat, and one boat is used
            right--; 
            count++;
        } 
        return count;  
    }
};