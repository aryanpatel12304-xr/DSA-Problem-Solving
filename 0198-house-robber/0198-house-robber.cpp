class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        int y = 0;

        for(int money : nums){
            int current  = max(x , y + money );
            y = x;
            x = current;
        }
        return x;
    }
};