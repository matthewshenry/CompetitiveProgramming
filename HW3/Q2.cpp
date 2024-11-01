//int split(int arr[], int n){
//    int count = 0;
//    int index = 0;
//    for(int i=1; i<=n; i++){
//        for(int j = index; j < n; j++){
//            if(arr[j] == i){
//                index = j;
//                break;
//            }
//        }
//        if(arr[index] != i){
//            count++;
//            i--;
//            index=0;
//        }
//    }
//    return count;
//}

#include <iostream>
#include <vector>
using namespace std;

int split(int arr[], int n){
    vector<int> position(n + 1);
    for (int i = 0; i < n; i++) {
        position[arr[i]] = i;
    }
    int count = 0;
    int prev = position[1];
    for (int i = 2; i <= n; i++) {
        if (position[i] < prev) {
            count++;
        }
        prev = position[i];
    }
    return count;
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        int arr[n];
        for(int j=0;j<n;j++){
            cin >> arr[j];
        }
        cout << split(arr, n) << endl;
    }

}