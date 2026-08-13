class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
      int n = piles.size();
      int s = 1;
      int e = *max_element(piles.begin() , piles.end());
      int ans = -1;
      while(s<=e){
        int mid = s + (e-s)/2;
        long long sum = 0;
        for(int i = 0 ; i<n ; i++){
            int t = (piles[i]+mid-1)/mid;
            sum = sum + t;
        }
        if(sum<=h){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
      }
      return ans;
    }
};