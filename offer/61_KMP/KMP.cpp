#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* core(char* str)
{
    int i = 0;
    int length = strlen(str);
    int* next = new int[length];
    next[0] = -1;
    int j = -1;
    while (i < length - 1) {
        if (j == -1 || str[i] == str[j]) {
            ++i;++j;
            if (str[i] != str[j])
                next[i] = j;
            else
                next[i] = next[j];
        } else
            j = next[j];
    }

    return next;
}

int kmp(char* s, char* ss)
{
    int* next = core(ss);
    int i = 0;
    int j = 0;
    int index = 0;

    while (s[i] != '\0' && ss[j] != '\0') {
        if (s[i] == ss[j]) {
            ++i;++j;
        } else {
            index += j - next[j];
            if (next[j] != -1)
                j = next[j];
            else {
                j = 0;
                ++i;
            }
        }
    }

    if (ss[j] == '\0')
        return index;
    else
        return -1;
}

int main()
{
    char s[100];
    char ss[100];
    scanf("%s %s", s, ss);
    int index = kmp(s, ss);
    printf("index=%d\n", index);
    
    return 0;
}
