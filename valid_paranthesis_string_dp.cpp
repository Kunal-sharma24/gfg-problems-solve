class Solution {
public:
    
    bool paranthesis(string s,int idx,int cnt,vector<vector<int>> &dp){
        if(cnt<0) return false;
        int n = s.size();
        if(idx==n){
            return (cnt==0); 
        }
        if(dp[idx][cnt]!=-1) return dp[idx][cnt];
        if(s[idx]=='(') return dp[idx][cnt]=paranthesis(s,idx+1,cnt+1,dp);
        else if(s[idx]==')') return dp[idx][cnt]=paranthesis(s,idx+1,cnt-1,dp);
        else return dp[idx][cnt] = paranthesis(s,idx+1,cnt+1,dp) || paranthesis(s,idx+1,cnt,dp) || paranthesis(s,idx+1,cnt-1,dp);
    }

    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));  //potentially the (idx -> n) tak reach kar sakte ha and (cnt -> n) too.
        return paranthesis(s,0,0,dp);
    }
};