#include<iostream>
#include<cstring>
#include<sstream>
#include"thesis.h"
#include<fstream>

using namespace std;

//含参数的构造函数
thesis::thesis(string _thes,string _name,string _journal,string _year,string _link,string _abst)
{
 thes=_thes;
 name=_name;
 abst=_abst;
 journal=_journal;
 year=_year;
 link=_link;
}
//拷贝构造函数
thesis::thesis(const thesis& thesis)
{
 thes=thesis.thes;
 name=thesis.name;
 abst=thesis.abst;
 journal=thesis.journal;
 year=thesis.year;
 link=thesis.link;
}
//设置论文的编号
void thesis::set_num(int n)
{
 num=n;
}
//设置论文名称
void thesis::set_thes(string th)
{
 thes=th;
}
//设置作者名
void thesis::set_name(string na)
{
 name=na;
}
//设置论文摘要
void thesis::set_abst(string ab)
{
 abst=ab;
}
//设置出版期刊
void thesis::set_journal(string jour)
{
 journal=jour;
}
//设置出版年份
void thesis::set_year(string a)
{
 year=a;
}
//设置论文链接
void thesis::set_link(string li)
{
 link=li;
}


//获取论文的编号
int thesis::get_num()
{
 return num;
}
//获得论文名称
string thesis::get_thes()
{
 return thes;
}
//获得作者名
string thesis::get_name()
{
 return name;
}
//获得论文摘要
string thesis::get_abst()
{
 return abst;
}
//获得出版期刊
string thesis::get_journal()
{
 return journal;
}
//获得出版年份
string thesis::get_year()
{
 return year;
}
//获得论文链接
string thesis::get_link()
{
 return link;
}


//将论文信息打印到屏幕上
void thesis::display_info()
{
 cout<<num<<'\t'<<thes.substr(0, 35)<<'\t'<<name.substr(0, 6)<<'\t'<<journal.substr(0, 10)<<'\t'<<year<<'\t'<<link.substr(0, 35)<<'\t'<<abst.substr(0, 35)<<'\t'<<endl;
}
//将论文信息保存到文件中
void thesis::save_node(ofstream& fout)
{
	fout<<thes<<'#'<<name<<'#'<<journal<<'#'<<year<<'#'<<link<<'#'<<abst<<endl;
}