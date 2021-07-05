class LRUCache {
    struct node{
        int key;
        int val;
        node(int k, int v) : key(k), val(v) {}
    };
    
    list<node> LRU;
    unordered_map<int, list<node>::iterator> Hash;
    int CSize;
    
public:
    LRUCache(int capacity) {
        CSize = capacity;
    }
    
    int get(int key) {
        // cout << "Get" << key << endl;
        if(Hash.find(key) != Hash.end())
        {
            auto n = Hash[key];
            Hash.erase(key);
            node ans = *n;
            LRU.erase(n);
            LRU.push_front(ans);
            Hash[key] = LRU.begin();
            return ans.val;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        // cout << key << "->" << value << endl;
        if(Hash.find(key) != Hash.end())
        {
            // cout << key << " e->" << value << endl;
            LRU.erase(Hash[key]);
            Hash.erase(key);
        }
        if(Hash.size() >= CSize)
        {
            Hash.erase(LRU.back().key);
            // cout << "erase" << endl;
            LRU.pop_back();
        }
        LRU.push_front(node(key, value));
        Hash[key] = LRU.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
