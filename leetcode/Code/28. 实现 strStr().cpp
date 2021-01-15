#include <iostream>
#include <string>

using namespace::std;

int strStr(string haystack, string needle) {
	int x = haystack.find(needle);
	return x;
}
int main()
{
	string haystack, needle;
	cin >> haystack;
	cin >> needle;
	cout << strStr(haystack, needle);
}

//accepted
