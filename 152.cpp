class Solution {
public:
    int t_max(int a, int b, int c){
        if(a >= b && a >= c)
            return a;
        if(b >= a && b >= c)
            return b;
        return c;
    }
    int max_prod(vector<int> a,int l, int r){
        if(l == r)
            return a[l];
        if(r - l == 1)
            return t_max(a[l], a[r], a[l] * a[r]);
        int mid = (l + r) >> 1;
        int l_p=a[mid], l_n=a[mid], r_p=a[mid+1], r_n=a[mid+1];
        int l_now = 1, r_now = 1;
        for(int i = mid;i >= l;--i){
           l_now *= a[i];
           l_p = max(l_now, l_p);
           l_n = min(l_now, l_n);
        } 
        for(int i = mid+1;i <= r;++i){
            r_now *= a[i];
            r_p = max(r_p, r_now);
            r_n = min(r_n, r_now);
        }
        int max_ = max(max(l_p * r_n, l_n * r_p), max(l_p * r_p, l_n * r_n));
        //cout <<l<<" " << r<< max_ << " ";
        int ans =  t_max(max_, max_prod(a, l, mid), max_prod(a, mid + 1, r));
        //cout << l << " " << r << " " << ans<<endl;
        return ans;
    }
    int maxProduct(vector<int>& nums) {
       return max_prod(nums, 0, nums.size() - 1); 
    }
};
