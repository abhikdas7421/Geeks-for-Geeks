//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    int dx[4] = {1, 0, 0, -1};
    int dy[4] = {0, -1, 1, 0};
    char direction[4] = {'D', 'L', 'R', 'U'};
    
    bool isSafe(int x, int y, int row, int col, vector<vector<int>> &arr, vector<vector<bool>> &visited)
    {
        if (
            ((x >= 0 && x < row) && (y >= 0 && y < col)) &&
            (arr[x][y] == 1) &&
            (visited[x][y] == false))
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    void solveMaze(vector<vector<int>> &arr, int row, int col, int srcx, int srcy, vector<vector<bool>> &visited, vector<string> &path, string output)
    {
        // base case
        if (srcx == row - 1 && srcy == col - 1)
        {
            // answer found
            path.push_back(output);
            return;
        }
        
        
        for(int i = 0; i < 4; i++)
        {
            int newx = srcx+dx[i];
            int newy = srcy+dy[i];
            char dir = direction[i];
            
            if(isSafe(newx, newy, row, col, arr, visited))
            {
                visited[newx][newy] = true;
                solveMaze(arr, row, col, newx, newy, visited, path, output+dir);
        
                // backtrack
                visited[newx][newy] = false;
                
            }
        }
    
    /*
        // Down -> (i+1, j)
        if (isSafe(srcx + 1, srcy, row, col, arr, visited))
        {
            visited[srcx + 1][srcy] = true;
            solveMaze(arr, row, col, srcx + 1, srcy, visited, path, output + 'D');
    
            // backtrack
            visited[srcx + 1][srcy] = false;
        }
    
        // Left -> (i, j-1)
        if (isSafe(srcx, srcy - 1, row, col, arr, visited))
        {
            visited[srcx][srcy - 1] = true;
            solveMaze(arr, row, col, srcx, srcy - 1, visited, path, output + 'L');
    
            // backtrack
            visited[srcx][srcy - 1] = false;
        }
    
        // Right -> (i, j+1)
        if (isSafe(srcx, srcy + 1, row, col, arr, visited))
        {
            visited[srcx][srcy + 1] = true;
            solveMaze(arr, row, col, srcx, srcy + 1, visited, path, output + 'R');
    
            // backtrack
            visited[srcx][srcy + 1] = false;
        }
    
        // Up -> (i-1, j)
        if (isSafe(srcx - 1, srcy, row, col, arr, visited))
        {
            visited[srcx - 1][srcy] = true;
            solveMaze(arr, row, col, srcx - 1, srcy, visited, path, output + 'U');
    
            // backtrack
            visited[srcx - 1][srcy] = false;
        }*/
        
        
    }
    
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        // Your code goes here

        int row = n;
        int col = n;
        
        vector<string> path;
        string output = "";
    
        if (maze[0][0] == 0 || maze[row - 1][col - 1] == 0)
        {
            return path;
        }
    
        vector<vector<bool>> visited(row, vector<bool>(col, false));
    
        // src ki value k true mark kardete h
        visited[0][0] = true;

        solveMaze(maze, row, col, 0, 0, visited, path, output);
    
        return path;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends