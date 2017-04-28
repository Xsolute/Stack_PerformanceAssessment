#include <stdio.h>
#define SIZE 10 // SIZE�� 10���� ����
#define OUTPUTSIZE SIZE*SIZE // OUTPUTSIZE�� SIZE�� �������� ����
int InPointer = -1, OutPointer = 0, InStack[SIZE], OutStack[OUTPUTSIZE]; // �������� ����
int Push(int item) {
	if (InPointer >= SIZE-1) { 
		printf("OVERFLOW\n\n");
		return 0;
	} // top�� SIZE-1���� ũ�ų� ���� ��� OVERFLOW ��� �� return
	else { 
		++InPointer;
		InStack[InPointer] = item;
		return 0;
	} // �ƴ� ��� top�� �÷��� item�� stack�� �Է½�Ű�� return
}
int Pop(int item) {
	if (InPointer == -1) { 
		printf("UNDERFLOW\n\n");
		return 0;
	} // top�� -1�� ��� UNDERFLOW ��� �� return
	else {
		--InPointer;
		return InStack[InPointer+1];
	} // �ƴ� ��� top�� ���̰� ���� ���̾��� stack[top+1]�� return
}
void StackPrint() {
	int i; // for���� ����ϴ� ���� i ����
	printf("STACK [ ");
	for (i = 0; i <= InPointer; i++) {
		printf("%d ", InStack[i]); // InStack ���� ���� ���
	}
	printf("]\nOUTPUT [ ");
	for (i = 0; i < OutPointer; i++) {
		printf("%d ", OutStack[i]); // OutStack ���� ���� ���
	}
	printf("]\n");
}
void main(void) {
	int item, i, temp; // �������� ����
	printf("STACK PROGRAM\nINPUT INTEGER TO PUSH\nINPUT 9999 TO POP\nINPUT 8888 TO END\nMAXIMUM STACK SIZE IS 10\nMAXIMUM OUTPUT STACK SIZE IS 100\n==============================\n");
	StackPrint(); // StackPrint �Լ� ȣ��
	for (;;) { // ���ѹݺ�
		printf("INPUT : ");
		scanf("%d", &item); // item �Է�
		printf("\n");
		if (item == 9999) { // item�� 9999�� ��� Pop
			if (InPointer != -1) {
				OutStack[OutPointer] = Pop(item); // InPointer�� -1�� �ƴ� ��� OutStack�� Pop(item)�� ����� ����
				OutPointer++;
			} else {
				Pop(item); // InPointer�� -1�� ��� 0�� ���޵Ǵ� ���� �����ϱ� ���� Pop�� ȣ��
			}
			StackPrint(); // StackPrint �Լ� ȣ��
		} else if (item == 8888) { // item�� 8888�� ��� ����
			return 0;
		} else {
			Push(item); // �̿��� ��� Push�Լ� ȣ�� �� StackPrint �Լ� ȣ��
			StackPrint();
		}
	}
}