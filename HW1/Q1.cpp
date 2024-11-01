#include <iostream>
using namespace std;

int divide(long long n){
    int divide_counter = 0;
    while(n!=1) {
        while (n % 2 == 0) {
            n = n / 2;
            divide_counter++;
        }
        while (n % 3 == 0) {
            n = 2 * (n / 3);
            divide_counter++;
        }
        while (n % 5 == 0) {
            n = 4 * (n / 5);
            divide_counter++;
        }
        if(n % 2 != 0 && n % 3 != 0 && n % 5 != 0 && n != 1){
            return -1;
        }
    }
    return divide_counter;
}
int main() {
    int num_inputs;
    cin >> num_inputs;
    while (num_inputs--) {
        long long n;
        cin >> n;
        cout << divide(n) << endl;
    }
    return 0;
}
//VJudge Name: henrymatthews
//I don't know why it won't let me name Q1 "Q1.cpp" and instead keeps adding a "-7" to it.
