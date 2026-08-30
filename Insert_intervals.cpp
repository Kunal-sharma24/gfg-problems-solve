// split this question in 3 halves
// left   -----   middle ---- right
// for left simple uske [i][1] wale ko final wale se compare karo->insert
// for middle [i][0] wala agar chota ha final se toh ->insert
// for right simple uske [i][0] > final se toh ->insert

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        int n = intervals.size();
        int intial = newInterval[0];
        int finals = newInterval[1];
        int i=0;
        while(i<n && intervals[i][1] < intial){
            answer.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }
        int left=intial;
        int right=finals;
        while(i<n && intervals[i][0]<=finals){
            left = min(left,intervals[i][0]);
            right = max(right,intervals[i][1]);
            i++;
        }
        answer.push_back({left,right});
        while(i<n){
            answer.push_back({intervals[i][0],intervals[i][1]});
            i++;
        }  
        return answer;
    }
};