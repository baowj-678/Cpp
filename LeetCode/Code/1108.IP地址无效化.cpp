#include <iostream>
#include <string>

using namespace::std;

string defangIPaddr(string address) 
{
	string new_address;
	for (int i(0); i < address.length(); i++)
	{
		if (address[i] != '.')
		{
			new_address.push_back(address[i]);
		}
		else
		{
			new_address.append("[.]");
		}
	}

	return new_address;
}

int main()
{
	string address = "1.1.1.1";
	cout << defangIPaddr(address) << endl;

}