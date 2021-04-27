#include <iostream>
// ������ �������� ������������ ������� ����� � ��� ������ �����
#define growthFactor 1.75
#define initialSize 5

// ������� ��������� ���� � ���������� �� ������, ������� ������������� � ������������ ��������
struct Stack {
	int* p;
	int cur = 0;
	int max = initialSize;
};

// �������� ������ ��� �����
void init(struct Stack* stack) {
	stack->p = (int*)malloc(stack->max * sizeof(int));
	if(stack->p == nullptr) exit(-1);
}

// ������� ��� ��������� ������� �����, ����� ���������� ������������ ����� ���������
void resize(struct Stack* stack) {
	if(stack->cur < stack->max) return;
	stack->p = (int*)realloc(stack->p, stack->max * growthFactor * sizeof(int));
	stack->max *= growthFactor;
	if(stack->p == nullptr) exit(-1);
}

// ���������� �������� � ����
void push(struct Stack* stack, int value) {
	resize(stack);
	stack->p[stack->cur++] = value;
}

// �������� �������� �� �����
int pop(struct Stack* stack) {
	return stack->p[--stack->cur];
};

// ������ �����
int size(struct Stack* stack) {
	return stack->cur;
}

// ����� �����
void print(struct Stack* stack) {
	for(int i = 0; i < stack->cur; i++) {
		std::cout << stack->p[i] << ' ';
	}
	std::cout << std::endl;
}

// ��������� ����� [-10, 20]
int random() {
	return (rand() % 31) - 10;
}

int main() {
	// �������� ����
	for(int i = 0; i < 5; i++) {
		Stack stack;
		init(&stack);

		// ���������� ����� ���������� �������
		int N = 10;
		for(int i = 0; i < N; i++) {
			push(&stack, random());
		}

		// ����� �����
		std::cout << "Stack: ";
		print(&stack);

		//���������� ������������� ��������
		int max = -10;
		for(int i = 0; i < N; i++) {
			int val = pop(&stack);
			if(val > max) {
				max = val;
			}
		}

		std::cout << "Max: " << max << std::endl << std::endl;
	}
	
	return 0;
}