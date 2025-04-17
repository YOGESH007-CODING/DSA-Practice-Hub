#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
// Problem Link: https://leetcode.com/problems/triangle/
// Problem Statement: Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
// Example: Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The path 2 -> 3 -> 5 -> 1 minimizes the total sum.

// # Recursion Brute Force
class Solution {
    public:
        int solve(vector<vector<int>>& triangle,int i,int j,int n){
            if(i==n){
                return 0;
            }
            int first = triangle[i][j] + solve(triangle,i+1,j,n);
            int second = triangle[i][j] + solve(triangle,i+1,j+1,n);
            return min(first,second);
        }
    
        int minimumTotal(vector<vector<int>>& triangle) {
            int n = triangle.size();
            int i = 0,j = 0;
            return solve(triangle,0,0,n);
        }
    };

    // # Tabulation 
    class Solution {
        public:
            // int solve(vector<vector<int>>& triangle,int i,int j,int n){
            //     if(i==n){
            //         return 0;
            //     }
            //     int first = triangle[i][j] + solve(triangle,i+1,j,n);
            //     int second = triangle[i][j] + solve(triangle,i+1,j+1,n);
            //     return min(first,second);
            // }
        
            int minimumTotal(vector<vector<int>>& triangle) {
                int n = triangle.size();
                int i = 0,j = 0;
                vector<vector<int>> dp(n,vector<int>(n,-1));
                for(int i = 0;i<n;i++){
                    for(int j = 0;j<i+1;j++){
                        if(i==0 && j==0) dp[0][0] = triangle[0][0];
                        else{
                            int just_up = INT_MAX,left_up = INT_MAX;
                            if(i>0 && j!=i) just_up = triangle[i][j] + dp[i-1][j];
                            if(i>0 && j>0) left_up = triangle[i][j] + dp[i-1][j-1];
                            dp[i][j] = min(just_up,left_up);
                        }
                    }
                }
                int mini = INT_MAX;
                for(int i = 0;i<n;i++){
                    mini = min(mini,dp[n-1][i]);
                }
                return mini;
            }
        };

        // # Memoization
        class Solution {
    public:
        int solve(vector<vector<int>> &dp,vector<vector<int>>& triangle,int i,int j,int n){
            if(i==n-1){
                return triangle[i][j];
            }
            if(dp[i][j]!=-1) return dp[i][j];
            int first = triangle[i][j] + solve(dp,triangle,i+1,j,n);
            int second = triangle[i][j] + solve(dp,triangle,i+1,j+1,n);
            return dp[i][j] = min(first,second);
        }
    
        int minimumTotal(vector<vector<int>>& triangle) {
            int n = triangle.size();
            int i = 0,j = 0;
            vector<vector<int>> dp(n,vector<int>(n,-1));
            return solve(dp,triangle,0,0,n);
        }
    };
// # Space Optimization
class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int n = triangle.size();
            int i = 0,j = 0;
            vector<int> prev(n);
            for(int i = 0;i<n;i++){
                vector<int> curr(n);
                for(int j = 0;j<i+1;j++){
                    if(i==0 && j==0) curr[0] = triangle[0][0];
                    else{
                        int just_up = INT_MAX,left_up = INT_MAX;
                        if(i>0 && j!=i) just_up = triangle[i][j] + prev[j];
                        if(i>0 && j>0) left_up = triangle[i][j] + prev[j-1];
                        curr[j] = min(just_up,left_up);
                    }
                }
                prev = curr;
            }
            int mini = INT_MAX;
            for(int i = 0;i<n;i++){
                mini = min(mini,prev[i]);
            }
            return mini;
        }
    };