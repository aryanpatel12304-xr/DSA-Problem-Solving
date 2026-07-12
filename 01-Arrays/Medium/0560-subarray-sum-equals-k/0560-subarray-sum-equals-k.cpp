class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int ans = 0;
        // for(int i = 0  ; i<nums.size() ; i++){
        //     long long sum = 0;
        //     for(int j = i ; j<nums.size() ; j++){
        //         sum = sum + nums[j];
        //         if(sum==k){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;

        //****Optimal**********
        int count = 0;
        vector<int>ans;
        int sum = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            sum = sum + nums[i];
            ans.push_back(sum);
        }
        unordered_map<int,int>m;
        for(int i = 0 ; i<ans.size() ; i++){
            if(ans[i]==k){
                count++;
            }
            int val =ans[i] - k;
            if(m.find(val)!=m.end()){
                count = count + m[val];
            }
          
            m[ans[i]]++;
        }
        return count;
    }
};