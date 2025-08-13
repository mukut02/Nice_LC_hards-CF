// Q: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/
// total even, odd computation using two dfs call 
// Good learning and insights tobe taken from this Q
class Solution {
private:
vector<vector<int>> adj1,adj2;
vector<int> evenSub1,oddSub1;
vector<int> evenSub2,oddSub2;
vector<int> evenTot1,oddTot1;
vector<int> evenTot2,oddTot2;

public:
void dfs11(int node,int parent){
    evenSub1[node] = 1;
    oddSub1[node] = 0;
    for(int child : adj1[node]){
        if(child != parent){
            
            dfs11(child, node);
            evenSub1[node]+=oddSub1[child];
            oddSub1[node]+=evenSub1[child];
        }
    }
}

void dfs12(int node,int parent,int evenUp, int oddUp){
    evenTot1[node] = evenSub1[node] + evenUp;
    oddTot1[node] =oddSub1[node] + oddUp;
    for(int child : adj1[node]){
       if(child!=parent){
          
          int childEUp = oddTot1[node] - evenSub1[child];
          int childOUp = evenTot1[node] - oddSub1[child];
          dfs12(child, node, childEUp, childOUp);    
       }
    }
}


void dfs21(int node,int parent){
    evenSub2[node] = 1;
    oddSub2[node] = 0;
    for(int child : adj2[node]){
        if(child != parent){

            dfs21(child, node);
            evenSub2[node]+=oddSub2[child];
            oddSub2[node]+=evenSub2[child];
        }
    }
}

void dfs22(int node,int parent,int evenUp, int oddUp){
    evenTot2[node] = evenUp + evenSub2[node];
    oddTot2[node]  = oddUp + oddSub2[node];

    for(int child : adj2[node]){
        if(child!=parent){
            int childEUp = oddTot2[node] - evenSub2[child];
            int childOUp = evenTot2[node] - oddSub2[child];

            dfs22(child, node, childEUp, childOUp);
        }
    }
}
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1=edges1.size() + 1;
        int n2=edges2.size() + 1;
        adj1.resize(n1);
        adj2.resize(n2);
        
        evenSub1.resize(n1);
        oddSub1.resize(n1);

        evenSub2.resize(n2);
        oddSub2.resize(n2);

        evenTot1.resize(n1);
        oddTot1.resize(n1);

        evenTot2.resize(n2);
        oddTot2.resize(n2);



        for(auto &e : edges1){
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }

        for(auto &e : edges2){
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }
        dfs11(0, -1);
        dfs21(0, -1);
        
        dfs12(0, -1,0,0);
        dfs22(0, -1,0,0);
        // for(int i=0;i<n1;++i){
        //     cout << i << ' ' << evenSub1[i] << ' ' << oddSub1[i] << '\n';
        // }
        // for(int i=0;i<n2;++i){
        //     cout << i << ' ' << evenSub2[i] << ' ' << oddSub2[i] << '\n';
        // }
        // for(int i=0;i<n1;++i){
        //     cout << i << ' ' << evenTot1[i] << ' ' << oddTot1[i] << '\n';
        // }
        // for(int i=0;i<n2;++i){
        //     cout << i << ' ' << evenTot2[i] << ' ' << oddTot2[i] << '\n';
    
        int maxNode2=0;

        for(auto &x : oddTot2){
            maxNode2=max(maxNode2, x);
        }
        vector<int> ans(n1);
        
        for(int i=0;i<n1;++i){
            ans[i] = evenTot1[i] + maxNode2;
        }

        return ans;
    }
};
