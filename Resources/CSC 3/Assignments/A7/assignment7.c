#include <stdio.h>
#include <stdlib.h>

typedef struct int_node IntNode;
struct int_node {
    int val;
    IntNode* next;
};

typedef struct int_list IntList;
struct int_list {
    IntNode* front;
};

// function definitions provided for these:
IntNode* create_list_node(int num, IntNode* next);
IntList create_list();
void list_insert_back(IntList* list, int num);
void print_list(IntList* list);
void free_list(IntList* list);


// function definitions to be completed:
void add_front(IntList* list, int num);
int get_last(IntList* list);
void remove_first(IntList* list);
int sum_squares(IntList* list);
void add_to_all(IntList* list, int num);
int get_all_below(IntList* input, IntList* dest, int threshold);
int are_all_above(IntList* list, int threshold);
int does_contain_multiples_of(IntList* list, int num);
int count_if_contains_multiples(IntList* list, IntList* vals);



int main(void) {
 IntList list = create_list();
 IntList dest = create_list();

    list_insert_back(&list, 10);
    list_insert_back(&list, 71);
    list_insert_back(&list, 9);
    list_insert_back(&list, 5);
    add_front(&list, 50);
    list_insert_back(&list, 6);
    list_insert_back(&list, 7);
    list_insert_back(&list, 8);

    printf("\n[1] add_front\n");
    print_list(&list);
    
    printf("\n[2] get_last\n");
    printf("%d\n",get_last(&list));
    
    printf("\n[3] remove_first\n");
    remove_first(&list);
    print_list(&list);
    
    printf("\n[4] sum_squares\n");
    printf("%d\n",sum_squares(&list));

    printf("\n[5] add_to_all\n");
    add_to_all(&list,5);
    print_list(&list);

    printf("\n[6] get_all_below\n");
    printf("RETURNS:\t %d\n",get_all_below(&list,&dest,13));
    printf("INPUT:\t\t");
    print_list(&list);
    printf("DEST:\t\t");
    print_list(&dest);

    printf("\n[7] are_all_above\n");
    printf("RETURNS:\t %d\n",are_all_above(&list,12));
    
    printf("\n[8] does_contain_multiples_of\n");
    printf("RETURNS:\t %d\n",does_contain_multiples_of(&list,8));
    
    IntList list1 = create_list();
    IntList list2 = create_list();
    list_insert_back(&list1, 9);
    list_insert_back(&list1, 7);
    list_insert_back(&list1, 18);
    list_insert_back(&list1, 12);
    list_insert_back(&list1, 21);
    list_insert_back(&list2, 12);
    list_insert_back(&list2, 5);
    list_insert_back(&list2, 14);
    list_insert_back(&list2, 3);
    printf("\n[9] count_if_contains_multiples\n");
    printf("List1:\t\t");
    print_list(&list1);
    printf("List2:\t\t");
    print_list(&list2);
    printf("RETURNS:\t %d\n",count_if_contains_multiples(&list1,&list2));

    printf("\nEndFunction\n");
    free_list(&list);
    free_list(&list1);
    free_list(&list2);

    return 0;
}

/*
 * Purpose: dynamically allocates space for a new IntNode,
 *          intialized with given num and next pointer values
 *          and returns a pointer to the new IntNode
 * Parameters: IntList* list_ptr, pointer to a valid IntList
 *             int num - new value to be added
 *             IntNode* next - the address of the IntNode the new IntNode should point to
 *                             or NULL the new IntNode should point to nothing
 * Returns: IntNode* - the address of the new IntNode
 */
IntNode* create_list_node(int num, IntNode* next){
    IntNode*  node = malloc(sizeof(IntNode));
    node->val = num;
    node->next = next;
    return node;
}

/*
 * Purpose: creates and returns an instance of IntList with front field set to NULL
 * Returns: IntList - the new IntList
 */
IntList create_list(){
    IntList list = {NULL};
    return list;
}

/*
 * Purpose: creates a new IntNode with num and adds it to the back of each nodes
 *          IntList pointed to by list_ptr
 * Parameters: IntList* list_ptr, pointer to a valid IntList
 *             int num - new value to be added
 * Returns: nothing
 */
void list_insert_back(IntList* list_ptr, int num){
    if (list_ptr->front == NULL){
        list_ptr->front = create_list_node(num, NULL);
    } else {
        IntNode* current_node = list_ptr->front;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = create_list_node(num, NULL);
    }
}

/*
 * Purpose: prints values in list on one line with space after each nodes
 * Parameters: IntList* list_ptr, pointer to a valid IntList
 * Returns: nothing
 */
void print_list(IntList* list_ptr) {
   IntNode* current_node = list_ptr->front;

   printf("[");
   while (current_node != NULL) {
       printf("%d", current_node->val);
       if (current_node->next != NULL) {
           printf(", ");
       }
       current_node = current_node->next;
   }

   printf("]\n");
}

/*
 * Purpose: deallocates space for every IntNode in IntList pointed to by list_ptr
 * Parameters: IntList* list_ptr, pointer to a valid IntList
 * Returns: nothing
 */
void free_list(IntList* list_ptr) {
    IntNode* current_node = list_ptr->front;
    IntNode* tmp = current_node;

    while (current_node != NULL) {
        tmp = current_node;
        current_node = current_node->next;
        free(tmp);
    }
    list_ptr->front = NULL;
}

/*
 * Purpose: creates a new IntNode with num and adds it to the front of
 *          IntList pointed to by list
 * Parameters: IntList* list, pointer to a valid IntList
 *             int num - new value to be added
 * Returns: nothing
 */
void add_front(IntList* list, int num) {


    if (list->front == NULL){
        list->front = create_list_node(num, NULL);
    } else {
        IntNode* current_node = list->front;
        IntNode* tmp = current_node;
        list->front = create_list_node(num, tmp);
    }
}

/*
 * Purpose: goes through all the nodes in the linked list,
 *          and returns the value in that last node (having a next data point of 'NULL')
 * Parameters: IntList* list, pointer to a valid IntList
 * Returns: last integer in the linked IntList list
 */
int get_last(IntList* list) {
    IntNode* current_node = list->front;
    int temp=0;
    if(list->front==NULL) {
        temp=-999;
    } else {
        while (current_node->next != NULL) {
            current_node=current_node->next;
        }
        temp=current_node->val;
    }
    return temp;
}

/*
 * Purpose: finds the node in the linked list that does not have a front 'NULL' value and
 *          deletes that node (essentially deallocates the heap memory through free() function)
 *          and connects next node to the frontal 'NULL' making that the first value in the linked list.
 * Parameters: IntList* list, pointer to a valid IntList
 * Returns: nothing
 */
void remove_first(IntList* list) {
    IntNode* current_node = list->front;
    IntNode* tmp = current_node;

    if (list->front == NULL) {
        //printf("Well Oh Well :/ Delete this\n");
    } else {
        tmp = current_node;
        list->front=current_node->next;
        free(tmp);
    }
}

/*
 * Purpose: goes through all the nodes in the linked list until it reaches the end 'NULL', 
 *          and returns the squared value of each nodes in the linked list 
 *          until it reaches the last node (having a next data point of 'NULL')
 * Parameters: IntList* list, pointer to a valid IntList
 * Returns: returns the squared integer value of each nodes in the linked list 
 */
int sum_squares(IntList* list) {
    IntNode* current_node = list->front;
    int temp=0;
    int squared=0;
    int sum=0;
    if(list->front==NULL) {
        temp=-999;
    } else {
        while (current_node->next != NULL) {
            temp=current_node->val;
            squared=temp*temp;
            sum+=squared;
            current_node=current_node->next;
            //printf("Data:%d\t\tSquaredData:%d\t\tAcquired:%d\n",temp,squared,sum);
        }
        temp=get_last(list);
        squared=temp*temp;
        sum+=squared;
        //printf("Data:%d\t\tSquaredData:%d\t\tAcquired:%d\n",temp,squared,sum);
        //printf("\nWe Got: ");
    }
    return sum;
}

/*
 * Purpose: goes through all the nodes in the linked list, 
 *          and adds the new integer value to each values of the nodes in the linked list,
 *          until it reaches the last node (having a next data point of 'NULL')
 * Parameters:  IntList* list, pointer to a valid IntList
 *              int num - new value to be added
 * Returns: nothing
 */
void add_to_all(IntList* list, int num) {
    IntNode* current_node = list->front;
    
    if (list->front != NULL){
        while (current_node->next != NULL) {
            current_node->val+=num;
            current_node=current_node->next;
        }
        current_node->val+=num;
    }
}

/*
 * Purpose: goes through all the nodes in the linked list input, 
 *          and checks and adds any value below the threshold to the linked list dest,
 *          until it reaches the last node of input (having a next data point of 'NULL')
 * Parameters:  IntList* input, pointer to a valid input IntList list
 *              IntList* dest, pointer to a valid destination IntList list
 *              int threshold - integer value to be compared with each linked list node values
 *              whether or not each nodes are below the threshold value
 * Returns:     number of node values below the threshold
 */
int get_all_below(IntList* input, IntList* dest, int threshold) {
    IntNode* current_node = input->front;
    int temp=0;
    int i=0;
    if (input->front != NULL) {
        while (current_node->next != NULL) {
            temp=current_node->val;
            if(temp<threshold) {
                list_insert_back(dest,temp);
                ++i;
            }
            current_node=current_node->next;
        }
        temp=get_last(input);
        if(temp<threshold) {
                list_insert_back(dest,temp);
                ++i;
            }
    }
    return i;
}

/*
 * Purpose: goes through all the nodes in the linked list, 
 *          and checks if any value is above the threshold in the linked list,
 *          until it reaches the last node of list (having a next data point of 'NULL')
 * Parameters:  IntList* list, pointer to a valid input IntList list
 *              int threshold - integer value to be compared with each linked list node values
 *              whether or not each nodes are above the threshold value
 * Returns:     1, if all node values are larger than threshold
 *              0, otherwise
 */
int are_all_above(IntList* list, int threshold) {
    IntNode* current_node = list->front;
    int temp=0;
    int value=1;
    if (list->front != NULL) {
        while ((current_node->next!=NULL)) {
            temp=current_node->val;
            if (temp<threshold) {
                value=0;
            }
            current_node=current_node->next;
        }
        temp=get_last(list);
        if (temp<threshold) {
            value=0;
        }
    }
    return value;
}

/*
 * Purpose: goes through all the nodes in the linked list, 
 *          and checks if any value in the linked list contains any multiple of num,
 *          until it reaches the last node of list (having a next data point of 'NULL')
 * Parameters:  IntList* list, pointer to a valid input IntList list
 *              int num, integer value to be checked with multiplicities in each node values
 * Returns:     1, if contains multiples in the node values
 *              0, otherwise
 */
int does_contain_multiples_of(IntList* list, int num) {
    IntNode* current_node = list->front;
    int temp=0;
    int value=0;
    if (list->front != NULL) {
        while ((current_node->next!=NULL)) {
            temp=current_node->val;
            if ((temp%num==0)) {
                value=1;
            }
            current_node=current_node->next;
        }
        temp=get_last(list);
        if ((temp%num==0)) {
            value=1;
        }
    }
    return value;
}

/*
 * Purpose: goes through all the nodes in the linked list val, 
 *          and checks if any value in the linked list list contains any multiple of node values in val,
 *          until it reaches the last node of list (having a next data point of 'NULL')
 * Parameters:  IntList* list, pointer to a valid IntList 
 *              IntList* val, pointer to a valid IntList 
 * Returns:     total number of values in list having a multiple of each nodal val value
 */
int count_if_contains_multiples(IntList* list, IntList* vals) {
    IntNode* current_node = vals->front;
    int temp=0;
    int dat=0;
    int sum=0;

    if(vals->front!=NULL) {
        while((current_node->next!=NULL)) {
            temp=current_node->val;
            if (does_contain_multiples_of(list,temp)==1) {
                dat=1;
                sum+=dat;
            }
            current_node=current_node->next;
        }
        temp=get_last(vals);
        if (does_contain_multiples_of(list,temp)==1) {
            dat=1;
            sum+=dat;
        }
    }
    return sum;
}
