class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int i;
        for(i = citations.size() - 1;i > -1;--i){
            if(citations[i] < citations.size() - i)
              break;
        }
        return citations.size() - i - 1;
    }
};
