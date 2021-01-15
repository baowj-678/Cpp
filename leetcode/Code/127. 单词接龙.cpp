//给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
//
//每次转换只能改变一个字母。
//转换过程中的中间单词必须是字典中的单词。
//说明 :
//
//如果不存在这样的转换序列，返回 0。
//所有单词具有相同的长度。
//所有单词只由小写字母组成。
//字典中不存在重复的单词。
//你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
//示例 1 :
//
//输入:
//beginWord = "hit",
//endWord = "cog",
//wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
//
//输出 : 5
//
//解释 : 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//返回它的长度 5。
//示例 2 :
//
//    输入 :
//    beginWord = "hit"
//    endWord = "cog"
//    wordList = ["hot", "dot", "dog", "lot", "log"]
//
//    输出 : 0
//
//    解释 : endWord "cog" 不在字典中，所以无法进行转换。
//
//    来源：力扣（LeetCode）
//    链接：https ://leetcode-cn.com/problems/word-ladder
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace::std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> s2b_map;
        unordered_map<string, vector<string>> s2s_map;
        for (auto s : wordList)
        {
            vector<string> tmp;
            for (auto key : s2s_map)
            {
                if (canSwitch(key.first, s))
                {
                    s2s_map[key.first].push_back(s);
                    tmp.push_back(key.first);
                }
            }
            s2s_map.insert(pair<string, vector<string>>{s, tmp});
            s2b_map.insert(pair<string, bool>{s, false});
        }
        queue<string> Q;
        int times = 0;
        Q.push(beginWord);
        Q.push("#");
        while (Q.size() > 1)
        {
            string tmp = Q.front();
            Q.pop();
            if (tmp == endWord)
                return times;
            else if (tmp == "#")
            {
                times++;
                Q.push("#");
                continue;
            }
            s2b_map[tmp] = true;
            vector<string> strs = s2s_map[tmp];
            for (string i : strs)
            {
                if (s2b_map[i] == true)
                    continue;
                Q.push(i);
            }
        }
        return 0;
    }
    bool canSwitch(string first, string second)
    {
        int cnt = 0;
        for (int i(0); i < first.size(); i++)
        {
            if (first[i] != second[i])
                cnt++;
        }
        return cnt == 1;
    }
};

int main()
{
    string begin = "hit";
    string end = "cog";
    vector<string> list = { "hot","dot","dog","lot","log","cog", "hit" };
    Solution so = Solution();
    cout<< so.ladderLength(begin, end, list);
}