#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_STACK_SIZE 100

//스택 생성

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
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

//노드 생성

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

// 중위 순회
void inorder(TreeNode* root, StackType* s) {
    if (root) {
        inorder(root->left, s);     // 왼쪽서브트리 순회
        //printf("%d ", root->data); // 노드 방문
        push(s, root->data);
        inorder(root->right, s);    // 오른쪽서브트리 순회
    }
}
// 전위 순회
void preorder(TreeNode* root, StackType* s) {
    if (root) {
        //printf("%d ", root->data); // 노드 방문
        push(s, root->data);
        preorder(root->left, s);    // 왼쪽서브트리 순회
        preorder(root->right, s);   // 오른쪽서브트리 순회
    }
}
// 후위 순회
void postorder(TreeNode* root, StackType* s) {
    if (root) {
        postorder(root->left, s);   // 왼쪽 서브 트리 순회
        postorder(root->right, s);  // 오른쪽 서브 트리 순회
        //printf("%d ", root->data); // 노드 방문
        push(s, root->data);
    }
}

int main() {

    StackType s;
    init_stack(&s);
    int num[11];

    printf("linked tree\n");

    printf("전위 순회=");
    preorder(root, &s);
    for (int i = 10; i >= 0; i--) {
        num[i] = pop(&s);
    }

    for (int i = 0; i < 11; i++){
        printf("%d ", num[i]);
    }
    printf("\n");

    printf("중위 순회=");
    inorder(root, &s);
    for (int i = 10; i >= 0; i--) {
        num[i] = pop(&s);
    }

    for (int i = 0; i < 11; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

    printf("후위 순회=");
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