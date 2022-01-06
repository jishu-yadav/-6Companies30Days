// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int price[]) {
        // code here
    int profit[k + 1][n + 1];

    for (int i = 0; i <= k; i++)
        profit[i][0] = 0;

    for (int j = 0; j <= n; j++)//k=0 no transaction so profit=0;
        profit[0][j] = 0;

    // fill the table in bottom-up fashion
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < n; j++) {
            int max_so_far = INT_MIN;

            for (int m = 0; m < j; m++)
                max_so_far = max(max_so_far,
                                 price[j] - price[m] + profit[i - 1][m]);

            profit[i][j] = max(profit[i][j - 1], max_so_far);
        }
    }

    return profit[k][n - 1];
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends
