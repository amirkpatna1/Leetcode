class UndergroundSystem {
public:
    unordered_map<string,unordered_map<string,pair<int,int>>> mp;
    unordered_map<int,pair<string,int>> idStringMap;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        idStringMap[id].first=stationName;
        idStringMap[id].second=t;
    }
    
    void checkOut(int id, string stationName, int t) {
        mp[idStringMap[id].first][stationName].first+=t-idStringMap[id].second;
        mp[idStringMap[id].first][stationName].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return mp[startStation][endStation].first/(mp[startStation][endStation].second*1.0);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */