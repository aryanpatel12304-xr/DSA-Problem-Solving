class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int ans = 1;
        int count = 1;
        set<int>st(nums.begin() , nums.end());
        vector<int>arr(st.begin() , st.end());
        sort(arr.begin() , arr.end());
          if(arr.size()==0){
                return 0;
            }
        for(int i = 1 ; i<arr.size() ; i++){
            if(arr[i]-arr[i-1]==1){
                count++;
                if(count>ans){
                    ans = count;
                }
            }
            else{
                count = 1;
            }
        }
        return ans;
    }
};