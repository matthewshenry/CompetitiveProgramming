#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> years;
int rainfall[50000];
int segmentTree[200000];

void buildTree(int node, int start, int end){
    if(start == end){
        segmentTree[node] = rainfall[start];
    }else{
        int mid = (start + end) / 2;
        buildTree(2 * node + 1, start, mid);
        buildTree(2 * node + 2, mid + 1, end);
        segmentTree[node] = max(segmentTree[2 * node + 1], segmentTree[2 * node + 2]); // Combine
    }
}

int  queryMax(int node, int start, int end, int l, int r){
    if(r < start || l > end) return -1; // Out of range
    if(l <= start && end <= r) return segmentTree[node]; // Fully in range
    int mid = (start + end) / 2;
    int leftMax = queryMax(2 * node + 1, start, mid, l, r);
    int rightMax = queryMax(2 * node + 2, mid + 1, end, l, r);
    return max(leftMax, rightMax);
}

int main(){
    ios::sync_with_stdio(0);
    while(true){
        int n, m;
        scanf("%d", &n);
        if(n==0){
            break;
        }
        years.clear();
        for(int & i : rainfall) i = -1;
        for(int & i : segmentTree) i = -1;
        for(int i = 0; i < n; i++){
            int y, r;
            scanf("%d %d", &y, &r);
            years.push_back(y);
            rainfall[i]=r;
        }
        buildTree(0, 0, n - 1);
        scanf("%d", &m);
        while(m--){
            int lYear, rYear;
            scanf("%d %d", &lYear, &rYear);
            int lIndex = lower_bound(years.begin(), years.end(), lYear) - years.begin();
            int rIndex = lower_bound(years.begin(), years.end(), rYear) - years.begin();
            bool l_exists = lIndex < n && years[lIndex] == lYear;
            bool r_exists = rIndex < n && years[rIndex] == rYear;
            if(!l_exists && !r_exists){
                printf("maybe\n");
            }
            else if(!l_exists){
                if(queryMax(0, 0, n - 1, lIndex, rIndex - 1) >= rainfall[rIndex]) {
                    printf("false\n");
                }
                else{
                    printf("maybe\n");
                }
            }
            else if(!r_exists){
                if(queryMax(0, 0, n - 1, lIndex + 1, rIndex - 1) >= rainfall[lIndex]) {
                    printf("false\n");
                }
                else{
                    printf("maybe\n");
                }
            }
            else{
                if (rainfall[lIndex] < rainfall[rIndex]){
                    printf("false\n");
                }else if (queryMax(0, 0, n - 1, lIndex + 1, rIndex - 1) >= rainfall[rIndex]) {
                    printf("false\n");
                }else{
                    if (rIndex - lIndex == rYear - lYear){
                        printf("true\n");
                    }else{
                        printf("maybe\n");
                    }
                }
            }
        }
        printf("\n");
    }
}