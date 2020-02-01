#include <iostream>
#include "Header.h"
using namespace std;

class binary {

	bool* num;

	binary(char* num, int number_system = 2) {
		bool sign;
		if (num[0] == '-') {
			sign = 1;
			num = num+1;
		}
		else
			sign = 0;
		switch(number_system){
		case 10:
			int int_number = num - '0';

			break;
		}

	}


};

template <typename Type>

//constractor with parameters (should I do the default constructor?)
MyList<Type>::MyList(int num = 10) {
	try {
		root = (Node<Type>*)malloc(sizeof(Node<Type>));
		root->item = 0;
		root->next = NULL;
		counter = 0;
		size = num;
	}
	catch (bad_alloc a) {
		cout << "Memory error";
	}

}

template <typename Type>

MyList<Type>::MyList(const Node<Type>* node) : root(node){}

template <typename Type>

MyList<Type>::~MyList() {
	Node<Type>* prev = NULL;
	while ((root)->next) {
		prev = root;
		root = root->next;
		free(prev);
	}
	free(root);
}



template <typename Type>

//get the end of the list
Node<Type>* MyList<Type>::get_last() {

	Node<Type>* tmp = root;

	while (tmp->next) {
		tmp = tmp->next;
	}
	return tmp;
}

template <typename Type>

//add to the end
void MyList<Type>::add_back(Type item) {
	if (counter < size){


		Node<Type>* last = get_last(); //the end of the list
		Node<Type>* tmp = new Node < Type >; //the new node

		tmp->item = item;
		tmp->next = NULL;

		last->next = tmp;
		
		
	}
	else{

		throw bad_alloc();
	}

}

template <typename Type>

//delete all nodes with item
void MyList<Type>::delete_node(Type item) {

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
void  MyList<Type>::print() {
	Node<Type>* tmp = root->next;
	cout << "My list:" << endl;
	while (tmp != NULL) {

		cout << tmp->item << endl;
		tmp = tmp->next;
	}
}

template <typename Type>

//delete all List
void MyList<Type>::delete_list() {
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
Node<Type>* MyList<Type>::find(Type item) {
	Node<Type>* tmp = root->next;

	while (tmp) {

		if (tmp->item == item) 
			
			return tmp;
		

		tmp = tmp->next;
	}

	
	return NULL;
}



int main()
{
	int b = 0;
	int size;
	cout << "Enter size:" << endl;
	cin >> size;
	MyList<int> a(size);


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
			try{
				a.add_back(choice);
			}
			catch (bad_alloc a) {
				cout << "There are no memory";
			}
			break;
		case 2:
			cout << "Enter item: " << endl;
			cin >> choice;
			a.delete_node(choice);
			break;
		case 3:
			a.print();
			break;
		case 4:
			cout << "Enter item: " << endl;
			cin >> choice;
			if(a.find(choice)!=NULL)
				cout << "There is this element" << endl;
			else
				cout << "There is no such element" << endl;
				
			break;
		case 5:
			a.delete_list();
			break;
		default:
			cout << "Enter 1-5 num" << endl;
		}
	}
	return 0;
}
