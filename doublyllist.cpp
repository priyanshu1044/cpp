#define MAX 10

using namespace std;

typedef struct list_node
{
        int value;
        struct list_node *next;
        struct list_node *prev;
}node;

node *head=NULL, *tail=NULL;
int fooCount = 0;

void insert_at_beginning(int value)
{
    node *new_node = new node ;
    new_node->value=value;
    
    if(fooCount > MAX || new_node == NULL )
    {
        cout<<"List can not accommodate more than" << MAX << "elements";
        exit(0);
    }
    //empty list
    if(fooCount==0 || head == NULL)
    {
        new_node->prev = new_node->next = NULL;
        head = tail = new_node;
        fooCount++;
        return;
    }
    head->prev = new_node;
    new_node->next = head;
    new_node->prev = NULL;
    head = new_node;
    fooCount++;
}

void insert_at_end(int value)
{
    node *new_node = new node;
    new_node->value = value;
    
    if(fooCount > MAX || new_node == NULL )
    {
        cout<<"List can not accommodate more than" << MAX << "elements";
        exit(0);
    }
    //empty list
    if(fooCount==0 || tail == NULL)
    {
        new_node->prev = new_node->next = NULL;
        head = tail = new_node;
        fooCount++;
        return;
    }
    tail->next = new_node;
    new_node->prev = tail;
    new_node->next = NULL;
    tail = new_node;
    fooCount++;
    
}

void delete_from_beginning()
{ 
    if(head == NULL || fooCount == 0)
    {
        cout << "INVALID SEQUENCE OF COMMANDS";
        exit(0);
    }
    
    node *new_node = head;
    if(new_node->next == NULL)
    {
        free(head);
        head = tail = NULL;
        return;
    }
    head->next->prev = NULL;     
    head = head->next;     
    free(new_node);                     
    fooCount--;
}
void delete_from_end()
{
    if(tail == NULL || fooCount == 0)
    {
        cout << "INVALID SEQUENCE OF COMMANDS";
        exit(0);
    }
    
    node *new_node = tail;
    tail->prev->next = NULL;
    tail = tail->prev;
    free(new_node);
    fooCount--;
}

void print_list()
{
    if(head == NULL || fooCount == 0){
        cout << "List is Empty";
        exit(0);
    }
    
    node *new_node = head;
    while(new_node != NULL)
    {
        cout << new_node -> value << " ";
        new_node = new_node -> next;
    }
    cout << endl;
   
    new_node = tail;
    while(new_node != NULL)
    {
        cout << new_node->value << " ";
        new_node = new_node -> prev;
    }
}

int main()
{
    int operation,number;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    do
    {
        cin>>operation;
        switch(operation)
        {
         case 0: 
         {
            cin>>number;
            insert_at_beginning(number);
            break;
         }
         case 1: 
         {
            cin>>number;
            insert_at_end(number);
            break;
         }
         case 2: 
         {
             delete_from_beginning();   
             break;
         }
         case 3: 
         {
             delete_from_end(); 
             break;
         }
         case 4:
         {
             print_list(); 
             break;
         }
        default:
        {
            cout<<"INVALID SEQUENCE OF COMMANDS";   
            break;
        }
                
        }
        
    } while(operation != 4);
    
    return 0;
}
