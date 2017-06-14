#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <set>
#include <math.h>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
#define MAXN 100005
#define Mod 1000000007
using namespace std;
int changex=8,changey=8;
struct Node
{
    int A[16][16];
    int f;
};
void mcopy(int des[16][16],int src[16][16])
{
    for(int i=1; i<=15; ++i)
        for(int j=1; j<=15; ++j)
            des[i][j]=src[i][j];
}
bool check(int flag,int tmp[16][16])
{
    int fflag;
    if(flag==0)
        fflag=1;
    else
        fflag=0;
    //����1���������ߣ��˵㶼��
    for(int i=1; i<=15; ++i) //ˮƽ����
        for(int j=1; j<=10; ++j)
        {
            if(tmp[i][j]!=fflag&&tmp[i][j+1]==flag&&tmp[i][j+2]==flag&&tmp[i][j+3]==flag&&tmp[i][j+4]==flag&&tmp[i][j+5]!=fflag)
                return true;
        }
    for(int i=1; i<=10; ++i) //��ֱ����
        for(int j=1; j<=15; ++j)
        {
            if(tmp[i][j]!=fflag&&tmp[i+1][j]==flag&&tmp[i+2][j]==flag&&tmp[i+3][j]==flag&&tmp[i+4][j]==flag&&tmp[i+5][j]!=fflag)
                return true;
        }
    for(int i=1; i<=10; ++i) //��б����
        for(int j=1; j<=10; ++j)
        {
            if(tmp[i][j]!=fflag&&tmp[i+1][j+1]==flag&&tmp[i+2][j+2]==flag&&tmp[i+3][j+3]==flag&&tmp[i+4][j+4]==flag&&tmp[i+5][j+5]!=fflag)
                return true;
        }
    for(int i=1; i<=10; ++i) //��б����
        for(int j=15; j>=6; --j)
        {
            if(tmp[i][j]!=fflag&&tmp[i+1][j-1]==flag&&tmp[i+2][j-2]==flag&&tmp[i+3][j-3]==flag&&tmp[i+4][j-4]==flag&&tmp[i+5][j-5]!=fflag)
                return true;
        }
    //����2����򵥵����ӳ���
    for(int i=1; i<=15; ++i) //ˮƽ����
        for(int j=1; j<=11; ++j)
        {
            if(tmp[i][j]==flag&&tmp[i][j+1]==flag&&tmp[i][j+2]==flag&&tmp[i][j+3]==flag&&tmp[i][j+4]==flag)
                return true;
        }
    for(int i=1; i<=11; ++i) //��ֱ����
        for(int j=1; j<=15; ++j)
        {
            if(tmp[i][j]==flag&&tmp[i+1][j]==flag&&tmp[i+2][j]==flag&&tmp[i+3][j]==flag&&tmp[i+4][j]==flag)
                return true;
        }
    for(int i=1; i<=11; ++i) //��б����
        for(int j=1; j<=11; ++j)
        {
            if(tmp[i][j]==flag&&tmp[i+1][j+1]==flag&&tmp[i+2][j+2]==flag&&tmp[i+3][j+3]==flag&&tmp[i+4][j+4]==flag)
                return true;
        }
    for(int i=1; i<=11; ++i) //��б����
        for(int j=15; j>=5; --j)
        {
            if(tmp[i][j]==flag&&tmp[i+1][j-1]==flag&&tmp[i+2][j-2]==flag&&tmp[i+3][j-3]==flag&&tmp[i+4][j-4]==flag)
                return true;
        }
    return false;
}
int h(int flag,int A[16][16])
{
    int tmp[16][16];
    mcopy(tmp,A);
    int fflag;
    if(flag==1)
        fflag=0;
    else
        fflag=1;
    int val=0;
    //����û�ж�ס�����ӣ��Լ�������������Ҫ�ܸ�
    for(int i=1; i<=15; ++i) //ˮƽ����
        for(int j=1; j<=11; ++j)
        {
            if(tmp[i][j]!=flag&&tmp[i][j+1]==fflag&&tmp[i][j+2]==fflag&&tmp[i][j+3]==fflag&&tmp[i][j+4]!=flag)
                val+= -1000;
            if(tmp[i][j]!=fflag&&tmp[i][j+1]==flag&&tmp[i][j+2]==flag&&tmp[i][j+3]==flag&&tmp[i][j+4]!=fflag)
                val+= 1000;
        }
    for(int i=1; i<=11; ++i) //��ֱ����
        for(int j=1; j<=15; ++j)
        {
            if(tmp[i][j]!=flag&&tmp[i+1][j]==fflag&&tmp[i+2][j]==fflag&&tmp[i+3][j]==fflag&&tmp[i+4][j]!=flag)
                val+= -1000;
            if(tmp[i][j]!=fflag&&tmp[i+1][j]==flag&&tmp[i+2][j]==flag&&tmp[i+3][j]==flag&&tmp[i+4][j]!=fflag)
                val+= 1000;
        }
    for(int i=1; i<=11; ++i) //��б����
        for(int j=1; j<=11; ++j)
        {
            if(tmp[i][j]!=flag&&tmp[i+1][j+1]==fflag&&tmp[i+2][j+2]==fflag&&tmp[i+3][j+3]==fflag&&tmp[i+4][j+4]!=flag)
                val+= -1000;
            if(tmp[i][j]!=fflag&&tmp[i+1][j+1]==flag&&tmp[i+2][j+2]==flag&&tmp[i+3][j+3]==flag&&tmp[i+4][j+4]!=fflag)
                val+= 1000;
        }
    for(int i=1; i<=11; ++i) //��б����
        for(int j=15; j>=5; --j)
        {
            if(tmp[i][j]!=flag&&tmp[i+1][j-1]==fflag&&tmp[i+2][j-2]==fflag&&tmp[i+3][j-3]==fflag&&tmp[i+4][j-4]!=flag)
                val+= -1000;
            if(tmp[i][j]!=fflag&&tmp[i+1][j-1]==flag&&tmp[i+2][j-2]==flag&&tmp[i+3][j-3]==flag&&tmp[i+4][j-4]!=fflag)
                val+= 1000;
        }
    //����δ��ס�����ӣ����۴�֮
    for(int i=1; i<=15; ++i) //ˮƽ����
        for(int j=1; j<=12; ++j)
        {
            if(tmp[i][j]!=flag&&tmp[i][j+1]==fflag&&tmp[i][j+2]==fflag&&tmp[i][j+3]!=flag)
                val+= -100;
            if(tmp[i][j]!=fflag&&tmp[i][j+1]==flag&&tmp[i][j+2]==flag&&tmp[i][j+3]!=fflag)
                val+= 100;
        }
    for(int i=1; i<=12; ++i) //��ֱ����
        for(int j=1; j<=15; ++j)
        {
            if(tmp[i][j]!=flag&&tmp[i+1][j]==fflag&&tmp[i+2][j]==fflag&&tmp[i+3][j]!=flag)
                val+= -100;
            if(tmp[i][j]!=fflag&&tmp[i+1][j]==flag&&tmp[i+2][j]==flag&&tmp[i+3][j]!=fflag)
                val+= 100;
        }
    for(int i=1; i<=12; ++i) //��б����
        for(int j=1; j<=12; ++j)
        {
            if(tmp[i][j]!=flag&&tmp[i+1][j+1]==fflag&&tmp[i+2][j+2]==fflag&&tmp[i+3][j+3]!=flag)
                val+= -100;
            if(tmp[i][j]!=fflag&&tmp[i+1][j+1]==flag&&tmp[i+2][j+2]==flag&&tmp[i+3][j+3]!=fflag)
                val+= 100;
        }
    for(int i=1; i<=12; ++i) //��б����
        for(int j=15; j>=4; --j)
        {
            if(tmp[i][j]!=flag&&tmp[i+1][j-1]==fflag&&tmp[i+2][j-2]==fflag&&tmp[i+3][j-3]!=flag)
                val+= -100;
            if(tmp[i][j]!=fflag&&tmp[i+1][j-1]==flag&&tmp[i+2][j-2]==flag&&tmp[i+3][j-3]!=fflag)
                val+= 100;
        }
    if(val!=0)
    {
        return val;
    }
    for(int i=1; i<=15; ++i)
        for(int j=1; j<=15; ++j)
            if(tmp[i][j]==8)
                tmp[i][j]=flag;
    int sum1=0;
    for(int i=1; i<=15; ++i) //ˮƽ����
        for(int j=1; j<=11; ++j)
            if(tmp[i][j]==flag&&tmp[i][j+1]==flag&&tmp[i][j+2]==flag&&tmp[i][j+3]==flag&&tmp[i][j+4]==flag)
                sum1++;
    for(int i=1; i<=11; ++i) //��ֱ����
        for(int j=1; j<=15; ++j)
            if(tmp[i][j]==flag&&tmp[i+1][j]==flag&&tmp[i+2][j]==flag&&tmp[i+3][j]==flag&&tmp[i+4][j]==flag)
                sum1++;
    for(int i=1; i<=11; ++i) //��б����
        for(int j=1; j<=11; ++j)
            if(tmp[i][j]==flag&&tmp[i+1][j+1]==flag&&tmp[i+2][j+2]==flag&&tmp[i+3][j+3]==flag&&tmp[i+4][j+4]==flag)
                sum1++;
    for(int i=1; i<=11; ++i) //��б����
        for(int j=15; j>=5; --j)
            if(tmp[i][j]==flag&&tmp[i+1][j-1]==flag&&tmp[i+2][j-2]==flag&&tmp[i+3][j-3]==flag&&tmp[i+4][j-4]==flag)
                sum1++;
    mcopy(tmp,A);
    for(int i=1; i<=15; ++i)
        for(int j=1; j<=15; ++j)
            if(tmp[i][j]==8)
                tmp[i][j]=fflag;
    int sum0=0;
    for(int i=1; i<=15; ++i) //ˮƽ����
        for(int j=1; j<=11; ++j)
            if(tmp[i][j]==fflag&&tmp[i][j+1]==fflag&&tmp[i][j+2]==fflag&&tmp[i][j+3]==fflag&&tmp[i][j+4]==fflag)
                sum0++;
    for(int i=1; i<=11; ++i) //��ֱ����
        for(int j=1; j<=15; ++j)
            if(tmp[i][j]==fflag&&tmp[i+1][j]==fflag&&tmp[i+2][j]==fflag&&tmp[i+3][j]==fflag&&tmp[i+4][j]==fflag)
                sum0++;
    for(int i=1; i<=11; ++i) //��б����
        for(int j=1; j<=11; ++j)
            if(tmp[i][j]==fflag&&tmp[i+1][j+1]==fflag&&tmp[i+2][j+2]==fflag&&tmp[i+3][j+3]==fflag&&tmp[i+4][j+4]==fflag)
                sum0++;
    for(int i=1; i<=11; ++i) //��б����
        for(int j=15; j>=5; --j)
            if(tmp[i][j]==fflag&&tmp[i+1][j-1]==fflag&&tmp[i+2][j-2]==fflag&&tmp[i+3][j-3]==fflag&&tmp[i+4][j-4]==fflag)
                sum0++;
    return val+sum1-sum0;
}
int move1(int A[16][16])
{
    int tmp[16][16],num,ans=INF;
    for(int i=1; i<=15; ++i)
        for(int j=1; j<=15; ++j)
            if(A[i][j]==8)
            {
                mcopy(tmp,A);
                tmp[i][j]=0; //������
                if(check(0,tmp))
                    num=-INF;
                else
                    num=h(1,tmp);
                //cout<<num<<endl;
                ans=min(ans,num);
            }
    return ans;
}
int move0(int A[16][16])
{
    int tmp[16][16],num,ans=INF;
    for(int i=1; i<=15; ++i)
        for(int j=1; j<=15; ++j)
            if(A[i][j]==8)
            {
                mcopy(tmp,A);
                tmp[i][j]=1; //������
                if(check(1,tmp))
                    num=-INF;
                else
                    num=h(0,tmp);
                //cout<<num<<endl;
                ans=min(ans,num);
            }
    return ans;
}
void solve1(Node &node)
{
    int tmp[16][16],f,ans=-INF,anst[16][16];
    for(int i=1; i<=15; ++i)
        for(int j=1; j<=15; ++j)
            if(node.A[i][j]==8)
            {
                mcopy(tmp,node.A);
                tmp[i][j]=1; //�Լ���
                if(check(1,tmp))
                    f=INF;
                else
                    f=move1(tmp);
                //cout<<f<<endl;
                if(f>ans)
                {
                    //cout<<f<<endl;
                    ans=f;
                    mcopy(anst,tmp);
                }
            }
    for(int i=1;i<=15;++i)
        for(int j=1;j<=15;++j)
            if(node.A[i][j]!=anst[i][j])
            {
                changex=i;
                changey=j;
                break;
            }
    mcopy(node.A,anst);
    node.f=ans;
    cout<<ans<<endl;
}
void solve0(Node &node)
{
    int tmp[16][16],f,ans=-INF,anst[16][16];
    for(int i=1; i<=15; ++i)
        for(int j=1; j<=15; ++j)
            if(node.A[i][j]==8)
            {
                mcopy(tmp,node.A);
                tmp[i][j]=0; //�Լ���
                if(check(0,tmp))
                    f=INF;
                else
                    f=move0(tmp);
                if(f>ans)
                {
                    cout<<f<<endl;
                    ans=f;
                    mcopy(anst,tmp);
                }
            }
    for(int i=1;i<=15;++i)
        for(int j=1;j<=15;++j)
            if(node.A[i][j]!=anst[i][j])
            {
                changex=i;
                changey=j;
                break;
            }
    mcopy(node.A,anst);
    node.f=ans;
    cout<<ans<<endl;
}
void show(int A[16][16])
{
    for(int i=0; i<=15; ++i)
    {
        for(int j=0; j<=15; ++j)
        {
            if(i==0)
            {
                cout<<j<<" ";
                if(j==0)
                    cout<<" ";
            }
            else if(j==0)
            {
                cout<<i<<" ";
                if(i<10)
                    cout<<" ";
            }
            else if((i==4&&j==4)||(i==4&&j==12)||(i==12&&j==4)||(i==12&&j==12)||(i==changex&&j==changey))
                cout<<A[i][j]<<"<";
            else
                cout<<A[i][j]<<" ";
            if(j>9&&i!=0)
                cout<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    int flag=1,myturn,first=1;
    int i,j;
    Node node;
    for(int i=1; i<=15; ++i)
        for(int j=1; j<=15; ++j)
            node.A[i][j]=8;
    cout<<"����(1)or����(0)?";
    cin>>myturn;
    while(1)
    {
        if(flag)
        {
            if(flag==myturn)
            {
                if(first)//�˹����ܵ�һ�β������м䣬��Ϊ�м䷶Χ��������ͬ�����Ե�һ��Ҫǿ�������м�
                {
                    node.A[8][8]=1;
                    first=0;
                }
                else
                    solve1(node);
            }
            else
            {
                cout<<"�Է���ѡ����?";
                cin>>i>>j;
                node.A[i][j]=1;
            }
            show(node.A);
            flag=0;
        }
        else
        {
            if(flag==myturn)
            {
                if(first)
                {
                    node.A[i-1][j-1]=0;
                    first=0;
                }
                else
                    solve0(node);
            }
            else
            {
                cout<<"�Է���ѡ����?";

                cin>>i>>j;
                node.A[i][j]=0;
            }
            show(node.A);
            flag=1;
        }
    }
    return 0;
}
