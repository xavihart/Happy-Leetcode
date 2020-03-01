class Solution {
public:
    int l[2005] = {0};
    int c[2005] = {0};
    int findNumberOfLIS(vector<int>& nums) {
        l[0] = 1;
        c[0] = 1;
        for(int i = 1;i < nums.size();++i){
            vector<pair<int,int>> numbers;
            int f=0;
            for(int j = 0;j < i;++j){
                if(nums[i] > nums[j]){
                    numbers.push_back(make_pair(l[j] + 1, c[j]));
                    f=1;
                }
            }
            if(!f){
                l[i] = 1;
                c[i] = 1;
                continue;
            }
            int max_len=-1;
            for(int j = 0;j < numbers.size();++j){
                max_len = max(max_len, numbers[j].first);
            }
            int counts = 0;
            for(int j = 0;j < numbers.size();++j){
                if(numbers[j].first == max_len){
                    counts += numbers[j].second;
                }
            }
            c[i] = counts;
            l[i] = max_len;
        }
      
     
        int max_=-1;
        int ans=0;
        for(int i = 0;i < nums.size();++i)
            max_ = max(l[i], max_);
        for(int i = 0;i < nums.size();++i)
            if(l[i] == max_)
                ans = ans + c[i];
        return ans;
               
    }
};
