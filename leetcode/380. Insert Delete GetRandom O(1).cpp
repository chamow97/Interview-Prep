class RandomizedSet {
private:
    vector<int> arr;
    unordered_map<int, int> m;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        arr.resize(0);
        m.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val) != m.end()) {
            return false;
        }
        arr.push_back(val);
        m[val] = arr.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        // get the last element
        if(m.find(val) == m.end()) {
            return false;
        }
        int lastElementVal = arr[arr.size() - 1];
        arr[m[val]] = lastElementVal;
        m[lastElementVal] = m[val];
        m.erase(val);
        arr.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
