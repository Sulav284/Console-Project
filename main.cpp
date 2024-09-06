#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>

using namespace std;

int randomNumberGenerator(int min, int max){
  
  return min+rand()%max;
}

void getName(string n){
  cin>>n;
}

int main(){
  srand(time(0));
// int bettingAmt;
  // char isBetting ;
  int playersNo;
  string playersName[2];
  int playerScore[2];
  string result;


  ofstream outfile;
  outfile.open("output.txt",ios::app);
 
// cout<<"*********Warning***********"<<endl;
//   cout<<"warning message"<<endl<<endl;

cout<<"How many players are playing? ";
  cin>>playersNo;
  if(playersNo<= 0 || playersNo > 2 ){
    cout<<"Invalid number of players"<<endl;
  }

  cout<<"-----------------------------------------------"<<endl;
  for(int i = 0; i < playersNo; i++){
    cout<<"Enter player "<<i+1<<" name: ";
    cin>>playersName[i];
  }
  

  // cout<<"Do you want to bet Money? (y/n)"<<endl;
  // cin>>isBetting;

  // if(isBetting == 'y' || isBetting == 'Y'){
  //   cout<<"How much money do you want to bet?"<<endl;
    
  //   cin>>bettingAmt;
  // }else{
  //   cout<<"Nice Choice"<<endl;
  // }

  cout<<endl<<"Let's start the game"<<endl;
  cout<<"-----------------------------------------------"<<endl;
  for(int i=0; i<playersNo; i++){
    cout<<playersName[i]<<"'s turn"<<endl;
    cout<<"Press any key to roll the dice";
    cin.ignore();
    cin.get();
    playerScore[i]=randomNumberGenerator(1,6);
    cout<<playerScore[i]<<endl<<endl;
    
  }
  cout<<"-----------------------------------------------"<<endl;

  cout<<"       ***GAMEOVER***           "<<endl;
  if(playerScore[0] > playerScore[1]){
    result = playersName[0]+" wins"+"\n";
    cout<<result;
  }
 else if (playerScore[0] < playerScore[1]){
   result = playersName[1]+"wins"+"\n";
    cout<<result;
 }else{
    cout<<"It's a tie"<<endl;
 }

  outfile<<result;
  outfile.close();
  
  return 0 ;
}
