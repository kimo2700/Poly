//
//  poly.cpp
//  poly
//
//  Created by Abdelhakim Mekkaoui on 10/7/19.
//  Copyright © 2019 u. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct Node;
class LinkedList;
struct Ploy;
ostream& operator<<(ostream& , Ploy );
struct Node{
    
    
    int cof;
    int pow;
    
    Node *next;
    
    Node(){
        
        cof=0;
        pow=0;
        
        next=NULL;
        
    }
    
    Node(int c,int p){
        
        cof=c;
        pow=p;
        
        next=NULL;
        
    }
    Node(int c,int p, bool s){
        
        cof=c;
        pow=p;
        
        next=NULL;
        
    }
    
    Node (const Node& node){
        
        cof=node.cof;
        pow=node.pow;
        
        next=NULL;
        //cout<<"copy node "<<endl;
    }
    
    ~Node(){
        delete next;
        
    }
    
    Node& operator=(const Node &node){
        //    cout<<"in = ";
        if (this!=&node)
        {cof=node.cof;
            pow=node.pow;
            next=NULL;
            
        }
        
        
        //cout<<"node operator = "<<endl;
        return *this;
    }
    
    Node& operator*(const Node &node){
        Node* result=new Node();
        (*result).cof=node.cof*cof;
        (*result).pow=node.pow+pow;
        
        
        //cout<<"node operator = "<<endl;
        return *result;
    }
    
};




class LinkedList
{
    
    Node dommy;
    
    
public:
    
    LinkedList(){
        
        dommy.cof=0;
        dommy.pow=0;
        dommy.next=NULL;
        
    }
    //~LinkedList(){
        
        //delete dommy.next;
        
   // }
    //insert  to linked list in decending order
    
    void insertNode(Node* node) {
        
        //use dommy's cof as counter
        
        if (dommy.cof==0)
            
        { dommy.next=node;
            //cout<<"dommy next changed"<<endl;
            //(*node).next=NULL;
            
            dommy.cof++;
            
            //cout<<"insert "<<(*node).count<<endl;
            //    cout<<"insert at head "<<(*node).cof<<" "<<(*node).pow<<endl;
        }
        
        else
            
        {
            
            Node* temp=dommy.next;
            
            //if new  > first element, insert new  at the head
            
            if ((*node).pow>(*temp).pow)
            {(*node).next=dommy.next;
                
                dommy.next=node;
                //cout<<"dommy changed in insert first nonempty"<<endl;
            }
            
            
            else
                
            {
                
                //iterate linked list, find the proper position for the new
                
                while(((*temp).next)!=NULL)
                {if ((*node).pow<(*(*temp).next).pow)
                    
                    temp=(*temp).next;
                    
                else
                    
                    break;
                    
                }
                
                //if the position is not at the end of the linked list
                
                if ((*temp).next!=NULL)
                    
                {
                    
                    (*node).next=(*temp).next;
                    
                    (*temp).next=node;
                    
                }
                
                //if it's the end of the linked list, insert at the end
                
                else
                    
                {(*temp).next=node;
                    (*node).next=NULL;
                    //    cout<<"insert in the end "<<(*node).cof<<" "<<(*node).pow<<endl;
                }
            }
            
            
            
            
            dommy.cof++;
        }
        
    }
    
    
    
    void insertNodeWithoutSort(Node* node) {
        
        //use dommy's cof as counter
        
        if (dommy.cof==0)
            
        { dommy.next=node;
            //cout<<"dommy next changed"<<endl;
            //(*node).next=NULL;
            
            dommy.cof++;
            
            //cout<<"insert "<<(*node).count<<endl;
            //cout<<"insert at head "<<(*node).cof<<" "<<(*node).pow<<endl;
        }
        
        else
            
        {
            
            
            Node* temp=dommy.next;
            
            //if new  > first element, insert new  at the head
            //iterate linked list, find the proper position for the new
            
            while(((*temp).next)!=NULL)
                temp=(*temp).next;
            
            //if the position is not at the end of the linked list
            
            if ((*temp).next!=NULL)
                
            {
                
                (*node).next=(*temp).next;
                
                (*temp).next=node;
                
            }
            
            //if it's the end of the linked list, insert at the end
            
            else
                
            {(*temp).next=node;
                (*node).next=NULL;
                //    cout<<"insert in the end "<<(*node).cof<<" "<<(*node).pow<<endl;
            }
            
            
            dommy.cof++;
        }
        
    }
    
    
    
    //delete first element of the linked list and return the deleted node
    
    Node* deleteNode(){
        
        Node* temp;
        
        temp=&dommy;
        
        Node *deletedNode;
        
        //delete when there are intergers in the linked list
        
        if (dommy.cof>0)
            
        {temp=(*temp).next;
            
            deletedNode=(temp);
            
            //cout<<"delete "<<(*temp).count<<endl;
            
            temp=(*temp).next;
            
            dommy.next=temp;
            //    cout<<"dommy changed in del"<<endl;
            dommy.cof--;
            (*deletedNode).next=NULL;
            return deletedNode;
        }
        else
        {//cout<<"empty linked list"<<endl;
            deletedNode=new Node(0,0);
            return deletedNode;
        }
        
    }
    
    Node* deleteNode(int pos){
        
        Node* deletedNode;
        
        
        Node* temp=dommy.next;
        
        //if new  > first element, insert new  at the head
        
        if (pos==1)
        {return deleteNode();
        }
        
        else if (pos==dommy.cof)
        {while(((*(*temp).next).next)!=NULL)
            temp=(*temp).next;
            deletedNode=((*temp).next);
            (*temp).next=NULL;
            (*deletedNode).next=NULL;
            dommy.cof--;
            return deletedNode;
        }
        else if (pos>1 || pos <dommy.cof )
            
        {
            
            //iterate linked list, find the proper position for the new node
            int count=1;
            while(((*temp).next)!=NULL)
            {count++;
                if (count<pos)
                    temp=(*temp).next;
                else
                    break;
                
            }
            
            //if the position is not at the end of the linked list
            
            deletedNode=((*temp).next);
            
            (*temp).next=(*(*temp).next).next;
            (*deletedNode).next=NULL;
            dommy.cof--;
            return deletedNode;
            
        }
        else
        {//    cout<<"invalid postion"<<endl;
            deletedNode=new Node(0,0);
            return deletedNode;
        }
        
        //    cout<<"insert "<<(*node).count<<endl;
        
        
    }
    
    
    void canonicalize(){
        Node* temp;
        Node* removedNode;
        temp=dommy.next;
        int pos=1;
        
        if (dommy.cof==1){
            if ((*temp).cof==0)
                removedNode=deleteNode();
        }
        else{
            //merge items which have same power
            while(((*temp).next)!=NULL)
            {pos++;
                if ((*temp).pow==(*(*temp).next).pow)
                {
                    (*temp).cof+=(*(*temp).next).cof;
                    removedNode=deleteNode(pos);
                    //cout<<"rn d ("<<(*removedNode).cof<<","<<(*removedNode).pow<<")"<<endl;
                    //cout<<"remove d ";printLinkedList();
                    pos--;
                }
                else
                    
                    temp=(*temp).next;
                
            }
            
            //remove items with power 0
            pos=0;
            temp=dommy.next;
            while(((*temp).next)!=NULL)
            {
                pos++;
                if ((*temp).cof==0)
                {removedNode=deleteNode(pos);
                    //cout<<"rn 0 ("<<(*removedNode).cof<<","<<(*removedNode).pow<<")"<<endl;
                    //cout<<"remove 0 "; printLinkedList();
                    pos--;
                }
                else
                    temp=(*temp).next;
            }
            //check last item
            pos=1;
            temp=dommy.next;
            while(((*temp).next)!=NULL)
            {pos++;
                temp=(*temp).next;
            }
            if ((*temp).cof==0)
            {    //removedNode=deleteNode(pos);
                removedNode=deleteNode(pos );
                //    cout<<"rn last 0 ("<<(*removedNode).cof<<","<<(*removedNode).pow<<")"<<endl;
                //cout<<"remove last 0 ";printLinkedList();
            }
        }
        
        
    }
    void printLinkedList() { //print the liked list
        
        Node *temp=dommy.next;
        
        
        if (dommy.cof==0)
            
        {
            
            cout<<"0 0"<<endl;
            
        }
        
        else
            
        {//iterate whole linked list and print each element
            
            while ((*temp).next!=NULL)
                
            {cout<<(*temp).cof <<"X"<<(*temp).pow<<" ";
                
                temp=(*temp).next;
                
            }
            
            cout<<(*temp).cof <<"X"<<(*temp).pow<<endl;
            
        }
        
    }
    
    
    bool isEmpty(){
        return (dommy.cof==0);
    }
    friend struct Ploy;
    friend ostream& operator<<(ostream& , Ploy );
};



struct Ploy{
    LinkedList* pll;  //store canonical ploy
    LinkedList* oll;  //store original ploy
    Ploy(){
        pll=new LinkedList();
        oll=new LinkedList();
        
    }
    Ploy(string s){
        pll=new LinkedList();
        oll=new LinkedList();
        int c,p;
        stringstream ss(s);
        while (ss>>c>>p)
        {
            
            Node* newNode=new Node(c,p);
            Node* newnodecopy=new Node(c,p);
            (*pll).insertNode(newNode);
            (*oll).insertNodeWithoutSort(newnodecopy);
            
        }
        //cout<<"before canonicalize";
        //(*pll).printLinkedList();
        (*pll).canonicalize();
        //(*pll).printLinkedList();
    }
    
    
    ~Ploy(){
        
        
        //cout<<"Destructor"<<endl;
    }
    /*  //error in copy constructor
     Ploy (const Ploy &ploy){
     Node* tempnode=new Node();
     tempnode=&(*(ploy.pll)).dommy;
     
     for (int i=0;i<(*(ploy.pll)).dommy.cof;i++)
     {
     tempnode=(*tempnode).next;
     
     Node* tempcopy=new Node();
     *tempcopy=*tempnode;
     
     (*pll).insertNode(tempcopy);
     }
     
     }*/
    
    Ploy& operator=(const Ploy &ploy){
        //    cout<<"in = ";
        if (this!=&ploy)
        {
            Node* tempnode=new Node();
            tempnode=&(*(ploy.pll)).dommy;
            
            for (int i=0;i<(*(ploy.pll)).dommy.cof;i++)
            {
                tempnode=(*tempnode).next;
                //    cout<<"temp addr "<<tempnode<<"   "<<(*tempnode).cof<<" "<<(*tempnode).pow<<endl;
                Node* tempcopy=new Node();
                *tempcopy=*tempnode;
                (*pll).insertNode(tempcopy);
            }
            
            // (*pll).printLinkedList();
        }
        return *this;
    }
    
    Ploy& operator+(const Ploy ploy2){
        //    cout<<"in + "<<endl;
        Ploy* result=new Ploy();
        Ploy* p1=new Ploy();
        Ploy* p2=new Ploy();
        (*p1)=*this;
        (*p2)=ploy2;
        
        
        while(!(*(*p1).pll).isEmpty())
        {Node* n1=new Node();
            n1=(*(*p1).pll).deleteNode();
            (*(*result).pll).insertNode(n1);
        }
        while(!(*(*p2).pll).isEmpty())
        {Node* n2=new Node();
            n2=(*(*p2).pll).deleteNode();
            (*(*result).pll).insertNode(n2);
        }
        
        //    cout<<"result before canonicalize + ";(*(*result).pll).printLinkedList();
        if (!(*(*result).pll).isEmpty())
            (*(*result).pll).canonicalize();
        //    cout<<"sum ";
        //    (*(*result).pll).printLinkedList();
        
        return *result;
        
    }
    
    
    Ploy& operator-(const Ploy ploy2){
        //cout<<"in - "<<endl;
        Ploy* result=new Ploy();
        Ploy* p1=new Ploy();
        Ploy* p2=new Ploy();
        (*p1)=*this;
        (*p2)=ploy2;
        
        
        while(!(*(*p1).pll).isEmpty())
        {Node* n1=new Node();
            n1=(*(*p1).pll).deleteNode();
            //(*n).next=NULL;
            (*(*result).pll).insertNode(n1);
        }
        while(!(*(*p2).pll).isEmpty())
        {Node* n2=new Node();
            n2=(*(*p2).pll).deleteNode();
            (*n2).cof*=-1;
            //(*n2).next=NULL;
            (*(*result).pll).insertNode(n2);
        }
        
        //cout<<"result before canonicalize - ";(*(*result).pll).printLinkedList();
        if (!(*(*result).pll).isEmpty())
            (*(*result).pll).canonicalize();
        //cout<<"sub ";
        //(*(*result).pll).printLinkedList();
        
        return *result;
        
    }
    
    
    Ploy& operator*(const Ploy ploy2){
        //    cout<<"in * "<<endl;
        Ploy* result=new Ploy();
        Ploy* p1=new Ploy();
        Ploy* p2=new Ploy();
        (*p1)=*this;
        (*p2)=ploy2;
        
        if( (*(*p1).pll).isEmpty() || (*(*p2).pll).isEmpty()   )
            return *result;
        else{
            Node* n1=new Node();
            n1=&(*(*p1).pll).dommy;
            for (int i=0;i<(*(*p1).pll).dommy.cof;i++)
            {
                n1=(*n1).next;
                Node* n1copy=new Node();
                *n1copy=*n1;
                
                Node* n2=new Node();
                n2=&(*(*p2).pll).dommy;
                for (int i=0;i<(*(*p2).pll).dommy.cof;i++)
                {n2=(*n2).next;
                    Node* n2copy=new Node();
                    *n2copy=*n2;
                    
                    (*(*result).pll).insertNode(&((*n1copy)*(*n2copy)));
                }
            }
            
            
            //    cout<<"result before canonicalize * ";(*(*result).pll).printLinkedList();
            if (!(*(*result).pll).isEmpty())
                (*(*result).pll).canonicalize();
            //    cout<<"product ";
            //    (*(*result).pll).printLinkedList();
            
            return *result;
        }
        //    return *this;
    }
    
    friend ostream& operator<<(ostream& , Ploy );
    
};
ostream& operator<<(ostream& os, Ploy ploy){
    Node *temp=(*(ploy.pll)).dommy.next;
    
    if ((*(ploy.pll)).dommy.cof==0)
        
    {
        cout<<"0 0"<<endl;
        
    }
    
    else
        
    {//iterate whole linked list and print each element
        
        while ((*temp).next!=NULL)
            
        {cout<<(*temp).cof <<"x"<<(*temp).pow<<" ";
            
            temp=(*temp).next;
            
        }
        
        cout<<(*temp).cof <<"X"<<(*temp).pow<<endl;
        
    }
    return os;
};



int main(){
    
    ifstream input("input.txt"); //read input file
    
    string line ;
    if ( input ) {
        while ( getline( input , line ) )
        {
            
        
    
            //cout <<"original 1: "<<   line << '\n' ;
            
            Ploy* ploy1=new Ploy(line);
            getline( input , line );
            //cout <<"original 2: "<<   line << '\n' ;
            Ploy* ploy2=new Ploy(line);
            cout <<"original 1: ";(*(*ploy1).oll).printLinkedList();
            cout <<"original 2: ";(*(*ploy2).oll).printLinkedList();
            cout<<"canonical 1: "<<(*ploy1);//(*(*ploy1).pll).printLinkedList();
            cout<<"canonical 2: "<<(*ploy2);//(*(*ploy2).pll).printLinkedList();
            
            Ploy* sum=new Ploy();
            (*sum)=(*ploy1)+(*ploy2);
            cout<<"sum: " <<(*sum);    //(*(*sum).pll).printLinkedList();
            
            Ploy* sub=new Ploy();
            (*sub)=(*ploy1)-(*ploy2);
            cout<<"difference: "<<(*sub); //(*(*sub).pll).printLinkedList();
            
            Ploy* mul=new Ploy();
            (*mul)=(*ploy1)*(*ploy2);
            cout<<"product: "<<(*mul); //(*(*mul).pll).printLinkedList();
            
            cout<<endl;
        }
    }
    
    
    
    return 0;
    
} 
