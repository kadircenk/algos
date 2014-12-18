#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template <class T>
struct Node {
    Node(const T& e = T(), Node* l = NULL, Node* r = NULL)
        : element(e), left(l), right(r) { }
    T element;
    Node* left;
    Node* right;
};

template <class T>
void preorder(const Node<T>* t)
{
    if (t)
    {
        cout << t->element << " ";
        preorder(t->left);
        preorder(t->right);
    }
}

template <class T>
void inorder(const Node<T>* t)
{
    if (t)
    {
        inorder(t->left);
        cout << t->element << " ";
        inorder(t->right);
    }
}

template <class T>
void postorder(const Node<T>* t)
{
    if (t)
    {
        postorder(t->left);
        postorder(t->right);
        cout << t->element << " ";
    }
}

template <class T, class S>
void walkLeft(const Node<T>* q, std::stack<S>& s)
{
    while (q)
    {
        cout << q->element << " ";
        s.push(q->right);
        q = q->left;
    }
}

template <class T>
void preorder_stack(const Node<T>* t)
{
    std::stack<const Node<T>*> s;

    s.push(t);

    while (!s.empty())
    {
        const Node<T>* q = s.top();
        s.pop();
        walkLeft(q, s);
    }
}

template <class T, class S>
void walkLeft2(const Node<T>* q, std::stack<S>& s)
{
    while (q)
    {
        s.push(q);
        q = q->left;
    }
}

template <class T>
void inorder_stack(const Node<T>* t)
{
    std::stack<const Node<T>*> s;

    s.push(t);
    walkLeft2(t->left, s);

    while (!s.empty())
    {
        const Node<T>* q = s.top();
        s.pop();

        cout << q->element << " ";

        walkLeft2(q->right, s);
    }
}

template <class T, class S>
void walkLeft3(const Node<T>* q, std::stack<S>& s)
{
    while (q)
    {
        if (q->right)
        {
            s.push(q->right);
        }
        s.push(q);
        q = q->left;
    }
}

template <class T>
void postorder_stack(const Node<T>* t)
{
    std::stack<const Node<T>*> s;

    walkLeft3(t, s);

    while (!s.empty())
    {
        const Node<T>* q, *r;

        q = s.top();
        s.pop();

        if (!q->right)
        {
            cout << q->element << " ";
        }
        else
        {
            if (!s.empty())
            {
                r = s.top();

                if (q->right == r) // right not processed yet
                {
                    s.pop();
                    s.push(q);
                    walkLeft3(q->right, s);
                }
                else
                {
                    cout << q->element << " ";
                }
            }
            else
            {
                cout << q->element << " ";
            }
        }
    }
}

template <class T>
void visit(const Node<T>* n)
{
    if (n)
    {
        cout << n->element << " ";
    }
}

template <class T>
void levelorder(const Node<T>* t)
{
    std::queue<const Node<T>*> q;

    if (t)
    {
        q.push(t);
    }

    while(!q.empty())
    {
        const Node<T>* n = q.front();
        q.pop();

        visit(n);

        if (n->left)
        {
            q.push(n->left);
        }

        if (n->right)
        {
            q.push(n->right);
        }
    }
}

template <class T>
void POSTorder(const Node<T>* t)
{
	std::stack<const Node<T>*> A;
	A.push(t);
	
	while (!A.empty())
	{
		const Node<T>* a = A.top();
		A.pop();
		
		if (!a->right && !a->left)
		{
			cout<<a->element<<" ";
		}
		else
		{
			Node<T>* b = new Node<T>;
			b->element=a->element;
			b->left=NULL;
			b->right=NULL;
			
			A.push(b);  // buradayken PostOrder
			
			if (a->right)
			{
				A.push(a->right);
			}
			
			// buradayken InOrder
			
			if (a->left)
			{
				A.push(a->left);
			}
			
			// buradayken PreOrder
			
		}
		
	}
	
}

int main()
{
    Node<char>* d = new Node<char>('d');                                       
    Node<char>* f = new Node<char>('f');
    Node<char>* h = new Node<char>('h');
    Node<char>* i = new Node<char>('i');

    Node<char>* g = new Node<char>('g', NULL, h);
    Node<char>* e = new Node<char>('e', f, g);
    Node<char>* b = new Node<char>('b', d, e);
    Node<char>* c = new Node<char>('c', i, NULL);
    Node<char>* a = new Node<char>('a', b, c);

    cout << "preorder:    "; 
    preorder(a);
    cout << endl;

    cout << "inorder:     "; 
    inorder(a);
    cout << endl;

    cout << "postorder:   "; 
    postorder(a);
    cout << endl;

    cout << "preorder_s:  "; 
    preorder_stack(a);
    cout << endl;

    cout << "inorder_s:   "; 
    inorder_stack(a);
    cout << endl;

    cout << "postorder_s: "; 
    postorder_stack(a);
    cout << endl;

    cout << "levelorder:  "; 
    levelorder(a);
    cout << endl;
    
    cout << "POSTorder:   "; 
    POSTorder(a);
    cout << endl;

    return 0;
}
