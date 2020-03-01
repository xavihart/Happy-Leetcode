class Solution {
public:
    void disp(vector<int> a){
        for(int i = 0;i < a.size();++i)
            cout << a[i] << " ";
        cout << "\n";
    }
    string largestMultipleOfThree(vector<int>& digits) {
        sort(digits.begin(), digits.end(), [](int a, int b){return  b < a;});
        //disp(digits);
        string k;
        int len = digits.size();
        for(int i = 0;i < len;++i){
            k.push_back('0' + digits[i]);
        }
        for(int i = 0;i < len;++i){
            digits[i] %= 3;
        }
        int tot = 0;
        for(int i = 0;i < len;++i)
            tot = tot + digits[i];
       
        if (tot % 3 == 0){
            if(k[0] == '0')
                k = "0";
            return k;
        }
        
        
        if(tot % 3 == 1){
            int f = 0;
            for(int i = len - 1;i >= 0;--i){
                if(digits[i] == 1){
                    k.erase(i, 1);
                    f = 1;
                    break;
                }
            }
            if (f){
                return k;
            }else{
                int a=-1, b=-1, num = 0;
               for(int i = len - 1;i >= 0;--i){
                    if(digits[i] % 3 == 2){
                        if(num == 0){
                            num ++;
                            a = i;
                        }else{
                            num ++;
                            b = i;
                            break;
                        }
                    }   
               }
                if (num != 2){
                    string k_ = "";
                    return k_;
                }else{
                    k.erase(a, 1);
                    k.erase(b, 1);
                    return k;
                }
            }
                
        }
        if(tot % 3 == 2){
            int f = 0;
            for(int i = len - 1;i >= 0;--i){
                if(digits[i] == 2){
                    k.erase(i, 1);
                    f = 1;
                    break;
                }
            }
            if (f){
                return k;
            }else{
                int a=-1, b=-1, num = 0;
               for(int i = len - 1;i >= 0;--i){
                    if(digits[i] % 3 == 1){
                        if(num == 0){
                            num ++;
                            a = i;
                        }else{
                            num ++;
                            b = i;
                            break;
                        }
                    }   
               }
                if (num != 2){
                    string k_ = "";
                    return k_;
                }else{
                    k.erase(a, 1);
                    k.erase(b, 1);
                    return k;
                }
            }
        }
            
        
        return k;
    }
};
