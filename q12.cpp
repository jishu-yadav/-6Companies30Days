class Solution {
  public:
    long long squaresInChessBoard(long long n) {
        long long int ans=((n)*(n+1)*(2*n+1))/6;
        return ans;
    }
};
