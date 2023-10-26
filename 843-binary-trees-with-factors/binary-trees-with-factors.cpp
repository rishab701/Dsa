class Solution {
public:
    int MOD=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        unordered_map<int,long long int>umap;
        umap[arr[0]]=1;
        for(int i=1;i<n;i++){
            long long  root=arr[i];
            umap[root]=1;
            for(int j=0;j<i;j++){
                long long LC = arr[j];
                if(root % LC == 0 && umap.find(root / LC) != umap.end()){
                   umap[root] += umap[LC] * umap[root / LC];
                }
            }
        }
        long long res=0;
        for(auto it:umap){
            res+=it.second;
        }
        return res % MOD;
    }
};