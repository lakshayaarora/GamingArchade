#include <iostream>
#include<time.h>
#include<queue>
#include<map>
int stackforcomputer[4];
int stackforuser[4];
int topforuser=-1;
int topforcomputer=-1;
using namespace std;
struct cell{
    int x,y;
    int dist;
    cell() {}
    cell(int x1,int y1,int d)
    {
int topforcomputer=-1;
        x=x1;
        y=y1;
        dist=d;
    }
};
int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
bool isValid(int x,int y,int N)
{
    if(x>=1 && x<=N && y>=1 && y<=N)
    return true;
    return false;
}

int minKnightsmove(int knightPos[],int targetPos[],int N)
{
       queue<cell> q;
       q.push(cell(knightPos[0], knightPos[1], 0));
       cell t;
    int x, y;
    bool visit[N + 1][N + 1];
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            visit[i][j] = false;
        }
    }
            visit[knightPos[0]][knightPos[1]] = true;

        while (!q.empty()) {
        t = q.front();
        q.pop();
         if (t.x == targetPos[0] && t.y == targetPos[1])
            return t.dist;
       for (int i = 0; i < 8; i++) {
            x = t.x + dx[i];
            y = t.y + dy[i];
            if (isValid(x, y, N) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(cell(x, y, t.dist + 1));

            }
        }
    }
    return 0;
}
int call_answerforKnights()
{
     srand(time(0));
    int N=(rand()%(11-6))+6;
    int knightPos[2],targetPos[2];

    knightPos[0]=rand()%(N)+1;
    knightPos[1]=rand()%(N)+1;
    targetPos[0]=rand()%(N)+1;
    targetPos[1]=rand()%(N)+1;
    cout<<endl;
    cout<<"\t\t THE KNIGHT'S MOVE"<<endl;
    cout<<"Given a square chessboard of "<<N<<"x"<<N<<"size, the position of Knight and position of atarget is given, Your task is to find out the minimum steps a Knight will take to reach the target position. Can you answer this puzzle?"<<endl;
    cout<<"........If you answer it correctly then you go onto the next game otherwise the Game ends here........"<<endl;
    cout<<"The Knight's Position is {"<<knightPos[0]<<","<<knightPos[1]<<"}" << endl;
    cout<<"The target Position is {"<<targetPos[0]<<","<<targetPos[1]<<"}"<<endl;
    int cmoves=minKnightsmove(knightPos,targetPos,N);
    return cmoves;
}
int answer(map<int,int>lad , map<int,int>snak)
{
    int moves = 0; //as initially moves is 0.
 queue<int> q;
 q.push(1);
 bool found = false;
 vector<int> vis(101,0);
 vis[1] = true;
 while(!q.empty() and !found)
 {
 int sz = q.size();
 while(sz--){
 int t = q.front();
 q.pop();
 for(int die = 1;die<=6;die++)
 {
 if(t+die == 100)
 {
 found=true;
 }
 if(t+die <= 100 && lad[t+die] && !vis[lad[t+die]])
 {
 vis[lad[t+die]] = true;
 if(lad[t+die] == 100){
 found = true;
 }
 q.push(lad[t+die]);
 }
 else if(t+die <= 100 && snak[t+die] && !vis[snak[t+die]])
 {
 vis[snak[t+die]] = true;
 if(snak[t+die] == 100)
 found = true;
 q.push(snak[t+die]);
 }
 else if(t+die <= 100 && !vis[t+die] && !snak[t+die] && !lad[t+die])
 {
 vis[t+die] = true;
 q.push(t+die);
 }
 }
 }
 moves++;
 }
  return moves;
}
 void seed()
   {
       srand(time(0));
   }
int call_answerforSnakeLadder()
{
  seed();
 cout<<endl;
  cout<<"You are the square 1 and have to reach the square 100. You have complete";
cout<<"control over the die and can get any number from 1-6. There will be several";
cout<<"ladders and snake in between. If you moved to the square having ladder then";
cout<<"you will climb up to the square till which the ladder ends. But if you moved to";
cout<<" the square having the head of the snake then you have to move down back to";
cout<<" the square having the tail of that particular snake.";
cout<<"For the given snakes and ladders you have to find the minimum steps to reach";
cout<<"the square 100";
cout<<endl<<endl;
 int ladders = (rand()%(4-1))+1,snakes = (rand()%(4-1))+1;
 map<int,int> lad;
 int x,y,m,n;
  cout<<"Number of Ladders = "<<ladders<<endl;
    seed();
 for(int i=0;i<ladders;i++)
 {
      x = (rand()%(30-2))+2;
      y = (rand()%(99-31))+31;
    lad.insert(pair<int, int>(x,y));
     cout<<"Ladder "<<i+1<<" "<<x<<"->"<<y<<endl;
 }


      cout<<"Number of Snakes = "<<snakes<<endl;
 map<int,int> snak;
 for(int i=0;i<ladders;i++)
 {
 int u,v;
 lad[u] = v; //it means that if we know that at uth position ladder is there soit will jump to the vth place.
 }
 fflush(stdin);
 seed();
  for(int i=0;i<snakes;i++)
 {
      m = (rand()%(99-31))+31;
      n = (rand()%(30-1))+1;
    snak.insert(pair<int, int>(m,n));
      cout<<"Snake "<<i+1<<" "<<m<<"->"<<n<<endl;
 }
 for(int i=0;i<snakes;i++)

 {
 int u,v;
 snak[u] = v; //it means that if we know that at uth position snake is there so it will fall back to the vth place.
 }
      int moves=answer(lad,snak);
      return moves;
}
void pushforcomputer(int value)
{
        topforcomputer++;
        stackforcomputer[topforcomputer]=value;
}
void pushforuser(int value)
{
        topforuser++;
        stackforuser[topforuser]=value;
}
void MasterMind()
{
    cout<<"\n Welcome to the last level, MASTERMIND !!"<<endl<<endl;
    cout<<"Here are the rules for the game "<<endl<<endl;
    cout<<"We will be setting a 5 digit/color code for you and you have to break it to win CHICKEN DINNER"<<endl<<endl;
    cout<<"1-If a digit/color is correct and is at correct position then it will get marked with @"<<endl<<endl;
    cout<<"2-If a digit/color is correct but at incorrect position then it will get marked with!"<<endl<<endl;
    cout<<"3-If the digit/color is not in the code then it will get marked with *"<<endl<<endl;
    cout<<"😈  You have to guess in less than 12 attempts"<<endl<<endl;
    string choice;
    againchoice:
    cout<<"Choose between COLOR or DIGIT,Enter your choice"<<endl<<endl;
    cin>>choice;
    cout<<endl;
    if(choice=="COLOR")
    {
        cout<<endl;
        cout<<endl<<"Now you have to guess a 4 color code and remember that 2 colors can be repeated"<<endl<<endl;
        cout<<"Variety of colors- White(0),Black(1),Orange(2),Yellow(3),Purple(4),Cyan(5),Green(6),Violet(7),Peach(8),Brown(9)"<<endl<<endl;
        int computernumber=rand()%(9999-1000+1)+1000;
 
        //creates a unique number in between 1000 and 9999
        int localvariable2=computernumber;
        while(localvariable2>0)
        {
            pushforcomputer(localvariable2%10);
            localvariable2=localvariable2/10;
        }
        int usernumber;
        int attempts=0;
        cout<<"Guess the number";
        while(attempts<=12)
        {
            cout<<endl;
            cin>>usernumber;
            cout<<endl;
            topforuser=-1;
            attempts++;
            if(usernumber==computernumber)
            {
                cout<<"VICTORY"<<endl;
                goto next;
            }
            else
            {
                while(usernumber>0)
                {
                pushforuser(usernumber%10);
                usernumber=usernumber/10;
                }
        for(int i=topforcomputer;i>=0;i--)
        {
            int j=0;
            if(stackforuser[i]==stackforcomputer[i])
            {
                cout<<"@";
            }
            else if(stackforuser[i]!=stackforcomputer[i])
            {
                int top=0;
                for(int j=topforcomputer;j>=0;j--)
                {
                    if(stackforuser[i]==stackforcomputer[j])
                    {
                        top++;
                    }
                }
                if(top==0)
                {
                    cout<<"*";
                }
                else
                {
                    cout<<"!";
                }
            }
            else
            {
                cout<<"*";
            }
        }
        }}
    }
    else if(choice=="DIGIT")
    {
        cout<<"Now you have to guess a 4 digit number and remember that 2 digits can be repeated"<<endl;
        int computernumber=rand()%(9999-1000+1)+1000;
        //creates a unique number in between 1000 and 9999
        int localvariable2=computernumber;
        while(localvariable2>0)
        {
            pushforcomputer(localvariable2%10);
            localvariable2=localvariable2/10;
        }
        int usernumber;
        int attempts=0;
        cout<<endl<<"Guess the number"<<endl<<endl;
        while(attempts<=12)
        {
            cout<<endl;
            cin>>usernumber;
            cout<<endl;
            topforuser=-1;
            attempts++;
            if(usernumber==computernumber)
            {
                cout<<"VICTORY IN "<<attempts<<" ATTEMPTS"<<endl;
                goto next;
            }
            else
            {
                while(usernumber>0)
                {
                pushforuser(usernumber%10);
                usernumber=usernumber/10;
                }
        for(int i=topforcomputer;i>=0;i--)
        {
            int j=0;
            if(stackforuser[i]==stackforcomputer[i])
            {
                cout<<"@";
            }
            else if(stackforuser[i]!=stackforcomputer[i])
            {
                int top=0;
                for(int j=topforcomputer;j>=0;j--)
                {
                    if(stackforuser[i]==stackforcomputer[j])
                    {
                        top++;
                    }
                }
                if(top==0)
                {
                    cout<<"*";
                }
                else
                {
                    cout<<"!";
                }
            }
            else
            {
                cout<<"*";
            }
        }
        }}
    }
    else
    {
        cout<<"Please Enter a valid choice "<<endl;
        goto againchoice;
    }
    next:
        return ;
}
int main()
{
    cout<<"\t \t \t \t Welcome to Our Gaming Estate"<<endl;
    cout<<"There is a rule in this game, once you enter the game you can’t leave the Game in between without getting whole thrill";
cout<<"The first game is “Snake and Ladders” in which user will be having the whole right to select dice numbers from 1-6.";
cout<<"Computer will generate different ladders and snakes, now user will have to tell the minimum steps to reach 100, if the user gives the correct answer,";
cout<<"then user will be promoted to level 2 which will be “The Knights move”, in which the user has to guess minimum steps to be travelled by the Knight from";
cout<<"the source position to the target position, if the user answers it correctly then the level will be upgraded to level 3  ,the last game 'Mastermind'";
cout<<" Break the code” in which the user will have to break the code in less than 12 attempts."<<endl<<endl;
cout<<"\t \t \t Welcome to our First Game i.e 'Snakes and Ladders'"<<endl;
    int movesSnake=call_answerforSnakeLadder();
    int b;
 cout<<"Enter the minimum steps you think it is required to win the game:";
 cin>>b;
 if(b==movesSnake)
 {
     cout<<"CONGRATULATIONS!! Your answer is correct.You can proceed further to our next game i.e. Knight's Tour";
     int Knightsmove=call_answerforKnights();
     int usermoves;
    cout<<"Enter the minimum number of moves";
    int f=0;
    while(f==0)
    {
     cin>>usermoves;
     if(usermoves>0)
       f=1;
       else
       cout<<"Please enter a non negative number";
    }
    if(usermoves==Knightsmove)
    {
        cout<<"Yayy!! You have answered it correctly"<<endl;
        MasterMind();
    }
    else
    {
        cout<<"Oh No!! Your answer is wrong"<<endl;
        cout<<"The Minimum No of moves are "<<Knightsmove<<endl;
        cout<<"The game ends here";
    }


 }
 else{
    cout<<"OOPS!! The required steps are:"<<movesSnake;
    cout<<"\n Since your answer was wrong.You cannot proceed further!!! The game ends here!"<<endl;
}
}