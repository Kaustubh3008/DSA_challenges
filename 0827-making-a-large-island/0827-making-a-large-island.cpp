class disjointSet{
public: 
    vector<int> rank,parent,size;
    disjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }
    //Path Compression
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }
    //Unoin By Rank
    void Union_By_Rank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    //Unoin By Size
    void Union_By_Size(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjointSet ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                for(int i=0;i<4;i++){
                    int newr= row+dr[i];
                    int newc= col+dc[i];
                    if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc] ==1){
                        int nodeNo= row*n+col;
                        int adjNodeNo= newr*n+newc;
                        ds.Union_By_Size(nodeNo,adjNodeNo);
                    }
                }
            }
        }
        int mx =0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                set<int> components;
                for(int i=0;i<4;i++){
                    int newr= row+dr[i];
                    int newc= col+dc[i];
                    if(newr>=0 && newr<n && newc>=0 && newc<n){
                        if(grid[newr][newc] ==1){
                            components.insert(ds.findUPar(newr*n+newc));
                        }
                    }
                }
                int totalsize =0;
                for(auto it : components){
                    totalsize+= ds.size[it];
                }
                mx = max(mx,totalsize+1);
            }
        }
        for(int cellNo =0; cellNo<n*n;cellNo++){
            mx = max(mx,ds.size[ds.findUPar(cellNo)]);
        }
        return mx;
    }
};