#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    // Constructor
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }
    // Build the segment tree
    void build(vector<int>& arr, int node, int start, int end) {
        // Leaf node
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        // Build left subtree
        build(arr, 2 * node + 1, start, mid);
        // Build right subtree
        build(arr, 2 * node + 2, mid + 1, end);
        // Store minimum of both children
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }
    // Public query function
    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
    // Actual recursive query
    int query(int node, int start, int end, int l, int r) {
        // Case 1: Completely outside the query range
        if (end < l || start > r) {
            return INT_MAX;
        }
        // Case 2: Completely inside the query range
        if (l <= start && end <= r) {
            return tree[node];
        }
        // Case 3: Partial overlap
        int mid = start + (end - start) / 2;
        int leftMin = query(
            2 * node + 1,
            start,
            mid,
            l,
            r
        );

        int rightMin = query(
            2 * node + 2,
            mid + 1,
            end,
            l,
            r
        );

        return min(leftMin, rightMin);
    }

    // Public update function
    void update(int index, int value) {
        update(0, 0, n - 1, index, value);
    }

    // Actual recursive update
    void update(int node, int start, int end,
                int index, int value) {

        // Reached the leaf
        if (start == end) {
            tree[node] = value;
            return;
        }

        int mid = start + (end - start) / 2;

        // Go to left child
        if (index <= mid) {
            update(
                2 * node + 1,
                start,
                mid,
                index,
                value
            );
        }

        // Go to right child
        else {
            update(
                2 * node + 2,
                mid + 1,
                end,
                index,
                value
            );
        }

        // Recalculate current node
        tree[node] = min(
            tree[2 * node + 1],
            tree[2 * node + 2]
        );
    }
};

int main() {

    vector<int> arr = {2, 5, 1, 4, 9, 3};

    SegmentTree st(arr);

    // Query minimum from index 1 to 4
    cout << st.query(1, 4) << '\n';
    // 1

    // Change arr[2] from 1 to 10
    st.update(2, 10);

    // Now array is:
    // {2, 5, 10, 4, 9, 3}

    cout << st.query(1, 4) << '\n';
    // 4

    // Another query
    cout << st.query(0, 5) << '\n';
    // 2

    return 0;
}