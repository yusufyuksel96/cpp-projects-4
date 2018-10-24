#include "SurveyClass.h"

SurveyClass::SurveyClass(){

    this->members=new LinkedList();

}
SurveyClass::SurveyClass(const SurveyClass& other){

    this->members=new LinkedList(*(other.members));


}
SurveyClass& SurveyClass::operator=(const SurveyClass& list){
    delete this->members;
    this->members = new LinkedList(*(list.members));
    return *this;


}
SurveyClass::SurveyClass(SurveyClass&& other){


    this->members=move(other.members);
    other.members=nullptr;




}

SurveyClass& SurveyClass::operator=(SurveyClass&& list){

    delete this->members;
    this->members=move(list.members);
    list.members=nullptr;
    return *this;


}
SurveyClass::~SurveyClass(){

    if(members){
        delete members;
    }
}

void SurveyClass::handleNewRecord(string _name, float _amount){

    int a= 0;
    Node* current=this->members->head;


    while(current!=nullptr){

        if(!current->name.compare(_name)){
            this->members->updateNode(_name, _amount);
            break;
        }
        current=current->next;
        a++;

    }

    if(this->members->length==a){

        this->members->pushTail(_name, _amount);
    }

}

float SurveyClass:: calculateMinimumExpense(){


    Node* current=this->members->head;
    float min=current->amount;


    while(current->next!=nullptr){

        if(current->next->amount < min){
            min=current->next->amount;

        }
        current=current->next;
    }

    min= static_cast<int>(min*100)/100.0;

    return min;

}
float SurveyClass::calculateMaximumExpense(){
    Node* current=this->members->head;
    float max=current->amount;

    while(current->next!=nullptr){

        if(current->next->amount > max){
            max=current->next->amount;

        }
        current=current->next;
    }
    max= static_cast<int>(max*100)/100.0;


    return max;

}
float SurveyClass::calculateAverageExpense(){

    Node* current=this->members->head;
    float sum=current->amount;
    int a=this->members->length;

    while(current->next!=nullptr){
        sum+=current->next->amount;
        current=current->next;

    }

    float average=sum/a;
    average= static_cast<int>(average*100)/100.0;

    return average;


}



