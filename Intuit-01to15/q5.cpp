class Solution {
public:
      bool isArraySplitAllowed(vector<int>& nums, int sum, int m) {
        int split = 1;
        int arrSum = 0;
        
        for(int i=0;i<nums.size();i++) {
            arrSum += nums[i];
            if(arrSum > sum) {
                arrSum = nums[i];
                split++;
            }
        }
        
        return split <= m;
    }
    int splitArray(vector<int>& nums, int m) {
        int l = 0, r = 0;
        for(int i: nums) {
            l = max(l, i);
            r += i;
        }
        
        while(l < r) {
            int mid = l + (r - l)/2;
            if(isArraySplitAllowed(nums, mid, m)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        
        return l;
    }
};
