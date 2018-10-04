#include <iostream> 
#include <fstream>
using namespace std;


template<class T>
class LinearList
{
private:
	int length;
	int MaxSize;
	T *element;
public:
	LinearList(int MaxLinearSize = 10);
	~LinearList() { delete[]element; }
	int isEmpty()const { return length == 0; }
	int Length()const { return length; }
	int Find(int k, T&x)const;
	int Search(const T&x)const;
	void Delete(int k, T&x);
	void Insert(int k, const T&x);
	void Output()const;
};
template<class T>
LinearList<T>::LinearList(int MaxListSize)
{
	MaxSize = MaxListSize;
	element = new T[MaxSize];
	length = 0;
}
template<class T>
int LinearList<T>::Find(int k, T&x)const
{
	if (k<1 || k>length)
		return 0;
	x = element[k - 1];
	return 1;
}
template<class T>
int LinearList<T>::Search(const T&x)const
{
	for (int i = 0; i < length; i++)
		if (element[i] == x)
			return ++i;
	return 0;
}
template<class T>
void LinearList<T>::Delete(int k, T&x)
{
	if (Find(k, x))
	{
		for (int i = k; i < length; i++)
			element[i - 1] = element[i];
		length--;
	}
	else
		cout << "out of bounds\n";
}
template<class T>
void LinearList<T>::Insert(int k, const T&x)
{
	if (k<0 || k>length)
		cout << "out of bounds\n"; //will not display in text file only command prompt
	if (length == MaxSize)
		cout << "no memory\n"; //will only display in command prompt
	for (int i = length - 1; i >= k; i--)
		element[i + 1] = element[i];
	element[k] = x;
	length++;
}
template<class T>
void LinearList<T>::Output()const
{
	ofstream outFile;
	outFile.open("Elena.Cruz.aList.txt"); //create and write to file

	if (isEmpty())
		outFile << "list is empty\n"; //original: cout << "list is empty\n";
	else
		for (int i = 0; i < length; i++)
			outFile << element[i] << "\t"; //original: cout << element[i] << "\t";

	outFile.close(); //close file
}
class LinkedList
{
private:
	struct node 
	{
		int data;
		node* next;
	};

	node* h;	// h = head
	node* c;	//c = current
	node* t1;	// t1 = temporary 1
	node* t2;	// t2 = temporary 2

public:
	LinkedList();
	void Insert(int pos, int insertData);
	void Delete(int pos, int delData);
	void Output();
};
LinkedList::LinkedList()
{
	h = NULL;
	c = NULL;
	t1 = NULL;
	t2 = NULL;
}
void LinkedList::Insert(int pos, int insertData)
{
	node* n = new node;
	n->data = insertData;
	n->next = NULL;


	if (h != NULL)
	{
		c = h;
		while (c->next != NULL)
		{
			c = c->next;
		}
		c->next = n;
	}
	else
	{
		h = n; //head = node* n = new node
	}
}

void LinkedList::Delete(int pos, int delData)
{
	node* delPtr = NULL;
	t1 = h;
	c = h;
	while (c != NULL && c->data != delData)
	{
		t1 = c;
		c = c->next;
	}
	if (c == NULL)
	{
		delete delPtr;
	}
	else
	{
		delPtr = c;
		c = c->next;
		t1->next = c;
		if (delPtr == h)
		{
			h = h->next;
			t1 = NULL;
		}
		delete delPtr;
	}
}
void LinkedList::Output()
{
	c = h;

	ofstream saveOutputFile;	//create and output file
	saveOutputFile.open("Elena.Cruz.lList.txt"); //write into this text file
	while (c != NULL)
	{
		saveOutputFile << c->data << "\t"; // one row, tabbed format
		c = c->next;
	}
	saveOutputFile.close(); 
}


int main()
{
	int ch;
	int k, x, len, p;
	LinearList <int> obj;
	LinkedList link;

	obj.Insert(0, 11);
	obj.Insert(1, 10);
	obj.Insert(2, 9);
	obj.Insert(3, 8);
	obj.Insert(4, 7);
	obj.Insert(5, 6);
	obj.Insert(6, 5);
	obj.Insert(7, 4);
	obj.Insert(8, 3);
	obj.Insert(9, 2);
	obj.Insert(10, 1);

	obj.Output(); 
	cout << endl;

	int temp = 7;
	obj.Delete(5, temp);

	obj.Output();
	cout << endl;

	obj.Insert(7, 100);
	
	obj.Output();
	cout << endl;


	link.Insert(0,11);
	link.Insert(1,10);
	link.Insert(2,9);
	link.Insert(3,8);
	link.Insert(4,7);
	link.Insert(5,6);
	link.Insert(6,5);
	link.Insert(7,4);
	link.Insert(8,3);
	link.Insert(9,2);
	link.Insert(10,1);

	link.Delete(5, temp);

	link.Insert(7,100);
	link.Output();
	cout << endl;


	return 0;
}


