class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int>dummy(arr.begin() , arr.end());
        vector<int>ans;
        int n = arr.size();
        int e = arr[n-1] + k;
        for(int i = 1 ; i<=e ; i++){
            if(find(dummy.begin() , dummy.end() , i ) ==dummy.end()){
                ans.push_back(i);
            }
        }
        return ans[k-1];
    }
};