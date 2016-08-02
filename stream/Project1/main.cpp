#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <algorithm>

using namespace std;

int main()
{
	string from, to;		//去的原文件名和目标文件名
	cin >> from >> to;

	ifstream is(from.c_str());			//输入流
	istream_iterator<string> ii(is);	//流的输入迭代器
	istream_iterator<string> eos;		//输入的哨兵

	vector<string> b(ii,eos);		//b 是一个向量，用输入进行初始化
	sort(b.begin(),b.end());		//对缓冲区排序

	ofstream os(to.c_str());
	ostream_iterator<string> oo(os,"\n");	//流的输出迭代器

	unique_copy(b.begin(),b.end(),oo);

	return !is.eof() || !os;

}
