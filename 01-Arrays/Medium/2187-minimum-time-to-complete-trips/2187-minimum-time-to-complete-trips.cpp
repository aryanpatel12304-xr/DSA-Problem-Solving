class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        long long s = *min_element(time.begin() , time.end());
        long long e =   s * totalTrips;
        long long ans = LLONG_MAX;
        while(s<=e){
            long long mid = s + (e-s)/2;
            long long sum = 0;
            for(int i = 0 ; i<n ; i++){
                long long d = mid / time[i];
                sum = sum + d;
                if(sum>=totalTrips){
                    break;
                }

            }
            if(sum>=totalTrips){
                ans = min(ans , mid);
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
            
        }
        return ans;
    }
};