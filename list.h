#ifndef _LIST_H
#define _LIST_H
#include<iostream>
#include"thesis.h"
using namespace std;
class List
{
public:
 List(){}//�޲������캯��
public:
 void input_info();//���ļ�����������Ϣ�����浽������
 void output_info();//�������е����ݴ�ӡ����Ļ��
public:
 void fuzzy_search_by_thes();//������������ģ������������Ϣ
 void fuzzy_search_by_name();//����������ģ������������Ϣ
 void fuzzy_search_by_year();//���ݳ������ģ������������Ϣ
 void fuzzy_search_by_journal();//���ݳ����ڿ�ģ������������Ϣ
 void fuzzy_search_by_abst();//��������ժҪģ������������Ϣ
public:
 void sort_by_thes();//�����������ƽ�������
 void sort_by_year();//�������ĳ�����ݽ�������
 void sort_by_journal();//�������ĳ����ڿ���������
public:
 void add_info();//����������Ϣ
 void delete_info_by_num();//ɾ��ָ�����ĵ���Ϣ
  void delete_info_by_thes();//ɾ��ָ�����ĵ���Ϣ
 void update_info_by_thes();//�޸�������Ϣ
 void update_info_by_num();//�޸�������Ϣ
public:
 void save_list();//�������浽�ļ���
 void delete_list();//��������

public:
 List *pHead;//�����ͷָ��
 thesis *data;//ָ��������Ϣ��ָ��
 List *pNext;//ָ����һ������ָ��
};
 
#endif // _LIST_H