class Solution {
   public:
    string maximumBinaryString(string binary) {
        int c[2] = {0}, t0 = -1, l = binary.size();
        for (int i = 0; i < l; i++) {
            c[binary[i] - '0']++;
            if (binary[i] == '0' && t0 == -1)
                t0 = i;
        }

        if (c[0] > 1)
            return string(t0 + c[0] - 1, '1') + "0" +
                   string(l - t0 - c[0], '1');
        else
            return binary;
    }
};