#include <iostream>
using namespace std;

int best_profit(int a[], int size, int price) {
    int maxSum = 0, currentSum = 0;
    for (int i = 0; i < size; i++) {
        currentSum = max(a[i]-price, currentSum + a[i]-price);
        maxSum = max(currentSum, maxSum);
    }
    return maxSum;
}

int main() {
    int num_inputs;
    int price;
    cin >> num_inputs;
    cin >> price;
    int a[num_inputs];
    for(int i=0; i<num_inputs; i++){
        int listeners;
        string tasks;
        cin >> listeners;
        a[i] = listeners;
    }
    cout << best_profit(a, num_inputs, price);
    return 0;

}