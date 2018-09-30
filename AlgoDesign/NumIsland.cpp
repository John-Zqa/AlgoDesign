//
//  NumIsland.cpp
//  AlgoDesign
//
//  Created by Qiao Zhu on 9/29/18.
//  Copyright © 2018 Qiao Zhu. All rights reserved.
//

#include <vector>
#include <queue>
using namespace std;

int numIslands(vector<vector<char>>& grid) {
    if(grid.empty()){
        return 0;
    }
    int count=0,m=(int)grid.size(),n=(int)grid[0].size();
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (grid[i][j]=='0') {
                continue;
            }
            queue<vector<int>> q;
            grid[i][j]='0';
            count++;
            vector<int> sPoint({i,j});
            q.push(sPoint);
            while (!q.empty()) {
                vector<int> cur = q.front();
                int x=cur[0],y=cur[1];
                q.pop();
                if (x>0 && grid[x-1][y]=='1') {
                    grid[x-1][y]='0';
                    q.push({x-1,y});
                }
                if (y>0 && grid[x][y-1]=='1') {
                    grid[x][y-1]='0';
                    q.push({x,y-1});
                }
                if (x<m-1 && grid[x+1][y]=='1') {
                    grid[x+1][y]='0';
                    q.push({x+1,y});
                }
                if (y<n-1 && grid[x][y+1]=='1') {
                    grid[x][y+1]='0';
                    q.push({x,y+1});
                }
            }
        }
    }
    return count;
}
