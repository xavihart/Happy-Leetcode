class Solution {
private:
    bool used[100];
    vector<vector<int>> ans;
public:
    void dfs(vector<int>& nums, vector<int> now){
        if (now.size() == nums.size()){
            ans.push_back(now);
            return;
        }
        for(int i = 0;i < nums.size();++i){
            if(used[i] == 1)
                continue;
            if(used[i] == 0){
                used[i] = 1;
                now.push_back(nums[i]);
                dfs(nums, now);
            }
            used[i] = 0;
            now.pop_back();
        }
        return ;
        
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> a;
        memset(used, 0, sizeof(used));
        dfs(nums,a);
        return ans;
    }
};
