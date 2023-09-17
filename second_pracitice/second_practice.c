#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_STACK_SIZE 100

//���� ����

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;
void init_stack(StackType* s) {
	s->top = -1;
}
int is_empty(StackType* s) {
	return (s->top == -1);
}
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}

//��� ����

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;
TreeNode n1 = { 4, NULL, NULL };
TreeNode n2 = { 5, NULL, NULL };
TreeNode n3 = { 3, &n1, &n2 };
TreeNode n4 = { 6, NULL, NULL };
TreeNode n5 = { 2, &n3, &n4 };
TreeNode n6 = { 8,  NULL, NULL };
TreeNode n7 = { 10, NULL, NULL };
TreeNode n8 = { 11,  NULL, NULL };
TreeNode n9 = { 9, &n7, &n8 };
TreeNode n10 = { 7, &n6, &n9 };
TreeNode n11 = { 1, &n5, &n10 };

TreeNode* root = &n11;

// ���� ��ȸ
void inorder(TreeNode* root, StackType* s) {
    if (root) {
        inorder(root->left, s);     // ���ʼ���Ʈ�� ��ȸ
        //printf("%d ", root->data); // ��� �湮
        push(s, root->data);
        inorder(root->right, s);    // �����ʼ���Ʈ�� ��ȸ
    }
}
// ���� ��ȸ
void preorder(TreeNode* root, StackType* s) {
    if (root) {
        //printf("%d ", root->data); // ��� �湮
        push(s, root->data);
        preorder(root->left, s);    // ���ʼ���Ʈ�� ��ȸ
        preorder(root->right, s);   // �����ʼ���Ʈ�� ��ȸ
    }
}
// ���� ��ȸ
void postorder(TreeNode* root, StackType* s) {
    if (root) {
        postorder(root->left, s);   // ���� ���� Ʈ�� ��ȸ
        postorder(root->right, s);  // ������ ���� Ʈ�� ��ȸ
        //printf("%d ", root->data); // ��� �湮
        push(s, root->data);
    }
}

int main() {

    StackType s;
    init_stack(&s);
    int num[11];

    printf("linked tree\n");

    printf("���� ��ȸ=");
    preorder(root, &s);
    for (int i = 10; i >= 0; i--) {
        num[i] = pop(&s);
    }

    for (int i = 0; i < 11; i++){
        printf("%d ", num[i]);
    }
    printf("\n");

    printf("���� ��ȸ=");
    inorder(root, &s);
    for (int i = 10; i >= 0; i--) {
        num[i] = pop(&s);
    }

    for (int i = 0; i < 11; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

    printf("���� ��ȸ=");
    postorder(root, &s);
    for (int i = 10; i >= 0; i--) {
        num[i] = pop(&s);
    }

    for (int i = 0; i < 11; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}