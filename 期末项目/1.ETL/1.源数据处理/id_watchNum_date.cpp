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
//string Trim(string& str)
//{
//	//str.find_first_not_of(" \t\r\n"),在字符串str中从索引0开始，返回首次不匹配"\t\r\n"的位置
//	str.erase(0, str.find_first_not_of(" \t\r\n"));
//	str.erase(str.find_last_not_of(" \t\r\n") + 1);
//	return str;
//}
//int watchnum(string id) {
//	ifstream infile;
//	infile.open("F:\\r2.txt", ios::in);
//	int num=0;
//	string a;
//	string::size_type idx;
//	string d;
//	string b = "product/productId:";
//	while(!infile.eof())
//	{
//		getline(infile, a);
//		d = a;
//		idx = a.find(b);
//		if (idx == string::npos)
//		{
//		}
//		else {
//			d.erase(0, 19);
//			if (d == id) {
//				num++;
//				break;
//			}
//		}
//	}
//	if (num == 0){
//		infile.close();
//		return 0;
//	}
//		
//	else {
//		while (d == id) {
//			for(int i=0;i<3;i++)
//				getline(infile, a);
//			d = a;
//			idx = a.find(b);
//			if (idx == string::npos)
//			{
//				break;
//			}
//			else {
//				d.erase(0, 19);
//				if (d == id) {
//					num++;
//				}
//			}
//		}
//		infile.close();
//		return num;
//	}
//}

int main()
{
	string id="B000NDFLWG";
	int num=0;
	ifstream fin;//打开文件流操作
	ofstream outfile;
	outfile.open("F:\\csv.txt", ios::app);
	fin.open("F:\\movieoutput.txt", ios::in);
	outfile << "id,watchNum,first" << endl;
	string line;
	string a;
	string::size_type idx;
	string d;
	string b = "product/productId:";
	string e = "9999999999";
	while (!fin.eof())
	{
		getline(fin, a);
		d = a;
		idx = a.find(b);
		if (idx == string::npos)
		{
		}
		else {
			d.erase(0, 19);
			if (d == id) {
				num++;
				getline(fin, a);
				getline(fin, a);
				d = a;
				d.erase(0, 13);
				if (d < e) {
					e = d;
				}
			}
			else {

				outfile << id << "," << num << ","<<e<<"000000000"<<endl;
				id = d;
				num = 1;
				getline(fin, a);
				getline(fin, a);
				d = a;
				d.erase(0, 13);
				e = d;
			}
		}
	}
	//while (!fin.eof())   //整行读取，换行符“\n”区分，遇到文件尾标志eof终止读取
	//{
	//	getline(fin, line);
	//	//istringstream sin(line); //将整行字符串line读入到字符串流istringstream中
	//	//vector<string> fields; //声明一个字符串向量
	//	//string field;
	//	//while (getline(sin, field, ',')) //将字符串流sin中的字符读入到field字符串中，以逗号为分隔符
	//	//{
	//	//	fields.push_back(field); //将刚刚读取的字符串添加到向量fields中
	//	//}
	//	id = line;
	//	num = watchnum(id);
	//	outfile << id << "," << num << endl;
	//}
	cout << "success!" << endl;
	outfile.close();
	
	fin.close();
	return 0;
}

