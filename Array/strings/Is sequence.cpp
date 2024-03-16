class Solution {
public:
    bool isSubsequence(string s, string t) {
      int count=0;
      for(int i=0;i<t.length();i++)
      {
          if(t[i]==s[count])
          {
              count=count+1;
          }
      } 
      return s.size()==count;// over
    }
};