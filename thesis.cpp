#include<iostream>
#include<cstring>
#include<sstream>
#include"thesis.h"
#include<fstream>

using namespace std;

//�������Ĺ��캯��
thesis::thesis(string _thes,string _name,string _journal,string _year,string _link,string _abst)
{
 thes=_thes;
 name=_name;
 abst=_abst;
 journal=_journal;
 year=_year;
 link=_link;
}
//�������캯��
thesis::thesis(const thesis& thesis)
{
 thes=thesis.thes;
 name=thesis.name;
 abst=thesis.abst;
 journal=thesis.journal;
 year=thesis.year;
 link=thesis.link;
}
//�������ĵı��
void thesis::set_num(int n)
{
 num=n;
}
//������������
void thesis::set_thes(string th)
{
 thes=th;
}
//����������
void thesis::set_name(string na)
{
 name=na;
}
//��������ժҪ
void thesis::set_abst(string ab)
{
 abst=ab;
}
//���ó����ڿ�
void thesis::set_journal(string jour)
{
 journal=jour;
}
//���ó������
void thesis::set_year(string a)
{
 year=a;
}
//������������
void thesis::set_link(string li)
{
 link=li;
}


//��ȡ���ĵı��
int thesis::get_num()
{
 return num;
}
//�����������
string thesis::get_thes()
{
 return thes;
}
//���������
string thesis::get_name()
{
 return name;
}
//�������ժҪ
string thesis::get_abst()
{
 return abst;
}
//��ó����ڿ�
string thesis::get_journal()
{
 return journal;
}
//��ó������
string thesis::get_year()
{
 return year;
}
//�����������
string thesis::get_link()
{
 return link;
}


//��������Ϣ��ӡ����Ļ��
void thesis::display_info()
{
 cout<<num<<'\t'<<thes.substr(0, 35)<<'\t'<<name.substr(0, 6)<<'\t'<<journal.substr(0, 10)<<'\t'<<year<<'\t'<<link.substr(0, 35)<<'\t'<<abst.substr(0, 35)<<'\t'<<endl;
}
//��������Ϣ���浽�ļ���
void thesis::save_node(ofstream& fout)
{
	fout<<thes<<'#'<<name<<'#'<<journal<<'#'<<year<<'#'<<link<<'#'<<abst<<endl;
}