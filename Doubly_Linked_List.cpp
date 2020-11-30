#include <iostream>


using namespace std;

struct node   //structure node...
{
	int data;  //node data
	struct node* next;
	struct node* prev;
};

class LinkedList    //linked list class..
{
private:
	node* start;   //starting node..

public:

	void insertBeg(int x);   //start node at the begining
	void insertEnd(int y);	//start node at the end
	void deleteBeg();		//delete node at the beginging
	void deleteEnd();		//delete node at the end
	void deleteGiven(int d); //delete a given node
	void printList();		//print the current list
	void search(int f);	//search a given value in the list
	int sum();				//summation of the linked list
	void listValue();		//assign fuction for starting node
};

void LinkedList::listValue()  //set start and end pointers to NULL
{
	start = NULL;  //Begining list is empty..
}


void LinkedList::insertBeg(int x)  //insert a node at the begining..
{
	struct node* newNode;  //define a new node....
	newNode = new node; //allocate memory for the new node..
	newNode->data = x;
	if (start == NULL)
	{
		start = newNode;
		newNode->prev = NULL;
		newNode->next = NULL;
	}

	else
	{
		newNode->next = start;
		newNode->prev = NULL;
		start->prev = newNode;
		start = newNode;
	}
}

void LinkedList::insertEnd(int y)  //insert a node at the end..
{
	node* newNode; //define a new node...
	node* temp;
	newNode = new node; //allocate memory...
	newNode->data = y;
	temp = start;
	if (start == NULL)
	{
		start = newNode;
		newNode->prev = NULL;
		newNode->next = NULL;
		return;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
		newNode->next = NULL;
		return;
	}


}

void LinkedList::deleteBeg() //delete a node from the begining...
{
	if (start == NULL)  //if the linked list is empty...
	{
		return;
	}

	node* temp;
	temp = start;
	start = start->next;
	start->prev = NULL;
	delete temp;
	return;

}

void LinkedList::deleteEnd()  //delete a node from the end
{
	if (start == NULL)  //if the linked list is empty...
	{
		cout << "Linked List is Empty" << endl;
		return;
	}
	node* temp;
	temp = start;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->prev->next = NULL;
	delete temp;


}

void LinkedList::deleteGiven(int d)  //delete a node with a given value...
{

	node* temp;
	temp = start;
	if (temp->next == NULL)  //if one node in the list...
	{
		if (temp->data != d)  //if that one element data is not the finding data..
		{
			cout << "Finding data doesn't exist in the list!!!!!" << endl;
			return;
		}
		start = NULL;
		delete temp;
		return;

	}

	while (temp->data != d)
	{
		temp = temp->next;
		if (temp == NULL)  //if finding element doesn't found in the list
		{
			cout << "Finding data doesn't exist in the list!!!!!" << endl;
			return;
		}

	}
	//if finding element found..........
	if (temp->next == NULL)  //if value in the last node....
	{
		temp->prev->next = NULL;
		delete temp;
		return;

	}
	if (temp->prev == NULL)  //if value in the first node...
	{
		temp->next->prev = NULL;
		start = temp->next;
		delete temp;
		return;
	}
	else	//if value in the middle of the list..
	{
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		delete temp;
		return;
	}

}

void LinkedList::printList()   //print the current list...
{
	node* temp;
	temp = start;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void LinkedList::search(int f) //search an existing element...
{
	node* temp;
	temp = start;
	while (temp != NULL)
	{
		if (temp->data == f)
		{
		    cout<<"found";  //if found the searching element....
			return;
		}
		temp = temp->next;
	}
	cout<<"not found";
	return;
	//I don't write a condion if not found the element,because in question said to search existing element..

}


int LinkedList::sum()  //get the list sum....
{
	node* temp;
	temp = start;
	int listSum = 0;

	while (temp != NULL)
	{
		listSum = listSum + temp->data;
		temp = temp->next;
	}
	return listSum;  //return the sum

}


int main()   //main fuction..
{

	LinkedList list; //linked list object
	list.listValue();
	int NoOfNodes, nodeData;
	cout << "Enter Number of Nodes : ";
	cin >> NoOfNodes;   //no of nodes..
	cout << "Enter Linked List data : " << endl;

	for (int i = 0; i < NoOfNodes; i++)  //insert the linked list....
	{
		cin >> nodeData;
		list.insertEnd(nodeData);
	}

	cout << endl;



	while (true)
	{
		int select;  //selecting a choice...
		cout << "1 - Insert Beginning" << endl;
		cout << "2 - Insert End" << endl;
		cout << "3 - Delete Beginning" << endl;
		cout << "4 - Delete End" << endl;
		cout << "5 - Delete Value" << endl;
		cout << "6 - Print" << endl;
		cout << "7 - Search" << endl;
		cout << "8 - Sum" << endl;
		cout << "0 - Exit" << endl;
		cout << "Enter your choice : ";
		cin >> select;


		if (select == 1)
		{
			int dataElement;
			cout << "Enter Node Data : ";
			cin >> dataElement;
			list.insertBeg(dataElement);
			cout << "Updated Linked List : ";
			list.printList();
		}
		else if (select == 2)
		{
			int dataElement;
			cout << "Enter Node Data : ";
			cin >> dataElement;
			list.insertEnd(dataElement);
			cout << "Updated Linked List : ";
			list.printList();
		}
		else if (select == 3)
		{
			list.deleteBeg();
			cout << "Updated Linked List : ";
			list.printList();
		}
		else if (select == 4)
		{
			list.deleteEnd();
			cout << "Updated Linked List : ";
			list.printList();
		}
		else if (select == 5)
		{
			int dataElement;
			cout << "Enter Node data want you to delete : ";
			cin >> dataElement;
			list.deleteGiven(dataElement);
			cout << "Updated Linked List : ";
			list.printList();
		}
		else if (select == 6)
		{
			cout << "Linked List : ";
			list.printList();
		}
		else if (select == 7)
		{
			int dataElement;
			cout << "Enter the searching Data(Existing Element) : ";
			cin >> dataElement;
			cout << "Searching Element Address : ";
		 list.search(dataElement);    //in here return the searching element address..if not found that element return a NULL

		}
		else if (select == 8)
		{
			cout << "Sum of the List : ";
			cout << list.sum();
		}
		else
		{
			return 0;
		}

		cout << endl << endl;
	}



}
