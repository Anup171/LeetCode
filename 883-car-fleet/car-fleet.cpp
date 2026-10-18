class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for(int i=0;i<position.size();i++){
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.rbegin(),cars.rend());
        vector<double> st;
        for(auto [p,s]:cars){
            double time=(double)(target-p)/s;
            st.push_back(time);
            if(st.size()>=2&&st[st.size()-1]<=st[st.size()-2]){
                st.pop_back();
            }
        }
        return st.size();
    }
};