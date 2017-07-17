#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *next;
};
void Print(struct node *head)
{
	while(head != NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}
struct node* Add(struct node *head1, struct node *head2)
{
	int carry = 0,sum = 0,p,q,rem;
	
	if(head1 == NULL)
		return head2;
	
	if(head2 == NULL)
		return head1;

	struct node *head = NULL,*tail;

	while(head1 != NULL || head2 != NULL)
	{
		if(head1 == NULL)
			p=0;
		else
			p = head1->data;

		if(head2 == NULL)
			q=0;
		else
			q = head2->data;

		sum = p+q+carry;
		rem = sum%10;
		carry = sum/10;

		if(head == NULL)
		{
			head = new node();
			head->data = rem;
			head->next = NULL;
			tail = head;
		}

		else
		{
			tail->next = new node();
			tail->next->data = rem;
			tail->next->next = NULL;
			tail = tail->next;
		}

		if(head1 != NULL)
			head1 = head1->next;
		if(head2 != NULL)
			head2 = head2->next;
	}

	return head;
}
int main()
{
	int i,j,k,n,m;
	struct node *head1,*head2,*tail1,*tail2;

	cin>>n;
	for(i=0;i<n;i++){
		cin>>m;
		if(head1 == NULL){
			head1 = new node();
			head1->data = m;
			head1->next = NULL;
			tail1 = head1;
		}
		else{
			tail1->next = new node();
			tail1->next->data = m;
			tail1->next->next = NULL;
			tail1 = tail1->next;
		}
	}

	cin>>n;
	for(i=0;i<n;i++){
		cin>>m;
		if(head2 == NULL){
			head2 = new node();
			head2->data = m;
			head2->next = NULL;
			tail2 = head2;
		}
		else{
			tail2->next = new node();
			tail2->next->data = m;
			tail2->next->next = NULL;
			tail2 = tail2->next;
		}
	}

	struct node *head = Add(head1,head2);
	Print(head);

}
