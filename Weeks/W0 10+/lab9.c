#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 30
#define MAX_WORD_ARRAY (MAX_WORD_LEN+1)

typedef struct date Date;
struct date {
    int year, month, day;
};

// PART 1: define a type to represent a store order which has the following:
//  - a customer name which cannot be more than 30 characters long
//  - a unique order number that is always an integer
//  - the delivery date of the order (notice the Date type we have provided above)
//  - the charge for the order in dollars (ie $14.56)
// Create an alias with the name Order for this type
// NOTE: you will not be able to compile until you have completed this.

typedef struct order Order;
struct order {
    char customer_name[30];
    int order_number;
    Date order_date;
    double price;
};

// PART 2: complete the definitions of the fuctions according to the documentation
// Uncomment the relevant code within main to test each function and
//  inspect the results to ensure they are what you expect to see.
void print_order(Order* ord);
Order create_order(char customer_name[], int order_number, int year, int month, int day, double charge);
void add_to_charge(Order* ord, double amount);
void update_date(Order* ord, int new_year, int new_month, int new_day);
void print_orders(Order store_orders[], int num_orders);
double get_total_charges(Order store_orders[], int num_orders);
void add_surcharge(Order store_orders[], int num_orders, double surcharge);
void get_highest_paying_customer(Order store_orders[], int num_orders, char name[]);
int get_earliest_order(Order store_orders[], int num_orders);


int main(void){

    Order order1= create_order("Rebecca Raspberry", 111, 2022, 3, 30, 6.10);
    Order order2 = create_order("Fiona Framboise", 116, 2022, 3, 29, 17.0);
    Order order3 = create_order("Neal Naranja", 225, 2020, 1, 6, 18.7);
    Order order4 = create_order("Hannah Hindbaer", 120, 2022, 3, 29, 12.0);
    Order my_orders[] = {order1, order2, order3, order4};

    
    printf("\ntest create_order and print_order:\n");
    print_order(&order1);
    print_order(&order2);
    print_order(&order3);
    print_order(&order4);
    

    
    printf("\ntest add_to_charge:\n");
    add_to_charge(&order1, 5.60);
    print_order(&order1);
    

    
    printf("\ntest update_date:\n");
    update_date(&order2, 2011, 4, 19);
    print_order(&order2);


    printf("\ntest print_orders:\n");
    print_orders(my_orders, 4);
    // TODO 6:
    // What do you notice about the orders in my_orders
    //      compared to order1, order2, order3 and order4?
    // Did the calls to add_to_charge and update_date change the values in my_orders?  Why?
    

    
    printf("\ntest get_total_charges:\n");
    double total_charges = get_total_charges(my_orders, 4);
    printf("Total Charges: %5f\n", total_charges);
    
         
    /*
    printf("\ntest add_surcharge:\n");
    add_surcharge(my_orders, 4, 3.0);
    print_orders(my_orders, 4);
    */

    /*
    printf("\ntest get_highest_paying_customer:\n");
    char name_of_highest[MAX_WORD_ARRAY];
    get_highest_paying_customer(my_orders, 4, name_of_highest);
    printf("%s\n", name_of_highest);
    */

    /*
    printf("\ntest get_earliest_order:\n");
    int position_of_earliest = get_earliest_order(my_orders, 4);
    printf("%d\n", position_of_earliest);
    print_order(&my_orders[position_of_earliest]);
    */
    return 0;
}

/* Purpose: prints details of Order pointed to by ord
 * Parameters: Order* ord - pointer to an instance of an Order
 * Returns: nothing
 */

void print_order(Order* ord) {
    printf("\n\n");
    printf("Customer Name:%s\n",ord->customer_name);
    printf("Order Number:%d\n",ord->order_number);
    printf("Date/Month/Year:%d/%d/%d\n",ord->order_date.day,ord->order_date.month,ord->order_date.day);
    printf("Charge:%.2f",ord->price);
}

/* Purpose: creates and returns an Order with given intial values
 * Parameters: char customer_name[] - null terminated string with length MAX_WORD_LEN
 *     int order_number
 *     int year, int month, int day - specify a valid Date
 *     double charge - in dollars, >=0
 * Returns: Order - the initialized order
 */
Order create_order(char customer_name[], int order_number, int year, int month, int day, double charge) {
    Order ord;
    strcpy(ord.customer_name,customer_name);
    ord.order_number=order_number;
    ord.order_date.month=month;
    ord.order_date.year=year;
    ord.order_date.day=day;
    ord.price=charge;

    return ord;
}

/* Purpose: adds given amount to charge in Order pointed to by ord
 * Parameters: Order* ord - pointer to an instance of an Order
 *             double amount - in dollars
 * Returns: nothing
 */
void add_to_charge(Order* ord, double amount) {
    ord->price+=amount;
}

/* Purpose: updates date in Order pointed to by ord with given values
 * Parameters: Order* ord - pointer to an instance of an Order
 *             int new_year, int new_month, int new_day - represent a valid date
 * Returns: nothing
 */
void update_date(Order* ord, int new_year, int new_month, int new_day) {
    ord->order_date.day+=new_day;
    ord->order_date.month+=new_month;
    ord->order_date.year+=new_year;
}

/* Purpose: prints all num_orders Orders in store_orders
 * Parameters: Order store_orders[] - array of Order instances
 *             int num_orders - number of Orders in store_orders, >=0
 * Returns: nothing
 */
 // NOTE: should call print_order
void print_orders(Order store_orders[], int num_orders) {
    // TODO 5: Add your code here
}

/* Purpose: calculates the total charge of all Orders in store_orders
* Parameters: Order store_orders[] - array of Order instances
*             int num_orders - number of Orders in store_orders, >=0
 * Returns: double - the total
 */
double get_total_charges(Order store_orders[], int num_orders) {
    double charge=0;
    for(int i=0;i<num_orders;++i) {
        charge+=store_orders[i].price;
    }
    return charge;
}

/* Purpose: adds surcharge to charge on all num_orders Orders in store_orders
 * Parameters: Order store_orders[] - array of Order instances
 *             int num_orders - number of Orders in store_orders, >=0
 *             int surcharge - in dollars, >=0
 * Returns: nothing
 */
 // NOTE: should call add_to_charge
void add_surcharge(Order store_orders[], int num_orders, double surcharge) {
    // TODO 8: Add your code here
}

/* Purpose: finds the customer name on the Order with the highest charge
 *        in all num_orders Orders in store_orders.
 *  If more than one Order with the highest charge, of those Orders,
 *   choose the Order that comes first in the array.
 * Parameters: Order store_orders[] - array of Order instances
 *             int num_orders - number of Orders in store_orders, >0
 *             char name[] - destination to place customer_name
 * Returns: nothing
 */
void get_highest_paying_customer(Order store_orders[], int num_orders, char name[]) {
    // TODO 9: Add your code here
}



/* Purpose: finds position of the Order with the earliest delivery date
 *        in all num_orders Orders in store_orders.
 * Parameters: Order store_orders[] - array of Order instances
 *             int num_orders - number of Orders in store_orders, >0
 * Returns: int - the position
 */
int get_earliest_order(Order store_orders[], int num_orders) {
    // TODO 10: Add your code here
    // NOTE: you will get a warning when you compile until you complete this function
}
