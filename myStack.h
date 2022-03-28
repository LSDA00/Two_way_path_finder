/*
Lucas Allen, 5004607031, assignment 9

Class_identifier: A linked list implementation of the stack
constructors:
myStack();
public functions:
void push(const Type&);
void pop();
Type top() const;
bool isEmpty() const;
static members:
Type item;
node * next;
node * topOfmyStack;
*/
template <class Type>
class myStack
{
public:
	myStack();
	myStack(const myStack<Type>&);
	const myStack<Type>& operator=(const myStack<Type>&);
	~myStack();

	void push(const Type&);
	void pop();
	Type top() const;
	bool isEmpty() const;

public:
	struct node
	{
		Type item;
		node * next;
	};
	node * topOfmyStack;				//pointer that points to the top of the stack
};

//default constructor that sets TopOfMyStack to NULL;
template <class Type>
myStack<Type>::myStack()
{
	topOfmyStack=NULL;
}

//copy constructor that performs a deep copy of the copy object to the *this object;
template <class Type>
myStack<Type>::myStack(const myStack<Type>& copy)
{
	topOfmyStack= NULL;
	*this = copy;
}
//assignment operator that does a deep copy of the rhs to the *this object
template<class Type>
const myStack<Type>& myStack<Type>::operator=(const myStack<Type>& rhs)
{
	topOfmyStack = NULL;
	*this = rhs;
}
//destructor, deallocates the stack object
template<class Type>
myStack<Type>::~myStack()
{
		while(!isEmpty())
		{
			pop();
		}

}
//pushes a new node to the top of the stack (aka a head insert) and assigns insert into this new node's item field
template <class Type>
void myStack<Type>::push(const Type& insert)
{
	node * pushNode = new node;
	pushNode->item = insert;
	pushNode->next = topOfmyStack;
	topOfmyStack = pushNode;
}
//removes the top element (head removal) if the stack is not empty, otherwise nothing happens
template <class Type>
void myStack<Type>::pop()
{
	if(!isEmpty())
	{
		node * removeHead = topOfmyStack;
		topOfmyStack = topOfmyStack->next;
		delete removeHead;
	}

}
//returns true if the stack is empty and false if the stack is not empty
template <class Type>
bool myStack<Type>::isEmpty() const
{
	return (topOfmyStack==NULL);
}
//returns the item of the top node in the stack
template <class Type>
Type myStack<Type>::top() const
{
	if(isEmpty())
	{
		std::cout<<"The list is empty"<<std::endl;
	}
	node * topNode = new node;
	topNode = topOfmyStack;
	return topNode->item;
}
