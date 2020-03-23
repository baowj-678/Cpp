#include <iostream>
#include <string>
#include "basic_array_function.h"

using namespace::std;
char* SLC(string A, string B, int a, int b);

int main()
{
    string A, B;
    cout << "Please Input string A:" << endl;
    cin >> A;
    cout << "Please Input string B:" << endl;
    cin >> B;
    cout << "The longest subsequence is:" << endl;
    SLC(A, B, A.length(), B.length());

}

char* SLC(string A, string B, int a, int b)
{
    if(a == 0 || b == 0)
        return 0;
    // init the data
    char** Max = create_two_dim_array(a, b);
    char** Record = create_two_dim_array(a, b);
    int i, j, k, length;
    k = 0;
    //init the matrix
    for(i = 0; i < a; i++)
    {
        if(A[i] == B[0])
        {
            k = 1;
            Record[i][0] = 0;
        }
        else
        {
            Record[i][0] = 't';
        }
        Max[i][0] = k;
    }
    k = 0;
    for(i = 0; i < b; i++)
    {
        if(A[0] == B[i])
        {
            k = 1;
            Record[0][i] = 0;
        }
        else
        {
            Record[0][i] = 'l';
        }
        Max[0][i] = k;
    }
    //fill max and record matrix
    for(i = 1; i < a; i++)
    {
        for(j = 1; j < b; j++)
        {
            if(A[i] == B[j])
            {
                Max[i][j] = Max[i - 1][j - 1] + 1;
                Record[i][j] = 0;
            }
            else
            {
                if(Max[i - 1][j] > Max[i][j - 1])
                {
                    Max[i][j] = Max[i - 1][j];
                    Record[i][j] = 't';
                }
                else
                {
                    Max[i][j] = Max[i][j - 1];
                    Record[i][j] = 'l';
                } 
            }
        }
    }

    /*cout << "Max:" << endl;
    array_print_two_dim(Max, a, b);
    cout << "Record:" <<endl;
    array_print_two_dim(Record, a, b);*/

    i = a - 1, j = b - 1;
    k = Max[i][j];
    length = 0;
    char* ans = new char[k];
    k--;
    for(; i >= 0 && j >= 0; )
    {
        if(Record[i][j] == 0)
        {
            ans[k--] = A[i];
            i--;
            j--;
        }
        else if(Record[i][j] == 't')
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    for(i = 0; i < Max[a - 1][b - 1]; i++)
        cout << ans[i];
    cout << endl;
    del_two_dim_array(Max, a);
    del_two_dim_array(Record, a);
    return ans;
}

