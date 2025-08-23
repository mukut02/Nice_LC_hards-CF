//https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/description/
// dp with bitmasking idea
// reverse the data ppl -> hat , make it hat -> ppl
// now bitmask on ppl -> whether wearing a hat or not (1 -> yes, 0 -> no)
class Solution {
public:
map<int,vector<int>> mpp;
#define MOD 1000000007
int n;
vector<vector<int>> dp;
int f(int mask,int i){
   if(dp[mask][i]!=-1) return dp[mask][i];
   if(mask == ((1<<n)-1)) return dp[mask][i]=1;
   if(i==41) return dp[mask][i]=0;

   int ans=f(mask,i+1);
   for(auto &p : mpp[i]){
        int set = (1<<p)&mask;
        if(!set){
            ans+=f(mask|(1<<p),i+1)%MOD;
            ans%=MOD;
        }
    }
   return dp[mask][i]=ans;
}
    int numberWays(vector<vector<int>>& hats) {
        n=hats.size();
        for(int p=0;p<n;++p){
            for(auto &hat : hats[p]){
                mpp[hat].push_back(p);
            }
        }
        dp.resize((1<<n), vector<int>(42,-1));
        return f(0,1);
    }
};
