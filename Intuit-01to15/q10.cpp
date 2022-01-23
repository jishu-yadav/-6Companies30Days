class Solution {
public:
    vector<int> root;
    vector<int> rank;
    
	//path compression
    int find(int x){
        if(x==root[x])
            return x;
        return root[x]=find(root[x]);
    }
    
	//union by rank
    void unioni(int x, int y){
        int rx=find(x);
        int ry=find(y);
        if(rx!=ry){
            if(rank[rx]>rank[ry])
                root[ry]=rx;
            else if(rank[rx]<rank[ry])
                root[rx]=ry;
            else{
                root[ry]=rx;
                rank[rx]++;
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isc) {
        int n=isc.size();
        if(n==1) return 1;
        root.resize(n);
        rank.resize(n);
        
        for(int i=0; i<n; i++){
            root[i]=i;
            rank[i]=1;
        }
        
		//covering the upper triangular matrix  so that each pair is checked once
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if(isc[i][j])
                    unioni(i,j);
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(root[i]==i)
                ans++;
        }
        
        return ans;
    }
};
