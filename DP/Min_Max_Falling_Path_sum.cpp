 #include <iostream>
 #include <vector>
#include <algorithm>
using namespace std;

// What to learn from this question ?
// It should work if you initialize 1e9 for this problem, but a more generic approach I find is to initialize to (matrix.length * 100) + 1. Why 100? Because numbers in the matrix are supposed to be between -100 and 100. Therefore, even if the matrix is filled with 100, the answer should never exceed (matrix.length * 100) + 1


// Function to find the minimum falling path sum in a matrix
// ## Memoization 
class Solution {
    public:
        int solve(vector<vector<int>> &dp,vector<vector<int>> &matrix,int n,int i,int j){
            if(i==0){
                return matrix[0][j];
            }
            if(dp[i][j]!=INT_MAX) return dp[i][j];
            int di_l = INT_MAX,di_r = INT_MAX;
            if(j>0) di_l =  solve(dp,matrix,n,i-1,j-1);
            if(j<n-1) di_r =  solve(dp,matrix,n,i-1,j+1);
            int di_up = solve(dp,matrix,n,i-1,j);
            return dp[i][j] = matrix[i][j] + min(di_up,min(di_l,di_r));
        }
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n = matrix.size();
            vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
            int sol = INT_MAX;
            for(int j = 0;j<n;j++){
                sol = min(sol,solve(dp,matrix,n,n-1,j));
            }
            return sol;
        }
    };

// ## Tabulation
class Solution {
    public:
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n = matrix.size();
            vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
            int sol = INT_MAX;
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(i==0) dp[0][j] = matrix[0][j];
                    else{
                        int up_left = INT_MAX,up_right = INT_MAX;
                        if(j>0) up_left = dp[i-1][j-1];
                        if(j<n-1) up_right = dp[i-1][j+1];
                        int up_top = dp[i-1][j];
                        dp[i][j] = matrix[i][j]+ min(up_top,min(up_left,up_right));
                    } 
                }
            }
            for(int i = 0;i<n;i++){
                sol = min(sol,dp[n-1][i]);
            }
            return sol;
        }
    };
// ## Space Optimization
class Solution {
    public:
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n = matrix.size();
            vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
            int sol = INT_MAX;
            vector<int> prev(n,INT_MAX);
            for(int i = 0;i<n;i++){
                vector<int> curr(n);
                for(int j = 0;j<n;j++){
                    if(i==0) curr[j] = matrix[i][j];
                    else{
                        int up_left = INT_MAX,up_right = INT_MAX;
                        if(j>0) up_left = prev[j-1];
                        if(j<n-1) up_right = prev[j+1];
                        int up_top = prev[j];
                        curr[j] = matrix[i][j]+ min(up_top,min(up_left,up_right));
                    } 
                }
                prev = curr;
            }
            for(int i = 0;i<n;i++){
                sol = min(sol,prev[i]);
            }
            return sol;
        }
    };