class TimeMap {
private:
    // Key: string -> Value: Vector of {timestamp, value}
    // The vector is naturally sorted by timestamp because 'set' is called in increasing order.
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // If key doesn't exist, return empty
        if (store.find(key) == store.end()) {
            return "";
        }

        // Reference to the sorted vector
        auto& values = store[key];

        // Binary Search for the rightmost value with time <= timestamp
        int left = 0;
        int right = values.size() - 1;
        string result = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (values[mid].first <= timestamp) {
                // This is a valid candidate (time is valid)
                result = values[mid].second;
                // Try to find a more recent one (move right)
                left = mid + 1;
            } else {
                // This timestamp is in the future (too big)
                // Move left
                right = mid - 1;
            }
        }

        return result;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */