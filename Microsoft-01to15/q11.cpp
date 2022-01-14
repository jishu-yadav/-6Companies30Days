// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

string toBinary(int n)
{
    string r;
    while (n != 0){
        int b = n%2;
        r = to_string(b)+r;
        n /= 2;
    }
    return r;
}
//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
    vector<string> res;
    for(int i =1;i<=N;i++){
        res.push_back(toBinary(i));
    }
    return res;
	// Your code here
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends
