class NumArray {
private:
    vector<int> segmentTree;
    int n;

    void buildTree(vector<int>& nums, int node, int start, int end){
        if(start == end){
            segmentTree[node] = nums[start];
        }else{
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            buildTree(nums, leftChild, start, mid);
            buildTree(nums, rightChild, mid + 1, end);
            segmentTree[node] = segmentTree[leftChild] + segmentTree[rightChild];
        }
    }

    void updateTree(int node, int start, int end, int idx, int val){
        if(start == end){
            segmentTree[node] = val;
        }else{
            int mid = start + (end - start) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            if(idx <= mid){
                updateTree(leftChild, start, mid, idx, val);
            }else{
                updateTree(rightChild, mid + 1, end, idx, val);
            }
            segmentTree[node] = segmentTree[leftChild] + segmentTree[rightChild];
        }
    }

    int queryTree(int node, int start, int end, int left, int right){
        if(right < start || end < left){
            return 0;
        }
        if(left <= start && end <= right){
            return segmentTree[node];
        }
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        int sumLeft = queryTree(leftChild, start, mid, left, right);
        int sumRight = queryTree(rightChild, mid + 1, end, left, right);

        return sumLeft + sumRight;
    }

public:
    NumArray(vector<int>& nums){
        n = nums.size();
        segmentTree.resize(4 * n, 0);
        buildTree(nums, 0, 0, n - 1);
    }

    void update(int index, int val){
        updateTree(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right){
        return queryTree(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */