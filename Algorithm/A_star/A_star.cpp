/**
* Description: A*Ëã·¨
* Author: Bao Wenjie
* Date: 2021/1/16
* Github: https://github.com/baowj-678
*/

#include <vector>
#include <set>
using namespace::std;

struct Location {
	int x;
	int y;
};

vector<Location> A_star(vector<vector<int>> Map, int start_x, int start_y, int end_x, int end_y, int obstacle)
{
	int Y = Map.size();
	int X = Map[0].size();
	set<long long> open_set;
	set<long long> close_set;
}


int main()
{

}