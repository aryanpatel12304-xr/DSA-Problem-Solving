class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        long long ans = 0;
        int sign = 1;

        while(i < n && s[i] == ' ') {
            i++;
        }

        if(i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if(i < n && s[i] == '+') {
            sign = 1;
            i++;
        }

        while(i < n && s[i] >= '0' && s[i] <= '9') {
            int digi = s[i] - '0';

            long long limit;

            if(sign == 1)
                limit = 2147483647;
            else
                limit = 2147483648LL;

            if(ans > limit / 10 || (ans == limit / 10 && digi > limit % 10)) {
                if(sign == 1)
                    return 2147483647;
                else
                    return -2147483648LL;
            }

            ans = ans * 10 + digi;
            i++;
        }

        return ans * sign;
    }
};