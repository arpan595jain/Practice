class Solution {
public:
    
    string RLE(string s, int n){
        
        if(n == 1){
            return s;
        }
        int i=0;
        string ans = "";
        int j=0;
        while(i<s.length()){ 
           int count = 0; 
          while(j<s.length() && s[i] == s[j]){
            j++;
          }
         count = j-i;
          ans += to_string(count);
          ans.push_back(s[i]);
          i=j;
        }
        n--;
        return RLE(ans, n);
    }
    string countAndSay(int n) {
        if(n == 1) return "1";
        string s ="1";
        return RLE(s,n);
    }
};
