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

//从文件导入论文信息，保存到链表中
void List::input_info()
{
 int num=0;//论文的编号
 string thes;//论文名称
 string name;//作者名
 string abst;//论文摘要
 string journal;//出版期刊
 string year;//出版年份
 string link;//论文链接

 List *current=NULL;//指向当前结点的指针
 List *previous=NULL;//指向前一个结点的指针

 ifstream in;
 in.open("thesis.txt",ios::in);//供读，文件不存在则创建(ifstream默认的打开方式)
 string line;
if(in){

 //创建链表
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
 // new 对象
 current=new List;//创建新结点
 current->data=new thesis(thes,name,journal,year,link,abst);


 if(previous==NULL)
 pHead=current;//保存头结点
 if(previous!=NULL)
 previous->pNext=current;//保存前一个结点的地址

 current->data->set_num(num);

 current->pNext=NULL;
 previous=current;
 }
}else{
	cout <<"Fail to open the file!" << endl;  
}
 in.close();//关闭文件

 /*
 ifstream fin;
 fin.open("thesis.txt",ios::in);
 if(!fin)
 {
 cout<<"Fail to open the file!"<<endl;
 exit(0);
 }
 //创建链表
 while(1)
 {
 //判断是否读完文件
 if(!(fin>>thes>>name>>journal>>year>>link>>abst))
 break;
 else{
 ++num;
 // new 对象
 current=new List;//创建新结点
 current->data=new thesis(thes,name,journal,year,link,abst);
 }

 if(previous==NULL)
 pHead=current;//保存头结点
 if(previous!=NULL)
 previous->pNext=current;//保存前一个结点的地址

 current->data->set_num(num);

 current->pNext=NULL;
 previous=current;
 }
 fin.close();//关闭文件
 */

}
 
void List::output_info()
{
 List *p=pHead;//保存头节点
 int num=0;//设置编号
 cout<<"编号\t"<<"论文名称\t\t\t\t"<<"作者名  "<<"出版期刊       "<<"出版年份 "<<"论文链接\t\t\t\t"<<"论文摘要\t\t"<<endl;
 while(p!=NULL)
 {
 ++num;
 p->data->set_num(num);
 p->data->display_info();
 p=p->pNext;
 }
}

//按照论文名称进行模糊查找
void List::fuzzy_search_by_thes(){
	List *p=pHead;//保存头节点
	int flag=0;//用来标记是否找到对应的论文
	char key[1000];
	cout<<"请输入关键字：";
	cin.getline(key,1000);//可以输入空格
	cout<<"编号\t"<<"论文名称\t\t\t\t"<<"作者名  "<<"出版期刊       "<<"出版年份 "<<"论文链接\t\t\t\t"<<"论文摘要\t\t"<<endl;
	while(p!=NULL){
		char buf[1000];
		strcpy(buf,p->data->thes.c_str());//将论文名称字符串转为字符数组
		if(strstr(buf,key)!=NULL){//strstr()函数
			++flag;
			p->data->display_info();
		}
		p=p->pNext;
	}
	if(flag==0)
		cout<<"Can't find this thesis！"<<endl;
}
//根据作者名模糊查找论文信息
void List::fuzzy_search_by_name()
{
 List *p=pHead;//保存头节点
 int flag=0;//用来标记是否找到对应的论文
 char key[1000];
cout<<"请输入关键字：";
cin.getline(key,1000);
 cout<<"编号\t"<<"论文名称\t\t\t\t"<<"作者名  "<<"出版期刊       "<<"出版年份 "<<"论文链接\t\t\t\t"<<"论文摘要\t\t"<<endl;
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
 cout<<"Can't find this thesis！"<<endl;
}
//根据出版年份模糊查找论文信息
void List::fuzzy_search_by_year()
{
 List *p=pHead;//保存头节点
 int flag=0;//用来标记是否找到对应的论文
char key[10];
cout<<"请输入关键字：";
cin>>key;
cout<<"编号\t"<<"论文名称\t\t\t\t"<<"作者名  "<<"出版期刊       "<<"出版年份 "<<"论文链接\t\t\t\t"<<"论文摘要\t\t"<<endl;
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
cout<<"Can't find this thesis！"<<endl;
}
//根据出版期刊模糊查找论文信息
void List::fuzzy_search_by_journal()
{
 List *p=pHead;//保存头节点
 int flag=0;//用来标记是否找到对应的论文
char key[1000];
cout<<"请输入关键字：";
cin.getline(key,1000);
cout<<"编号\t"<<"论文名称\t\t\t\t"<<"作者名  "<<"出版期刊       "<<"出版年份 "<<"论文链接\t\t\t\t"<<"论文摘要\t\t"<<endl;
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
cout<<"Can't find this thesis！"<<endl;
}
//按照论文摘要进行模糊查找
void List::fuzzy_search_by_abst()
{
List *p=pHead;//保存头节点
 int flag=0;//用来标记是否找到对应的论文
char key[2000];
cout<<"请输入关键字：";
cin.getline(key,2000);
cout<<"编号\t"<<"论文名称\t\t\t\t"<<"作者名  "<<"出版期刊       "<<"出版年份 "<<"论文链接\t\t\t\t"<<"论文摘要\t\t"<<endl;
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
cout<<"Can't find this thesis！"<<endl;

}

 List* cut(List*& head) { //寻找处于一条链表中间的节点
	List PP;
	PP.pHead=head;
	List* p=PP.pHead;
  List* q = head;
  List* second_head=NULL;
  List* h;
  List* g;
  while(q && q->pNext) {//让两个指针同时走, 其中一个是另一个的速度的两倍
    q = q->pNext;
    if(q->pNext) {
      p = p->pNext;
      q = q->pNext;
    }
  }
  second_head =p->pNext;
  p->pNext = NULL;
  for(h=PP.pHead,g=head;h->pNext!=NULL;h=h->pNext,g=g->pNext)  //链表赋值，一个一个赋值，不能直接用=
	  g=h;
  return second_head;
}

//根据论文名称排序
 /*void List::sort_by_thes(){
	   List *p=NULL;
 List *q=NULL;
 string thes1,thes2;
 for(p=pHead;p->pNext!=NULL;p=p->pNext)
 for(q=p->pNext;q!=NULL;q=q->pNext)
 {
 thes1=p->data->thesis::get_thes();//调用基类的函数得到论文出版年份
 thes2=q->data->thesis::get_thes();
 if(thes1>thes2)
 {
 List temp;//临时结点对象
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
	   thes1=q->data->thesis::get_thes();//调用基类的函数得到论文出版年份
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
pHead=p;//重要！不然pHead还是第一个
  }

  //根据出版期刊排序
/*  void List::sort_by_journal(){
  List *p=NULL;
 List *q=NULL;
 string jour1,jour2;
 for(p=pHead;p->pNext!=NULL;p=p->pNext)
 for(q=p->pNext;q!=NULL;q=q->pNext)
 {
 jour1=p->data->thesis::get_journal();//调用基类的函数得到论文出版年份
 jour2=q->data->thesis::get_journal();
 if(jour1>jour2)
 {
 List temp;//临时结点对象
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
	   jour1=q->data->thesis::get_journal();//调用基类的函数得到论文出版年份
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
pHead=p;//重要！不然pHead还是第一个
  }

List* merge3(List*& head, List*& mid){       //合并排序
	List tmp;
	List* h;
	List* g;
	List *p = &tmp, *q = head, *t = mid;    //p用来依次存放年份从小到大的节点
	string year1,year2;
	
	while(q && t){
		year1 = q->data->thesis::get_year();//调用基类的函数得到论文出版年份
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
	
	while(q){                  //最后有链表可能会剩一两个
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
    List *mid = cut(head); //找出链表中间节点的地址
    mergesort3(head); //递归
    mergesort3(mid);
    head = merge3(head,mid);  //合并排序两段排好顺序的链表
	}
}

  //根据出版年份排序
 void List::sort_by_year(){
	 /*             //优化前的冒泡排序算法
	 List *p=NULL;
     List *q=NULL;
     string year1,year2;
     for(p=pHead;p->pNext!=NULL;p=p->pNext)
     for(q=p->pNext;q!=NULL;q=q->pNext)
	 {
		 year1=p->data->thesis::get_year();//调用基类的函数得到论文出版年份
		 year2=q->data->thesis::get_year();
		 if(year1>year2)
		 {
			 List temp;//临时结点对象
			 temp.data=p->data;
			 p->data=q->data;
			 q->data=temp.data;
		 }
	 }*/
	 List *p = pHead;
	 mergesort3(p);
	 pHead = p;//重要！不然pHead还是没变
  }
 

//增加论文信息
void List::add_info(){
	int num=0;//论文的编号
    char thes1[1000];//论文名称
	char name1[1000];//作者名
	char abst1[2000];//论文摘要
	char journal1[1000];//出版期刊
	char year1[10];//出版年份
	char link1[1000];//论文链接
	string thes;string name;string journal;string year;string link;string abst;
	int location=0;//位置编号
	int flag=0;//标记是否有对应的编号
	List *p=pHead;//指向当前结点的指针
	List *pf=NULL;//指向前一个结点的指针
	List *new_node;//指向新增结点的指针
	cout<<"请输入你想增加的信息的位置（位置编号,大于0）：";
	cin>>location;
	c=getchar();//读上一个输入之后的回车否则下面getline会读进去
	while(p!=NULL){//遍历链表
		num=p->data->get_num();
		if(num==location){
			++flag;
			while(1){
				cout<<"请输入论文的信息："<<endl;
				new_node=new List;//创建一个新的结点
				cout<<"论文名称\t\t\t\t"<<"作者名  "<<"出版期刊       "<<"出版年份 "<<"论文链接\t\t\t\t"<<"论文摘要\t\t"<<endl;
				cin.getline(thes1,1000);cin.getline(name1,1000);cin.getline(journal1,1000);
				while(1){
					cin.getline(year1,10);
					year=year1;
					if(year.size()!=4||year<"1900"||year>"2021")//
						cout<<"请重新输入正确的年份：";
					else
						break;
				}
				cin.getline(link1,1000);cin.getline(abst1,2000);
				thes=thes1;name=name1;journal=journal1;link=link1;abst=abst1;
				List *q=pHead;
				List *f=NULL;//记录p指针的前一个指针
				while(q!=NULL){//遍历链表
					if((thes!=q->data->thes||name!=q->data->name||journal!=q->data->journal||year!=q->data->year||link!=q->data->link||abst!=q->data->abst)&&(q=q->pNext)){
						f=q;//论文信息不重复则p指向下一个继续比较
	                    //q=q->pNext;
					}else
						break;//遇到重复的论文则退出遍历
				}
				if(thes!=f->data->thes||name!=f->data->name||journal!=f->data->journal||year!=f->data->year||link!=f->data->link||abst!=f->data->abst)
					break;//如果遍历完都不重复，则跳出存入节点
				cout<<"该论文已存在！请重新输入！";//否则重新输入
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


	if(flag==0){//没有找到输入的位置编号，则默认将论文信息加在最后
		while(1){
			cout<<"请输入论文的信息"<<endl;
			new_node=new List;//创建一个新的结点
			cout<<"论文名称\t\t\t\t"<<"作者名  "<<"出版期刊       "<<"出版年份 "<<"论文链接\t\t\t\t"<<"论文摘要\t\t"<<endl;
			cin.getline(thes1,1000);cin.getline(name1,1000);cin.getline(journal1,1000);
			while(1){
				cin.getline(year1,10);
				year=year1;
				if(year.size()!=4||year<"1900"||year>"2021")
					cout<<"请重新输入正确的年份：";
				else
					break;
			}
			cin.getline(link1,1000);cin.getline(abst1,2000);
			thes=thes1;name=name1;journal=journal1;link=link1;abst=abst1;

			List *q=pHead;
			List *f=NULL;
			while(q!=NULL){//遍历链表
				if((thes!=q->data->thes||name!=q->data->name||journal!=q->data->journal||year!=q->data->year||link!=q->data->link||abst!=q->data->abst)&&(q=q->pNext)){
					f=q;
				}
				else
					break;
			}
			if(thes!=f->data->thes||name!=f->data->name||journal!=f->data->journal||year!=f->data->year||link!=f->data->link||abst!=f->data->abst)
				break;
			cout<<"该论文已存在！请重新输入！";
		}

		new_node->data=new thesis(thes,name,journal,year,link,abst);
		pf->pNext=new_node;
		new_node->pNext=NULL;
	}
}

//删除指定论文的信息
void List::delete_info_by_thes(){
	string thes;//论文名称

	List *p=pHead;//指向当前结点的指针
	List *pf=NULL;//指向前一个结点的指针

	char content[1000];
	c=getchar();
	cout<<"请输入信息待删除论文名称：";
	cin.getline(content,1000);

	int flag=0;//标记是否找到对应论文；
	string na=content;//将字符串数组转化成string类型
	char answer;//记录回答的内容

	while(p!=NULL){
		thes=p->data->get_thes();
		if(thes==na){
			flag++;
			cout<<"编号\t"<<"论文名称\t\t\t\t"<<"作者名  "<<"出版期刊       "<<"出版年份 "<<"论文链接\t\t\t\t"<<"论文摘要\t\t"<<endl;
			p->data->display_info();

			cout<<"你确定要删除这组信息吗？(Y/N)";
			cin>>answer;
			if(tolower(answer)=='y'){
				if(pf==NULL){
					delete p->data;//删除论文信息所占内存
					List *temp=p;//暂时保存指向该结点的指针
				    pHead=p->pNext;//跳过当前结点，实现信息的删除
					delete temp;//将其所占内存删除
				}else{
					delete p->data;//删除论文信息所占内存
					List *temp=p;//暂时保存指向该结点的指针
					pf->pNext=p->pNext;//跳过当前结点，实现信息的删除
					delete temp;//将其所占内存删除
				}

				cout<<"\t该组信息已删除！"<<endl;
				break;
			}else{
				break;
			}
		}
		pf=p;//保存当前指针
		p=p->pNext;//设置指针指向下一个结点
	}
	if(flag==0)
		cout<<"没有找到该论文！"<<endl;
}
void List::delete_info_by_num(){
int n;//论文名称

 List *p=pHead;//指向当前结点的指针
 List *pf=NULL;//指向前一个结点的指针

 int content;
 cout<<"请输入信息待删除论文编号：";
 cin>>content;

 int flag=0;//标记是否找到对应论文；
 char answer;//记录回答的内容

 while(p!=NULL)
 {
 //++n;
 n=p->data->get_num();
 if(n==content)
 {
 flag++;
 cout<<"编号\t"<<"论文名称\t\t\t\t"<<"作者名  "<<"出版期刊       "<<"出版年份 "<<"论文链接\t\t\t\t"<<"论文摘要\t\t"<<endl;
 p->data->display_info();

 cout<<"你确定要删除这组信息吗？(Y/N)";
 cin>>answer;
 if(tolower(answer)=='y')
 {
  if(pf==NULL)
  {
  delete p->data;//删除论文信息所占内存
  List *temp=p;//暂时保存指向该结点的指针
  pHead=p->pNext;//跳过当前结点，实现信息的删除
  delete temp;//将其所占内存删除
  }
  else
  {
  delete p->data;//删除论文信息所占内存
  List *temp=p;//暂时保存指向该结点的指针
  pf->pNext=p->pNext;//跳过当前结点，实现信息的删除
  delete temp;//将其所占内存删除
  }

  cout<<"\t该组信息已删除！"<<endl;
  break;
 }
 else
 {
  break;
 }
 }
 pf=p;//保存当前指针
 p=p->pNext;//设置指针指向下一个结点
 }
 if(flag==0)
 cout<<"没有找到该论文！"<<endl;
 }

//修改指定论文信息
void List::update_info_by_thes(){
	string thes;//论文名称

	List *p=pHead;//指向当前结点的指针
	List *pf=NULL;//指向前一个结点的指针

	char content[1000];
	c=getchar();
	cout<<"请输入信息待修改论文的名称：";
	cin.getline(content,1000);

	int flag=0;//标记是否找到对应论文；
	string na=content;//将字符串数组转化成string类型
	char answer;//记录回答的内容

	while(p!=NULL){
		thes=p->data->get_thes();
		if(thes==na){
			flag++;
			cout<<"编号\t"<<"论文名称\t\t\t\t"<<"作者名  "<<"出版期刊       "<<"出版年份 "<<"论文链接\t\t\t\t"<<"论文摘要\t\t"<<endl;
			p->data->display_info();

			cout<<"你确定要修改这组信息吗？(Y/N)";
			cin>>answer;
			if(tolower(answer)=='y'){
				int serial;
				char m[2000];
				string modify;
				cout<<"请输入你要修改的内容：1 论文名称 2 作者名 3 出版期刊 4 出版年份 5 论文链接 6 论文摘要(输入选项的数字)"<<endl;
				cin>>serial;
				c=getchar();
				switch(serial){
				case 1:
					cout<<"请问你想将它修改为什么？"<<endl;
					cin.getline(m,2000);
					modify=m;
					p->data->thes=modify;
					cout<<"\t该组信息已修改！"<<endl;
					break;
				case 2:
					cout<<"请问你想将它修改为什么？"<<endl;
					cin.getline(m,2000);
					modify=m;
					p->data->name=modify;
					cout<<"\t该组信息已修改！"<<endl;
					break;
				case 3:
					cout<<"请问你想将它修改为什么？"<<endl;
					cin.getline(m,2000);
					modify=m;
					p->data->journal=modify;
					cout<<"\t该组信息已修改！"<<endl;
					break;
				case 4:
					cout<<"请问你想将它修改为什么？"<<endl;
					while(1){
						cin.getline(m,2000);
						modify=m;
						if(modify.size()!=4||modify<"1900"||modify>"2021")//字符串类型比较不好
							cout<<"请重新输入正确的年份：";
						else{
							p->data->year=modify;
							break;
						}
					}
					cout<<"\t该组信息已修改！"<<endl;
					break;
				case 5:
					cout<<"请问你想将它修改为什么？"<<endl;
					cin.getline(m,2000);
					modify=m;
					p->data->link=modify;
					cout<<"\t该组信息已修改！"<<endl;
					break;
				case 6:
					cout<<"请问你想将它修改为什么？"<<endl;
					cin.getline(m,2000);
					modify=m;
					p->data->abst=modify;
					cout<<"\t该组信息已修改！"<<endl;
					break;
				}
			}
			else
			{
				break;
			}
		}
		pf=p;//保存当前指针
		p=p->pNext;//设置指针指向下一个结点
	}
	if(flag==0)
		cout<<"没有找到该论文！"<<endl;
}
void List::update_info_by_num(){
int n;//论文编号

 List *p=pHead;//指向当前结点的指针
 List *pf=NULL;//指向前一个结点的指针

 int content;
 cout<<"请输入信息待修改论文的编号：";
 cin>>content;

 int flag=0;//标记是否找到对应论文；
 char answer;//记录回答的内容

 while(p!=NULL)
 {
 //++n;
 n=p->data->get_num();
 if(n==content)
 {
 flag++;
 cout<<"编号\t"<<"论文名称\t\t\t\t"<<"作者名  "<<"出版期刊       "<<"出版年份 "<<"论文链接\t\t\t\t"<<"论文摘要\t\t"<<endl;
 p->data->display_info();

 cout<<"你确定要修改这组信息吗？(Y/N)";
 cin>>answer;
 if(tolower(answer)=='y')
 {
  int serial;
  char m[2000];
	 string modify;
  cout<<"请输入你要修改的内容：1 论文名称 2 作者名 3 出版期刊 4 出版年份 5 论文链接 6 论文摘要(输入选项的数字)"<<endl;
  cin>>serial;
   c=getchar();
  switch(serial){
  case 1:
	  cout<<"请问你想将它修改为什么？"<<endl;
  cin.getline(m,2000);
  modify=m;
  p->data->thes=modify;
  cout<<"\t该组信息已修改！"<<endl;
  break;
  case 2:
	  cout<<"请问你想将它修改为什么？"<<endl;
 cin.getline(m,2000);
  modify=m;
  p->data->name=modify;
  cout<<"\t该组信息已修改！"<<endl;
  break;
  case 3:
	  cout<<"请问你想将它修改为什么？"<<endl;
  cin.getline(m,2000);
  modify=m;
  p->data->journal=modify;
  cout<<"\t该组信息已修改！"<<endl;
  break;
  case 4:
	  cout<<"请问你想将它修改为什么？"<<endl;
 /* cin.getline(m,2000);
  modify=m;
  p->data->year=modify*/;
  while(1){
	 cin.getline(m,2000);
	  modify=m;
	 if(modify.size()!=4||modify<"1900"||modify>"2021")//字符串类型比较不好
		 cout<<"请重新输入正确的年份：";
	 else{
		 p->data->year=modify;
		 break;}
 }
  cout<<"\t该组信息已修改！"<<endl;
  break;
  case 5:
	  cout<<"请问你想将它修改为什么？"<<endl;
  cin.getline(m,2000);
  modify=m;
  p->data->link=modify;
  cout<<"\t该组信息已修改！"<<endl;
  break;
  case 6:
	  cout<<"请问你想将它修改为什么？"<<endl;
  cin.getline(m,2000);
  modify=m;
  p->data->abst=modify;
  cout<<"\t该组信息已修改！"<<endl;
  break;
 }
 }
 else
 {
  break;
 }
 }
 pf=p;//保存当前指针
 p=p->pNext;//设置指针指向下一个结点
 }
 if(flag==0)
 cout<<"没有找到该论文！"<<endl;
 }

//将链表保存到文件中
void List::save_list()
{
 List *p=pHead;//用来遍历链表的指针
 ofstream fout;
 fout.open("thesis.txt",ios::out);//供写，文件不存在则创建，若文件已存在则清空原内容(ofstream默认的打开方式)
 while(p!=NULL)
 {
 p->data->save_node(fout);
 p=p->pNext;
 }
 fout.close();//关闭文件
}
//销毁链表
void List::delete_list()
{
 List *p=pHead;
 List *pt;
 while(p!=NULL)
 {
 pt=p;
 p=p->pNext;
 delete pt->data;//删除论文信息所占内存
 delete pt;//删除链表结点所占内存
 }
 pt=NULL;
 pHead=NULL;
 p=NULL;
}