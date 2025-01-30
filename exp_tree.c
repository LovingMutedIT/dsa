#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	char data[100];
	struct node *left, *right;
}

struct node *createnode(char *data) {
	struct node *temp;
	temp = (struct node *) malloc (sizeof(struct node))
	strcpy(temp->data, data);
	temp->left = NULL;
	temp->right = NULL;
}

int evaluate(Node* root, int age, int healthy, int drivingHours, int passDrivingTest) {
    if (!root) return 0;

    if (strcmp(root->data, "age>=18") == 0) return age >= 18;
    if (strcmp(root->data, "Healthy==True") == 0) return healthy;
    if (strcmp(root->data, "DrivingHours>=25") == 0) return drivingHours >= 25;
    if (strcmp(root->data, "PassDrivingTest==True") == 0) return passDrivingTest;
   
    if (strcmp(root->data, "^") == 0) {
        int leftVal = evaluate(root->left, age, healthy, drivingHours, passDrivingTest);
        int rightVal = evaluate(root->right, age, healthy, drivingHours, passDrivingTest);
        return leftVal && rightVal; 
    }

    return 0;
}


struct node *createExpTree() {
	struct node *n1 = createNode("age>=18");
	struct node *n2 = createNode("Healthy==True");
	struct node *n3 = createNode("DrivingHours>=25");
	struct node *n4 = createNode("PassDrivingTest==True")
	
	struct node* op1 = createNode("^");
	op1->left = n1;
	op1->right = n2;

	struct node* op2 = createNode("^");
    	op2->left = op1;
    	op2->right = n3;

	struct node* op3 = createNode("^");
	op3->left = op2;
	op3->right = n4;

    	return op3; 
}

int main() {
	int age, health, hours, test;
	printf("Enter the age: ");
	scanf("%d",&age);
	printf("Enter the health status: ");
	scanf("%d",&health);
	printf("Enter the no of hours: ");
	scanf("%d",&hours);
	printf("Enter the test result: ");
	scanf("%d",&test);
	root = createExpTree();
	
	int result = evaluate(root, age, healthy, drivingHours, passDrivingTest);

   
   	if (result)
        	printf("Driving Test Pass\n");
    	else
        	printf("Driving Test Fail\n");

	    return 0;

}
