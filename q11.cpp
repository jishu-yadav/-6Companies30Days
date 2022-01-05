// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int p[2];
        int *res = p;
        // int* res = (int*)malloc(2*sizeof(int));
        vector<int>map(n+1,0);
        for(int i=0;i<n;i++){
            map[arr[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(map[i]==2){
                p[0]=i;
            }
            if(map[i]==0)
                p[1] = i;
        }
        return res;
    
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
