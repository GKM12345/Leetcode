class Solution {

public:

    int min(int a , int b){

        if( a < b){

            return a;

        }

        return b;

    }

    void p (vector<string>&ans , string curr , int i , string &s , int dots){

        if(i == s.size() && dots == 4){

            curr.pop_back();

            ans.push_back(curr);

            return;

        }

        if(dots > 4){

            return;

        }

        for(int j = 1 ; j <= min(3 ,s.size() - i) ; j++){

            string x = s.substr(i, j);

            if(stoi(x) <= 255 && (j == 1 || s[i] != '0')){

                p(ans, curr + x + '.' , i + j , s , dots + 1);

            }

        }

    }

    vector<string> restoreIpAddresses(string s) {

        if (s.size() > 12){

            return {};

        }

        vector<string> ans;

        p(ans ,"" , 0 , s ,0);

        return ans;

    }

};