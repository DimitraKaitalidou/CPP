#include <iostream>
#include <string>

using namespace std;

class Node
{
	// Access specifier 
    public:

	// Node data
	int node_data;
	Node *next_node;
};

class Stack
{
	// Access specifier 
    public:

	// Stack nodes
	Node *top_stack;

	// Stack functions
	void pop_stack()
	{
		Node *temp_node;
		if (isEmpty_stack())
		{
			cout << "The Stack is empty. \n";
			return;
		}

		temp_node = top_stack -> next_node;
		delete top_stack;
		top_stack = temp_node;
	}

	void push_stack(int d)
	{
		Node *new_node = new Node;
		new_node -> node_data = d;
		new_node -> next_node = top_stack;
		top_stack = new_node;
		return;
	}

	int isEmpty_stack()
	{
		if(top_stack == NULL) return 1;
		else return 0;
	}

	void getTop_stack()
	{
		if (isEmpty_stack()) cout << "The Stack is empty. \n";
		else cout << "The top of the Stack is: " << top_stack -> node_data << "\n";
	}
};

class Queue
{
	// Access specifier 
    public:

	// Queue nodes
	Node *top_queue;
	Node *tail_queue;

	// Queue functions
	void remove_queue()
	{
		Node *temp_node;
		if (isEmpty_queue())
		{
			cout << "The Queue is empty. \n";
			return;
		}

		temp_node = top_queue -> next_node;
		delete top_queue;
		top_queue = temp_node;
	}

	void insert_queue(int d)
	{
		Node *new_node = new Node;
		new_node -> node_data = d;
		new_node -> next_node = NULL;
		if (tail_queue != NULL) tail_queue -> next_node = new_node;
		tail_queue = new_node;
		if (top_queue == NULL)  top_queue = tail_queue;
		return;
	}

	int isEmpty_queue()
	{
		if (top_queue == NULL) return 1;
		else return 0;
	}

	void getTop_queue()
	{
		if(isEmpty_queue()) cout << "The Queue is empty. \n";
		else cout << "The top of the Queue is: " << top_queue -> node_data << "\n";
	}
};

int main()
{
	// Initialize variables
	char action;
	int input;
	string select;

	// Select what to create
	cout << "Press 0 to create a Stack, or 1 to create a Queue, or q to exit. \n";
	cin >> select;

	if (select.compare("q") == 0)
	{
		system("pause");
		return 0;
	}

	while (select.compare("0") != 0 && select.compare("1") != 0 && select.compare("q") != 0)
	{
		cout << "Wrong input! \n";
		cout << "Press 0 to create a Stack, or 1 to create a Queue, or q to exit. \n";
		cin >> select;

		if (select.compare("q") == 0)
		{
			system("pause");
			return 0;
		}
	}

	if (select.compare("0") == 0)
	{
		Stack S1;
		cout << "A Stack was created. \n";

		while (1)
		{
			cout << "Select action for the Queue: 0 -> Exit 1 -> Push 2 -> Pop 3 -> Results \n";
			cin >> action;

			switch (action)
			{
			   case '0':
				   system("pause");
				   return 0;
			   case '1':
				   cout << "Push data into the Stack. \n";
				   cin >> input;
				   S1.push_stack(input);
				   break;
			   case '2':
				   S1.pop_stack();
				   break;
			   case '3':
				   S1.getTop_stack();
				   break;
			   default:
				   cout << "Wrong input! \n";
				   break;
			}
		}
	}
	else
	{
		Queue Q1;
		cout << "A Queue was created. \n";

		while (1)
		{
			cout << "Select action for the Queue: 0 -> Exit 1 -> Insert 2 -> Remove 3 -> Results \n";
			cin >> action;

			switch (action)
			{
			    case '0':
				   system("pause");
				   return 0;
			    case '1':
				   cout << "Insert data into the Queue. \n";
				   cin >> input;
				   Q1.insert_queue(input);
				   break;
			    case '2':
				   Q1.remove_queue();
				   break;
			    case '3':
				   Q1.getTop_queue();
				   break;
			    default:
				   cout << "Wrong input! \n";
				   break;
			}
		}
	}

	system("pause");
	return 0;
}