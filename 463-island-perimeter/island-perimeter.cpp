class Solution {
public:
    int dfs(vector<vector<int>>&grid,int r,int c){
        if(r<0 ||r>=grid.size()||c<0 ||c>=grid[0].size()){
            return 1;

        }
        if(grid[r][c]==0){
            return 1;
        }
        if(grid[r][c]==2){
            return 0;
        }
        grid[r][c]=2;

        int perimeter=0;
        perimeter +=dfs(grid,r,c-1);
        perimeter +=dfs(grid,r+1,c);
        perimeter +=dfs(grid,r,c+1);
        perimeter +=dfs(grid,r-1,c);
        return perimeter;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return dfs(grid,i,j);
                }
            }
        }
        return 0;

    }
};