#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <algorithm>

using namespace std;

int main()
{
	string from, to;		//ȥ��ԭ�ļ�����Ŀ���ļ���
	cin >> from >> to;

	ifstream is(from.c_str());			//������
	istream_iterator<string> ii(is);	//�������������
	istream_iterator<string> eos;		//������ڱ�

	vector<string> b(ii,eos);		//b ��һ����������������г�ʼ��
	sort(b.begin(),b.end());		//�Ի���������

	ofstream os(to.c_str());
	ostream_iterator<string> oo(os,"\n");	//�������������

	unique_copy(b.begin(),b.end(),oo);

	return !is.eof() || !os;

}
