class Solution {
public:
    int findComplement(int num) {
        
      int count=log2(num)+1;
      long long mask=pow(2,count)-1;
        return num^mask;
        
    }
};