class Solution {
public:
    int longestMountain(
        vector<int>& a) {
        int n = a.size();
        int x=0;
        int l=0,ml=0,j=0;
        for(int i=1;i<n-1;){
            if(a[i-1]<a[i]&&a[i]>a[i+1]){
             
                 j=i;
                x=1;
                while(j>=1 &&a[j-1]<a[j]){
                    j--;
                    x++;
                  
                }
                
                while(i<=n-2 && a[i]>a[i+1]){
                 
                    x++;
                    i++;
                 
                }
                ml = max(ml, x);
                
            }
            else{
                i++;
            }
           
        }
        
        return ml;
    }
};
