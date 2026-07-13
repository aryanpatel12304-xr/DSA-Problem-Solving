class Solution {
public:
    vector<vector<int>> generate(int n) {
     vector<vector<int>>final_ans;
     for(int i = 0 ; i<n ; i++){
        vector<int>ans;
        long long x = 1;
        ans.push_back(x);
        for(int j = 1 ; j<=i ; j++){
            x = x * (i+1-j)/j;
            ans.push_back(x);
        }
        final_ans.push_back(ans);
     }
     return final_ans;
    }
};