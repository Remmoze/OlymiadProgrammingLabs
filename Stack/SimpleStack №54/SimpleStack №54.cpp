﻿#include <iostream>
#include <string>

#define MAX_SIZE 100
class Stack {
public:
	void push(int value) {
		elements[cur++] = value;
	};
	void pop() {
		--cur;
	};
	int back() {
		return elements[cur - 1];
	};
	int size() {
		return cur;
	}
	void clear() {
		cur = 0;
	}
	void print() {
		for(int i = 0; i < cur; i++) {
			std::cout << elements[i];
		}
		std::cout << std::endl;
	}
private:
	int cur = 0;
	int elements[MAX_SIZE];
};

int main() {
	Stack stack;
	std::string input;
	int inp;
	do {
		std::cin >> input;
		if(input == "push") {
			std::cin >> inp;
			stack.push(inp);
			std::cout << "ok" << std::endl;
		} else if(input == "pop") {
			std::cout << stack.back() << std::endl;
			stack.pop();
		}
		else if(input == "back") {
			std::cout << stack.back() << std::endl;
		} 
		else if(input == "size") {
			std::cout << stack.size() << std::endl;
		}
		else if(input == "clear") {
			stack.clear();
			std::cout << "ok" << std::endl;
		}	
	} while(input != "exit");
	std::cout << "bye" << std::endl;
	return 0;
}