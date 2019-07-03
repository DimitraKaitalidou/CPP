// Copyright 2019, Dimitra S. Kaitalidou, All rights reserved

import java.io.*;
import java.util.Scanner;

class Node
{
	// Node information
	int node_data;
	Node next_node = null;
}

class Structure 
{
	// Structure variables
	Node top = null;

	// Structure functions
	void remove()
	{
		if (isEmpty() == 1) 
		{
			System.out.println("It is empty");
			return;
		}

		Node temp_node = new Node();
		temp_node = top.next_node;
		top = null;
		top = temp_node;
	}

	int isEmpty() 
	{
		if (top == null)
			return 1;
		else
			return 0;
	}

	void getTop() 
	{
		if (isEmpty() == 1)
			System.out.println("It is empty");
		else
			System.out.println("The top is: " + top.node_data);
	}
}

class Stack extends Structure 
{
	// Stack functions
	void push(int d) 
	{
		Node new_node = new Node();
		new_node.node_data = d;
		new_node.next_node = top;
		top = new_node;
		return;
	}
}

class Queue extends Structure 
{
	// Queue variables
	Node tail;

	// Queue functions
	void insert(int d) 
	{
		Node new_node = new Node();
		new_node.node_data = d;
		new_node.next_node = null;
		if (tail != null)
			tail.next_node = new_node;
		tail = new_node;
		if (top == null)
			top = tail;
		return;
	}
}

public class StackOrQueue 
{

	public static void main(String[] args) 
	{
		// Declare variables
		char action;
		int input;
		String select;

		// Select what to create
		System.out.println("Press 0 to create a Stack, or 1 to create a Queue, or q to exit.");
		Scanner scanner = new Scanner(System.in);
		select = scanner.nextLine();
		if (select.equals("q") == true)
			return;

		while (select.equals("0") == false && select.equals("1") == false && select.equals("q") == false) 
		{
			System.out.println("Wrong input!");
			System.out.println("Press 0 to create a Stack, or 1 to create a Queue, or q to exit.");
			select = scanner.nextLine();
			if (select.equals("q") == true)
				return;
		}

		// Manage the data structures
		if (select.equals("0") == true) 
		{
			Stack S1 = new Stack();
			System.out.println("A Stack was created.");

			while (true) 
			{
				System.out.println("Select action for the Stack: 0 -> Exit 1 -> Push 2 -> Pop 3 -> Results");
				action = scanner.next().charAt(0);

				switch (action) {
				case '0':
					scanner.close();
					return;
				case '1':
					System.out.println("Push data into the Stack.");
					input = scanner.nextInt();
					S1.push(input);
					break;
				case '2':
					S1.remove();
					break;
				case '3':
					S1.getTop();
					break;
				default:
					System.out.println("Wrong input!");
				}
			}
		} 
		else 
		{
			Queue Q1 = new Queue();
			System.out.println("A Queue was created.");

			while (true) 
			{
				System.out.println("Select action for the Queue: 0 -> Exit 1 -> Insert 2 -> Remove 3 -> Results");
				action = scanner.next().charAt(0);

				switch (action) {
				case '0':
				    scanner.close();
					return;
				case '1':
					System.out.println("Insert data into the Queue.");
					input = scanner.nextInt();
					Q1.insert(input);
					break;
				case '2':
					Q1.remove();
					break;
				case '3':
					Q1.getTop();
					break;
				default:
					System.out.println("Wrong input!");
				}
			}
		}
	}
}
