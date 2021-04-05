class UndergroundSystem {
public:
    using Start = pair <string, int>;
    using StartEnd = pair <string, string>;
    using SumAndAmount = pair <int, int>;

    struct StartEndHash {
        int operator() (const StartEnd& x) const{
            return hash <string> () (x.first + x.second);
        }
    };

    unordered_map <int, Start> startInfo;
    unordered_map <StartEnd, SumAndAmount, StartEndHash> table;
    
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        startInfo[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto startTime = startInfo[id].second;
        table[{startInfo[id].first, stationName}].first += t - startTime;
        table[{startInfo[id].first, stationName}].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto sum = table[{startStation, endStation}].first;
        auto amount = table[{startStation, endStation}].second;
        return double(sum) / amount;
    }
};
