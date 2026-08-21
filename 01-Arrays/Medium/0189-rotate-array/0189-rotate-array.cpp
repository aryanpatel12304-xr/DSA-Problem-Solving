class Solution {
public:
    void rotate(vector<int>& nums, int k) {  
    int t = k % nums.size();
    reverse(nums.begin() , nums.end());
    reverse(nums.begin() , nums.begin()+t);
    reverse(nums.begin()+t , nums.end());
    }
};