class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 0) return false;
        if((n & 1) == 0) return false;
        // as 3 is prime number 3^19 always divisible by 3^1..18
        return (1162261467 % n == 0);
    }
};
