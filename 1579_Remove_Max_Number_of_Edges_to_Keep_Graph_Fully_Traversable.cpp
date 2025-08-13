// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/

class Solution {
public:
vector<vector<int>> parent;
vector<vector<int>> rank;
int find(int u,int type){
    if(parent[u][type]==u){
        return u;
    }
    return parent[u][type]=find(parent[u][type], type);
}

void unite(int u,int v,int type){
    int U=find(u,type);
    int V=find(v,type);

    if(U==V) return;

    if(rank[U][type] > rank[V][type]){
        parent[V][type]=U;
    }
    else if(rank[U][type] < rank[V][type]){
        parent[U][type]=V;
    }
    else{
        parent[V][type]=U;
    }
}

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        parent.resize(n+1,vector<int>(2,0));
        rank.resize(n+1,vector<int>(2,0));

        for(int i=1;i<=n;++i){
            parent[i][0]=i;
            parent[i][1]=i;
        }
       
        int ans=0;
        for(auto &e : edges){
            if(e[0]==3){
                if(find(e[1],1)&&find(e[1],0) == find(e[2],0)&&find(e[2],1) ){
                    ans++;
                }
                else{
                    unite(e[1],e[2],0);
                    unite(e[1],e[2],1);
                }
            }
        }

        // for(int i=1;i<=n;++i){
        //     cout << find(i,0) << ' ';
        // }
        // cout << '\n';
        // for(int i=1;i<=n;++i){
        //     cout << find(i,1) << ' ';
        // }
        for(auto &e : edges){
            if(e[0]!=3){
                if(find(e[1],e[0]-1) == find(e[2],e[0]-1)){
                    ans++;
                }
                else{
                    unite(e[1],e[2],e[0]-1);
                }
            }
        }
        // for(int i=1;i<=n;++i){
        //     cout << find(i,1) << ' ';
        // }
        set<int> st1,st2;
        for(int i=1;i<=n;++i){
            st1.insert(find(i,0));
            st2.insert(find(i,1));
        }
        if(st1.size()==1 && st2.size()==1){
            return ans;
        }
        return -1;
    }
};
