#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<sstream>
#include<string.h>
#include"list.h"
#include"thesis.h" 
using namespace std;
char c=' '; 

//���ļ�����������Ϣ�����浽������
void List::input_info()
{
 int num=0;//���ĵı��
 string thes;//��������
 string name;//������
 string abst;//����ժҪ
 string journal;//�����ڿ�
 string year;//�������
 string link;//��������

 List *current=NULL;//ָ��ǰ����ָ��
 List *previous=NULL;//ָ��ǰһ������ָ��

 ifstream in;
 in.open("thesis.txt",ios::in);//�������ļ��������򴴽�(ifstreamĬ�ϵĴ򿪷�ʽ)
 string line;
if(in){

 //��������
 while(getline(in,line))
 {
	 string dir;
	string dir_list[50];
	int i=0;
	
	stringstream ss(line);
	while(getline(ss, dir, '#')){
		dir_list[i] = dir;
		i++;
	}

 thes=dir_list[0];
name=dir_list[1];
 journal=dir_list[2];
  year=dir_list[3];
 link=dir_list[4];
 abst=dir_list[5];

 ++num;
 // new ����
 current=new List;//�����½��
 current->data=new thesis(thes,name,journal,year,link,abst);


 if(previous==NULL)
 pHead=current;//����ͷ���
 if(previous!=NULL)
 previous->pNext=current;//����ǰһ�����ĵ�ַ

 current->data->set_num(num);

 current->pNext=NULL;
 previous=current;
 }
}else{
	cout <<"Fail to open the file!" << endl;  
}
 in.close();//�ر��ļ�

 /*
 ifstream fin;
 fin.open("thesis.txt",ios::in);
 if(!fin)
 {
 cout<<"Fail to open the file!"<<endl;
 exit(0);
 }
 //��������
 while(1)
 {
 //�ж��Ƿ�����ļ�
 if(!(fin>>thes>>name>>journal>>year>>link>>abst))
 break;
 else{
 ++num;
 // new ����
 current=new List;//�����½��
 current->data=new thesis(thes,name,journal,year,link,abst);
 }

 if(previous==NULL)
 pHead=current;//����ͷ���
 if(previous!=NULL)
 previous->pNext=current;//����ǰһ�����ĵ�ַ

 current->data->set_num(num);

 current->pNext=NULL;
 previous=current;
 }
 fin.close();//�ر��ļ�
 */

}
 
void List::output_info()
{
 List *p=pHead;//����ͷ�ڵ�
 int num=0;//���ñ��
 cout<<"���\t"<<"��������\t\t\t\t"<<"������  "<<"�����ڿ�       "<<"������� "<<"��������\t\t\t\t"<<"����ժҪ\t\t"<<endl;
 while(p!=NULL)
 {
 ++num;
 p->data->set_num(num);
 p->data->display_info();
 p=p->pNext;
 }
}

//�����������ƽ���ģ������
void List::fuzzy_search_by_thes(){
	List *p=pHead;//����ͷ�ڵ�
	int flag=0;//��������Ƿ��ҵ���Ӧ������
	char key[1000];
	cout<<"������ؼ��֣�";
	cin.getline(key,1000);//��������ո�
	cout<<"���\t"<<"��������\t\t\t\t"<<"������  "<<"�����ڿ�       "<<"������� "<<"��������\t\t\t\t"<<"����ժҪ\t\t"<<endl;
	while(p!=NULL){
		char buf[1000];
		strcpy(buf,p->data->thes.c_str());//�����������ַ���תΪ�ַ�����
		if(strstr(buf,key)!=NULL){//strstr()����
			++flag;
			p->data->display_info();
		}
		p=p->pNext;
	}
	if(flag==0)
		cout<<"Can't find this thesis��"<<endl;
}
//����������ģ������������Ϣ
void List::fuzzy_search_by_name()
{
 List *p=pHead;//����ͷ�ڵ�
 int flag=0;//��������Ƿ��ҵ���Ӧ������
 char key[1000];
cout<<"������ؼ��֣�";
cin.getline(key,1000);
 cout<<"���\t"<<"��������\t\t\t\t"<<"������  "<<"�����ڿ�       "<<"������� "<<"��������\t\t\t\t"<<"����ժҪ\t\t"<<endl;
 while(p!=NULL){
 char buf[1000];
	strcpy(buf,p->data->name.c_str());
if(strstr(buf,key)!=NULL){	
 ++flag;
 p->data->display_info();
 }
 p=p->pNext;
 }
 if(flag==0)
 cout<<"Can't find this thesis��"<<endl;
}
//���ݳ������ģ������������Ϣ
void List::fuzzy_search_by_year()
{
 List *p=pHead;//����ͷ�ڵ�
 int flag=0;//��������Ƿ��ҵ���Ӧ������
char key[10];
cout<<"������ؼ��֣�";
cin>>key;
cout<<"���\t"<<"��������\t\t\t\t"<<"������  "<<"�����ڿ�       "<<"������� "<<"��������\t\t\t\t"<<"����ժҪ\t\t"<<endl;
while(p!=NULL){
	char buf[10];
	strcpy(buf,p->data->year.c_str());
if(strstr(buf,key)!=NULL){	
++flag;
 p->data->display_info();
 }
 p=p->pNext;
 }
if(flag==0)
cout<<"Can't find this thesis��"<<endl;
}
//���ݳ����ڿ�ģ������������Ϣ
void List::fuzzy_search_by_journal()
{
 List *p=pHead;//����ͷ�ڵ�
 int flag=0;//��������Ƿ��ҵ���Ӧ������
char key[1000];
cout<<"������ؼ��֣�";
cin.getline(key,1000);
cout<<"���\t"<<"��������\t\t\t\t"<<"������  "<<"�����ڿ�       "<<"������� "<<"��������\t\t\t\t"<<"����ժҪ\t\t"<<endl;
while(p!=NULL){
	char buf[1000];
	strcpy(buf,p->data->journal.c_str());
if(strstr(buf,key)!=NULL){	
++flag;
 p->data->display_info();
 }
 p=p->pNext;
 }
if(flag==0)
cout<<"Can't find this thesis��"<<endl;
}
//��������ժҪ����ģ������
void List::fuzzy_search_by_abst()
{
List *p=pHead;//����ͷ�ڵ�
 int flag=0;//��������Ƿ��ҵ���Ӧ������
char key[2000];
cout<<"������ؼ��֣�";
cin.getline(key,2000);
cout<<"���\t"<<"��������\t\t\t\t"<<"������  "<<"�����ڿ�       "<<"������� "<<"��������\t\t\t\t"<<"����ժҪ\t\t"<<endl;
while(p!=NULL){
	char buf[2000];
	strcpy(buf,p->data->abst.c_str());
if(strstr(buf,key)!=NULL){	
++flag;
 p->data->display_info();
 }
 p=p->pNext;
 }
if(flag==0)
cout<<"Can't find this thesis��"<<endl;

}

 List* cut(List*& head) { //Ѱ�Ҵ���һ�������м�Ľڵ�
	List PP;
	PP.pHead=head;
	List* p=PP.pHead;
  List* q = head;
  List* second_head=NULL;
  List* h;
  List* g;
  while(q && q->pNext) {//������ָ��ͬʱ��, ����һ������һ�����ٶȵ�����
    q = q->pNext;
    if(q->pNext) {
      p = p->pNext;
      q = q->pNext;
    }
  }
  second_head =p->pNext;
  p->pNext = NULL;
  for(h=PP.pHead,g=head;h->pNext!=NULL;h=h->pNext,g=g->pNext)  //����ֵ��һ��һ����ֵ������ֱ����=
	  g=h;
  return second_head;
}

//����������������
 /*void List::sort_by_thes(){
	   List *p=NULL;
 List *q=NULL;
 string thes1,thes2;
 for(p=pHead;p->pNext!=NULL;p=p->pNext)
 for(q=p->pNext;q!=NULL;q=q->pNext)
 {
 thes1=p->data->thesis::get_thes();//���û���ĺ����õ����ĳ������
 thes2=q->data->thesis::get_thes();
 if(thes1>thes2)
 {
 List temp;//��ʱ������
 temp.data=p->data;
 p->data=q->data;
 q->data=temp.data;
 }
 }
  }*/
  List* merge1(List*& head, List*& mid) {
  List tmp;
  List *p = &tmp, *q = head, *t = mid;
  string thes1,thes2;
 
  while(q && t) {
	   thes1=q->data->thesis::get_thes();//���û���ĺ����õ����ĳ������
       thes2=t->data->thesis::get_thes();
    if(thes1 <= thes2) {
      p->pNext= q;
      p = p->pNext;
      q = q->pNext;
    }
    else {
      p->pNext= t;
      p = p->pNext;
      t = t->pNext;
    }
  }
  
  while(q){
	  p->pNext=q;
	  q=q->pNext;
	   p=p->pNext;
  }
  while(t){
	p->pNext=t;
	t=t->pNext;
	 p=p->pNext;
  }
  /*
  if(q) 
    p->pNext = q;
  else
    p->pNext = t;*/
 return tmp.pNext;
}
  void mergesort1(List*& head) {
  if(head->pNext) {
    List *mid=cut(head);
    mergesort1(head);
    mergesort1(mid);
    head = merge1(head, mid);
  }
}
 void List::sort_by_thes(){
List *p=pHead;
mergesort1(p);
pHead=p;//��Ҫ����ȻpHead���ǵ�һ��
  }

  //���ݳ����ڿ�����
/*  void List::sort_by_journal(){
  List *p=NULL;
 List *q=NULL;
 string jour1,jour2;
 for(p=pHead;p->pNext!=NULL;p=p->pNext)
 for(q=p->pNext;q!=NULL;q=q->pNext)
 {
 jour1=p->data->thesis::get_journal();//���û���ĺ����õ����ĳ������
 jour2=q->data->thesis::get_journal();
 if(jour1>jour2)
 {
 List temp;//��ʱ������
 temp.data=p->data;
 p->data=q->data;
 q->data=temp.data;
 }
 }
  }
 */
 List* merge2(List*& head, List*& mid) {
  List tmp;
  List *p = &tmp, *q = head, *t = mid;
  string jour1,jour2;
 
  while(q && t) {
	   jour1=q->data->thesis::get_journal();//���û���ĺ����õ����ĳ������
       jour2=t->data->thesis::get_journal();
    if(jour1 <= jour2) {
      p->pNext= q;
      p = p->pNext;
      q = q->pNext;
    }
    else {
      p->pNext= t;
      p = p->pNext;
      t = t->pNext;
    }
  }
  
  while(q){
	  p->pNext=q;
	  q=q->pNext;
	   p=p->pNext;
  }
  while(t){
	p->pNext=t;
	t=t->pNext;
	 p=p->pNext;
  }
  /*
  if(q) 
    p->pNext = q;
  else
    p->pNext = t;*/
 return tmp.pNext;
}
 void mergesort2(List*& head) {
  if(head->pNext) {
    List *mid=cut(head);
    mergesort2(head);
    mergesort2(mid);
    head = merge2(head, mid);
  }
}
 void List::sort_by_journal(){
List *p=pHead;
mergesort2(p);
pHead=p;//��Ҫ����ȻpHead���ǵ�һ��
  }

List* merge3(List*& head, List*& mid){       //�ϲ�����
	List tmp;
	List* h;
	List* g;
	List *p = &tmp, *q = head, *t = mid;    //p�������δ����ݴ�С����Ľڵ�
	string year1,year2;
	
	while(q && t){
		year1 = q->data->thesis::get_year();//���û���ĺ����õ����ĳ������
        year2 = t->data->thesis::get_year();
        if(year1 <= year2){
			p->pNext = q;
			p = p->pNext;
			q = q->pNext;
		}else{
			p->pNext = t;p = p->pNext;
			t = t->pNext;
		}
	}
	
	while(q){                  //�����������ܻ�ʣһ����
		p->pNext = q;
		q = q->pNext;
		p = p->pNext;//
	}
	while(t){
		p->pNext = t;
		t = t->pNext;
		p = p->pNext;
	}
	return tmp.pNext;
}

void mergesort3(List*& head){
	if(head->pNext){
    List *mid = cut(head); //�ҳ������м�ڵ�ĵ�ַ
    mergesort3(head); //�ݹ�
    mergesort3(mid);
    head = merge3(head,mid);  //�ϲ����������ź�˳�������
	}
}

  //���ݳ����������
 void List::sort_by_year(){
	 /*             //�Ż�ǰ��ð�������㷨
	 List *p=NULL;
     List *q=NULL;
     string year1,year2;
     for(p=pHead;p->pNext!=NULL;p=p->pNext)
     for(q=p->pNext;q!=NULL;q=q->pNext)
	 {
		 year1=p->data->thesis::get_year();//���û���ĺ����õ����ĳ������
		 year2=q->data->thesis::get_year();
		 if(year1>year2)
		 {
			 List temp;//��ʱ������
			 temp.data=p->data;
			 p->data=q->data;
			 q->data=temp.data;
		 }
	 }*/
	 List *p = pHead;
	 mergesort3(p);
	 pHead = p;//��Ҫ����ȻpHead����û��
  }
 

//����������Ϣ
void List::add_info(){
	int num=0;//���ĵı��
    char thes1[1000];//��������
	char name1[1000];//������
	char abst1[2000];//����ժҪ
	char journal1[1000];//�����ڿ�
	char year1[10];//�������
	char link1[1000];//��������
	string thes;string name;string journal;string year;string link;string abst;
	int location=0;//λ�ñ��
	int flag=0;//����Ƿ��ж�Ӧ�ı��
	List *p=pHead;//ָ��ǰ����ָ��
	List *pf=NULL;//ָ��ǰһ������ָ��
	List *new_node;//ָ����������ָ��
	cout<<"�������������ӵ���Ϣ��λ�ã�λ�ñ��,����0����";
	cin>>location;
	c=getchar();//����һ������֮��Ļس���������getline�����ȥ
	while(p!=NULL){//��������
		num=p->data->get_num();
		if(num==location){
			++flag;
			while(1){
				cout<<"���������ĵ���Ϣ��"<<endl;
				new_node=new List;//����һ���µĽ��
				cout<<"��������\t\t\t\t"<<"������  "<<"�����ڿ�       "<<"������� "<<"��������\t\t\t\t"<<"����ժҪ\t\t"<<endl;
				cin.getline(thes1,1000);cin.getline(name1,1000);cin.getline(journal1,1000);
				while(1){
					cin.getline(year1,10);
					year=year1;
					if(year.size()!=4||year<"1900"||year>"2021")//
						cout<<"������������ȷ����ݣ�";
					else
						break;
				}
				cin.getline(link1,1000);cin.getline(abst1,2000);
				thes=thes1;name=name1;journal=journal1;link=link1;abst=abst1;
				List *q=pHead;
				List *f=NULL;//��¼pָ���ǰһ��ָ��
				while(q!=NULL){//��������
					if((thes!=q->data->thes||name!=q->data->name||journal!=q->data->journal||year!=q->data->year||link!=q->data->link||abst!=q->data->abst)&&(q=q->pNext)){
						f=q;//������Ϣ���ظ���pָ����һ�������Ƚ�
	                    //q=q->pNext;
					}else
						break;//�����ظ����������˳�����
				}
				if(thes!=f->data->thes||name!=f->data->name||journal!=f->data->journal||year!=f->data->year||link!=f->data->link||abst!=f->data->abst)
					break;//��������궼���ظ�������������ڵ�
				cout<<"�������Ѵ��ڣ����������룡";//������������
			}
			
			new_node->data=new thesis(thes,name,journal,year,link,abst);
			if(pf==NULL){
				new_node->pNext=p;
				pHead=new_node;
				break;
			}else{
				new_node->pNext=p;
				pf->pNext=new_node;
				break;
			}
		}
		pf=p;
		p=p->pNext;
	}


	if(flag==0){//û���ҵ������λ�ñ�ţ���Ĭ�Ͻ�������Ϣ�������
		while(1){
			cout<<"���������ĵ���Ϣ"<<endl;
			new_node=new List;//����һ���µĽ��
			cout<<"��������\t\t\t\t"<<"������  "<<"�����ڿ�       "<<"������� "<<"��������\t\t\t\t"<<"����ժҪ\t\t"<<endl;
			cin.getline(thes1,1000);cin.getline(name1,1000);cin.getline(journal1,1000);
			while(1){
				cin.getline(year1,10);
				year=year1;
				if(year.size()!=4||year<"1900"||year>"2021")
					cout<<"������������ȷ����ݣ�";
				else
					break;
			}
			cin.getline(link1,1000);cin.getline(abst1,2000);
			thes=thes1;name=name1;journal=journal1;link=link1;abst=abst1;

			List *q=pHead;
			List *f=NULL;
			while(q!=NULL){//��������
				if((thes!=q->data->thes||name!=q->data->name||journal!=q->data->journal||year!=q->data->year||link!=q->data->link||abst!=q->data->abst)&&(q=q->pNext)){
					f=q;
				}
				else
					break;
			}
			if(thes!=f->data->thes||name!=f->data->name||journal!=f->data->journal||year!=f->data->year||link!=f->data->link||abst!=f->data->abst)
				break;
			cout<<"�������Ѵ��ڣ����������룡";
		}

		new_node->data=new thesis(thes,name,journal,year,link,abst);
		pf->pNext=new_node;
		new_node->pNext=NULL;
	}
}

//ɾ��ָ�����ĵ���Ϣ
void List::delete_info_by_thes(){
	string thes;//��������

	List *p=pHead;//ָ��ǰ����ָ��
	List *pf=NULL;//ָ��ǰһ������ָ��

	char content[1000];
	c=getchar();
	cout<<"��������Ϣ��ɾ���������ƣ�";
	cin.getline(content,1000);

	int flag=0;//����Ƿ��ҵ���Ӧ���ģ�
	string na=content;//���ַ�������ת����string����
	char answer;//��¼�ش������

	while(p!=NULL){
		thes=p->data->get_thes();
		if(thes==na){
			flag++;
			cout<<"���\t"<<"��������\t\t\t\t"<<"������  "<<"�����ڿ�       "<<"������� "<<"��������\t\t\t\t"<<"����ժҪ\t\t"<<endl;
			p->data->display_info();

			cout<<"��ȷ��Ҫɾ��������Ϣ��(Y/N)";
			cin>>answer;
			if(tolower(answer)=='y'){
				if(pf==NULL){
					delete p->data;//ɾ��������Ϣ��ռ�ڴ�
					List *temp=p;//��ʱ����ָ��ý���ָ��
				    pHead=p->pNext;//������ǰ��㣬ʵ����Ϣ��ɾ��
					delete temp;//������ռ�ڴ�ɾ��
				}else{
					delete p->data;//ɾ��������Ϣ��ռ�ڴ�
					List *temp=p;//��ʱ����ָ��ý���ָ��
					pf->pNext=p->pNext;//������ǰ��㣬ʵ����Ϣ��ɾ��
					delete temp;//������ռ�ڴ�ɾ��
				}

				cout<<"\t������Ϣ��ɾ����"<<endl;
				break;
			}else{
				break;
			}
		}
		pf=p;//���浱ǰָ��
		p=p->pNext;//����ָ��ָ����һ�����
	}
	if(flag==0)
		cout<<"û���ҵ������ģ�"<<endl;
}
void List::delete_info_by_num(){
int n;//��������

 List *p=pHead;//ָ��ǰ����ָ��
 List *pf=NULL;//ָ��ǰһ������ָ��

 int content;
 cout<<"��������Ϣ��ɾ�����ı�ţ�";
 cin>>content;

 int flag=0;//����Ƿ��ҵ���Ӧ���ģ�
 char answer;//��¼�ش������

 while(p!=NULL)
 {
 //++n;
 n=p->data->get_num();
 if(n==content)
 {
 flag++;
 cout<<"���\t"<<"��������\t\t\t\t"<<"������  "<<"�����ڿ�       "<<"������� "<<"��������\t\t\t\t"<<"����ժҪ\t\t"<<endl;
 p->data->display_info();

 cout<<"��ȷ��Ҫɾ��������Ϣ��(Y/N)";
 cin>>answer;
 if(tolower(answer)=='y')
 {
  if(pf==NULL)
  {
  delete p->data;//ɾ��������Ϣ��ռ�ڴ�
  List *temp=p;//��ʱ����ָ��ý���ָ��
  pHead=p->pNext;//������ǰ��㣬ʵ����Ϣ��ɾ��
  delete temp;//������ռ�ڴ�ɾ��
  }
  else
  {
  delete p->data;//ɾ��������Ϣ��ռ�ڴ�
  List *temp=p;//��ʱ����ָ��ý���ָ��
  pf->pNext=p->pNext;//������ǰ��㣬ʵ����Ϣ��ɾ��
  delete temp;//������ռ�ڴ�ɾ��
  }

  cout<<"\t������Ϣ��ɾ����"<<endl;
  break;
 }
 else
 {
  break;
 }
 }
 pf=p;//���浱ǰָ��
 p=p->pNext;//����ָ��ָ����һ�����
 }
 if(flag==0)
 cout<<"û���ҵ������ģ�"<<endl;
 }

//�޸�ָ��������Ϣ
void List::update_info_by_thes(){
	string thes;//��������

	List *p=pHead;//ָ��ǰ����ָ��
	List *pf=NULL;//ָ��ǰһ������ָ��

	char content[1000];
	c=getchar();
	cout<<"��������Ϣ���޸����ĵ����ƣ�";
	cin.getline(content,1000);

	int flag=0;//����Ƿ��ҵ���Ӧ���ģ�
	string na=content;//���ַ�������ת����string����
	char answer;//��¼�ش������

	while(p!=NULL){
		thes=p->data->get_thes();
		if(thes==na){
			flag++;
			cout<<"���\t"<<"��������\t\t\t\t"<<"������  "<<"�����ڿ�       "<<"������� "<<"��������\t\t\t\t"<<"����ժҪ\t\t"<<endl;
			p->data->display_info();

			cout<<"��ȷ��Ҫ�޸�������Ϣ��(Y/N)";
			cin>>answer;
			if(tolower(answer)=='y'){
				int serial;
				char m[2000];
				string modify;
				cout<<"��������Ҫ�޸ĵ����ݣ�1 �������� 2 ������ 3 �����ڿ� 4 ������� 5 �������� 6 ����ժҪ(����ѡ�������)"<<endl;
				cin>>serial;
				c=getchar();
				switch(serial){
				case 1:
					cout<<"�������뽫���޸�Ϊʲô��"<<endl;
					cin.getline(m,2000);
					modify=m;
					p->data->thes=modify;
					cout<<"\t������Ϣ���޸ģ�"<<endl;
					break;
				case 2:
					cout<<"�������뽫���޸�Ϊʲô��"<<endl;
					cin.getline(m,2000);
					modify=m;
					p->data->name=modify;
					cout<<"\t������Ϣ���޸ģ�"<<endl;
					break;
				case 3:
					cout<<"�������뽫���޸�Ϊʲô��"<<endl;
					cin.getline(m,2000);
					modify=m;
					p->data->journal=modify;
					cout<<"\t������Ϣ���޸ģ�"<<endl;
					break;
				case 4:
					cout<<"�������뽫���޸�Ϊʲô��"<<endl;
					while(1){
						cin.getline(m,2000);
						modify=m;
						if(modify.size()!=4||modify<"1900"||modify>"2021")//�ַ������ͱȽϲ���
							cout<<"������������ȷ����ݣ�";
						else{
							p->data->year=modify;
							break;
						}
					}
					cout<<"\t������Ϣ���޸ģ�"<<endl;
					break;
				case 5:
					cout<<"�������뽫���޸�Ϊʲô��"<<endl;
					cin.getline(m,2000);
					modify=m;
					p->data->link=modify;
					cout<<"\t������Ϣ���޸ģ�"<<endl;
					break;
				case 6:
					cout<<"�������뽫���޸�Ϊʲô��"<<endl;
					cin.getline(m,2000);
					modify=m;
					p->data->abst=modify;
					cout<<"\t������Ϣ���޸ģ�"<<endl;
					break;
				}
			}
			else
			{
				break;
			}
		}
		pf=p;//���浱ǰָ��
		p=p->pNext;//����ָ��ָ����һ�����
	}
	if(flag==0)
		cout<<"û���ҵ������ģ�"<<endl;
}
void List::update_info_by_num(){
int n;//���ı��

 List *p=pHead;//ָ��ǰ����ָ��
 List *pf=NULL;//ָ��ǰһ������ָ��

 int content;
 cout<<"��������Ϣ���޸����ĵı�ţ�";
 cin>>content;

 int flag=0;//����Ƿ��ҵ���Ӧ���ģ�
 char answer;//��¼�ش������

 while(p!=NULL)
 {
 //++n;
 n=p->data->get_num();
 if(n==content)
 {
 flag++;
 cout<<"���\t"<<"��������\t\t\t\t"<<"������  "<<"�����ڿ�       "<<"������� "<<"��������\t\t\t\t"<<"����ժҪ\t\t"<<endl;
 p->data->display_info();

 cout<<"��ȷ��Ҫ�޸�������Ϣ��(Y/N)";
 cin>>answer;
 if(tolower(answer)=='y')
 {
  int serial;
  char m[2000];
	 string modify;
  cout<<"��������Ҫ�޸ĵ����ݣ�1 �������� 2 ������ 3 �����ڿ� 4 ������� 5 �������� 6 ����ժҪ(����ѡ�������)"<<endl;
  cin>>serial;
   c=getchar();
  switch(serial){
  case 1:
	  cout<<"�������뽫���޸�Ϊʲô��"<<endl;
  cin.getline(m,2000);
  modify=m;
  p->data->thes=modify;
  cout<<"\t������Ϣ���޸ģ�"<<endl;
  break;
  case 2:
	  cout<<"�������뽫���޸�Ϊʲô��"<<endl;
 cin.getline(m,2000);
  modify=m;
  p->data->name=modify;
  cout<<"\t������Ϣ���޸ģ�"<<endl;
  break;
  case 3:
	  cout<<"�������뽫���޸�Ϊʲô��"<<endl;
  cin.getline(m,2000);
  modify=m;
  p->data->journal=modify;
  cout<<"\t������Ϣ���޸ģ�"<<endl;
  break;
  case 4:
	  cout<<"�������뽫���޸�Ϊʲô��"<<endl;
 /* cin.getline(m,2000);
  modify=m;
  p->data->year=modify*/;
  while(1){
	 cin.getline(m,2000);
	  modify=m;
	 if(modify.size()!=4||modify<"1900"||modify>"2021")//�ַ������ͱȽϲ���
		 cout<<"������������ȷ����ݣ�";
	 else{
		 p->data->year=modify;
		 break;}
 }
  cout<<"\t������Ϣ���޸ģ�"<<endl;
  break;
  case 5:
	  cout<<"�������뽫���޸�Ϊʲô��"<<endl;
  cin.getline(m,2000);
  modify=m;
  p->data->link=modify;
  cout<<"\t������Ϣ���޸ģ�"<<endl;
  break;
  case 6:
	  cout<<"�������뽫���޸�Ϊʲô��"<<endl;
  cin.getline(m,2000);
  modify=m;
  p->data->abst=modify;
  cout<<"\t������Ϣ���޸ģ�"<<endl;
  break;
 }
 }
 else
 {
  break;
 }
 }
 pf=p;//���浱ǰָ��
 p=p->pNext;//����ָ��ָ����һ�����
 }
 if(flag==0)
 cout<<"û���ҵ������ģ�"<<endl;
 }

//�������浽�ļ���
void List::save_list()
{
 List *p=pHead;//�������������ָ��
 ofstream fout;
 fout.open("thesis.txt",ios::out);//��д���ļ��������򴴽������ļ��Ѵ��������ԭ����(ofstreamĬ�ϵĴ򿪷�ʽ)
 while(p!=NULL)
 {
 p->data->save_node(fout);
 p=p->pNext;
 }
 fout.close();//�ر��ļ�
}
//��������
void List::delete_list()
{
 List *p=pHead;
 List *pt;
 while(p!=NULL)
 {
 pt=p;
 p=p->pNext;
 delete pt->data;//ɾ��������Ϣ��ռ�ڴ�
 delete pt;//ɾ����������ռ�ڴ�
 }
 pt=NULL;
 pHead=NULL;
 p=NULL;
}