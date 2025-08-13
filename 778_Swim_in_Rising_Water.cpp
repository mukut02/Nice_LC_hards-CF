// https://leetcode.com/problems/swim-in-rising-water/description/
// BS + BFS 
class Solution {
public:
bool check(int time,vector<vector<int>>& grid){
    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};
    int n=grid.size();
    queue<pair<int,int>> q;
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    q.push({0, 0});
    vis[0][0]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;

        q.pop();
        cout << x << ' ' << y << '\n';
        for(int t=0;t<4;++t){
            int nx = x+dx[t];
            int ny = y+dy[t];
            
            if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]<=time && !vis[nx][ny]){
                // cout << nx << ' ' << ny << '\n';
                vis[nx][ny]=1;
                q.push({nx, ny});
            }
        }
        if(x==n-1 && y==n-1){
            return true;
        }
    }
    return false;
}
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int l=grid[0][0], r=n*n;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(check(mid, grid)){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }

        return l;
    }
};
