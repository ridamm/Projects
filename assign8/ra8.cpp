#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int co[2][14],e[2][100],pos=1,tr[3][1000],num=0;
int comp()
{

	float x1=0,x2=2,x3=0,x4=0;
	float y1=2,y2=0,y3=2,y4=0;
	float beta,alpha;
    if(((y3-y4)*(x1-x2)-(x3-x4)*(y1-y2))==0)
    {
       // printf("b");
        if(x3<x2&&x1<x4&&y3<y2&&y1<y4)
            return 1;
        else
            return 0;
    }
    else if(x1==x2)
    {
        //printf("aa");
        beta=(float)(x2-x4)/(x3-x4);
        alpha=(float)(beta*(y3-y4)+(y4-y2))/(y1-y2);
        printf("a %f  b %f\n",alpha,beta);
        if(alpha>=0&&alpha<=1&&beta>=0&&beta<=1)
        {
            //printf("%f %f\n",alpha,beta);
            return 1;
        }
        else
            return 0;
    }
    else
    {
        beta=(float)((x4-x2)*(y1-y2)-(y4-y2)*(x1-x2))/((y3-y4)*(x1-x2)-(x3-x4)*(y1-y2));
        alpha=(float)(beta*(x3-x4)+(x4-x2))/(x1-x2);
        printf("al %f  be %f\n",alpha,beta);
        if(alpha>=0&&alpha<=1&&beta>=0&&beta<=1)
        {
            //printf("%f %f\n",alpha,beta);
            return 1;
        }
        else
            return 0;
    }
}
int main()
{
	int f=comp();
	return 0;
}
