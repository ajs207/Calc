#include "core.hpp"

//evaluate tree
double eval(node* a)
{

	
	if (a->value->Char == '+' || a->value->Char == '-' || a->value->Char == '*' || a->value->Char == '/' || a->value->Char == '%')
		switch (a->value->Char){
		case '+':
			
			return eval(a->left) + eval(a->right);
		case '-':
			return eval(a->left) - eval(a->right);
		case '*':
			return eval(a->left) * eval(a->right);
		case '/':
			return eval(a->left) / eval(a->right);
		case '%':
		{
					int b = a->left->value->num; int c = a->right->value->num;
					return b % c;
		}

	}
	else if (a->value->num >= 0 || a->value->num <= 9)
		return a->value->num;
	else
		return NULL;
	
}
int main()
{
	string str;
	
	cout << "enter string" << endl;
	
	getline(cin, str);
	
	tree* test = ast(str);
	
	if (test != NULL)
	{
		cout << eval(test->root) << endl;
	}
}