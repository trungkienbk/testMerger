/* #include <iostream>
using namespace std;
struct node
{   int HP;
    int data;
    string ID;
    node *next;
};
node* head=NULL;
node *createLinkedList(int n)
{
    if(n==0){
        head=nullptr;
        return head;
    }
    node* temp=new node;
    head=temp;
    cin>>temp->data;
    temp->next=NULL;
    for(int i=1;i<n;i++){
        temp->next=new node;
        temp=temp->next;
        cin>>temp->data;
    }
    temp->next=NULL;
    return head;
}
bool isEqual(node *head1, node *head2)
{
    if(head1==NULL && head2 == NULL) {
        return 1;
    } else {
        if(head1==NULL || head2==NULL){
            return 0;
        }
    }
    if(head1->data == head2 -> data){
        return isEqual(head1->next,head2->next);
    } else return 0;
}
void print(node *head)
{
    while (head != nullptr)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}
bool check_data(node *list1,node *list2){
    if(list1->data<list2->data) return true;
    if(list1->data<list2->data) return false;
    return true;
}
node* merge_no_if(node *list1,node *list2){
    node *sort=nullptr;
    node *list_res=nullptr;
    if(list1==nullptr && list2==nullptr)
    {
        list_res=nullptr;
    }
    if(list1==nullptr && list2 != nullptr){
        list_res= list2;
    }
    if(list2==nullptr && list1!=nullptr){
        list_res= list1;
    }
    if(list1 && list2){
        if(check_data(list1,list2)==true){
            sort=list1;
            list1=list1->next;
        } else {
            sort=list2;
            list2=list2->next;
        }
    }
    list_res=sort;
    while(list1 && list2){
        if(check_data(list1,list2)==true){
            sort->next=list1;
            sort=list1;
            list1=sort->next;
        } else {
            sort->next=list2;
            sort=list2;
            list2=sort->next;
        }
    }
    if(list1== nullptr) sort->next=list2;
    if(list2== nullptr) sort->next=list1;
    return list_res;
}
int main()
{
    int n = 0;
    cin>> n;
    node *head1 = createLinkedList(n);
    int m = 0;
    cin>> m;
    node *head2 = createLinkedList(m);
    cout << "LinkedList 1 is : ";print(head1);
    cout << "LinkedList 2 is : ";print(head2);
    merge_no_if(head1,head2);
    cout << "Merge LinkedList: ";print(head1);
    return 0;
}
*/

#include <iostream>
#include <string>
using namespace std;
struct node
{   int HP;
    bool isSpecial;
    string ID;
    node *next;
};
node* head=NULL;
node *createLinkedList(int n)
{   if(n==0){return head= nullptr;}
    node* temp=new node;
    head=temp;
    cin>>temp->HP>>temp->isSpecial>>temp->ID;
    temp->next=NULL;
    for(int i=1;i<n;i++){
        temp->next=new node;
        temp=temp->next;
        cin>>temp->HP>>temp->isSpecial>>temp->ID;
    }
    temp->next=NULL;
    return head;
}
void print(node *head)
{
    while (head != nullptr)
    {
        cout << "(" <<head->HP<<","<<head->isSpecial<<","<<head->ID<<")" << "->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}
int size (node *list){
    int size=0;
    if(list== nullptr){
        size=0;
    }
    node *list_size=list;
    while(list_size!= nullptr){
        size++;
        list_size=list_size->next;
    }
    return size;
}
bool check_condition(node *list1,node *list2){
 //   if(list1== nullptr || list2== nullptr) return true;
    if(list1->HP<list2->HP) return true;
    if(list1->HP>list2->HP) return false;
    if(list1->isSpecial<list2->isSpecial) return true;
    if(list1->isSpecial>list2->isSpecial) return false;
    if(int(list1->ID.at(0))<int(list1->ID.at(0))) return true;
    if(int(list1->ID.at(0))>int(list1->ID.at(0))) return false;
    return true;
}
    node* merge(node *list1,node *list2){
    node *sort=nullptr;
    node *list_res=nullptr;
    if(list1==nullptr && list2==nullptr) return list_res=nullptr;
    if(size(list1)==0 && size(list2)!=0){
        return list_res=list2;
    }
    if(size(list1)!=0 && size(list2)==0){
        return list_res=list1;
    }
    if(size(list1)!=0 && size(list2)!=0){
        if(check_condition(list1,list2)){
            sort=list1;
            list1=sort->next;
        }
         else {
             sort=list2;
             list2=sort->next;
         }
    }
    list_res=sort;
    while(size(list1)!=0 && size(list2)!=0){
        if(check_condition(list1,list2)==true){
            sort->next=list1;
            sort=list1;
            list1=sort->next;
        } else {
            sort->next=list2;
            sort=list2;
            list2=sort->next;
        }
    }
    if(list1==nullptr){
        sort->next=list2;
    }
    if(list2==nullptr){
        sort->next=list1;
    }
    return list_res;
}

/* node *mergeSortedLists(node *head1, node *head2){
    node *result = NULL;
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    if (check_condition(head1,head2)==true) {
        result = head1;
        result->next = mergeSortedLists(head1->next, head2);
    } else {
        result = head2;
        result->next = mergeSortedLists(head1, head2->next);
    }
    return result;
}
*/
int main()
{
    int n = 0;
    cin>> n;
    node *head1 = createLinkedList(n);
    int m = 0;
    cin>> m;
    node *head2 = createLinkedList(m);
    cout << "LinkedList 1 is : ";print(head1);
    cout<<  "Size List  1    : "<<size(head1)<<endl;
    cout << "LinkedList 2 is : ";print(head2);
    cout<<  "Size List  2    : "<<size(head2)<<endl;
    node *head_res=merge(head1,head2);
    cout << "Merge LinkedList: ";print(head_res);
    return 0;
}
