#include <iostream>
#include <cmath>
using namespace std;
//abstract

class verifyAge{
    virtual int verification()=0;
}; //

class person : verifyAge {
    int Age;
    string Name;
public:
    void getName(){
    cout << "Please enter Name."<<endl;
    cin >> Name;
    }
    void getAge(){
    cout << "Please enter Age."<<endl;
    cin >> Age;
    }
    void setName(string name){
        Name = name ;
    }
    void setAge(int age){
        Age = age;
    }
    string printName(){
    return Name;
    }
    int printAge(){
    return Age;
    }
    int verification(){
        string answer,failed, ok;
        failed = "you can't access it.";
        ok = "permission granted";
        cout <<"Are you over 18? Press y or n.";
        cin >> answer;
        if( answer == "y"|| answer =="Y") {cout << ok<<endl; return 1;
        }
        else if (answer == "n"|| answer =="N") {cout << failed<<endl; return 0;}
        else {cout<< "Invalid input"<<endl; return 0; };
    }
person( string name ,int age){
        Age = age;
        Name= name;
    }    
};
class gamer {
    string Name1;
    int Age1; 
    public:
    char areYouOn(){
        char input1;
        cout<<"Do you wanna Play again?? press Y for again and N for "<<endl;
        cin>>input1;
        if (input1=='y'||input1 =='Y')
            return 'y';
        else return 'n';
    }
    void announcer(){
        cout<< "Lets game Mr."<<Name1<<endl;  
    }
    void HorT(){ 
         int num1 = rand()%2+1;
        char Input;
        cout << "Please enter head or tails. Press H or T."<<endl;
        cin>> Input;
   switch (num1)
   {
   case 1:
       cout << "Heads\n";
       break;
   case 2:
       cout << "Tails\n";
       break;
   default: cout<< "Error\n";
        
       break;
   }
   switch(Input){
       case 'h':
        if(num1==1)cout<<"You Win. Congratulations!"<<endl;
        else cout<<"You Lose. Try Again."<<endl;
         break;
       case 't':
        if(num1==2)cout<<"You Win. Congratulations!"<<endl;
        else cout<<"You Lose. Try Again."<<endl;
         break;
        default : cout<<"Invalid input."<<endl;
        break;
   }
    }
    void diceRoll(){
       int num2 = rand()%6+1;
       switch(num2){
           case 1 : cout<<"You roll 1."<<endl;
           break;
           case 2 : cout<<"You roll 2."<<endl;
           break;
           case 3 : cout<<"You roll 3."<<endl;
           break;
           case 4 : cout<<"You roll 4."<<endl;
           break;
           case 5 : cout<<"You roll 5."<<endl;
           break;
           case 6 : cout<<"You roll 6."<<endl;
           break;
           default: cout<<"Error";
           break;
           
       }
    }
    int chooseGame(){
        int choice;
        cout<<"please choose game: 1 for head/tails , 2 for dice roll"<<endl;
        cin>>choice;
        return choice;
    }
 gamer(person player1){
     Name1 = player1.printName();
     Age1 = player1.printAge();
 }

}; 

int main(){
    person person1 = person("suraj", 25) ;

    if (person1.verification()==1){
        person1.getName();
        person1.getAge();
        person1.printName();
        person1.printAge();
    }
    else return 0;
    gamer gamer1 = gamer(person1);
    gamer1.announcer();
    char test = 'y';
    if(gamer1.chooseGame()==1){
        while( test == 'y')
        { gamer1.HorT();
        test = gamer1.areYouOn();
        };
    }else if (gamer1.chooseGame()==2){
        while( test == 'y')
        { gamer1.diceRoll();
        test = gamer1.areYouOn();
        };
    }
}