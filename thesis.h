#ifndef _thesis_H
#define _thesis_H
#include<iostream>
#include<cstring>
#include<sstream>
#include<fstream>
using namespace std;

class thesis
{
public://����ʵ�ַ�װ�ԣ���ΪҪʵ��������Ϣ���޸�
 int num;//���ĵı��
 string thes;//��������
 string name;//������
 string abst;//����ժҪ
 string journal;//�����ڿ�
 string year;//�������
 string link;//��������

public:
 thesis(){}//�޲����Ĺ��캯��
 thesis(string _thes,string _name,string _journal,string _year,string _link,string _abst);//�������Ĺ��캯��
 thesis(const thesis& thesis);//�������캯��
 virtual ~thesis(){}//��������
public:
 //����������Ϣ��غ���
 void set_num(int n);//�������ĵı��
 void set_thes(string th);//������������
 void set_name(string na);//����������
 void set_abst(string ab);//��������ժҪ
 void set_journal(string jour);//���ó����ڿ�
 void set_year(string a);//���ó������
 void set_link(string li);//������������


 //��ȡ������Ϣ��غ���
 int get_num();//��ȡ���ĵı��
 string get_thes();//�����������
 string get_name();//���������
 string get_abst();//�������ժҪ
 string get_journal();//��ó����ڿ�
 string get_year();//��ó������
 string get_link();//������������


 virtual void display_info();//��������Ϣ��ӡ����Ļ��
 virtual void save_node(ofstream& fout);//��������Ϣ���浽�ļ���

};
#endif // _thesis_H