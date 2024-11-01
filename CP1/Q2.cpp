#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    long long n;
    long long count=0;
    cin >> n;
    long long arr[n];
    unordered_map<long long, long long> frequency;
    for(long long i=0; i<n; i++) {
        cin >> arr[i];
        frequency[arr[i]]++;
    }
    for(long long i=0; i<n; i++) {
        long long match = -arr[i];
        if(frequency[match] > 0){
            count+=frequency[match];
        }
        if (arr[i] == match) {
            count--;
        }
    }
    cout << count / 2 << endl;
    return 0;
}
