// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  string res = "";
  int n = src.size();
  int i;
  int c=0;
  while(c<n){
        while(src[i]==src[c]){
            c++;
         }
         res += src[i] + to_string(c-i); 
         i = c;
  }
  return res;
}     
 
