#include <iostream>
#include <cstdlib>
using namespace std;


struct Node {
	int val;
	Node* next;


};



// Èíèöèàëèçàöèè ýëåìåíòà îäíîñâÿçíîãî ñïèñêà íóëÿìè

void init(Node* node) {

	//node = (struct Node*)malloc(sizeof(struct Node)); 
	node->val = 0;
	node->next = NULL;

}

// Îòîáðàæåíèÿ îäíîñâÿçíîãî ñïèñêà íà ýêðàí

void show(Node* head) {
	
	
	 while (head->val != NULL) {

		cout << head->val << " ";
		head = head->next;


	}
}

void pushNode(Node* head, Node* node) {

int push_count=0;
    while (head->next != NULL)
        head = head->next;

    head->next = node;
    node->next = NULL;
    push_count+=1;
}


void copyMas(Node* source, Node* dest) {
	
	while (source->next != NULL || dest->next != NULL) {

		dest->val = source->val;
		source = source->next;
		dest = dest->next;
		

	}

}



int testCopyMas(){
    Node* source = new Node;
	Node* dest = new Node;
	Node* source_node = source;
	Node* dest_node = dest;
	init(source);
	init(dest);
	for (int x = 1; x < 11; x++) {
	pushNode(source, new Node);
	source_node->val =x ;
	source_node = source_node->next;
}
for (int x = 1; x < 11; x++) {
	pushNode(dest, new Node);
	dest_node->val =1 ;
	dest_node = dest_node->next;
}
copyMas(source,dest);
for (int x = 1; x < 11; x++) {
	if (source->val != dest -> val){ return -1;}
	source=source->next;
	dest=dest->next;
	
}
return 0;
    
}



static void runTest(int (*testFunction)(), const std::string& testName)
{
    if (testFunction() == 0)
        std::cout << "Test " << testName << " - OK" << std::endl;
    else
        std::cout << "Test " << testName << " - FAIL" << std::endl;
}



int main() {

	runTest(testCopyMas, "testCopyMas");


}
