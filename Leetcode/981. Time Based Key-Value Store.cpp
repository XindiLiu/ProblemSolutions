struct stamped_key {
    string key;
    int timestamp;
    const bool operator < (const stamped_key& a)const { return key == a.key ? timestamp < a.timestamp : key < a.key; }
    const bool operator > (const stamped_key& a)const { return key == a.key ? timestamp > a.timestamp : key > a.key; }

};
class TimeMap {
public:
    map<stamped_key, string, less<stamped_key>> timemap;
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        timemap[stamped_key({key, timestamp})] = value;
    }

    string get(string key, int timestamp) {
        auto a = (timemap.upper_bound(stamped_key({key, timestamp})));
        if (a == timemap.begin()) {
            return "";
        }
        --a;
        if (a->first.key != key) {
            return "";
        }
        return a->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */