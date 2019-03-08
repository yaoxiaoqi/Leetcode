class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<int> buckets;
    MyHashSet() {
        buckets.resize(1000001, 0);
    }
    
    void add(int key) {
        buckets[key] = 1;
        return;
    }
    
    void remove(int key) {
        buckets[key] = 0;
        return;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return buckets[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
