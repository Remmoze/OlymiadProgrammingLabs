#include <iostream>
#define growthFactor 1.75
#define initialSize 5

struct Stack {
	int* p;
	int cur = 0;
	int max = initialSize;
};

void init(struct Stack* stack) {
	stack->p = (int*)malloc(stack->max * sizeof(int));
	if(stack->p == nullptr) exit(-1);
}

void resize(struct Stack* stack) {
	if(stack->cur < stack->max) return;
	stack->p = (int*)realloc(stack->p, stack->max * growthFactor * sizeof(int));
	stack->max *= growthFactor;
	if(stack->p == nullptr) exit(-1);
}

void push(struct Stack* stack, int value) {
	resize(stack);
	stack->p[stack->cur++] = value;
}

bool isEmpty(struct Stack* stack) {
	return stack->cur <= 0;
}

int pop(struct Stack* stack) {
	return stack->p[--stack->cur];
};
int back(struct Stack* stack) {
	return stack->p[stack->cur - 1];
};
int size(struct Stack* stack) {
	return stack->cur;
}
void clear(struct Stack* stack) {
	stack->cur = 0;
}
void print(struct Stack* stack) {
	for(int i = 0; i < stack->cur; i++) {
		std::cout << stack->p[i];
	}
	std::cout << std::endl;
}

int main() {
	Stack stack;
	init(&stack);
	push(&stack, 1);
	printf("%i", pop(&stack));
	return 0;
}