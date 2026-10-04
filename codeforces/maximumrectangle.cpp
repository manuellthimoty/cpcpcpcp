#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> horizontal(m,vector<int>(n));
        vector<vector<int>> vertical(m,vector<int>(n));
        for(int i = 0 ; i < m ; i++){
            if(matrix[i][0] == 1){
                horizontal[i][0] = 1;
            }
            else{
                horizontal[i][0] = 0;
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(matrix[0][i] == 1){
                vertical[0][i] = 1;
            }
            else{
                vertical[0][i] = 0;
            }
        }
        for(int i = 0 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                if(matrix[i][j] == 0){
                    horizontal[i][j] = 0;
                }
                else{
                    horizontal[i][j] = horizontal[i][j-1] + 1;
                    
                }
            }
        }
        for(int i = 1 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == 0){
                    vertical[i][j] = 0 ;
                }
                else{
                    vertical[i][j] = vertical[i-1][j] + 1;
                }
            }
        }
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, 0)));
        for(int i = 0 ; i < m ; i++){
            dp[i][0][0] = vertical[i][0];
            dp[i][0][1] = 1;
        }
        for(int i = 0 ; i < n ; i++){
            dp[0][i][0] = 1;
            dp[0][1][1] = horizontal[0][i];
        }
        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < m ; j++){
                if(matrix[i][j] = 0){
                    continue;
                }
                if(matrix[i][j-1] == 0 && matrix[i-1][j] == 0){
                    dp[i][j][0] = 1;
                    dp[i][j][1] = 1;
                }
                int horizontalMax = horizontal[i][j-1];
                int verticalMax = vertical[i-1][j];
                int pojokKiriHeight = min(dp[i-1][j-1][0],verticalMax);
                int pojokKiriWidth = min(dp[i-1][j-1][1],horizontalMax);
                
            }
    }
};