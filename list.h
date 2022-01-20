#ifndef _LIST_H
#define _LIST_H
#include<iostream>
#include"thesis.h"
using namespace std;
class List
{
public:
 List(){}//无参数构造函数
public:
 void input_info();//从文件导入论文信息，保存到链表中
 void output_info();//将链表中的数据打印到屏幕上
public:
 void fuzzy_search_by_thes();//根据论文名称模糊查找论文信息
 void fuzzy_search_by_name();//根据作者名模糊查找论文信息
 void fuzzy_search_by_year();//根据出版年份模糊查找论文信息
 void fuzzy_search_by_journal();//根据出版期刊模糊查找论文信息
 void fuzzy_search_by_abst();//根据论文摘要模糊查找论文信息
public:
 void sort_by_thes();//根据论文名称进行排序
 void sort_by_year();//根据论文出版年份进行排序
 void sort_by_journal();//根据论文出版期刊进行排序
public:
 void add_info();//增加论文信息
 void delete_info_by_num();//删除指定论文的信息
  void delete_info_by_thes();//删除指定论文的信息
 void update_info_by_thes();//修改论文信息
 void update_info_by_num();//修改论文信息
public:
 void save_list();//将链表保存到文件中
 void delete_list();//销毁链表

public:
 List *pHead;//链表的头指针
 thesis *data;//指向论文信息的指针
 List *pNext;//指向下一个结点的指针
};
 
#endif // _LIST_H