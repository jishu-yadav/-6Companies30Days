// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
     map<char, vector<string>>m;
    vector<string>res;
    void helper(int start,string digits,string cur){
        if(start == digits.size())
            res.emplace_back(cur);
        vector<string>vec=m[digits[start]];
        for(int i=0;i<vec.size();i++){
            string s = vec[i];
            cur+=s;
            helper(start+1,digits,cur);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return res;
        m['2'] = {"a","b","c"};
        m['3'] = {"d","e","f"};
        m['4'] = {"g","h","i"};
        m['5'] = {"j","k","l"};
        m['6'] = {"m","n","o"};
        m['7'] = {"p","q","r","s"};
        m['8'] = {"t","u","v"};
        m['9'] = {"w","x","y","z"};

        helper(0,digits,"");
        return res;
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        string s ="";
        for(int i=0;i<N;i++){
            s=s+to_string(a[i]);
        }
        vector<string> v = letterCombinations(s); 
        return v;
        //Your code here
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends
