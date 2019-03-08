class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if (n <= 1) return true;
        unordered_set<int> keys;
        queue<int> currentKeys;
        currentKeys.push(0);
        keys.insert(0);

        while(!currentKeys.empty()) {
            for (auto k: rooms[currentKeys.front()]) {
                if (keys.count(k) == 0) {
                    currentKeys.push(k);
                    keys.insert(k);
                }
            }
            currentKeys.pop();
        }
        
        return keys.size() == n;
    }
};
