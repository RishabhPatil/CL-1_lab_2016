#include<iostream>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;

class kmeans
{

	struct points
	{
	 float x;
	 float y;
	};
public:
	struct points p[8];
	struct points c[3];
	void input();
	int km();
	float distance(float a,float b,float x,float y);
};
int tally[8][10];
int count;
int n;

void kmeans::input()
{
	p[0].x=2;p[0].y=2;
	p[1].x=1;p[1].y=14;
	p[2].x=10;p[2].y=7;
	p[3].x=1;p[3].y=11;
	p[4].x=3;p[4].y=4;
	p[5].x=11;p[5].y=8;
	p[6].x=4;p[6].y=3;
	p[7].x=12;p[7].y=2;
	int i,random=0;
	srand(time(NULL));
	for(i=0;i<3;i++)
	{
		random=(rand())%7;
		c[i].x=p[random].x;
		c[i].y=p[random].y;
	}
}

float kmeans::distance(float a,float b,float x,float y)
{
	float t1=a-x;
	float t2=b-y;
	if(t1<0)
		t1=-t1;
	if(t2<0)
		t2=-t2;
	return (t1+t2);
}

int kmeans::km()
{
	int i,j;
	float table[8][4];
	for(i=0;i<n;i++)
	{
		table[i][0]=distance(p[i].x,p[i].y,c[0].x,c[0].y);
		table[i][1]=distance(p[i].x,p[i].y,c[1].x,c[1].y);
		table[i][2]=distance(p[i].x,p[i].y,c[2].x,c[2].y);
		if(table[i][0]<=table[i][1] && table[i][0]<=table[i][2])
		{
			tally[i][count]=0;
			table[i][3]=table[i][0];
		}
		else if(table[i][1]<=table[i][0] && table[i][1]<=table[i][2])
		{
			tally[i][count]=1;
			table[i][3]=table[i][1];
		}
		else if(table[i][2]<=table[i][0] && table[i][2]<=table[i][1])
		{
			tally[i][count]=2;
			table[i][3]=table[i][2];
		}
	}
	cout<<"TABLE: "<<count+1<<endl;
	cout<<"Centroids are: ("<<c[0].x<<","<<c[0].y<<"), ("<<c[1].x<<","<<c[1].y<<"), ("<<c[2].x<<","<<c[2].y<<")"<<endl;

	cout<<"c1\tc2\tc3\tmin"<<endl;
	cout<<"-------------------------"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
		{
			cout<<table[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"-------------------------"<<endl;

	float c0=0,c1=0,c2=0,c0x=0,c0y=0,c1x=0,c1y=0,c2x=0,c2y=0;
	for(i=0;i<n;i++)
	{
		if(tally[i][count]==0)
		{
			c0x+=p[i].x;
			c0y+=p[i].y;
			c0++;
		}
		else if(tally[i][count]==1)
		{
			c1x+=p[i].x;
			c1y+=p[i].y;
			c1++;
		}
		else if(tally[i][count]==2)
		{
			c2x+=p[i].x;
			c2y+=p[i].y;
			c2++;
		}
	}
	c[0].x=c0x/c0;
	c[0].y=c0y/c0;
	c[1].x=c1x/c1;
	c[1].y=c1y/c1;
	c[2].x=c2x/c2;
	c[2].y=c2y/c2;

	int flag=0;
	if(count!=0)
	{
		for(i=0;i<n;i++)
		{
			if(tally[i][count]==tally[i][count-1])
				flag++;
		}
	}
	count++;
	return flag;
}

int main()
{
	kmeans k;
	k.input();
	n=8;
	count=0;
	int flag=k.km();
	while(flag!=8)
		flag=k.km();
	if(flag==8)
		cout<<"Centroids found"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<count;j++)
			cout<<tally[i][j]<<"  ";
		cout<<endl;
	}
	return 0;
}

