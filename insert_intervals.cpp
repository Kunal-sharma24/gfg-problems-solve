class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 1;
        int left = intervals[0][0];
        int right = intervals[0][1];
        while(i<n){
            if(intervals[i][0] <= right) {
                right=max(right,intervals[i][1]);
            }
            else{
                ans.push_back({left,right});
                left=intervals[i][0];
                right=intervals[i][1];
            }
            i++;
        }
        ans.push_back({left,right});
        return ans;
    }
};

/*
Dry Code / Pseudo Code (Hinglish Note):

1. Sabse pehle intervals ko sorted order mein kar do.
   - Isse overlapping intervals ek saath aa jayenge.

2. Ek current interval choose karo:
   - left = intervals[0][0]
   - right = intervals[0][1]

3. Har next interval ke liye check karo:
   - Agar next interval ka start <= current right:
       - Matlab overlap ho raha hai.
       - To current right ko max(current right, next interval end) se update karo.
   - Warna:
       - current merged interval ko ans mein push karo.
       - Ab naya current interval banao:
         left = next interval start
         right = next interval end

4. Loop khatam hone ke baad bhi last merged interval ko ans mein push karo.

5. Final answer return kar do.

Example:
[1,3], [2,6], [8,10], [15,18]
Sorted -> same order
1st -> [1,3]
2nd overlap -> [1,6]
3rd no overlap -> push [1,6]
4th no overlap -> push [8,10]
Then push last [15,18]

Final result:
[[1,6],[8,10],[15,18]]
*/


