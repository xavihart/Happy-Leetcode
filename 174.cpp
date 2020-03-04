class Solution {
private:
    int row, col;
    int used[100][100];
    int min_live = -1e9;
    int dir[4] = {1, 0, 0, 1};
public:
    bool valid(int x, int y){
        return (x >= 0) && (x < row) && (y >= 0) && (y < col);
    }
    void dfs(vector<vector<int>> a, int x, int y, int min_hp, int now_hp){
        if(min_hp < min_live)
            return;
        if(x == row - 1 && y == col - 1){
           // now_hp += a[x][y];
        // min_hp = min(min_hp, now_hp);
            min_live = max(min_hp, min_live);
        }
        for(int i = 0;i < 2;++i){
            int x_now = x + dir[i], y_now = y + dir[i + 2];
            if(!valid(x_now, y_now)) continue;
            if(!used[x_now][y_now]){
                used[x_now][y_now] = 1;
                int now = now_hp + a[x_now][y_now];
                dfs(a, x_now, y_now, min(min_hp, now), now);
            }
            used[x_now][y_now] = 0;
        }
        
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(used, 0, sizeof(used));
        row = dungeon.size();
        col =dungeon[0].size();
        dfs(dungeon, 0, 0, dungeon[0][0], dungeon[0][0]);
        return (min_live >= 0) ? 1 : -min_live + 1;
    }
};
