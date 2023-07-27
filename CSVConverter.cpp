#include <fstream>
#include <string>
#include "CSVConverter.h"

// ��؂蕶���ŋ�؂�ꂽ1�s���̃f�[�^���瓮�I1�����z��𐶐�����֐�
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

// CSV�`���t�@�C�����瓮�I2�����z��𐶐�����֐�
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