/**
 * Author: Bao Wenjie
 * Date: 2021/3/23
 * Link: https://leetcode-cn.com/problems/flatten-nested-list-iterator/
 */
 
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace::std;

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
	vector<NestedInteger> list;
	stack<int> now_p;
    NestedIterator(vector<NestedInteger> &nestedList) {
        this->list = nestedList;
    }
    
    
    int next() {
        bool find = false;
        return this->next(this->list, this->now_p, find);
    }

	int next(vector<NestedInteger> l, stack<int>& s, bool& find)
	{
    	if(s.empty()) //Õ»Îª¿Õ
    	{
            int ans;
    		if(l[0].isInteger())
    		{
                ans = l[0].getInteger();
                find = true;
    		}
            else
            {
                ans = this->next(l[0].getList(), s, find);
            }
            s.push(0);
            return ans;
    	}
    	
        int p = s.top();
        s.pop();
    	if(l[p].isInteger())
    	{
    		if(++p >= l.size())
    		{
                find = false;
                return 0;
            }
    	}
    	
        int ans = this->next(l[p].getList(), s, find);
        if(find)
        {
            s.push(p);
            return ans;
        }
        else
        {
            if(++p < l.size())
            {
                int ans = this->next(l[p].getList(), s, find);
                s.push(p);
                return ans;
            }
            else
            {
                find = false;
                return 0;
            }
        }
    }

    bool hasNext() {
        return this->hasNext(this->list, this->now_p);
    }
    bool hasNext(vector<NestedInteger> l, stack<int>& s)
    {
    	if(s.empty())
    	{
            if (l.size() > 0)
                return true;
            return false;
    	}
    	int p = s.top();
    	if(p + 1 < l.size())
    	{
    		return true;
		}
		else
		{
			if(l[p].isInteger())
			{
                return false;
			}
            else
            {
                s.pop();
                bool ans = this->hasNext(l[p].getList(), s);
                s.push(p);
                return ans;
            }
		}
	}
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
