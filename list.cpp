#include <iostream>
#include "Header.h"
using namespace std;

template <typename Type>

//constractor with parameters (should I do the default constructor?)
MyList<Type>::MyList(int num) {
	try {
		root = (Node<Type>*)malloc(sizeof(Node<Type>));
		root->item = 0;
		root->next = NULL;
		counter = 0;
		size = 0;
	}
	catch (bad_alloc a) {
		cout << "Memory error";
		system("pause");
	}

}

template <typename Type>

MyList<Type>::MyList(const Node<Type>* node) : root(node){}

template <typename Type>

MyList<Type>::~MyList() {}



template <typename Type>

//get the end of the list
Node<Type>* MyList<Type>::getLast() {

	Node<Type>* tmp = root;

	while (tmp->next) {
		tmp = tmp->next;
	}
	return tmp;
}

template <typename Type>

//add to the end
void MyList<Type>::Add_back(Type item) {
	if (counter < size){
		try {

			Node<Type>* last = getLast(); //the end of the list
			Node<Type>* tmp = new Node < Type > ; //the new node

			tmp->item = item;
			tmp->next = NULL;

			last->next = tmp;
		}
		catch (bad_alloc a) {
			cout << "There are no memory";
			system("pause");
		}
	}
	else{

		cout << "Sorry, there are no memory for it";
	}

}

template <typename Type>

//delete all nodes with item
void MyList<Type>::Delete(Type item) {

	Node<Type>* tmp = root;

	int count = 0; //count of nodes

	while (tmp->next != NULL) { //while it's not the end of the list

		if (tmp->next->item == item) { //if the next one has item

			Node<Type>* add = tmp->next->next; //save it's pointer
			free(tmp->next); //delete node
			tmp->next = add; //restore the list
			count++;
			counter--;

		}
		else {
			tmp = tmp->next; //next node
		}
		if (tmp == NULL) //if we delete prnultimate
			break;

	}

	if (count == 0)
		cout << "There are no such element" << endl;

}

template <typename Type>

//vizualization
void  MyList<Type>::Print() {
	Node<Type>* tmp = root->next;
	cout << "My list:" << endl;
	while (tmp != NULL) {

		cout << tmp->item << endl;
		tmp = tmp->next;
	}
}

template <typename Type>

//delete all List
void MyList<Type>::DeleteList() {
	Node<Type>* prev = NULL;
	while ((root)->next) {
		prev = root;
		root = root->next;
		free(prev);
	}
	free(root);
}

template <typename Type>

//find first entry of node with item
Node<Type>* MyList<Type>::Find(Type item) {
	Node<Type>* tmp = root;

	while (tmp) {

		if (tmp->item == item) {
			cout << "There is this element" << endl;
			return tmp;
		}

		tmp = tmp->next;
	}

	cout << "There is no such element" << endl;
	return NULL;
}



int main()
{
	int b = 0;
	MyList<int> a;


	int choice;
	while (b != 5) {
		cout << "What do you wanna to do" << endl;
		cout << "1. Add" << endl << "2. Delete several nodes" << endl
			<< "3. Print the List" << endl << "4. Find an element" << endl
			<< "5. Exit" << endl;
		cin >> b;
		switch (b) {
		case 1:
			cout << "Enter item: " << endl;
			cin >> choice;
			a.Add_back(choice);
			break;
		case 2:
			cout << "Enter item: " << endl;
			cin >> choice;
			a.Delete(choice);
			break;
		case 3:
			a.Print();
			break;
		case 4:
			cout << "Enter item: " << endl;
			cin >> choice;
			a.Find(choice);
			break;
		case 5:
			a.DeleteList();
			break;
		}
	}
	return 0;
}
