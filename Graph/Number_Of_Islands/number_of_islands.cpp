#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setNeighbour(vector<vector<char> > & grid, int i, int j, int m, int n)
    {
        if(i+1 < m)
        {
            if(grid[i+1][j] == '1')
            {
                grid[i+1][j] = '2';
                setNeighbour(grid, i+1, j, m, n);
            }
        }
        if(i-1 >=0)
        {
            if(grid[i-1][j] == '1')
            {
                grid[i-1][j] = '2';
                setNeighbour(grid, i-1, j, m, n);
            }
        }
        if(j-1 >=0)
        {
            if(grid[i][j-1] == '1')
            {
                grid[i][j-1] = '2';
                setNeighbour(grid, i, j-1, m, n);
            }
        }
        if(j+1 < n)
        {
            if(grid[i][j+1] == '1')
            {
                grid[i][j+1] = '2';
                setNeighbour(grid, i, j+1, m, n);
            }
        }
            
    }
    int numIslands(vector<vector<char> > & grid) {
        int m = grid.size();
        int n = grid[0].size();
        int k = 0;                  // Number of Islands
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] != '1')
                    continue;
                else
                {
                    grid[i][j] = '2';       // marks the visited node
                    k++;                  // increase the number of islands
                    setNeighbour(grid, i, j, m, n);
                }
            }
        }
        return k;
    }
};

int main() {
    Solution solution;

    // Example usage with a grid
    vector<vector<char> > grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    int islands = solution.numIslands(grid);

    cout << "Number of Islands: " << islands << endl;

    return 0;
}
