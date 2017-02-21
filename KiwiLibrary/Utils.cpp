#include "stdafx.h"

#include "Utils.h"

vector<char> splitJamo(wchar_t c)
{
	static char choTable[] = { 1, 2, 4, 7, 8, 9, 17, 18, 19, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 };
	static char jongTable[] = { 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 26, 27, 28, 29, 30 };
	auto t = c - 0xAC00;
	vector<char> ret;
	int jong = t % 28;
	int jung = (t / 28) % 21;
	int cho = (t / 28 / 21);
	if(cho != 11) ret.push_back(choTable[cho]);
	ret.push_back(jung + 31);
	if (jong) ret.push_back(jongTable[jong - 1]);
	return move(ret);
}

vector<char> splitJamo(wstring hangul)
{
	static char choTable[] = { 1, 2, 4, 7, 8, 9, 17, 18, 19, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 };
	static char jongTable[] = { 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23, 24, 26, 27, 28, 29, 30 };
	vector<char> ret;
	for (auto c : hangul)
	{
		auto t = c - 0xAC00;
		int jong = t % 28;
		int jung = (t / 28) % 21;
		int cho = (t / 28 / 21);
		if (cho != 11) ret.push_back(choTable[cho]);
		ret.push_back(jung + 31);
		if (jong) ret.push_back(jongTable[jong - 1]);
	}
	return move(ret);
}