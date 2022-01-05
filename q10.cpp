#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(n--)
    {
        int temp;
        cin>>temp;
        if(pq.size()<10)
            pq.push(temp);
        else 
        {
            if(temp>pq.top())
            {
                pq.push(temp);
                pq.pop();
            }
        }
    }
    vector<int> res;
    while(!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }
    for(int i:res)
    {
        cout<<i<<" ";
    }
    return 0;
}
// #include <iostream>
// using namespace std;
// int findKthLargest(vector<long long int>& nums, int k) {
//         vector<long long int>v;
//         priority_queue<int>pq(nums.begin(),nums.end());
//         int klargest;
//         while(k--){
//             klargest = pq.top();
//             v.push_back(klargest);
//             pq.pop();
//         }
//         return v;
//     }
// int main() {
//     vector<long long int>nums;
//     long long int n;
//     cin >> n;
//     long long int x;
//     for(long long int i=0;i<n;i++){
//         cin >> x;
//         nums.push_back(x);
//     }
//     vector<long long int>v(10);
//     v = findKthLargest(nums,10);
// }
