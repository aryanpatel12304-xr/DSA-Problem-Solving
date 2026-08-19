class Solution {
public:
    int shipWithinDays(vector<int>& w, int days) {
        int n = w.size();
        int s = *max_element(w.begin() , w.end());
        int _sum = 0;
        for(int i = 0 ; i<n ; i++){
            _sum = _sum + w[i];
        }
        int e = _sum;
        int ans = 0;
        while(s<=e){
            int mid = s + (e-s)/2;
            int d = 1;
            int sum = 0;
            for(int i = 0 ;  i<n ; i++){
                if(sum + w[i] > mid){
                    d++;
                    sum = w[i];
                }
                else{
                    sum = sum + w[i];
                }
            }
            if(d<=days){
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