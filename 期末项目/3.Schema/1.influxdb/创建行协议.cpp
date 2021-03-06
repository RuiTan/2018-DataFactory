// 创建行协议.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"


// csv处理.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
//删除字符串中空格，制表符tab等无效字符
string Trim(string& str)
{
	//str.find_first_not_of(" \t\r\n"),在字符串str中从索引0开始，返回首次不匹配"\t\r\n"的位置
	str.erase(0, str.find_first_not_of(" \t\r\n"));
	str.erase(str.find_last_not_of(" \t\r\n") + 1);
	return str;
}
string deal(string genre) {
	
	string::size_type idx;
	idx = genre.find(",");
	while(idx != string::npos)
	{
		
		genre.insert(idx, "\\");
		idx = genre.find(",",idx+2);
	}
	idx = genre.find(" ");
	while (idx != string::npos)
	{

		genre.insert(idx, "\\");
		idx = genre.find(" ", idx + 2);
	}
	return genre;
}

int main()
{
	int num = 0;
	ifstream fin;//打开文件流操作
	ifstream lin;
	ifstream gin;
	ofstream outfile;
	outfile.open("F:\\m.txt", ios::app);
	fin.open("F:\\temp.txt", ios::in);
	lin.open("F:\\language.txt", ios::in);
	gin.open("F:\\genre.txt", ios::in);
	string line;
	string a;
	string::size_type idx;
	string id;
	string watchNum;
	string releaseTime;
	string language;
	string genre;
	while (!fin.eof())   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
	{
		getline(fin, line);
		istringstream sin(line); //将整行字符串line读入到字符串流istringstream中
		vector<string> fields; //声明一个字符串向量
		string field;
		while (getline(sin, field, ',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
		{
			fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
		}
		id = fields[0];
		watchNum = fields[1];
		releaseTime = fields[2];
		getline(lin, language);
		getline(gin, genre);
		genre = deal(genre);
		language = deal(language);
		
		outfile << "test,language="<<language<<",genre="<<genre<<" watchNum=" << watchNum <<",id=\"" << id <<"\" "<< releaseTime << "000000000" << endl;
	}
	cout << "success!" << endl;
	outfile.close();
	fin.close();
	gin.close();
	lin.close();
	return 0;
}

