#include <bits/stdc++.h>
using namespace std;
int mat[100][100];
struct node{
	int row,col;
};
void Rotate(int n)
{
	int i,j,k,t,tmp,max_col;
	struct node p1,p2,p3,p4;

	for(t=0;t<n/2;t++)
	{
		p1.row=t;
		p1.col=t;

		p2.row=t;
		p2.col=n-1-t;

		p3.row=n-1-t;
		p3.col=n-1-t;

		p4.row=n-1-t;
		p4.col=t;
		/*
		cout<<p1.row<<" "<<p1.col<<endl;
		cout<<p2.row<<" "<<p2.col<<endl;
		cout<<p3.row<<" "<<p3.col<<endl;
		cout<<p4.row<<" "<<p4.col<<endl;
		*/
		max_col = n-1-t;

		for(i=0;1;i++)
		{
			tmp = mat[p1.row][p1.col];
			mat[p1.row][p1.col] = mat[p4.row][p4.col];
			mat[p4.row][p4.col] = mat[p3.row][p3.col];
			mat[p3.row][p3.col] = mat[p2.row][p2.col];
			mat[p2.row][p2.col] = tmp;

			p1.col++;
			p2.row++;
			p3.col--;
			p4.row--;

			if(p1.col >= max_col)
				break;
		}
	}

}
int main()
{
	int i,j,k,m,n;
	cin>>n;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cin>>mat[i][j];
	}

	Rotate(n);

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}
	
}
