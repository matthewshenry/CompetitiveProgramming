#include <iostream>
#include <deque>
#include <string>
using namespace std;

void processBAPCProgram() {
    int num_cases;
    cin >> num_cases;

    while (num_cases--) {
        string rd;
        cin >> rd;
        int n;
        cin >> n;
        string list_input;
        cin >> list_input;
        deque<int> dq;
        string nums_string;

        for (char ch : list_input) {
            if (isdigit(ch)) {
                nums_string += ch;
            } else if (!nums_string.empty()) {
                dq.push_back(stoi(nums_string));
                nums_string.clear();
            }
        }

        bool reverse_flag = false;
        bool error_flag = false;

        for (char command : rd) {
            if (command == 'R') {
                reverse_flag = !reverse_flag;
            } else if (command == 'D') {
                if (dq.empty()) {
                    error_flag = true;
                    break;
                } else {
                    if (reverse_flag) {
                        dq.pop_back();
                    } else {
                        dq.pop_front();
                    }
                }
            }
        }

        if (error_flag) {
            cout << "error\n";
        } else {
            cout << "[";
            if (reverse_flag) {
                for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
                    if (it != dq.rbegin()) cout << ",";
                    cout << *it;
                }
            } else {
                for (auto it = dq.begin(); it != dq.end(); ++it) {
                    if (it != dq.begin()) cout << ",";
                    cout << *it;
                }
            }
            cout << "]\n";
        }
    }
}

int main() {
    processBAPCProgram();
    return 0;
}
