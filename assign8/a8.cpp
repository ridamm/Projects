#include<fstream>
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
int cox[2][14],co[2][14],e[2][100],pos=1,tr[3][400],num=0,potr=0;
void re()
{
	ifstream file;
	file.open("input.txt",ios::in);
	for(int i=0;i<14;i++)
	{
		file>>co[0][i];
		file>>co[1][i];
		cox[0][i]=co[0][i];
		cox[1][i]=co[1][i];
	}
	file.close();
}
void wr()
{
	ofstream file;
	file.open("output.txt",ios::out);
	for(int i=0;i<potr;i++)
	{
		file<<tr[0][i]<<" ";
		file<<tr[1][i]<<" ";
		file<<tr[2][i]<<"\n";
		/*file<<co[0][i]<<" ";
		file<<co[1][i]<<"\n";*/
	}
	file.close();
}
void sor()
{
	for(int i=0;i<14;i++)
	{
		//int sm=co[0][i],pos=i;
		for(int j=0;j<(13-i);j++)
		{
			if(co[0][j]>co[0][j+1])
			{
                int t=co[0][j];
                co[0][j]=co[0][j+1];
                co[0][j+1]=t;
                t=co[1][j];
                co[1][j]=co[1][j+1];
                co[1][j+1]=t;
			}
			else if(co[0][j]==co[0][j+1])
			{
                if(co[1][j]>co[1][j+1])
                {
                    int t=co[0][j];
                    co[0][j]=co[0][j+1];
                    co[0][j+1]=t;
                    t=co[1][j];
                    co[1][j]=co[1][j+1];
                    co[1][j+1]=t;
                }
			}
		}
	}
}
int comp(int a,int b,int c,int d)                       //RETURN 0 IF LINE SEGMENTS DONT INTERSECT(VALID EDGE)
{

	float x1=co[0][a],x2=co[0][b],x3=co[0][c],x4=co[0][d];
	float y1=co[1][a],y2=co[1][b],y3=co[1][c],y4=co[1][d];
	float beta,alpha;
    if(((y3-y4)*(x1-x2)-(x3-x4)*(y1-y2))==0)
    {
       // printf("b");
        if(x3<=x2&&x1<=x4&&y3<=y2&&y1<=y4)
        {
            if(((x2==x3)&&(y2==y3))||((x1==x4)&&(y1==y4)))
                return 0;
            else
                return 1;
        }
        else
            return 0;
    }
	else if(((x1==x3)&&(y1==y3))||((x1==x4)&&(y1==y4))||((x2==x3)&&(y2==y3))||((x2==x4)&&(y2==y4)))
    {
        return 0;
    }
    else if(x1==x2)
    {
        //printf("aa");
        beta=(float)(x2-x4)/(x3-x4);
        alpha=(float)(beta*(y3-y4)+(y4-y2))/(y1-y2);
        //printf("a %f  b %f\n",alpha,beta);
        if(alpha>=0&&alpha<=1&&beta>=0&&beta<=1)
        {
            //printf("%f %f\n",alpha,beta);
           // if((alpha==0||alpha==1)&&(beta==0||beta==1))
             //   return 0;
            //else
                return 1;
        }
        else
            return 0;
    }
    else
    {
        beta=(float)((x4-x2)*(y1-y2)-(y4-y2)*(x1-x2))/((y3-y4)*(x1-x2)-(x3-x4)*(y1-y2));
        alpha=(float)(beta*(x3-x4)+(x4-x2))/(x1-x2);
        //printf("al %f  be %f\n",alpha,beta);
        if(alpha>=0&&alpha<=1&&beta>=0&&beta<=1)
        {
            //printf("%f %f\n",alpha,beta);
           // if((alpha==0||alpha==1)&&(beta==0||beta==1))
            //    return 0;
            //else
                return 1;
        }
        else
            return 0;
    }
}
void triangulate()
{
    for(int i=0;i<14;i++)
    {
        for(int j=i+1;j<14;j++)
        {
            int f=0;
            for(int l=0;l<pos;l++)
            {
                if((e[0][l]==i+1)&&(e[1][l]==j+1))
                {
                    f=1;
                    break;
                }
            }
            if(f==1)
            {
                for(int k=j+1;k<14;k++)
                {
                    int f1=0,f2=0;
                    for(int m=0;m<pos;m++)
                    {
                        if((e[0][m]==i+1)&&(e[1][m]==k+1))
                        {
                            f1=1;
                            break;
                        }
                    }
                    for(int m=0;m<pos;m++)
                    {
                        if((e[0][m]==j+1)&&(e[1][m]==k+1))
                        {
                            f2=1;
                            break;
                        }
                    }
                    if(f1==1&&f2==1)
                    {
                        int w[3];
                        for(w[0]=0;w[0]<14;w[0]++)
                        {
                            if((co[0][i]==cox[0][w[0]])&&(co[1][i]==cox[1][w[0]]))
                                break;
                        }
                        for(w[1]=0;w[1]<14;w[1]++)
                        {
                            if((co[0][j]==cox[0][w[1]])&&(co[1][j]==cox[1][w[1]]))
                                break;
                        }
                        for(w[2]=0;w[2]<14;w[2]++)
                        {
                            if((co[0][k]==cox[0][w[2]])&&(co[1][k]==cox[1][w[2]]))
                                break;
                        }
                        for(int i=0;i<3;i++)
                        {
                            for(int j=0;j<(3-i);j++)
                            {
                                if(w[j]>w[j+1])
                                {
                                    int t=w[j];
                                    w[j]=w[j+1];
                                    w[j+1]=w[j];
                                }
                            }
                        }
                        tr[0][potr]=w[0]+1;
                        tr[1][potr]=w[1]+1;
                        tr[2][potr]=w[2]+1;
                        potr++;
                    }
                    break;
                }
            }
        }
    }
}
int main()
{
	re();
	sor();
	//for(int i=0;i<14;i++)
		//printf("%i %i\n",co[0][i],co[1][i]);
	e[0][0]=1;
	e[1][0]=2;
	for(int i=2;i<14;i++)
	{
		for(int j=0;j<i;j++)
		{
			int f=0;
			for(int k=0;k<pos;k++)
			{
				int f=comp(j,i,e[0][k]-1,e[1][k]-1);
				if(f==1)
					goto label;
			}
			if(f==0)
			{
				e[0][pos]=j+1;
				e[1][pos]=i+1;
				pos++;
			}
			label:;
		}
	}
	triangulate();
	wr();
	return 0;
}
