#include <iostream>
using namespace std;

int miles(int speed, int hours, int prev_hours) {
    int use_hours = hours - prev_hours;
    return speed*use_hours;
}

int main() {
    int num_inputs = 0;
    while(true){
        int total_miles = 0;
        int prev_hours = 0;
        cin >> num_inputs;
        if(num_inputs == -1){
            break;
        }
        while (num_inputs--) {
            int speed;
            int hours;
            cin >> speed;
            cin >> hours;
            total_miles+=miles(speed, hours, prev_hours);
            prev_hours = hours;
        }
        cout << total_miles << " miles" << endl;
    }
    return 0;
}
