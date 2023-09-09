class DisjointSet
{
    public : 
    vector<int> usize , parent;
    
    DisjointSet(int n)
    {
        usize.resize(n+1);
        parent.resize(n+1);
        
        for(int i = 0 ; i<=n;i++)
        {
            usize[i] =1 ;
            parent[i] =i;
        }
    } 
    
    int findUP(int n)
    {
        if(parent[n] == n)
        {
            return n;
        }
        else
        {
            return parent[n] = findUP(parent[n]);
        }
    }
    
    void UnionBySize(int u , int v)
    {
        int ultp_u = findUP(u);
        int ultp_v = findUP(v);
        
        if(ultp_u == ultp_v)
            return;
        else if(usize[ultp_u] > usize[ultp_v])
        {
            parent[ultp_v] = ultp_u;
            usize[ultp_u] += usize[ultp_v];
        }
        else
        {
            parent[ultp_u] = ultp_v;
            usize[ultp_v] += usize[ultp_u];
        }
    }
};
class Solution {
  public:
    int makeConnected(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        
        int m = edge.size();
        
        int extraedges = 0;
        
        
        for(int i=0;i<m;i++)
        {
            int u = edge[i][0];
            int v = edge[i][1];
            
            if(ds.findUP(u)==ds.findUP(v))
            {
                extraedges++;
            }
            else
            {
                ds.UnionBySize(u,v);
            }
        }
        
        int operations = -1;
        
        for(int i=0;i<n ;i++)
        {
            if(ds.parent[i]==i)
            {
                operations++;
            }
        }
        
        return operations<=extraedges?operations:-1;
    }
};