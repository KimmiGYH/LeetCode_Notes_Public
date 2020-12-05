#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    void bfs(int m, int n, queue<pair<int,int>>&Q, vector<vector<int>>& grid, vector<vector<bool>>&visited)
    {
        int rowOffset[] = {0,0,1,-1};
        int colOffset[] = {1,-1,0,0};
        int currentHeight;
        int cx,cy;
        int px,py;
        
        while(!Q.empty())
        {
            cx = Q.front().first;
            cy = Q.front().second;
            currentHeight = grid[cx][cy];
            
            Q.pop();
            
            for(int k=0;k<4;k++)
            {
                px = cx + rowOffset[k];
                py = cy + colOffset[k];
                
                if(px>=0 && px<m && py>=0 && py<n && grid[px][py]>=currentHeight && !visited[px][py])
                {
                    visited[px][py] = true;
                    Q.push({px,py});
                }
            }
        }
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        vector<vector<int>>result;
        
        int m = grid.size();
        if(m==0) return result;
        
        int n = grid[0].size();
        if(n==0) return result;
        
        vector<vector<bool>>pacificVisited(m,vector<bool>(n,false));
        vector<vector<bool>>atlanticVisited(m,vector<bool>(n,false));
        
        queue<pair<int,int>>Q;
        
        // add pacific boundary nodes  in to queue
        for(int i=0;i<n;i++) {
            if(!pacificVisited[0][i]) {
                pacificVisited[0][i] = true;
                Q.push({0,i});                    
            }
        }

        for(int i=1;i<m;i++) {
            if(!pacificVisited[i][0]) {
                pacificVisited[i][0] = true;
                Q.push({i,0});                    
            }
        }

        bfs(m,n,Q,grid,pacificVisited);
        
        // add atlantic boundary nodes
        for(int i=0;i<n;i++) {
            if(!atlanticVisited[m-1][i]) {
                atlanticVisited[m-1][i] = true;
                Q.push({m-1,i});                    
            }
        }

        for(int i=0;i<m-1;i++) {
            if(!atlanticVisited[i][n-1]) {
                atlanticVisited[i][n-1] = true;
                Q.push({i,n-1});                    
            }
        }
        
        bfs(m,n,Q,grid,atlanticVisited);
        
        // push nodes in to result vector which are reachable both from pacific and atlantic boundary
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(pacificVisited[i][j] && atlanticVisited[i][j])
                    result.push_back({i,j});
        
        return result;
    }
};