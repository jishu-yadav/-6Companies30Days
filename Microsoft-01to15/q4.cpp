// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int>spiral;
        int n = matrix.size(),m = matrix[0].size();
        int top=0,left = 0,right = m-1,bottom=n-1;
        int dir = 0,i=0; 
        while(top<=bottom && left<=right){
            if(dir==0){
                for(i=left;i<=right;i++)
                    spiral.push_back(matrix[top][i]);
                top++;
            }
            else if(dir==1){
                for(i=top;i<=bottom;i++)
                    spiral.push_back(matrix[i][right]);
                right--;
            }
            else if(dir==2){
                for(i=right;i>=left;i--)
                    spiral.push_back(matrix[bottom][i]);
                bottom--;
            }
            else if(dir==3){
                for(i=bottom;i>=top;i--)
                    spiral.push_back(matrix[i][left]);
                left++;
            }
            
            dir = (dir+1)%4;
            
        }
        return spiral;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
