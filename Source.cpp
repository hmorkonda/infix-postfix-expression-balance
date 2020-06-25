
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>
#include <cmath>

using namespace std;

struct node {

	node *next;
	char data;
	long long int data2;
};
class stacker {
private:
	node *top;
public:
	stacker() {
		top = nullptr;
	}
	string expression;
	bool isEmpty() {
		if (top == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	bool isoperand(char x) {
		if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x == ' ') {
			return false;
		}
		else {
			return true;
		}
	}
	int precedence(char x) {
		if (x == '+' || x == '-') {
			return 3;
		}
		else if (x == '*' || x == '/') {
			return 4;
		}
		else if (x == '(') {
			return 1;
		}
		else if (x == ')') {
			return 2;
		}
		else {
			return 0;
		}
	}
	void push(char x) {

		node *temp = new node;
		//if (temp == nullptr) {
		//	cout << "stack is full" << endl;
		//}
		//else{
		temp->data = x;
		temp->next = top;
		top = temp;
		//}

	}
	char pop() {

		node *temp = new node;
		int x = -1;
		if (top == nullptr) {
			cout << "stack is empty" << endl;
		}
		else {
			temp = top;
			top = top->next;
			x = temp->data;
			delete temp;
		}
		return x;
	}



	bool isBalanced(string exp) {
		//cout << "printing exp: " << exp << endl;

		int len = exp.length();
		if (exp[len - 1] == '+' || exp[len - 1] == '-' || exp[len - 1] == '*' || exp[len - 1] == '/') {
			return false;
		}
		else {
			for (int i = 0; exp[i] != '\0'; i++) {
				if (exp[i + 1] != '\0') {
					if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
						if (exp[i + 1] == '+' || exp[i + 1] == '-' || exp[i + 1] == '*' || exp[i + 1] == '/') {
							return false;
						}
					}

				}
			}
		}



		for (int i = 0; exp[i] != '\0'; i++) {
			if (exp[i] == '(') {
				push(exp[i]);
			}
			else if (exp[i] == ')')
			{
				if (top == nullptr)
				{
					return false;
				}
				else
				{
					pop();

				}
			}
		}


		if (top == nullptr) {
			return true;
		}
		else {
			//cout << top->data;
			return false;
		}
	}


};

int main() {


	stacker object;
	string exp = "2*5+123/2+96+(-5+9)*(-10+7)";
	if (object.isBalanced(exp)) {
		cout << "expression balanced" << endl;
	}
	else {
		cout << "expression not balanced" << endl;
	}

	system("pause");
	

	return 0;
}