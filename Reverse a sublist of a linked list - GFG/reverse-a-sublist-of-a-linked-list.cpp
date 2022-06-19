// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
public:
    Node *reverse(Node *head, Node *end)
    {
        Node *start = head, *temp = NULL, *prev = NULL;
        while (start && start != end)
        {
            temp = start->next;
            start->next = prev;
            prev = start;
            start = temp;
        }
        start->next = prev;
        prev = start;
        // cout<<prev->data<<endl;
        return prev;
    }

    Node *reverseBetween(Node *head, int m, int n)
    {
        // code here
        if (!head)
            return head;
        Node *start = head, *end = NULL, *pprev = head;
        int i = 1, j = m;
        while (i < m && start)
        {
            pprev = start;
            start = start->next;
            i++;
        }
        end = start;
        while (j < n && end)
        {
            end = end->next;
            j++;
        }
        // cout<<end->data<<" "<<start->data<<endl;
        Node *end_next = end->next;
        Node *temp = reverse(start, end);
        Node *curr = temp;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = end_next;
        if (start != head)
        {
            pprev->next = temp;
            //   cout<<pprev->data<<endl;
            return head;
        }
        return temp;
    }
};




// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends