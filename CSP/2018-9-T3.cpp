/**
* Topic: CSP-2018-9-样式选择器
* Author: Bao Wenjie
* Email: bwj_678@qq.com
* Date: 2020/8/21
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace::std;

struct Line {
	int tag;
	string id;
	int tab;
	vector<int> parents;
};
typedef Line* pLine;
map<string, int> Tag2Num;


bool search(string querry, pLine* doc, int index);
vector<int> find(int tag, string id, pLine* doc, int n);
int main()
{
	// 输入
	int n, m;
	scanf_s("%d%d", &n, &m);
	string s;
	getline(cin, s);
	pLine* doc = new pLine[n];
	// 读取文档
	for (int i(0); i < n; i++)
	{
		getline(cin, s);
		pLine tmp = new Line;
		int tab = 0;
		int start = -1;
		int blank = 0;
		for (int j(0); j < s.length(); j++)
		{
			if (s[j] == '.')
				tab++;
			else
			{
				if (start == -1)
					start = j;
				else
				{
					if (s[j] == ' ')
						blank = j;
				}
			}
		}
		// 无属性标签
		if (blank == 0)
		{
			string tag = s.substr(start, s.length() - start);
			int tag_num = Tag2Num.size();
			map<string, int>::iterator itor = Tag2Num.find(tag);
			// 已有该标签
			if (itor != Tag2Num.end())
			{
				tag_num = itor->second;
			}
			else
			{
				Tag2Num.insert(pair<string, int>(tag, tag_num));
			}
			tmp->tab = (tab /= 2);
			tmp->tag = tag_num;
			tmp->id = "";
			// 寻找父节点
			for (int j(i - 1); j >= 0; j--)
			{
				if (doc[j]->tab == tab - 1)
					tmp->parents.push_back(j);
				else
					break;
			}
		}
		else
		{
			string tag = s.substr(start, blank - start);
			string id = s.substr(blank + 1, s.length() - blank - 1);
			int tag_num = Tag2Num.size();
			map<string, int>::iterator itor = Tag2Num.find(tag);
			// 已有该标签
			if (itor != Tag2Num.end())
			{
				tag_num = itor->second;
			}
			else
			{
				Tag2Num.insert(pair<string, int>(tag, tag_num));
			}
			tmp->tab = (tab /= 2);
			tmp->id = id;
			tmp->tag = tag_num;
			// 寻找父节点
			for (int j(i - 1); j >= 0; j--)
			{
				if (doc[j]->tab == tab - 1)
					tmp->parents.push_back(j);
				else
					break;
			}
		}
		//
		doc[i] = tmp;
	}
	// 读入查询
	vector<vector<int>> ans;
	for (int i(0); i < m; i++)
	{
		getline(cin, s);
		string tag = "";
		string id = "";
		int end = s.length();
		for (int j = (s.length() - 1); j>= 0; j--)
		{
			if (s[j] == ' ')
			{
				// 属性
				if (s[j + 1] == '#')
				{
					if (id != "")
					{
						break;
					}
					id = s.substr(j + 1, end - j);
					end = j;
					continue;
				}
				// 标签
				else
				{
					tag = s.substr(j + 1, end - j);
					end = j;
					break;
				}
			}
		}
		if (tag == "" && id == "")
		{
			if (s[0] == '#')
				id = s;
			else
				tag = s;
			end = 0;
		}
		int tag_;
		if (tag == "")
			tag_ = -1;
		else
		{
			transform(tag.begin(), tag.end(), tag.begin(), ::tolower);
			map<string, int>::iterator itor = Tag2Num.find(tag);
			// 不存在该标签
			if (itor == Tag2Num.end())
				tag_ = -2;
			else
				tag_ = itor->second;
		}
		vector<int> vec = find(tag_, id, doc, n);
		string querry = s.substr(0, end);
		vector<int>::iterator itor_vec = vec.begin();
		while(itor_vec != vec.end())
		{
			if (search(querry, doc, *itor_vec) == false)
			{
				itor_vec = vec.erase(itor_vec);
			}
			else
			{
				itor_vec++;
			}
		}
		vec.insert(vec.begin(), vec.size() - 1);
		ans.push_back(vec);
	}
	vector<vector<int>>::iterator itor = ans.begin();
	while (itor != ans.end())
	{
		vector<int>::iterator innor_itor = itor->begin();
		while (innor_itor != itor->end())
		{
			printf("%d ", *innor_itor + 1);
			innor_itor++;
		}
		printf("\n");
		itor++;
	}

}

/**
* 判断在index之前是否存在查询
*/
bool search(string querry, pLine* doc, int index)
{
	if (querry == "")
		return true;
	else
	{
		int i;
		for (i = querry.length() - 1; i >= 0; i--)
		{
			if (querry[i] == ' ')
				break;
		}
		string tag;
		if (i == -1)
		{
			tag = querry;
			querry = "";
		}
		else
		{
			tag = querry.substr(i + 1, querry.length());
			querry = querry.substr(0, i);
		}
		map<string, int>::iterator itor = Tag2Num.find(tag);
		vector<int> vec = doc[index]->parents;
		bool isOK = false;
		vector<int>::iterator itor_vec = vec.begin();
		while (itor_vec != vec.end())
		{
			if (search(querry, doc, *itor_vec))
			{
				isOK = true;
				break;
			}
			itor_vec++;
		}
		return isOK;
	}
}

vector<int> find(int tag, string id, pLine* doc, int n)
{
	vector<int> vec;
	for (int i(0); i < n; i++)
	{
		if (tag == -1 || tag == doc[i]->tag)
		{
			if (id == "" || id == doc[i]->id)
			{
				vec.push_back(i);
			}
		}
	}
	return vec;
}