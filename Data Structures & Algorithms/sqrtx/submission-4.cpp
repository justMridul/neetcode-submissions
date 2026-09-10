class Solution {
public:
    int mySqrt(int x) {
          if (x < 2) return x; 
        int low = 1;
        int high = x / 2;

     while(low <= high){
        long long mid = low + (high - low) / 2; // Use long long
        long long num = mid * mid;              // Safely stores large values

        if (num == x) return mid;
        else if (num > x) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
     return high;
    }
};