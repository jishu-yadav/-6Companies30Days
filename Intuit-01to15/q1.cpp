#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    long long int sum=0;
	    for(long long int i=0;i<n;i++)
	        sum+=arr[i];
	        
	    bool t[n+1][sum+1];
	    for(long long int i=0;i<=sum;i++){
	        t[0][i] = false;
	    }
	     for(long long int i=0;i<=n;i++){
	        t[i][0] = true;
	    }
	     for(long long int i=1;i<=n;i++){
	         for(long long int j=1;j<=sum;j++){
	                if(arr[i-1]<=j)
	                    t[i][j]=t[i-1][j]||t[i-1][j-arr[i-1]];
	               else
	                    t[i][j]=t[i-1][j];    
	        }
	    }
	    vector<long long int>v;
	    for(long long int i=0;i<=sum/2;i++)
	            if(t[n][i]==true)
	            v.push_back(i);
	            
	    long long int mn = INT_MAX;
	    
	    for(long long int i=0;i<v.size();i++){
	        mn = min(mn,abs(sum-2*v[i]));
	    }
	    
	    return mn;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
