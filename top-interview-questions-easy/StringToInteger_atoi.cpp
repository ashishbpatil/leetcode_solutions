class Solution {
public:
    int myAtoi(string s) {
        bool negFlag = false;
        long ret = 0;
        int i=0;
        for(; i<s.size();++i)
        {
            if(s[i] == ' ')
            {
                continue;
            }else if(s[i] == '-')
            {
                ++i;
                negFlag = true;
                break;
            }else if(s[i] == '+')
            {
                ++i;
                break;
            }else if(s[i] >= '0' && s[i] <= '9'){
                break;
            }else{
                return 0;
            }
        }
        for(; i<s.size();++i)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                ret = (ret * 10) + (s[i] - '0');
                if(ret > numeric_limits<int>::max())
                {
                    return (negFlag) ? numeric_limits<int>::min() : numeric_limits<int>::max();
                }
            }else{
                break;                 
            }       
        }
        return (negFlag) ? ret*-1 : ret;
    }
};
