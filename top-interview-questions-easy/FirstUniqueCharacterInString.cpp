class Solution {
public:
    int firstUniqChar(string s) {
        static const auto io_sync = []{
            std::ios::sync_with_stdio(false);
            std::cin.tie(nullptr);
            return nullptr;
        }();
        
        unordered_map<char, int> repVal;
        for(auto c : s)
        {
            repVal[c]++;
        }
        for(int i = 0;i<s.size();++i)
        {
            if(repVal[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
