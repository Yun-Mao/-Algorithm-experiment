#include<iostream>
#include <iomanip>
using namespace std;
int board[100][100];
int title=1;
//tr �����У�tc ������ dr��ȱ�� dc ��ȱ�� size ��ģ��С2^k
void ChessBoard(int tr, int tc,int dr, int dc, int size)
{
    if(size==1)
        return;
    int t = title++;     // L�͹��ƺ�
    int s=size/2;

    if(dr<tr+s && dc <tc+s)
    {
        ChessBoard(tr,tc,dr,dc,s);
    }
    else
    {
        board[tr+s-1][tc+s-1]=t;
        ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
    }

    if(dr>=tr+s&&dc<tc+s)
    {
        ChessBoard(tr+s,tc,dr,dc,s);
    }
    else
    {
        board[tr+s][tc+s-1]=t;
        ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
    }
    if (dr < tr + s && dc >= tc + s)
        ChessBoard(tr, tc+s, dr, dc, s);
    else
    {
        board[tr + s - 1][tc + s] = t;
        ChessBoard(tr, tc+s, tr+s-1, tc+s, s);
    }
    if (dr >= tr + s && dc >= tc + s)
        ChessBoard(tr+s, tc+s, dr, dc, s);
    else
    {
        board[tr + s][tc + s] = t;
        ChessBoard(tr+s, tc+s, tr+s, tc+s, s);
    }
}
int main()
{
    int size,dr,dc;
    cout<<"\t\t\t���̸�������\n";
    cout<<"2^k��2^k ������䳤size(size=2,4,8,16,32,64)��";
    cin>>size;
    cout<<"�ֱ��������������±�dr,���±�dc(0-"<<(size-1)<<"):";
    cin>>dr>>dc;
    board[dr][dc]=0;
    cout<<"���̸���ͼ��\n";
    ChessBoard(0, 0, dr, dc, size);

    int i,j;
    for( i=0; i<size; i++)
    {
        for( j=0; j<size; j++)
        cout<<setw(6)<<board[i][j];//setw(6)//���������6���ַ�ʱ���������հ�
        cout<<endl<<endl;
    }
    return 0;
}
