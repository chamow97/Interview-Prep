class UndergroundSystem {
public:
    map<int, string> idToStation;
    map<int, int> idToInTime;
    map< pair<string, string>, int > totalTime;
    map< pair<string, string>, int > total;
    UndergroundSystem() {
        idToStation.clear();
        idToInTime.clear();
        totalTime.clear();
        total.clear();
    }
    
    void checkIn(int id, string stationName, int t) {
        if(idToInTime[id] == 0 || idToInTime[id] == -1) {
            idToStation[id] = stationName;
            idToInTime[id] = t;   
        }
    }
    
    void checkOut(int id, string stationName, int t) {
        int diff = t - idToInTime[id];
        string st = idToStation[id];
        idToInTime[id] = -1;
        idToStation[id] = stationName;
        totalTime[make_pair(st, stationName)] += diff;
        total[make_pair(st, stationName)] += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        double currVal = (double)((totalTime[make_pair(startStation, endStation)] * 1.00) / (total[make_pair(startStation, endStation)] * 1.00));
        return currVal;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
