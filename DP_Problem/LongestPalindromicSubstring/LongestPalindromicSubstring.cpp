#include <iostream>
#include <string>

using namespace std;

string FindLongestPalindromicSubstring(const string& s)
{
    int length = s.length();

    if (length == 0)
        return string("");

    if (length == 1)
        return s;

    bool dp[length][length];
    int i, j;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (i >= j)
                dp[i][j] = true;
            else
                dp[i][j] = false;
        }
    }

    int k;
    int maxLen = 1;
    int rf = 0;
    int rt = 0;

    for (k = 1; k < length; k++) {
        for (i = 0; k + i < length; i++) {
            j = i + k;
            if (s[i] != s[j])
                dp[i][j] = false;
            else {
                dp[i][j] = dp[i + 1][j - 1];
                if (dp[i][j]) {
                    if (k + 1 > maxLen) {
                        maxLen = k + 1;
                        rf = i;
                        rt = j;
                    }
                }
            }
        }
    }
    return s.substr(rf, rt - rf + 1);
}

int main()
{
    string str;
    
    cout << "Please enter the string to judge: ";
    cin >> str;
    cout << "The longest palindromic substring of " << str << " is: "; 
    cout << FindLongestPalindromicSubstring(str) << endl;

    return 0;
}
