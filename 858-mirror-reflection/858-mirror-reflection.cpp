class Solution {
    public: int mirrorReflection(int p, int q) {
        if (p == q) {
            return 1;
        }

        if (q == 0) {
            return 0;
        }

        int lcm = p * q / gcd(p, q);
        int x = lcm / p;
        int y = lcm / q;

        if (x % 2 == 1 && y % 2 == 1) {
            return 1;
        } else if (x % 2 == 0 && y % 2 == 1) {
            return 0;
        } else {
            return 2;
        }
    }

    private: int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};