typedef int element;
typedef struct DlistNode{
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
}DlistNode;

void init(DlistNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

//"before" 바로 옆에 새 노드 추가하기
void dinsert_node(DlistNode* before, DlistNode* new_node) {
	new_node->llink = before;
	new_node->rlink = before->rlink;
	before->rlink->llink = new_node;
	before->rlink = new_node;
}

void dremove_node(DlistNode* phead_node, DlistNode* removed) {
	if (removed == phead_node) return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

void display(DlistNode* phead) {
	DlistNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<--- | %x | %d | %x | --->\n", p->llink, p->data, p->rlink);
	}
	printf("\n");
}

void main() {
	DlistNode head_node; //DlistNode* head_node = (DlistNode*)malloc(sizeof(DlistNode));
	DlistNode* p[10];
	init(&head_node); //init(head_node);
	for (int i = 0; i < 5; i++) {
		p[i] = (DlistNode*)malloc(sizeof(DlistNode));
		p[i]->data = i;
		dinsert_node(&head_node, p[i]);
	}
	dremove_node(&head_node, p[4]); //dremove_node(head_node, p[4]);
	display(&head_node); //display(head_node);
}
