#include <stdio.h>
#include <string.h>

#define N 100

char a[N], b[N], str[N];
int c[N][N];

int lcs_len(char* a, char* b, int c[][N])
{
    int m = strlen(a), n = strlen(b), i, j;

    for( i=0; i<=m; i++ )
        c[i][0]=0;
    for( i=0; i<=n; i++ )
        c[0][i]=0;

    for( i=1; i<=m; i++ )
    {
        for( j=1; j<=n; j++ )
        {
            if (a[i-1]==b[j-1])
                c[i][j]=c[i-1][j-1]+1;
            else if (c[i-1][j]>=c[i][j-1])
                c[i][j]=c[i-1][j];
            else
                c[i][j]=c[i][j-1];
        }
    }

    return c[m][n];
}

char* build_lcs(char s[], char* a, char* b)
{
    int i = strlen(a), j = strlen(b);
    int k = lcs_len(a,b,c);
    s[k] = '\0';
    while( k>0 )
    {
        if (c[i][j]==c[i-1][j])
            i--;
        else if (c[i][j]==c[i][j-1])
            j--;
        else
        {
            s[--k]=a[i-1];
            i--; j--;
        }
    }

    return s;
}

int main()
{
    printf("Enter two string (length < %d) :\n",N);
    scanf("%s%s",a,b);
    printf("LCS=%s\n",build_lcs(str,a,b));

    return 0;
}
