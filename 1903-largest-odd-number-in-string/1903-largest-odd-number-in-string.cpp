class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        // string ans = "";
        // string sum = "";
        // for(int i = 0 ; i<n ; i++){
        //     sum = sum + num[i];
        //     if((sum.back()-'0')%2==1){
        //         ans = max(sum , ans);
        //     }
        // }
        // return ans;
        for(int i = n-1 ; i>=0 ; i--){
            if((num[i]-'0')%2==1){
                return num.substr(0 , i+1);
            }
        }
        return "";
    }
};