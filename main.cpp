#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include"thesis.h"
#include"list.h"
using namespace std;

void menu();
void menu1();
void menu2();
void menu3();

int main(void)
{
char c=' ';
 int choice,choice1,choice2,choice3;
 string subj;
 List pHead;
 pHead.input_info();
 

 while(1)
 {
 menu();
 cout<<"请选择你要进行的操作：";
 cin>>choice;
 switch(choice)
 {
 //信息维护功能
 case 1:
 while(1)
 {
  pHead.input_info();
  system("cls");
  menu1();
  cout<<"请选择你要进行的操作：";
  cin>>choice1;
  switch(choice1)
  {
  //增加论文信息
  case 1:
  pHead.output_info();//遍历链表，并打印论文的信息
  pHead.add_info();//增加论文信息
  system("cls");
  cout<<"\n\n\n\t\t论文信息表（更新）"<<endl;
  pHead.output_info();//遍历链表，并打印论文的信息
  pHead.save_list();//将改动保存到文件中
  cout<<"\n改动已保存到文件中"<<endl<<endl;
  system("pause");
   system("cls");
  break;
  //删除论文信息
  case 2:
  pHead.output_info();//遍历链表，并打印论文的信息
  pHead.delete_info_by_thes();//删除论文信息
  system("cls");
  cout<<"\n\n\n\t\t论文信息表（更新）"<<endl;
  pHead.output_info();//遍历链表，并打印论文的信息
  pHead.save_list();//将改动保存到文件中
  cout<<"\n改动已保存到文件中"<<endl<<endl;
  system("pause");
   system("cls");
  break;
   case 3:
  pHead.output_info();//遍历链表，并打印论文的信息
  pHead.delete_info_by_num();//删除论文信息
  system("cls");
  cout<<"\n\n\n\t\t论文信息表（更新）"<<endl;
  pHead.output_info();//遍历链表，并打印论文的信息
  pHead.save_list();//将改动保存到文件中
  cout<<"\n改动已保存到文件中"<<endl<<endl;
  system("pause");
   system("cls");
  break;
  case 4:
  pHead.output_info();//遍历链表，并打印论文的信息
  pHead.update_info_by_thes();//修改论文信息
  system("cls");
  cout<<"\n\n\n\t\t论文信息表（更新）"<<endl;
  pHead.output_info();//遍历链表，并打印论文的信息
  pHead.save_list();//将改动保存到文件中
  cout<<"\n改动已保存到文件中"<<endl<<endl;
  system("pause");
  system("cls");
  break;
   case 5:
  pHead.output_info();//遍历链表，并打印论文的信息
  pHead.update_info_by_num();//修改论文信息
  system("cls");
  cout<<"\n\n\n\t\t论文信息表（更新）"<<endl;
  pHead.output_info();//遍历链表，并打印论文的信息
  pHead.save_list();//将改动保存到文件中
  cout<<"\n改动已保存到文件中"<<endl<<endl;
  system("pause");
  system("cls");
  break;
  default:
  system("cls");
  break;
  }
  if(choice1!=1&&choice1!=2&&choice1!=2)
  break;
 }
 break;

 //信息查询功能
 case 2:
 while(1)
 {
  system("cls");
  menu2();
  cout<<"请选择你要进行的操作：";
  cin>>choice2;
  c=getchar();//读入回车
  switch(choice2)
  {
  //按论文名称进行模糊查询
   case 1:
 pHead.fuzzy_search_by_thes();
  system("pause");
  system("cls");
  break;
  //按作者名进行模糊查询
  case 2:
  pHead.fuzzy_search_by_name();
  system("pause");
  system("cls");
  break;
  //按出版期刊进行模糊查询
   case 3:
  pHead.fuzzy_search_by_journal();
  system("pause");
  system("cls");
  break; 
  //按出版年份进行模糊查询
   case 4:
  pHead.fuzzy_search_by_year();
  system("pause");
  system("cls");
  break;
   //按论文摘要进行模糊查询
  case 5:
 pHead.fuzzy_search_by_abst();
  system("pause");
  system("cls");
  break;
  default:
  system("cls");
  break;
  }
  if(choice2!=1&&choice2!=2&&choice2!=3&&choice2!=4)
  break;
 }
 break;


 //排序功能
 case 3:
 while(1)
 {
  system("cls");
  menu3();
  cout<<"请选择你要进行的操作：";
  cin>>choice3;
  switch(choice3)
  {
  //根据论文名称排序
  case 1:
  pHead.sort_by_thes();
  pHead.output_info();
  cout<<endl;
  system("pause");
   system("cls");
 pHead.input_info();
  break;
  case 2:
  //根据出版期刊排序
  pHead.sort_by_journal();
  pHead.output_info();
  cout<<endl;
  system("pause");
   system("cls");
    pHead.input_info();
  break;
  case 3:
  //根据出版年份排序
  pHead.sort_by_year();
  pHead.output_info();
  cout<<endl;
  system("pause");
   system("cls");
    pHead.input_info();
  break;
  default:
  system("cls");
  break;
  }
  if(choice3!=1&&choice3!=2&&choice3!=3)
  break;
 }
 break;
 default:
 return 0;
 }
 }
 pHead.delete_list();
 return 0;
}
