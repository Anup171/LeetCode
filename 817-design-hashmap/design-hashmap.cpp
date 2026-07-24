class MyHashMap {
public:
    vector<vector<pair<int,int>>> table;
    int size=1000;
    MyHashMap() {
        table.resize(size);
    }
    void put(int key, int value) {
        int index=key%size;
        for(auto &p:table[index]){
            if(p.first==key){
                p.second=value;
                return;
            }
        }
        table[index].push_back({key,value});
    }
    
    int get(int key) {
        int index=key%size;
        for(auto &p:table[index]){
            if(p.first==key){
                return p.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int index = key % size;
        for (int i = 0; i < table[index].size(); i++) {
            if (table[index][i].first == key) {
                table[index].erase(table[index].begin() + i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */