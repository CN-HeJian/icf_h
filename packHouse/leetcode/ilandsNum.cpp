// Copyright 2022 icf
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

class Solution {
public: 
    int res;
    
    vector<int> dx={0,0,-1,1};
    vector<int> dy={-1,1,0,0};
    int m;
    int n;

    int numIslands(vector<vector<char>>& grid) {
        m = grid[0];
        n = grid[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i]=='1'){
                    res++;
                    infect(i,j,grid);
                }
            }
        }
        return res;
    }

    void infect(int i,int j,vector<vector<char>>& grid){
        if(i<0 || i>=m || j<0 || j>=n){
            return ;
        }

        if(grid[i][j]=='1'){
            grid[i][j] = 'X'; 
        }

        for(int i=0;i<4;i++){
            infect(i+dx[i],j+dy[i],grid);
        }

    }

};