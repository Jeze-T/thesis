#include<iostream>
using namespace std;
//主界面
void menu()
{
 cout<<"\n\n\t\t----------------个人论文管理系统------------------"<<endl<<endl;
 cout<<"\t\t1、信息维护功能"<<" "<<"\t\t2、信息查询功能"<<" "<<"\t\t3、排序功能"<<endl<<endl;
 cout<<"\t\t4、退出"<<endl<<endl;
 return;
}

 
//信息维护功能界面
void menu1()
{
 cout<<"\n\n\t\t信息维护功能"<<endl<<endl;
 cout<<"\t\t1、增加论文信息"<<endl<<endl;
 cout<<"\t\t2、按论文名称删除论文信息"<<endl<<endl;
 cout<<"\t\t3、按论文编号删除论文信息"<<endl<<endl;
 cout<<"\t\t4、按论文名称修改论文信息"<<endl<<endl;
 cout<<"\t\t5、按论文编号修改论文信息"<<endl<<endl;
 cout<<"\t\t6、返回"<<endl<<endl;
 return;
}

//信息查询功能界面
void menu2()
{
 cout<<"\n\n\t\t信息查询功能"<<endl<<endl;
 cout<<"\t\t1、按论文名称模糊查询"<<endl<<endl;
 cout<<"\t\t2、按作者名模糊查询"<<endl<<endl;
 cout<<"\t\t3、按出版期刊模糊查询"<<endl<<endl;
 cout<<"\t\t4、按出版年份模糊查询"<<endl<<endl;
 cout<<"\t\t5、按论文摘要模糊查询"<<endl<<endl;
 cout<<"\t\t6、返回"<<endl<<endl;
 return;
}

//排序功能界面
void menu3()
{
 cout<<"\n\n\t\t排序功能"<<endl<<endl;
 cout<<"\t\t1、根据论文名称排序"<<endl<<endl;
 cout<<"\t\t2、根据出版期刊排序"<<endl<<endl;
 cout<<"\t\t3、根据出版年份排序"<<endl<<endl;
 cout<<"\t\t4、返回"<<endl<<endl;
 return;
}