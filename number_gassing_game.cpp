#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int inputuser;
    string name;
    char input;
    int score=0;

    cout<<"enter your name :";
    getline(cin,name);
    cout<<endl;
    do
    {
        srand(0);
        int variable=rand()%5+1;
        cout<<"enter any number in between range 1 to 5    ";
        cin>>inputuser;
        cout<<endl;
        if(inputuser==variable)
        {
            cout<<"congatulations !you gussed the correct number "<<endl;
                score++;
        }
        else
        {
            cout<<"sorry, you guessed wrong number ry again"<<endl;
        }
        cout<<"would you like to try again Y/N    ";
        cin>>input;
        cout<<endl;

    }while(input!='N');
    cout<<"your score is       "<<score<<endl;
    cout<<"game end"<<endl;
}
