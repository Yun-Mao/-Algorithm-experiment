#include<iostream>
#include <iomanip>
using namespace std;
int board[100][100];
int title=1;
//tr 左上行，tc 左上列 dr残缺行 dc 残缺列 size 规模大小2^k
void ChessBoard(int tr, int tc,int dr, int dc, int size)
{
    if(size==1)
        return;
    int t = title++;     // L型骨牌号
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
    cout<<"\t\t\t棋盘覆盖问题\n";
    cout<<"2^k×2^k 个方格变长size(size=2,4,8,16,32,64)：";
    cin>>size;
    cout<<"分别输入特殊块的行下标dr,列下标dc(0-"<<(size-1)<<"):";
    cin>>dr>>dc;
    board[dr][dc]=0;
    cout<<"棋盘覆盖图：\n";
    ChessBoard(0, 0, dr, dc, size);

    int i,j;
    for( i=0; i<size; i++)
    {
        for( j=0; j<size; j++)
        cout<<setw(6)<<board[i][j];//setw(6)//输出量不足6个字符时在左面填充空白
        cout<<endl<<endl;
    }
    return 0;
}
