#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0) {
			return 0;
		}

        vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;

        for (int x = 0; x < grid.size(); x++) {
            for (int y = 0; y < grid[x].size(); y++) {
                if (grid[x][y] == '1' && visit[x][y] == false) {
                    count++;
                    dfs(x, y, grid, visit);
                }
            }
        }

        return count;
    }

    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visit) {

        visit[x][y] = true;

        // up
        if (x-1 >= 0 && grid[x-1][y] == '1' && visit[x-1][y] == false) {
            dfs(x-1, y, grid, visit);
        }

        // right
        if (y+1 < grid[0].size() && grid[x][y+1] == '1' && visit[x][y+1] == false) {
            dfs(x, y+1, grid, visit);
        }

        // down
        if (x+1 < grid.size() &&  grid[x+1][y] == '1' && visit[x+1][y] == false) {
            dfs(x+1, y, grid, visit);
        }

        // left
        if (y-1 >= 0 && grid[x][y-1] == '1' && visit[x][y-1] == false) {
            dfs(x, y-1, grid, visit);
        }
    }
};

int main()
{
	vector<char> x0 = {'1', '1', '0', '0', '0'};
	vector<char> x1 = {'1', '1', '0', '0', '0'};
	vector<char> x2 = {'0', '0', '1', '0', '0'};
	vector<char> x3 = {'0', '0', '0', '1', '1'};
	vector<vector<char>> grid = {x0, x1, x2, x3};

	Solution slt;
	int count = slt.numIslands(grid);

	printf("count = %d\n", count);

	return 0;
}
