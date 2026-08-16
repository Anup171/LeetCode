class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> checkinmap;
    unordered_map<string,pair<int,int>> timestamp;
    UndergroundSystem() {
    }
    void checkIn(int id, string stationName, int t) {
        checkinmap[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto [startStation,startTime]=checkinmap[id];
        string route=startStation+"#"+stationName;
        timestamp[route].first+=(t-startTime);
        timestamp[route].second++;
        checkinmap.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route=startStation+"#"+endStation;
        auto[totalTime,trips]=timestamp[route];
        return (double)totalTime/trips;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */