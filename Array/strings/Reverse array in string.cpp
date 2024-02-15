class Solution {
private:
    void reverse(string &s, int left , int right) {
        while(left < right) {
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp; 
        }
    }
public:
    string reverseWords(string s) {
        int n = s.size();
        // Reverse the entire string
        reverse(s, 0, n - 1);

        // Reverse each word in the string and remove extra spaces
        int i = 0, j = 0;
        while (j < n) {
            while (j < n && s[j] == ' ') j++; // Skip leading spaces
            if (j < n && i > 0) s[i++] = ' '; // Add space if not first word
            int start = i;
            while (j < n && s[j] != ' ') s[i++] = s[j++]; // Copy word
            reverse(s, start, i - 1); // Reverse word
        }
        s.resize(i); // Resize string to remove trailing spaces
        return s;
    }
};