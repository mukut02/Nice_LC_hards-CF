// https://leetcode.com/problems/similar-string-groups/
class Solution {
public:
class DSU{
public:
    vector<int> parent,size;
    DSU(int n){
        size.resize(n);
        parent.resize(n);
        for(int i=0;i<n;++i){
            parent[i]=i;
        }
    }

    int find(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=find(parent[u]);
    }

    void unite(int u,int v){
        int U=find(u),V=find(v);
        if(U==V) return;
        if(size[U] < size[V]) swap(U,V);
        size[U]+=size[V];
        parent[V]=U;
    }
};
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        DSU dsu(n);
        int l=strs[0].size();
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                vector<int> pos;
                for(int k=0;k<l;++k){
                   if(strs[i][k]!=strs[j][k]){
                    pos.push_back(k);
                   }
                   if(pos.size()>2) break;
                }
                if(pos.size()==0){
                    dsu.unite(i,j);
                }
                if(pos.size()==2){
                    string temp=strs[i];
                    // cout << pos[0] << ' ' << pos[1] << '\n';
                    swap(temp[pos[0]], temp[pos[1]]);
                    if(temp==strs[j]){
                        dsu.unite(i,j);
                    }
                }
            }
        }
        set<int> st;

        for(int i=0;i<n;++i){
            st.insert(dsu.find(i));
        }
        return st.size();
    }
};
