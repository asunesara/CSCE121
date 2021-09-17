#include <iostream>
#include "LinkedList.h"

using namespace std;
int main() {
    // TODO(student): the rest of the Tests
    LinkedList list;
    
    LinkedList copyconstruct;
    copyconstruct = list;


    LinkedList operatoractual(copyconstruct);
    cout<<"The size for copyconstruct: "<<copyconstruct.size()<<endl;           
    cout<<"The size for list: "<<list.size()<<endl;
    cout<<"The size for operatoractual: "<<operatoractual.size()<<endl;
    
    
    
    list.push_back(1);
    list.push_back(1);
    list.push_back(1);
    
    copyconstruct = list;
    LinkedList operatoractual2(copyconstruct);

    cout<<"The size for copyconstruct: "<<copyconstruct.size()<<endl;
    cout<<"The size for list: "<<list.size()<<endl;
    cout<<"The size for operatoractual: "<<operatoractual2.size()<<endl;
    cout<<"Remove duplicates now "<<endl;
    operatoractual.remove_duplicates();
    cout<<"Checking size after removing dup"<<operatoractual.size()<<endl;;

    cout<<"The destructor is occuring now ";
    operatoractual.~LinkedList();


    LinkedList length;
    length.push_back(5);
    length.push_back(4);
    length.push_back(6);
    length.push_back(2);
    length.push_back(1);
    length.push_back(3);
    length.push_back(2);
    LinkedList lengthconnstruct;
    lengthconnstruct = length;
    LinkedList operatorlength(lengthconnstruct);
    cout<<"The remove at inndex 1 is ";
    //length.remove(1);
    cout<<endl;
    cout<<"The contains at 1 is "<<length.contains(5)<<endl;
    cout<<"The size of this is: "<<length.size()<<endl;
    cout<<"The length max decrease "<<length.length_max_decreasing()<<endl;
    cout<<"This is head: "<<length.head()<<endl;
    cout<<"Remove duplicates now "<<endl;
    length.remove_duplicates();
    cout<<"Checking size after removing dup "<<length.size()<<endl;
    
    cout<<"The destructor is occuring now ";
    //length.~LinkedList();



    LinkedList testing;             //constructor 1
    testing.push_back(100);
    testing.push_back(20);          //pushback 2
    testing.push_back(300);
    testing.push_back(40);
    testing.push_back(20);
    testing.push_back(2);
    testing.push_back(-1);
    LinkedList testing2;                    //constructor 2
    testing2 = testing;                    //operator = 3
    LinkedList finaltest(testing2);       //copy constructor 4
    cout<<endl<<"This is the linked list function ";
    LinkedList();
    cout<<"The remove at inndex 1 is ";
    //finaltest.remove(1);
    cout<<endl;
    cout<<"The contains at 1 is "<<finaltest.contains(5)<<endl;
    cout<<endl<<"The size of this is: "<<finaltest.size()<<endl;                              //size 5
    cout<<"The length max decrease "<<finaltest.length_max_decreasing()<<endl;          //length max 6
    cout<<"This is head: "<<finaltest.head()<<endl;                                     //head 7
    cout<<"Remove duplicates now "<<endl;
    finaltest.remove_duplicates();                                                  //remove length max 8
    cout<<"Checking size after removing dup "<<finaltest.size()<<endl;
    cout<<"The destructor is occuring now ";
    //finaltest.~LinkedList();



    LinkedList final;
    final.push_back(1);
    
    LinkedList final2;
    final2 = final;
    LinkedList outputfinal(final2);
    cout<<"The remove at inndex 1 is ";
    //outputfinal.remove(0);
    cout<<endl;
    cout<<"The contains at 1 is "<<outputfinal.contains(5)<<endl;


    LinkedList finally;
    
    LinkedList finally2;
    finally2 = finally;
    LinkedList outputfinally(finally2);
    cout<<endl;
    cout<<"The contains at 1 is "<<outputfinally.contains(5)<<endl;



    LinkedList trying;
    testing.push_back(100000);
    testing.push_back(1000);          //pushback 2
    testing.push_back(100);
    testing.push_back(100000000);
    testing.push_back(100);
    testing.push_back(100);
    testing.push_back(-1);
    LinkedList trying2;
    trying2 = trying;
    LinkedList outputtrying(trying2);
    


    cout<<"The remove at inndex 1 is ";
    //outputtrying.remove(0);
    cout<<endl;
    cout<<"The contains at 1 is "<<outputtrying.contains(-1)<<endl;
    //cout<<endl<<"The size of this is: "<<outputtrying.size()<<endl;                              //size 5
    //cout<<"The length max decrease "<<outputtrying.length_max_decreasing()<<endl;          //length max 6
    //cout<<"This is head: "<<outputtrying.head()<<endl;                                     //head 7
    //cout<<"Remove duplicates now "<<endl;
    //outputtrying.remove_duplicates();                                                  //remove length max 8
    //cout<<"Checking size after removing dup "<<outputtrying.size()<<endl;
    //cout<<"The destructor is occuring now ";
    



    cout<<endl<<"---------------------------------------------------------"<<endl;
    



    cout<<endl<<"---------------------------------------------------------"<<endl;
    cout<<endl<<"---------------------------------------------------------"<<endl;
    cout<<endl<<"---------------------------------------------------------"<<endl;



    LinkedList done;
    done.push_back(5);
    done.push_back(1);
    done.push_back(7);
    done.push_back(-6); 
    done.push_back(-8); 
    done.push_back(5);
    done.push_back(6); 
    done.push_back(-5); 
    done.push_back(0);
    done.push_back(-7); 
    done.push_back(4); 
    done.push_back(-5);
    done.push_back(-6);
    done.push_back(-4) ;
    done.push_back(-6); 
    done.push_back(-9); 
    done.push_back(3) ;
    done.push_back(-1) ;
    done.push_back(-3) ;
    done.push_back(1) ;
    done.push_back(-9) ;
    done.push_back(2) ;
    done.push_back(-1) ;
    done.push_back(-2) ;
    done.push_back(6) ;
    done.push_back(0) ;
    done.push_back(8) ;
    done.push_back(-7) ;
    done.push_back(6) ;
    done.push_back(8) ;
    done.push_back(4) ;
    done.push_back(9) ;
    done.push_back(-5) ;
    done.push_back(-8) ;
    done.push_back(0) ;
    done.push_back(-7) ;
    done.push_back(-3) ;
    done.push_back(-3);
    done.push_back(-6) ;
    done.push_back(-5) ;
    done.push_back(6) ;
    done.push_back(4) ;
    done.push_back(9) ;
    done.push_back(-8) ;
    done.push_back(-1) ;
    done.push_back(2) ;
    done.push_back(-8) ;
    done.push_back(6) ;
    done.push_back(-1) ;
    done.push_back(8) ;
    done.push_back(9) ;
    done.push_back(7) ;
    done.push_back(-6) ;
    done.push_back(-8) ;
    done.push_back(5) ;
    done.push_back(0) ;
    done.push_back(1) ;
    done.push_back(-3) ;
    done.push_back(-5) ;
    done.push_back(1) ;
    done.push_back(7) ;
    done.push_back(6) ;
    done.push_back(2) ;
    done.push_back(9) ;
    done.push_back(4) ;
    done.push_back(-1) ;
    done.push_back(0) ;
    done.push_back(4) ;
    done.push_back(7) ;
    done.push_back(9) ;
    done.push_back(9) ;
    done.push_back(9) ;
    done.push_back(9) ;
    done.push_back(3) ;
    done.push_back(-3) ;
    done.push_back(3) ;
    done.push_back(-4) ;
    done.push_back(-4) ;
    done.push_back(6) ;
    done.push_back(-4) ;
    done.push_back(-4) ;
    done.push_back(-9) ;
    done.push_back(-5) ;
    done.push_back(-4) ;
    done.push_back(-6) ;
    done.push_back(1) ;
    done.push_back(-5) ;
    done.push_back(-3) ;
    done.push_back(-8) ;
    done.push_back(9) ;
    done.push_back(7) ;
    done.push_back(-4) ;
    done.push_back(6) ;
    done.push_back(9) ;
    done.push_back(-8) ;
    done.push_back(9) ;
    done.push_back(-4) ;
    done.push_back(7) ;
    done.push_back(0) ;
    done.push_back(-9);
    LinkedList copydone;
    copydone = done;


    LinkedList finaldone(copydone);

    cout<<"remove dup"<<endl;
    finaldone.remove_duplicates();
    cout<<finaldone.size();
    cout<<endl;





    return 0;
}
