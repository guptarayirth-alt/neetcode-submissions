class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
         this->k = k;
        for(int it: nums)
        {
            pq.push(it);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }}
    
    int add(int val) {
        pq.push(val);
        if(pq.size()> k)
        {
            pq.pop();
        }
        
    }
};
