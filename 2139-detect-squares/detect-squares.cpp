class DetectSquares {
public:
    map<pair<int,int>,int> freq;
    DetectSquares() { 
    } 
    void add(vector<int> point) {
        freq[{point[0],point[1]}]++;
    }
    int count(vector<int> point) {
        int x=point[0];
        int y=point[1];
        int ans=0;
        for(auto ele:freq){
            int x2=ele.first.first;
            int y2=ele.first.second;
            if(abs(y2 - y) != abs(x2 - x) || x == x2 || y == y2){
                continue;
            }
            ans+=ele.second*freq[{x,y2}]*freq[{x2,y}];
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */