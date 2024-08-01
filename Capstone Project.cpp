#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* insert(struct TreeNode* node, int key) {
    if (node == NULL) return createNode(key);
    if (key < node->val) {
        node->left = insert(node->left, key);
    } else if (key > node->val) {
        node->right = insert(node->right, key);
    }
    return node;
}

int isIdentical(struct TreeNode* a, struct TreeNode* b) {
    if (a == NULL && b == NULL) return 1;
    if (a != NULL && b != NULL) {
        return (a->val == b->val &&
                isIdentical(a->left, b->left) &&
                isIdentical(a->right, b->right));
    }
    return 0;
}

int countWays(int* nums, int numsSize, struct TreeNode* originalBST, int* temp, int start, int end, int* used) {
    if (start == end) {
        struct TreeNode* newBST = NULL;
        for (int i = 0; i < numsSize; i++) {
            newBST = insert(newBST, temp[i]);
        }
        if (isIdentical(newBST, originalBST)) {
            return 1;
        }
        return 0;
    }
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (!used[i]) {
            used[i] = 1;
            temp[start] = nums[i];
            count += countWays(nums, numsSize, originalBST, temp, start + 1, end, used);
            used[i] = 0;
        }
    }
    return count;
}

int numOfWays(int* nums, int numsSize) {
    struct TreeNode* originalBST = NULL;
    for (int i = 0; i < numsSize; i++) {
        originalBST = insert(originalBST, nums[i]);
    }
    int* temp = (int*)malloc(numsSize * sizeof(int));
    int* used = (int*)calloc(numsSize, sizeof(int));
    int result = countWays(nums, numsSize, originalBST, temp, 0, numsSize, used);
    free(temp);
    free(used);
    return result;
}

int main() {
	int numsSize;
	printf("Enter number of elements of the array:\n");
	scanf("%d",&numsSize);
	printf("Enter elements of the array:\n");
	int nums[numsSize];
	for(int i=0;i<numsSize;i++)
	{
		scanf("%d",&nums[i]);
	}
    printf("Number of ways to reorder the array to get the same BST: %d\n", numOfWays(nums, numsSize));
    return 0;
}

