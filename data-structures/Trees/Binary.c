#include <stdio.h>
#include <stdlib.h>

// Ʈ�� ��� ����ü ����
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// ��� ���� �Լ�
TreeNode* createNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    if (node == NULL) {
        printf("�޸� �Ҵ� ����\n");
        exit(1);
    }
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

// BST ���� �Լ�
TreeNode* bstInsert(TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = bstInsert(root->left, value);
    }
    else {
        root->right = bstInsert(root->right, value);
    }
    return root;
}

// BST Ž�� �Լ�
TreeNode* bstSearch(TreeNode* root, int value) {
    if (root == NULL || root->value == value) {
        return root;
    }
    if (value < root->value)
        return bstSearch(root->left, value);
    else
        return bstSearch(root->right, value);
}

// ���� ��ȸ (Root, Left, Right)
void preorder(TreeNode* root) {
    if (root != NULL) {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    TreeNode* root = NULL;
    int values[] = { 50, 30, 70, 20, 40, 60, 80 };
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = bstInsert(root, values[i]);
    }

    printf("���� ��ȸ: ");
    preorder(root);
    printf("\n");

    int target = 40;
    if (bstSearch(root, target))
        printf("BST���� %d�� ã�ҽ��ϴ�.\n", target);
    else
        printf("BST���� %d�� ã�� ���߽��ϴ�.\n", target);

    // �޸� ������ ��������� ��� ��带 free�ϴ� ������ �Լ��� �ʿ��մϴ�.

    return 0;
}