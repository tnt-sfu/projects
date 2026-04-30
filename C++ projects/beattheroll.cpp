// Question 2 assignment 3: Beat the roll
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// Preparing all required functions
void printWelcomeMessage(){
    cout << setfill('*') <<setw(45)<<""<<endl;
    cout<<"Welcome to Roller's Un-Random house of dice!"<<endl;
     cout<<setfill('*')<<setw(45)<<""<<endl;
};
string getName(){
    string name;
    cout<<"What is your first name?";
    cin>>name;
    return name;
};

void setSeed(){
    
    cout<<"Would you like to pick up an un-random game, or let the timer pick?"<<endl;
    int choice;
    cout<<"Enter 0 for timer, or pick your own un-random game: ";
    cin>>choice;
    
    if(choice==0){
        srand(time(NULL));
        cout<<"THE TIMER! A daring choice!"<<endl;
    }else{
        srand(choice);
        cout<<choice<<"! A wise and safe choice."<<endl;
    }
};

int getRandomNum(){

    return rand()%6+1;
};

int getMaxBet(){
    int bet;
   
    cout<<"What would you like to be the maximum bet? :";
    cin>>bet;
    
    while(bet<1){
        cout<<"The maximum bet must be greater than or equal to 1."<<endl;
        cout<<"What would you like to be the maximum bet? :";
        cin>>bet;
        
    };
    return bet;
    
};

int getUserBet(int maxBet, int score){
    int userBet;
    cout<<"Enter your bet: ";
    cin>>userBet;
    
    while(userBet<=0 ||userBet>score||userBet>maxBet){
        if(userBet<=0){
            cout<<"You must bet at least 1."<<endl;
        }else if (userBet>maxBet){
             cout<<"You must not bet more than the maximum bet ("<<maxBet<<")."<<endl;
        }else{
             cout<<"You must not bet more than your score ("<<score<<")."<<endl;
        }
        
        cout<<"Enter your bet: ";
        cin>>userBet;
    };
    
    return userBet;
    
}
int main() {
      
    
      
      //print welcome message
       printWelcomeMessage();
       
       //get user name
      string userName=getName();
      
      //set up psuedo random generator
      setSeed();
      
      cout<<endl;
      
      //get Max bet
      int maxBet= getMaxBet();
      
    //set initial points
      int points=50;
      
    //set round
    int round=1;
      
      while(points>0&&points<100){
        cout<<endl;
        cout<<"Round "<<round<<" You have "<<points<<" points."<<endl;
        cout<<"Dealer rolls: ";
        int d1=getRandomNum();
        int d2=getRandomNum();
        cout<<d1<<" + "<<d2<<" = "<<d1+d2;
         cout << setfill(' ') <<setw(30)<<"";
        int userBet=getUserBet(maxBet,points);
           
        cout<<"You roll:     ";
        int p1=getRandomNum();
        int p2=getRandomNum();
        cout<<p1<<" + "<<p2<<" = "<<p1+p2<<"."<<endl;
        
        if((d1+d2)>(p1+p2)){
            cout<<userName<<", you lost. :-("<<endl;
            points-= userBet;
        }else{
            cout<<userName<<", you won! :-)"<<endl;
            points+=userBet;
        }
        
        cout<<"Current score: "<<points<<"."<<endl;
        round++;
      }
      
      if(points==0){
          cout<<"I'm sorry, "<<userName<<"; you are out of points so you lose."<<endl;
      }else{
          cout<<"Congratulations "<<userName<<"! You win the game with a score of "<<points<<"."<<endl;
      }
      
    return 0;
}
