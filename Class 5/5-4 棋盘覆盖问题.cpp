#include <iostream>
#include <iomanip>
using namespace std;

int board[100][100];  //存放棋盘L型的标号数组；
int tile=1;    // L型骨牌号
void chessBoard(int tr, int tc, int dr, int dc, int size)
{
	  if (size==1)
		  return;
      int t = tile++;     // L型骨牌号
	  int s = size/2;     // 分割棋盘
      //________________________________________________ 覆盖左上角子棋盘
      if (dr<tr+s&&dc<tc+s)     // 特殊方格在此棋盘中
		  chessBoard(tr, tc, dr, dc, s);
      else                               // 此棋盘中无特殊方格
	  {
         board[tr+s-1][tc+s-1]=t; // 用 t 号L型骨牌覆盖右下角
         chessBoard(tr,tc,tr+s-1, tc+s-1, s);// 覆盖其余方格
	  }

	  //________________________________________________ 覆盖右上角子棋盘
      if (dr < tr + s && dc >= tc + s)     // 特殊方格在此棋盘中
		  chessBoard(tr, tc+s, dr, dc, s);
      else                                  // 此棋盘中无特殊方格
	  {
		  board[tr + s - 1][tc + s] = t;   //用t号L型骨牌覆盖左下角
          chessBoard(tr, tc+s, tr+s-1, tc+s, s);// 覆盖其余方格
	  }

	 //_______________________________________________ 覆盖左下角子棋盘
      if (dr >= tr + s && dc < tc + s)  // 特殊方格在此棋盘中
		  chessBoard(tr+s, tc, dr, dc, s);
      else                               // 此棋盘中无特殊方格
	  {
         board[tr + s][tc + s - 1] = t;  // 用 t 号L型骨牌覆盖右上角
        chessBoard(tr+s, tc, tr+s, tc+s-1, s);// 覆盖其余方格
	  }

	  //__________________________________________________ 覆盖右下角子棋盘
      if (dr >= tr + s && dc >= tc + s)  // 特殊方格在此棋盘中
		  chessBoard(tr+s, tc+s, dr, dc, s);
      else
	  {
         board[tr + s][tc + s] = t;     // 用 t 号L型骨牌覆盖左上角
         chessBoard(tr+s, tc+s, tr+s, tc+s, s); // 覆盖其余方格
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
	chessBoard(0, 0, dr, dc, size);

	int i,j;
	for( i=0;i<size;i++)
	{
		for( j=0;j<size;j++)
			cout<<setw(6)<<board[i][j];//setw(6)//输出量不足6个字符时在左面填充空白
		cout<<endl<<endl;
	}
	return 0;
}



