#include <iostream>
#include <vector>
using namespace std;

bool checkStar(const vector<vector<pair<char, bool>>>& grid, int i, int j, int width){
    if(grid[i][j].first == '#'){
        return false;
    }
    bool check = true;
    if(j < width-1) {
        if (!grid[i][j].second && !checkStar(grid, i, j + 1, width)) {
            check = false;
        }
    }else{
        if (!grid[i][j].second){
            check=false;
        }
    }
    return check;
}

int main(){
    int depth, width;
    int caseNum = 1;
    while(cin >> depth >> width) {
        int stars = 0;
        cin.ignore();
        vector<vector<pair<char, bool>>> grid(depth, vector<pair<char, bool>>(width, {'a', false}));
        for (int i = 0; i < depth; i++) {
            string line;
            getline(cin, line);
            for (int j = 0; j < width; j++) {
                grid[i][j].first = line[j];
            }
        }
        for (int i = 0; i < depth; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j].first == '-') {
                    if (!checkStar(grid, i, j, width)) {
                        stars++;
                    }
                    if (i + 1 < depth) grid[i + 1][j].second = true;
                    if (j + 1 < width) grid[i][j + 1].second = true;
                }
                //cout << stars;
            }
            //cout << endl;
        }
        cout << "Case " << caseNum << ": " << stars << endl;
        caseNum++;
    }
    return 0;
}
