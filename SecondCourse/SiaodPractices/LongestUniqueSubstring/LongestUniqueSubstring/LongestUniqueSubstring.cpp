#include <iostream>
#include <vector>


int main()
{
	int length = 0;
	int max = 0;
	std::string s = "dvdf";
	std::vector<char> uniqueSubstr;
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < uniqueSubstr.size(); j++)
		{
			if (s[i] == uniqueSubstr[j])
			{
				if (max < length) max = length;
				length = 0;
				for (int k = i - 1; k >= 0; k--)
				{
					if (s[k] == uniqueSubstr[j])
					{
						i = k + 1;
						break;
					}
				}
				uniqueSubstr.clear();
				break;
			}
		}
		uniqueSubstr.push_back(s[i]);
		length++;
	}
	if (max < length) max = length;
	std::cout << max;
}