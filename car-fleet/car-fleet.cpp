class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> carPos(position.size());
        for (int i = 0; i < carPos.size(); i++) {
            carPos[i].first = position[i];
            carPos[i].second = speed[i];
        }
        
        //Reverse Sorted Order
        sort(carPos.begin(), carPos.end(), greater<pair<int, int>>());
        
        int fleet = 1;
        double lastHour = (target - carPos[0].first) * 1.0 / carPos[0].second;
        
        for (int i = 1; i < carPos.size(); i++) {
            double hour = (target - carPos[i].first) * 1.0 / carPos[i].second;
            if ( hour > lastHour) {
                lastHour = hour;
                fleet++;
            }
        }
        return fleet;
    
    }
};