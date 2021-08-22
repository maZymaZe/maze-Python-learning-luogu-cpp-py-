class Solution {
   public:
    void duplicateZeros(vector<int>& arr) {
        int l = arr.size(), c = 0;
        for (int i = 0; i < l; i++) {
            if (arr[i] == 0)
                c += 2;
            else
                c++;
            if (c >= l) {
                int r = l - 1;
                if (c > l) {
                    arr[r--] = 0;
                    for (int j = i - 1; j >= 0; j--) {
                        if (arr[j] == 0) {
                            arr[r--] = 0;
                            arr[r--] = 0;
                        } else
                            arr[r--] = arr[j];
                    }
                } else {
                    for (int j = i; j >= 0; j--) {
                        if (arr[j] == 0) {
                            arr[r--] = 0;
                            arr[r--] = 0;
                        } else
                            arr[r--] = arr[j];
                    }
                }
                break;
            }
        }
    }
};