class Solution {
public:
    vector<int> getRow(int n) {
        vector<int>ans;
    long long a = 1;
    ans.push_back(a);
    for(int i = 1 ; i<=n ; i++){
        if(i==n){
            ans.push_back(1);
        } 
       else{
         a = a * (n-i+1)/i;
        ans.push_back(a);
       }
    }
    return ans;
    }
};