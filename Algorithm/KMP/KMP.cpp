/**
* @Title: KMP
* @Author: Bao Wenjie
* @Email: bwj_678@qq.com
* @Date: 2021/8/19
*/
#include <stdio.h>
#include <string.h>
#define MAXN 10000

char W[MAXN];
char S[MAXN];
int Next[MAXN];

int KMP(char s[], char w[], int s_len, int w_len);
void get_next(char w[], int w_len, int next[]);

int main()
{
    printf("Input S:\n");
    scanf("%s", S);
    int s_len = strlen(S);
    printf("Input W:\n");
    scanf("%s", W);
    int w_len = strlen(W);
    printf("%d\n", KMP(S, W, s_len, w_len));
}

void get_next(char w[], int w_len, int next[])
{
    next[0] = 0;
    int i = 1, j = 0;
    while(i < w_len)
    {
        if(i > 1 && w[i - 1] == w[j])
            next[i++] = next[j++] + 1;
        else if(j == 0)
            next[i++] = 0;
        else
            j = next[j];
    }
}

int KMP(char s[], char w[], int s_len, int w_len)
{
    get_next(w, w_len, Next);
    for(int i = 0, j = 0; i < s_len;)
    {
        if(s[i] == w[j])
        {
            i++;
            j++;
        }
        else
        {
            j = Next[j];
            i++;
        } 
        if(j == w_len)
            return i - w_len + 1;
    }
    return -1;
}