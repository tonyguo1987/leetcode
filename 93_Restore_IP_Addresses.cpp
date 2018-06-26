class Solution {
    // Compare two numerical strings
    bool cmpStr(string a, string b){
        if (a.length() > b.length())
            return true;
        else if(a.compare(b) >= 0)
            return true;
        else 
            return false;
    }
    // Check if the string is a valid number between 0-255
    bool checkDigit(string ref, string target){
        bool case1 = ref.length() > target.length();
        bool case2 =target.length() > 1 and target[0] == '0';
        bool case3 = ref.compare(target) >= 0;
        if ((case1 || case3) && !case2)
            return true;
        else
            return false;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        const int NUM_DIGITS = 3;
        string s_max = "255";
        vector<string> res;
        for (int i = 1; i <= NUM_DIGITS; i++ ){
            string si = s.substr(0, i);
            if (!checkDigit(s_max, si))
                continue;
            for (int j = 1; j <= NUM_DIGITS; j++){
                if (i+j >= s.length())
                    continue;
                string sj = s.substr(i, j);
                if (!checkDigit(s_max, sj))
                    continue;
                for (int k = 1; k <= NUM_DIGITS ; k++ ){
                    if (i+j+k >= s.length())
                        continue;
                    string sk = s.substr(i+j, k);
                    if (!checkDigit(s_max, sk))
                        continue;
                    for (int w = 1;w <= NUM_DIGITS; w++){
                        if (i+j+k+w != s.length())
                            continue;
                        string sw = s.substr(i+j+k, w);
                        if (!checkDigit(s_max, sw))
                            continue;
                        else{
                            string ip = si + string(".") + sj + string(".") + sk + string(".") + sw;
                            res.push_back(ip);
                        }
                    }
                    
                }
            }
        }
        return res;
    }
};
