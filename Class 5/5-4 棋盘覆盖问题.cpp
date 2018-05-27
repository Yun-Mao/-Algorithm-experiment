#include <iostream>
#include <iomanip>
using namespace std;

int board[100][100];  //�������L�͵ı�����飻
int tile=1;    // L�͹��ƺ�
void chessBoard(int tr, int tc, int dr, int dc, int size)
{
	  if (size==1)
		  return;
      int t = tile++;     // L�͹��ƺ�
	  int s = size/2;     // �ָ�����
      //________________________________________________ �������Ͻ�������
      if (dr<tr+s&&dc<tc+s)     // ���ⷽ���ڴ�������
		  chessBoard(tr, tc, dr, dc, s);
      else                               // �������������ⷽ��
	  {
         board[tr+s-1][tc+s-1]=t; // �� t ��L�͹��Ƹ������½�
         chessBoard(tr,tc,tr+s-1, tc+s-1, s);// �������෽��
	  }

	  //________________________________________________ �������Ͻ�������
      if (dr < tr + s && dc >= tc + s)     // ���ⷽ���ڴ�������
		  chessBoard(tr, tc+s, dr, dc, s);
      else                                  // �������������ⷽ��
	  {
		  board[tr + s - 1][tc + s] = t;   //��t��L�͹��Ƹ������½�
          chessBoard(tr, tc+s, tr+s-1, tc+s, s);// �������෽��
	  }

	 //_______________________________________________ �������½�������
      if (dr >= tr + s && dc < tc + s)  // ���ⷽ���ڴ�������
		  chessBoard(tr+s, tc, dr, dc, s);
      else                               // �������������ⷽ��
	  {
         board[tr + s][tc + s - 1] = t;  // �� t ��L�͹��Ƹ������Ͻ�
        chessBoard(tr+s, tc, tr+s, tc+s-1, s);// �������෽��
	  }

	  //__________________________________________________ �������½�������
      if (dr >= tr + s && dc >= tc + s)  // ���ⷽ���ڴ�������
		  chessBoard(tr+s, tc+s, dr, dc, s);
      else
	  {
         board[tr + s][tc + s] = t;     // �� t ��L�͹��Ƹ������Ͻ�
         chessBoard(tr+s, tc+s, tr+s, tc+s, s); // �������෽��
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
	chessBoard(0, 0, dr, dc, size);

	int i,j;
	for( i=0;i<size;i++)
	{
		for( j=0;j<size;j++)
			cout<<setw(6)<<board[i][j];//setw(6)//���������6���ַ�ʱ���������հ�
		cout<<endl<<endl;
	}
	return 0;
}



