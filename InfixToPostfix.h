#ifndef INFIXTOPOSTFIX_H
#define INFIXTOPOSTFIX_H

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op) {
	if (op == '+' || op == '-') {
		return 1;
	}
	else if (op == '*' || op == '/') {
		return 2;
	}
	return 0;
}

class InfixToPostfix {
private:
	string postfix;
public:
	InfixToPostfix() { postfix = ""; };

	void Convert(string infix) {
		stack<char> s;
		postfix.clear();

		for (char& c : infix) {
			if (isalpha(c)) {
				postfix += c;
			}
			else if (c == '(') {
				s.push(c);
			}
			else if (c == ')') {
				if (!s.empty()) {
					while (s.top() != '(') {
						postfix += s.top();
						s.pop();
					}
					s.pop();
				}
			}
			else if (c == ' ') {
				continue;
			}
			else {
				while (!s.empty() && precedence(s.top()) <= precedence(c)) {
					postfix += s.top();
					s.pop();
				}
				s.push(c);
			}
		}

		while (!s.empty()) {
			postfix += s.top();
			s.pop();
		}
	};

	string getPostfix() {
		return postfix;
	}
};

#endif