class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int sum = 0;
        for(int i = 0 ; i<n ; i++){
            if(s[i]=='I'){
                if(i+1<n && s[i+1]=='V' || s[i+1] == 'X'){
                    sum = sum - 1;
                }
               else{
                 sum = sum + 1;
               }
            }
            if(s[i]=='V'){
                sum = sum + 5;
            }
              if(s[i]=='X'){
                if(i+1<n && s[i+1]=='L' || s[i+1]=='C'){
                    sum = sum - 10;
                }
                else{
                    sum = sum + 10;
                }
            }
              if(s[i]=='L'){
                sum = sum + 50;
            }
              if(s[i]=='C'){
               if(i+1<n && s[i+1]=='D' || s[i+1] == 'M'){
                sum = sum  - 100;
               }
               else{
                 sum = sum + 100;
               }
            }
              if(s[i]=='D'){
                sum = sum + 500;
            }
              if(s[i]=='M'){
                sum = sum + 1000;
            }
        
        }
        return sum;
    }
};