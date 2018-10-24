#include "LinkedList.h"


LinkedList::LinkedList(){

    this->length = 0;
    this->head = nullptr;
    this->tail = nullptr;

}

LinkedList::LinkedList(const LinkedList& list){

    this->length = list.length;

    if(list.head==nullptr){
        this->head = nullptr;
        this->tail = nullptr;

    }

    else{
        this->head = new Node(*(list.head));
        this->tail = new Node(*(list.tail));
    }

}

LinkedList& LinkedList::operator=(const LinkedList& list){

    this->length = list.length;
    delete this->head;
    delete this->tail;
    if(list.head==nullptr){
        this->head = nullptr;
        this->tail = nullptr;

    }

    else{
        this->head = new Node(*(list.head));
        this->tail = new Node(*(list.tail));
    }
    return *this;


}

LinkedList::LinkedList(LinkedList&& list){
    this->length = move(list.length);
    this->head = move(list.head);
    this->tail = move(list.tail);




    list.length=0;
    list.head=nullptr;
    list.tail=nullptr;


}

LinkedList& LinkedList::operator=(LinkedList&& list){
    this->length = move(list.length);
    delete this->head;
    this->head = move(list.head);
    delete this->tail;
    this->tail = move(list.tail);

    list.length=0;
    list.head=nullptr;
    list.tail=nullptr;


    return *this;
}


void LinkedList::pushTail(string _name, float _amount){

    int x=this->length;

    Node* newnode= new Node(_name, _amount);


    if(this->head ==nullptr){
        this->head=newnode;
        this->tail=newnode;
        this->length=x+1;


    }
    else{
        this->tail->next=newnode;
        this->tail=newnode;
        this->length=x+1;

    }


}

void LinkedList::updateNode(string _name, float _amount){

    Node* current=this->head;

    while(current!=nullptr){
        if(!current->name.compare(_name)){

            current->amount=_amount;

        }
        current=current->next;

    }




}

LinkedList::~LinkedList(){
    if (head) {
        delete head;
    }
}






