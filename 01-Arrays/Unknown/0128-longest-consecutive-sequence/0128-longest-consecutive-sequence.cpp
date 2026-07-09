class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        unordered_set<int>st(nums.begin() , nums.end());
        int ans = 1;

        for(auto it : st){
            if(st.find(it-1)==st.end()){
                int count = 1;
                int x = it;
                 while(st.find(x+1) != st.end()){
                x++;
                count++;
            }
             ans = max(ans , count);
            }
           
           
        }
        return ans;
    }
};