class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
     vector<int>p;
     vector<int>n;

    for(int i = 0 ; i<nums.size() ; i++){
        if(nums[i]>=0){
            p.push_back(nums[i]);
        }
        else{
            n.push_back(nums[i]);
        }
    }

    vector<int>ans(nums.size());
    int x = 0;
    int y = 0;
    for(int i = 0 ; i<nums.size() ; i=i+2){
        ans[i] = p[x];
        x++;
    }
     for(int i = 1 ; i<nums.size() ; i=i+2){
        ans[i] = n[y];
        y++;
    }
    return ans;

    }
};