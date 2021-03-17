/**
 * Author: Bao Wenjie
 * Date: 2021/3/17
 * Link: https://leetcode-cn.com/problems/distinct-subsequences/
 */

#include<iostream>
#include <vector>
using namespace::std;

class Solution {
public:
    int numDistinct(string s, string t) {
    	int n = t.length(), m = s.length();
    	if(n == 0)
    	{
    		return 1;
		}
		else if(m == 0)
		{
			return 0;
		}
    	vector<long long> result(m, 0);
    	if(s[0] == t[0])
    		result[0] = 1;
    	for(int j = 1; j < m; j++)
    	{
    		if(s[j] == t[0])
    		{
    			result[j] = result[j-1] + 1;
			}
			else
			{
				result[j] = result[j-1];
			}
		}
		
    	for(int i = 1; i < n; i++) // t
    	{
			for(int j = m-1; j >= 0; j--) // s
			{
				if(s[j] == t[i])
				{
					if(j > 0)
					{
						result[j] = result[j-1];
					}
					else
					{
						result[j] = 0;
					}
				}
				else
				{
					result[j] = 0;
				}
			}
			for(int j = 1; j < m; j++)
			{
				result[j] += result[j-1];
			}

		}
		return result[m-1];
    }
};


int main()
{
	string s = "xslledayhxhadmctrliaxqpokyezcfhzaskeykchkmhpyjipxtsuljkwkovmvelvwxzwieeuqnjozrfwmzsylcwvsthnxujvrkszqwtglewkycikdaiocglwzukwovsghkhyidevhbgffoqkpabthmqihcfxxzdejletqjoxmwftlxfcxgxgvpperwbqvhxgsbbkmphyomtbjzdjhcrcsggleiczpbfjcgtpycpmrjnckslrwduqlccqmgrdhxolfjafmsrfdghnatexyanldrdpxvvgujsztuffoymrfteholgonuaqndinadtumnuhkboyzaqguwqijwxxszngextfcozpetyownmyneehdwqmtpjloztswmzzdzqhuoxrblppqvyvsqhnhryvqsqogpnlqfulurexdtovqpqkfxxnqykgscxaskmksivoazlducanrqxynxlgvwonalpsyddqmaemcrrwvrjmjjnygyebwtqxehrclwsxzylbqexnxjcgspeynlbmetlkacnnbhmaizbadynajpibepbuacggxrqavfnwpcwxbzxfymhjcslghmajrirqzjqxpgtgisfjreqrqabssobbadmtmdknmakdigjqyqcruujlwmfoagrckdwyiglviyyrekjealvvigiesnvuumxgsveadrxlpwetioxibtdjblowblqvzpbrmhupyrdophjxvhgzclidzybajuxllacyhyphssvhcffxonysahvzhzbttyeeyiefhunbokiqrpqfcoxdxvefugapeevdoakxwzykmhbdytjbhigffkmbqmqxsoaiomgmmgwapzdosorcxxhejvgajyzdmzlcntqbapbpofdjtulstuzdrffafedufqwsknumcxbschdybosxkrabyfdejgyozwillcxpcaiehlelczioskqtptzaczobvyojdlyflilvwqgyrqmjaeepydrcchfyftjighntqzoo";
	string t = "rwmimatmhydhbujebqehjprrwfkoebcxxqfktayaaeheys";
	Solution solution;
	cout << solution.numDistinct(s, t);
}
