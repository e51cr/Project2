//#include <iostream> 
//#include <fstream>
//using namespace std;
//
//class LinkedList
//{
//private:
//	struct node
//	{
//		int data;
//		node* next;
//	};
//
//	node* h;	// h = head
//	node* c;	//c = current
//	node* t1;	// t1 = temporary 1
//	node* t2;	// t2 = temporary 2
//
//public:
//	LinkedList();
//	void Insert(int pos, int insertData);
//	void Delete(int pos, int delData);
//	void Output();
//};
//LinkedList::LinkedList()
//{
//	h = NULL;
//	c = NULL;
//	t1 = NULL;
//	t2 = NULL;
//}
//void LinkedList::Insert(int pos, int insertData)
//{
//	node* n = new node;
//	n->data = insertData;
//	n->next = NULL;
//
//
//	if (h != NULL)
//	{
//		c = h;
//		while (c->next != NULL)
//		{
//			c = c->next;
//		}
//		c->next = n;
//	}
//	else
//	{
//		h = n; //head = node* n = new node
//	}
//}
//
//void LinkedList::Delete(int pos, int delData)
//{
//	node* delPtr = NULL;
//	t1 = h;
//	c = h;
//	while (c != NULL && c->data != delData)
//	{
//		t1 = c;
//		c = c->next;
//	}
//	if (c == NULL)
//	{
//		delete delPtr;
//	}
//	else
//	{
//		delPtr = c;
//		c = c->next;
//		t1->next = c;
//		if (delPtr == h)
//		{
//			h = h->next;
//			t1 = NULL;
//		}
//		delete delPtr;
//	}
//}
//void LinkedList::Output()
//{
//	c = h;
//
//	ofstream saveOutputFile;	//create and output file
//	saveOutputFile.open("Elena.Cruz.lList.txt"); //write into this text file
//	while (c != NULL)
//	{
//		saveOutputFile << c->data << "\t"; // one row, tabbed format
//		c = c->next;
//	}
//	saveOutputFile.close();
//}
//
//int main()
//{
//	LinkedList link;
//
//	link.Insert(0, 11);
//	link.Insert(1, 10);
//	link.Insert(2, 9);
//	link.Insert(3, 8);
//	link.Insert(4, 7);
//	link.Insert(5, 6);
//	link.Insert(6, 5);
//	link.Insert(7, 4);
//	link.Insert(8, 3);
//	link.Insert(9, 2);
//	link.Insert(10, 1);
//
//	link.Delete(5, 7);
//
//	link.Insert(7, 100);
//	link.Output();
//	cout << endl;
//
//	return 0;
//
//}