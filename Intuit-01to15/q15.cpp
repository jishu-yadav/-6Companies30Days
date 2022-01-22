class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       
        int left = 1, right = *max_element(piles.begin(),piles.end());
        
        while(left < right){
            int m = (left + right )/2;
            int hrspent = 0;
            for(int p:piles){
                hrspent += (p / m) + (p % m != 0); 
            }
            if(hrspent<=h){
                    right = m;
                }
            else{
                    left = m+1;
            }
        }
        return right;
    }
};
