#include "core.hpp"

void prefix(node* a){
	cout << a->value->Char;
	if (a->left != NULL)prefix(a->left);
	if (a->right != NULL)prefix(a->right);
	
}
int main()
{
	string str;
	
	cout << "enter string" << endl;
	
	getline(cin, str);
	
	tree* test = ast(str);
	
	if (test != NULL)
	{
		cout << "prefix:  "; prefix(test->root); cout << endl;
	}
}