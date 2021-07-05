class Solution {
public:
    int reverse(int x) {
        long retVal = 0;
        while(x != 0)
        {
            retVal = (retVal * 10) + (x%10);
            x /= 10;
        }
        return (numeric_limits<int>::min() > retVal || retVal > numeric_limits<int>::max()) ? 0 : (int)retVal;         
    }
};
