#include<bits/stdc++.h>
using namespace std;
char a[9];
void setup(){
    for(int i=1; i<10; i++){
        a[i]='-';
}
}
void printBoard(){
     for(int i=1; i<10; i++){
        cout << a[i] << ' ';
        if(i==3 || i==6 || i==9)
        cout << '\n';
    }
}
/*1 2 3
4 5 6
7 8 9*/
int checkWinner(){

    if(a[1]==a[4] && a[4]==a[7] && a[1]!='-')return 1;
    else if(a[2]==a[5] && a[5]==a[8] && a[5]!='-' ) return 1;
    else if(a[3]==a[6] && a[6]==a[9] && a[3]!='-') return 1;
    else if(a[1]==a[2] && a[2]==a[3] && a[1]!='-') return 1;
    else if(a[4]==a[5] && a[5]==a[6] && a[4]!='-') return 1;
    else if(a[7]==a[8] && a[8]==a[9] && a[7]!='-') return 1;
    else if(a[1]==a[5] && a[5]==a[9]  && a[5]!='-') return 1;
    else if(a[3]==a[5] && a[5]==a[7] && a[5]!='-') return 1;
    return 0;

}
int computermove(){
    int x=1;
    while(x){
        int r=rand()%9+1;
        if(a[r]=='-')return r;
    }
 }

void printBoardWinner(int x){
    if(x==1){
         for(int i=1; i<10; i++){
         cout << 'X' << ' ';
          if(i==3 || i==6 || i==9) cout << '\n';
        }

    }
    else{
         for(int i=1; i<10; i++){
        cout << 'O' << ' ';
        if(i==3 || i==6 || i==9) cout << '\n';
    }

}
}
int main(){
    setup();
   printBoard();
   cout << "if even number cam player 1 turn" << '\n';
   cout << "else player 2 turn " << '\n';
   int i=rand()%6+1;
    cout << i;
   if(i%2==0){
    cout << "player 1 turn" << '\n';
    cout << "choose a number " << '\n';
    int count=0;
        while(count!=9){
            cout << "please enter number" << '\n';
            int x;
            cin >> x;
            if(a[x]!='-'){cout << "move not allowed" << '\n';}
            else
            {   a[x]='X';
                count++;
                printBoard();
                int wa=checkWinner();
                if(wa==1){
                    cout << "Congragulations You Won the Game" << '\n';
                    printBoardWinner(1);
                    return 1;
                }
                int p=computermove();
                cout << "computers turn " << '\n';
               // cout << "p is " << p << '\n';
                a[p]='O';
                printBoard();
                int w=checkWinner();
                if(w==1){
                    cout << "Sorry YOU lost" << '\n';
                    printBoardWinner(0);
                    return 1;
                }
            }
       }
   }
   else{

        int count=0;
        cout << "computers turn" << '\n';
        a[1]='O';
        printBoard();
        while(count!=8){
                      cout << "please enter number" << '\n';
            int x;
            cin >> x;
            if(a[x]!='-'){cout << "move not allowed" << '\n';}
            else
            {   a[x]='X';
                count++;
                printBoard();
                int w=checkWinner();
                if(w==1){
                    cout << "Congragulations You Won the Game" << '\n';
                    printBoardWinner(1);
                    return 1;
                }
                int p=computermove();
                cout << "computers turn " << '\n';
                a[p]='O';
               // cout << "P is " <<p << '\n';
                printBoard();
                int waa=checkWinner();
                if(waa==1){
                    cout << "Sorry YOU lost" << '\n';
                    printBoardWinner(0);
                    return 1;
                }
            }

        }

   }


}
