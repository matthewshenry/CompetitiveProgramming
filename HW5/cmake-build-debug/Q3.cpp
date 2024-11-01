#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i=0; i<n; i++){
        cin >> c[i];
    }
    vector<vector<int>> moves(n, vector<int>(n, 0));
    for (int i=0; i< n; i++){
        moves[i][i] = 1;
    }
    for (int len = 2; len<=n; len++){
        for (int l = 0; l <= n - len; l++){
            int r = l + len - 1;
            moves[l][r] = moves[l+1][r]+1;
            if (c[l] == c[r]) {
                moves[l][r] = min(moves[l][r], moves[l+1][r - 1]);
            }
            for (int k = l+1; k<=r; k++){
                if (c[l] == c[k]){
                    moves[l][r] = min(moves[l][r], moves[l+1][k - 1]+moves[k+1][r]);
                }
            }
        }
    }
    cout << moves[0][n-1] << endl;
}