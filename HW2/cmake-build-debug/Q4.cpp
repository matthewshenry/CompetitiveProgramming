#include <iostream>
#include <vector>
#include <string>
using namespace std;

string greg(int array[], int operations[][3], int queries[][2], int n, int m, int k) {
    // Auxiliary array to count how many times each operation is applied
    vector<int> operation_count(m + 1, 0);

    // Process each query and mark how many times operations should be applied
    for (int i = 0; i < k; i++) {
        int x = queries[i][0] - 1;  // Convert to zero-indexed
        int y = queries[i][1] - 1;  // Convert to zero-indexed
        operation_count[x]++;       // Increment start of operation range
        if (y + 1 < m) {
            operation_count[y + 1]--;  // Decrement after end of operation range
        }
    }

    // Accumulate the operation counts to determine the final counts
    for (int i = 1; i < m; i++) {
        operation_count[i] += operation_count[i - 1];
    }

    // Now apply each operation based on how many times it should be applied
    vector<int> result(array, array + n);  // Copy the initial array to result
    vector<int> array_diff(n + 1, 0);      // Difference array for efficient range updates

    for (int i = 0; i < m; i++) {
        int li = operations[i][0] - 1;  // Convert to zero-indexed
        int ri = operations[i][1] - 1;  // Convert to zero-indexed
        int di = operations[i][2];

        int times = operation_count[i];  // Number of times this operation is applied
        if (times > 0) {
            array_diff[li] += di * times;  // Apply the operation to the start of the range
            if (ri + 1 < n) {
                array_diff[ri + 1] -= di * times;  // Undo it after the end of the range
            }
        }
    }

    // Apply the difference array to compute the final values in result array
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            array_diff[i] += array_diff[i - 1];
        }
        result[i] += array_diff[i];  // Update the original array with the computed diff
    }
}

int main(){
    int n, m, k;
    cin >> n;
    cin >> m;
    cin >> k;
    int array[n];
    int operations[m][3];
    int queries[k][2];
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < 3; j++){
            cin >> operations[i][j];
        }
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < 2; j++){
            cin >> queries[i][j];
        }
    }
    cout << greg(array, operations, queries, n, m, k) << endl;
    return 0;
}
