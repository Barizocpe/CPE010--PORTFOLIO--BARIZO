#include <iostream>
#include <vector>
using namespace std;


// Counts paths from (0,0) to (i,j) whose total cost equals 'cost'.
// Works backwards from the destination, subtracting each cell's value.
int countPaths(const vector<vector<int>>& mat, int i, int j, int cost) {
    if (i < 0 || j < 0 || cost < 0)
        return 0;


    if (i == 0 && j == 0)
        return (mat[0][0] == cost) ? 1 : 0;


    return countPaths(mat, i - 1, j, cost - mat[i][j]) +
           countPaths(mat, i, j - 1, cost - mat[i][j]);
}


int main() {
    int M, N, cost;
    cout << "Enter rows and columns: ";
    cin >> M >> N;


    vector<vector<int>> mat(M, vector<int>(N));
    cout << "Enter the matrix:\n";
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> mat[i][j];


    cout << "Enter target cost: ";
    cin >> cost;


    cout << "Number of paths with cost " << cost << ": "
         << countPaths(mat, M - 1, N - 1, cost) << endl;
    return 0;
}