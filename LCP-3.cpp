class Solution {

public:
    int cango(string command, int x, int y){
        int x_u=0, y_u=0;
        for(int i = 0;i < command.length();++i){
            if(command[i] == 'U')
                y_u ++;
            else 
                x_u ++;
        }
        int times = min(x / x_u, y / y_u);
        int x_start = times * x_u, y_start = times * y_u;
        int t = 0;
        while(1){
            if(x_start > x || y_start > y){
                return -1;
            }else{
                if(x_start == x && y_start == y)
                    return times * command.length() + t;
                char c = command[t % command.length()];
                if(c == 'U')
                    y_start ++;
                else 
                    x_start ++;
                t++;
            }
        }
    }
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        int t = cango(command, x, y);
        if(t < 0){ 
            return 0;
        }else{
            for(int i = 0;i < obstacles.size();++i){
                int k = cango(command, obstacles[i][0], obstacles[i][1]);
                if (k < 0) continue; 
                if(k < t)
                    return 0;
            }
        }
        return 1;
    }
};
