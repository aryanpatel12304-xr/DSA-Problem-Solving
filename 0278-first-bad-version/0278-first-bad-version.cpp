// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

// The API isBadVersion is already defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid;   // bad version found, search left side
            } else {
                left = mid + 1; // still good, search right side
            }
        }
        return left; // left == right, first bad version
    }
};
