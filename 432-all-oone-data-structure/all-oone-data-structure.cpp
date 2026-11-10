class AllOne {
private:
    struct Node {
        int count;
        std::unordered_set<std::string> keys;
        Node(int c) : count(c) {}
    };

    std::list<Node> bucketList;
    std::unordered_map<std::string, std::list<Node>::iterator> keyMap;

public:
    AllOne() {}
    
    void inc(string key) {
        if (keyMap.find(key) == keyMap.end()) {
            // Key doesn't exist. It should belong to a bucket with count 1.
            if (bucketList.empty() || bucketList.front().count > 1) {
                bucketList.push_front(Node(1));
            }
            bucketList.front().keys.insert(key);
            keyMap[key] = bucketList.begin();
        } else {
            // Key exists. Move it to the next frequency bucket.
            auto currIter = keyMap[key];
            int currCount = currIter->count;
            auto nextIter = std::next(currIter);
            
            if (nextIter == bucketList.end() || nextIter->count > currCount + 1) {
                nextIter = bucketList.insert(nextIter, Node(currCount + 1));
            }
            
            nextIter->keys.insert(key);
            keyMap[key] = nextIter;
            
            currIter->keys.erase(key);
            if (currIter->keys.empty()) {
                bucketList.erase(currIter);
            }
        }
    }
    
    void dec(string key) {
        auto currIter = keyMap[key];
        int currCount = currIter->count;
        
        currIter->keys.erase(key);
        
        if (currCount == 1) {
            keyMap.erase(key);
        } else {
            auto prevIter = (currIter == bucketList.begin()) ? bucketList.end() : std::prev(currIter);
            
            if (currIter == bucketList.begin() || prevIter->count < currCount - 1) {
                prevIter = bucketList.insert(currIter, Node(currCount - 1));
            }
            
            prevIter->keys.insert(key);
            keyMap[key] = prevIter;
        }
        
        if (currIter->keys.empty()) {
            bucketList.erase(currIter);
        }
    }
    
    string getMaxKey() {
        if (bucketList.empty()) return "";
        return *(bucketList.back().keys.begin());
    }
    
    string getMinKey() {
        if (bucketList.empty()) return "";
        return *(bucketList.front().keys.begin());
    }
};