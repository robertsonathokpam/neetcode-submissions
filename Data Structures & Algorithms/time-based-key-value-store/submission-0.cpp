class TimeMap {
public:
    unordered_map<string,map<int, string>> mp;
    TimeMap() {}

    void set(string key, string v, int t) { 
        mp[key].insert({t, v});
        }

    string get(string key, int z) {
        if (mp.count(key)) {
            auto it=mp[key].upper_bound(z);
            if(it==mp[key].begin()){
                return "";
            }else{
               return  prev(it)->second;
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */