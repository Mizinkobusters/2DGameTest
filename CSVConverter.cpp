#include <fstream>
#include <string>
#include "CSVConverter.h"

// 区切り文字で区切られた1行分のデータから動的1次元配列を生成する関数
std::vector<int> Split(std::string str, char delimiter)
{
	std::vector<int> result;

	for (size_t first = 0, last = 0; first < str.size(); first = last + 1)
	{
		last = str.find(delimiter, first);
		if (last == std::string::npos)
		{
			last = str.size();
		}
		std::string s = str.substr(first, last - first);

		int x = atoi(s.c_str());

		result.push_back(x);
	}
	return result;
}

// CSV形式ファイルから動的2次元配列を生成する関数
std::vector<std::vector<int> > Convert(const char* filename)
{
	std::string line;
	std::vector<std::vector<int> > data;

	std::ifstream ifs(filename);
	if (ifs)
	{
		while (std::getline(ifs, line) && line.size() > 0)
		{
			std::vector<int> temp = Split(line, ',');
			data.push_back(temp);
		}
		ifs.close();
	}
	return data;
}