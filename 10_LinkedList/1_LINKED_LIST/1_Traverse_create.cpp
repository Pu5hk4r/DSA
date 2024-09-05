/*
not reccomended to use this code 
because this code can be esaily implemented using vector ,list ,dequeue

*/#include <iostream>  

using namespace std;

class LinkedList {

private:

	struct Node{  // node structure

		int data;

		Node *next;

		Node(int value):data(value), next(nullptr) {};//constructor the initialse the node list

	};

	Node *head; // pointer to the head first node

public:

	LinkedList() :head(nullptr){}

	~LinkedList() { // allocated memory is free when the object is destroyed

		deletelist();
	}

	void insert_at_end(int data)
	{
		Node *new_node = new Node(data);

		if(head == nullptr){

			head = new_node;

		} else{

			Node *current = head;

			while(current->next != nullptr){

				current = current->next;

			}

			current->next = new_node;
		}
	}


	void traverse() const{

		Node * current = head;

		cout<<"List elements are : [";

		while(current != nullptr){

			std::cout<< current->data<< " ";

			current = current->next;
		}

		cout<<"]";


		cout<<"\n";


	}


	void deletelist(){

		Node * current = head;

		Node* next = nullptr;

		while(current != nullptr){

			next = current->next;

			delete current;

			current = next;
		}

		head = nullptr;
	}
};


int main()
{
	LinkedList list;

	int numnodes , data;


	cout<<"enter the number of nodes: "<<"\n";

	cin>> numnodes;


	for(int i=0;i<numnodes;i++){

		cout<<"enter value of nodes "<<(i+1)<<":";

		cin>>data;

		list.insert_at_end(data);
	}


	list.traverse();


	return 0;
}