class Solution {
public:
    int minDays(vector<int>& bloom, int m, int k) {
       int n = bloom.size();
      long long pro = 1LL * m * k;
       if(pro>n){
        return -1;
       }
       int s = *min_element(bloom.begin() , bloom.end());
       int e = *max_element(bloom.begin() , bloom.end());
       int ans = -1;
       while(s<=e){
        int mid = s + (e-s)/2;
        int count = 0;
        int m_count = 0;
        for(int i = 0 ; i<n ; i++){
            if(bloom[i]<=mid){
                count++;
            }
            else{
                count = 0;
            }
            if(count == k){
                m_count++;
                count = 0;
            }
        }

        if(m_count>=m){
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