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
 cout<<"��ѡ����Ҫ���еĲ�����";
 cin>>choice;
 switch(choice)
 {
 //��Ϣά������
 case 1:
 while(1)
 {
  pHead.input_info();
  system("cls");
  menu1();
  cout<<"��ѡ����Ҫ���еĲ�����";
  cin>>choice1;
  switch(choice1)
  {
  //����������Ϣ
  case 1:
  pHead.output_info();//������������ӡ���ĵ���Ϣ
  pHead.add_info();//����������Ϣ
  system("cls");
  cout<<"\n\n\n\t\t������Ϣ�����£�"<<endl;
  pHead.output_info();//������������ӡ���ĵ���Ϣ
  pHead.save_list();//���Ķ����浽�ļ���
  cout<<"\n�Ķ��ѱ��浽�ļ���"<<endl<<endl;
  system("pause");
   system("cls");
  break;
  //ɾ��������Ϣ
  case 2:
  pHead.output_info();//������������ӡ���ĵ���Ϣ
  pHead.delete_info_by_thes();//ɾ��������Ϣ
  system("cls");
  cout<<"\n\n\n\t\t������Ϣ�����£�"<<endl;
  pHead.output_info();//������������ӡ���ĵ���Ϣ
  pHead.save_list();//���Ķ����浽�ļ���
  cout<<"\n�Ķ��ѱ��浽�ļ���"<<endl<<endl;
  system("pause");
   system("cls");
  break;
   case 3:
  pHead.output_info();//������������ӡ���ĵ���Ϣ
  pHead.delete_info_by_num();//ɾ��������Ϣ
  system("cls");
  cout<<"\n\n\n\t\t������Ϣ�����£�"<<endl;
  pHead.output_info();//������������ӡ���ĵ���Ϣ
  pHead.save_list();//���Ķ����浽�ļ���
  cout<<"\n�Ķ��ѱ��浽�ļ���"<<endl<<endl;
  system("pause");
   system("cls");
  break;
  case 4:
  pHead.output_info();//������������ӡ���ĵ���Ϣ
  pHead.update_info_by_thes();//�޸�������Ϣ
  system("cls");
  cout<<"\n\n\n\t\t������Ϣ�����£�"<<endl;
  pHead.output_info();//������������ӡ���ĵ���Ϣ
  pHead.save_list();//���Ķ����浽�ļ���
  cout<<"\n�Ķ��ѱ��浽�ļ���"<<endl<<endl;
  system("pause");
  system("cls");
  break;
   case 5:
  pHead.output_info();//������������ӡ���ĵ���Ϣ
  pHead.update_info_by_num();//�޸�������Ϣ
  system("cls");
  cout<<"\n\n\n\t\t������Ϣ�����£�"<<endl;
  pHead.output_info();//������������ӡ���ĵ���Ϣ
  pHead.save_list();//���Ķ����浽�ļ���
  cout<<"\n�Ķ��ѱ��浽�ļ���"<<endl<<endl;
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

 //��Ϣ��ѯ����
 case 2:
 while(1)
 {
  system("cls");
  menu2();
  cout<<"��ѡ����Ҫ���еĲ�����";
  cin>>choice2;
  c=getchar();//����س�
  switch(choice2)
  {
  //���������ƽ���ģ����ѯ
   case 1:
 pHead.fuzzy_search_by_thes();
  system("pause");
  system("cls");
  break;
  //������������ģ����ѯ
  case 2:
  pHead.fuzzy_search_by_name();
  system("pause");
  system("cls");
  break;
  //�������ڿ�����ģ����ѯ
   case 3:
  pHead.fuzzy_search_by_journal();
  system("pause");
  system("cls");
  break; 
  //��������ݽ���ģ����ѯ
   case 4:
  pHead.fuzzy_search_by_year();
  system("pause");
  system("cls");
  break;
   //������ժҪ����ģ����ѯ
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


 //������
 case 3:
 while(1)
 {
  system("cls");
  menu3();
  cout<<"��ѡ����Ҫ���еĲ�����";
  cin>>choice3;
  switch(choice3)
  {
  //����������������
  case 1:
  pHead.sort_by_thes();
  pHead.output_info();
  cout<<endl;
  system("pause");
   system("cls");
 pHead.input_info();
  break;
  case 2:
  //���ݳ����ڿ�����
  pHead.sort_by_journal();
  pHead.output_info();
  cout<<endl;
  system("pause");
   system("cls");
    pHead.input_info();
  break;
  case 3:
  //���ݳ����������
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
