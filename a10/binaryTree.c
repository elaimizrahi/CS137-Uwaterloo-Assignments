#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct bstnode {
	int item;
	struct bstnode *left;
	struct bstnode *right;
};

struct bst {
	struct bstnode *root;
	int count;
};

struct bst *bst_create(void)
{
	struct bst *t = malloc(sizeof(struct bst));
	t->root = NULL;
	t->count = 0;
	return t;
}

void destroy(struct bstnode *node)
{
	if (node != NULL)
	{
		destroy(node->left);
		destroy(node->right);
		free(node);
	}
}

void bst_destroy(struct bst *t)
{
	destroy(t->root);
	free(t);
}


int bst_search(struct bst *t, int val)
{
	struct bstnode *node = t->root;
	if(!(node)){
		return 0;
	}
	while(node){
		if(val > node->item){
			node = node->right;
		}		
		else if(val < node->item){
			node = node->left;
		}
		else if(val == node->item){
			return 1;
		}
	}
	return 0;//search(t->root, val);
}



void bst_insert(int num, struct bst *t)
{	
	t->count = t->count + 1;;
	if(!(t->root)){
		struct bstnode *start = malloc(sizeof(struct bstnode));
		t->root = start;
		start->item = num;
		start->right = NULL;
		start->left = NULL;
		return;
	}

	struct bstnode *curnode = t->root;
	struct bstnode *nextnode = t->root;
	while(nextnode){
		if(num == nextnode->item){
			t->count--;
			return;
		}
		if(num > nextnode->item){
			curnode = nextnode;
			nextnode = curnode->right;
		}
		else if(num < nextnode->item){
			curnode = nextnode;
			nextnode = curnode->left;
		}
	}
	assert(curnode);
	//printf("%d", curnode->item);	
	struct bstnode *node = malloc(sizeof(struct bstnode));

	if(num > curnode->item){	
	
		node->item = num;
		node->left = NULL;
		node->right = NULL;
		curnode->right = node;

	}
	else if(num < curnode->item){		
		node->item = num;
		node->left = NULL;
		node->right = NULL;
		curnode->left = node;

	}

}

void print(struct bstnode *node)
{
	if (node)
	{
		print(node->left);
		printf("%d ", node->item);
		print(node->right);
	}
}

void bst_print(struct bst *t)
{
	if (t->root)
	{
		print(t->root);
		printf("\n");
	}
}



int bst_min(struct bst *t)
{
	struct bstnode *node = t->root;
	while(node->left){
		node = node->left;
	}
	return node->item;
}


int bst_max(struct bst *t)
{
	struct bstnode *node = t->root;
	while(node->right){
		node = node->right;
	}
	return node->item;
}

int recursivehelper(struct bstnode *node){
	if(node->left == NULL && node->right){
		return 1 + recursivehelper(node->right);
	}
	if(node->right == NULL && node->left){
		return 1 + recursivehelper(node->left);
	}
	if(node->right == NULL && node->left == NULL){
		return 0;
	}
	else{
		int i = 1 + recursivehelper(node->left);
		int j = 1 + recursivehelper(node->right);
		if(i > j){
			return i;
		}
		else if(j>i){
			return j;
		}
		else{
			return i;
		}
	}
	
	return 0;
}


int bst_height(struct bst *t)
{
	if(!(t->root)){
		return 0;
	}
	//printf("%d", recursivehelper(t->root))

	return recursivehelper(t->root);
}

/*
int main(void)
{
	//public test order matters	
	printf("hi\n");

	struct bst *tree = bst_create();
	bst_insert(100, tree);
	bst_insert(150, tree);
	bst_insert(78, tree);
	bst_insert(88, tree);
	assert(bst_min(tree) == 78);
	assert(bst_max(tree) == 150);
	bst_print(tree);
	bst_insert(-130, tree);
	assert(tree->count == 5);
	bst_insert(-130, tree);
	assert(tree->count == 5);
	bst_print(tree);
	assert(bst_search(tree, 100));
	assert(!bst_search(tree, 90));
	assert(bst_height(tree) == 2);

// continue with secret tests.. order matters
	bst_insert(120, tree);
	bst_insert(113, tree);
	bst_insert(-60, tree);
	bst_insert(90, tree);
	bst_insert(190, tree);
	bst_print(tree);
	assert(bst_min(tree) == -130);
	assert(bst_max(tree) == 190);
	assert(tree->count == 10);
	assert(bst_height(tree) == 3);
	bst_destroy(tree);

	struct bst *tr = bst_create();
	bst_insert(100, tr);
	bst_insert(90, tr);
	bst_insert(80, tr);
	assert(bst_min(tr) == 80);
	assert(bst_max(tr) == 100);
	assert(tr->count == 3);
	bst_print(tr);
	assert(bst_height(tr) == 2);
	bst_destroy(tr);
//
	struct bst *tr2 = bst_create();
	bst_insert(100, tr2);
	bst_insert(190, tr2);
	bst_insert(280, tr2);
	bst_insert(300, tr2);
	bst_insert(490, tr2);
	bst_insert(580, tr2);
	assert(bst_min(tr2) == 100);
	assert(bst_max(tr2) == 580);
	assert(tr2->count == 6);
	assert(bst_height(tr2) == 5);
	bst_print(tr2);
	bst_destroy(tr2);
//
	struct bst *tr3 = bst_create();
	bst_insert(100, tr3);
	assert(bst_min(tr3) == 100);
	assert(bst_max(tr3) == 100);
	assert(tr3->count == 1);
	assert(bst_height(tr3) == 0);
	bst_print(tr3);
	bst_destroy(tr3);
//
}//
//
//*/