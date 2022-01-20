#ifndef _thesis_H
#define _thesis_H
#include<iostream>
#include<cstring>
#include<sstream>
#include<fstream>
using namespace std;

class thesis
{
public://不能实现封装性，因为要实现论文信息的修改
 int num;//论文的编号
 string thes;//论文名称
 string name;//作者名
 string abst;//论文摘要
 string journal;//出版期刊
 string year;//出版年份
 string link;//论文链接

public:
 thesis(){}//无参数的构造函数
 thesis(string _thes,string _name,string _journal,string _year,string _link,string _abst);//含参数的构造函数
 thesis(const thesis& thesis);//拷贝构造函数
 virtual ~thesis(){}//析构函数
public:
 //设置论文信息相关函数
 void set_num(int n);//设置论文的编号
 void set_thes(string th);//设置论文名称
 void set_name(string na);//设置作者名
 void set_abst(string ab);//设置论文摘要
 void set_journal(string jour);//设置出版期刊
 void set_year(string a);//设置出版年份
 void set_link(string li);//设置论文链接


 //获取论文信息相关函数
 int get_num();//获取论文的编号
 string get_thes();//获得论文名称
 string get_name();//获得作者名
 string get_abst();//获得论文摘要
 string get_journal();//获得出版期刊
 string get_year();//获得出版年份
 string get_link();//设置论文链接


 virtual void display_info();//将论文信息打印到屏幕上
 virtual void save_node(ofstream& fout);//将论文信息保存到文件中

};
#endif // _thesis_H