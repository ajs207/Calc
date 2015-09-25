#include "core.hpp"
//postfix notation
void postfix(node* a){  
	if(a->left!=NULL)postfix(a->left);
	if(a->right!=NULL)postfix(a->right);
	cout << a->value->Char;

}
int main()
{
	string str;
	cout << "enter string" << endl;
	
	getline(cin, str);
	
	
	tree* test = ast(str);
	if (test != NULL)
	{
		cout << "postfix:  "; postfix(test->root); cout << endl;
	}
}