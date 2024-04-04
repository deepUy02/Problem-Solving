bool hasOnlyOneChild(int pre[], int size) {
    int max_val = INT_MAX, min_val = INT_MIN; // initialize max and min to extreme values
    for (int i = 1; i < size; i++) {
        if (pre[i] < min_val || pre[i] > max_val) {
            return false;
        }
        if (pre[i] < pre[i-1]) {
            max_val = pre[i-1];
        } else {
            min_val = pre[i-1];
        }
    }
    return true;
}