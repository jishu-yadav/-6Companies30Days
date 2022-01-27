class Solution {
public:
    struct comp
    {
        bool operator()(const string &a, const string &b)
        {
            return a.length()==b.length() ? (a>b) : a.length()>b.length();
        }    
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        priority_queue<string,vector<string>,comp>pq;
        
        for(auto &t : nums)
        {
            pq.push(t);
            
            if(pq.size()>k)pq.pop();
        }
        
        return pq.top();
    }
};
