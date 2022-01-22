// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    // bool dfs(vector<vector<char>>& board, string word,int i,int j,int n){
    //     if(n==word.size()) return true;
    //     if(i<0 || i>=board.size() || j<0 || j>=board[i].size() || board[i][j]!=word[n])
    //         return false;
    //     board[i][j] = '0';
    //     bool check = dfs(board,word,i+1,j,n+1) || // down
    //     dfs(board,word,i,j+1,n+1)|| //right
    //     dfs(board,word,i-1,j,n+1)|| //up
    //     dfs(board,word,i,j-1,n+1); // left
    //     return check;
    // }
     bool backtrack(vector<vector<char>>& board, string word,int pos,int i, int j,int r,int c){
        if(i<0||j<0||i>=r||j>=c||word[pos]!=board[i][j])
            return false;
        board[i][j] = '#';
        if(pos==word.size()-1)
            return true;
        if(backtrack(board,word,pos+1,i+1,j,r,c)||backtrack(board,word,pos+1,i-1,j,r,c)||backtrack(board,word,pos+1,i,j+1,r,c)||backtrack(board,word,pos+1,i,j-1,r,c))
            return true;
        board[i][j] = word[pos];
        return false;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        // if(word=="") return false;
        // for(int i=0;i<board.size();i++){
        //     for(int j=0;j<board[i].size();j++){
        //         if(board[i][j]==word[0]&&dfs(board,word,i,j,0))
        //             return true;
        //     }
        // }
        // return false;
        int m = board.size();
        int n = board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(backtrack(board,word,0,i,j,m,n))
                    return true;
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
