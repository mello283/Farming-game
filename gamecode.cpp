//leapday is finally fixed
//next is to make the crops grow according to season
//fix when crops that regrow actually die
//suggestion for code, make a stack of days upcoming and fill it a year out


#include <iostream>
#include <string>
#include <cstring>
#include "crops.h"
#include "player.h"
using namespace std;
int xPos=0;
int yPos=0;
int m=3,n=3;
void endOfDay(crop* field);
void decision(crop* field,player* p);
void plantCrop(crop* field,player* p);
void harvest(crop* field,player* p);
void stats(player* p);
void buySeeds(crop* field,player* p);
void buySeeds(crop* field,player* p)
{
    bool outOfSeason=false;
    int choice=0,i=0;
    switch(season)
    {
        case 'p':
            for(i=0;i<6;i++)
            {
                cout<<i<<": "<<seedList[i].name<<endl;

            }
            while(i>6&&i<=0)
                cin>>i;
            break;
        case 's':
            for(i=7;i<13;i++)
            {
                cout<<i-7<<": "<<seedList[i].name<<endl;
            }
            while(i>6&&i<=0)
                cin>>i;
            break;
        case 'f':
            for(i=14;i<20;i++)
            {
                cout<<i-14<<": "<<seedList[i].name<<endl;

            }
            while(i>6&&i<=0)
                cin>>i;
            break;
        case 'w':
            for(int i=21;i<27;i++)
            {
                cout<<i-21<<": "<<seedList[i].name<<endl;
            }
            while(i>6&&i<=0)
                cin>>i;
            break;
        default:outOfSeason=true;
    }
    if(outOfSeason)
    {
        for(i=0;i<27;i++)
        {
            cout<<i<<": "<<seedList[i].name<<endl;
        }
    }
    while(i>27&&i<=0)
        cin>>i;
}
void stats(player* p)
{
    cout<<"\n___stats___\n"<<gold;
}
void harvest(crop* field,player* p)
{
    if((isalpha((field+xPos*n+yPos)->type)))
    {
        (field+xPos*n+yPos)->type='.';
        gold+=(field+xPos*n+yPos)->value;
        *(field+xPos*n+yPos)=blank;
    }
}
void plantCrop(crop* field,player* p)
{
    *(field+xPos*n+yPos)=garlic;
}

void endOfDay(crop* field)
{
    //check for water
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if((field+i*n+j)->isWatered)
            {
                (field+i*n+j)->isWatered=false;
                if((field+i*n+j)->type!='.')
                {
                    (field+i*n+j)->growTime++;
                }
            }
            else
            {
                if((field+i*n+j)->type!='.')
                {
                    (field+i*n+j)->growTime--;
                }
            }
        }
    }
    //increase number of days and check seasons
    day++;
    if(day>31&&day<61&&season!='s')
    {
        if(leapDay&&season!='L')
        {
            cout<<"\nToday is leap day\n";  
            cin.ignore();
            cout<<"\nCrops grow instantly one time today\n";
            cin.ignore();
            season='L';
        }
        else
        {
            season='s';
            cout<<"\n\n\n\nStart of summer\n\n\n\n";
            day=31;
        }
    }
    if(day>=61&&day<91&&season!='f')
    {
        season='f';
        cout<<"\n\n\n\nStart of fall\n\n\n\n";
    }
    if(day>=91&&day<121&&season!='w')
    {
        season='w';
        cout<<"\n\n\n\nStart of winter\n\n\n\n";
    }
    if(day>=121)
    {
        day=1;
        season='p';
        year++;
        if(year%4==0)
            leapDay=true;
        cout<<"\n\n\n\nStart of spring\n\n\n\n";
    }
}
void decision(crop* field,player* p)
{
    char d;
    cout<<"\ninput your decision\n";
    cout<<"\nwasd to move, 1. water plants, 2. plant crops, 3. harvest, 4.buy seeds , 5.show stats, 0. end the day\n";
    cin>>d;
    switch(d)
    {
        case 'w':
        if(xPos-1>=0)
            xPos--;
            break;
        case 's':
        if(xPos+1<n)
            xPos++;
            break;
        case 'a':
        if(yPos-1>=0)
            yPos--;
            break;
        case 'd':
        if(yPos+1<m)
            yPos++;
            break;
        case '1':
            (field+xPos*n+yPos)->isWatered=true;
           break;
        case '2':
            plantCrop(field,p);
            break;
        case '3':
            harvest(field,p);
            break;
        case '4':
            buySeeds(field,p);
            break;
        case '5':
            stats(p);
            break;
        case '0':
            endOfDay(field);
            break;
        default:cout<<"invalid input";
    }
    cout<<endl;

}
//(arr+1*1+2)->death=(-(arr+1*1+2)->growTime);
int main()
{
    crop* field = new crop[m * n];
    player* p;
    //initialize the array
    int i=0,j=0;
    for(i=0;i<m;++i)
    {
        for(j=0;j<n;++j)
        {
            (*(field+i*n+j))=blank;
            (field+i*n+j)->type;
        }
    }
    int k=0;
    char disChar='.';
    for(k=0;;++k)
    {

        //display the array
        for(i=0;i<m;++i)
        {
            for(j=0;j<n;++j)
            {
                disChar='.';
                if((field+i*n+j)->type!='.')
                {
                    if((field+i*n+j)->growTime+(field+i*n+j)->death>0)
                    {
                        disChar='^';
                    }
                    if((field+i*n+j)->growTime==(field+i*n+j)->death)
                    {
                        disChar=(field+i*n+j)->type;
                    }
                    if((field+i*n+j)->isWatered==true)
                    {
                        disChar='*';
                    }
                    if((field+i*n+j)->growTime+(field+i*n+j)->death==0&&(field+i*n+j)->growTime!=0)
                    {
                        disChar='%';
                    }
                    if(leapDay&&season=='L')
                    {
                        disChar=(field+i*n+j)->type;
                    }
                }
                else
                {
                    if((field+i*n+j)->isWatered==true)
                    {
                        disChar='*';
                    }
                }
                cout<<disChar<<" ";
            }
            if(i==0)
                cout<<"     X: "<<xPos+1<<" Y: "<<yPos+1;
            if(i==1)
                cout<<"     Season: "<<season<<" Day: "<<day;
            if(i==2)
                cout<<"     Gold: "<<gold;
            cout<<endl;
        }        
        char decisionMain;
        cout<<"type ' for decision screen\n";
        cin>>decisionMain;
        if(decisionMain=='\'')
        {
            decision(field,p);
        }

    }
    delete[] field;
    return 0;
}

/*
    *(arr+1*n+1)=bean;
    (arr+1*n+3)->type='Q';
    *(arr+1*n+1)=*(arr+1*n+3);
    cout<<"\n\n\n"<<(arr+1*n+1)->value<<endl<<(arr+1*n+1)->type;
*/
//    for(i=0;i<m;++i)
//    {
//        for(j=0;j<n;++j)
//        {
//            cout<<(arr+i*n+j)->type<<" "<<(arr+i*n+j)->season<<",";
//        }
//    }
    //cout<<"\n\nTomato: "<<(arr+0*n+0)->type;
    
    
//inner display loop
/*                if((field+i*n+j)->growTime+(field+i*n+j)->death>0)
                {
                    if((field+i*n+j)->isWatered)
                        cout<<"* ";
                    else
                        cout<<"^ ";
                }
                else if((field+i*n+j)->growTime+(field+i*n+j)->death<0)
                {
                    if((field+i*n+j)->isWatered)
                        cout<<"* ";
                    else
                        cout<<". ";
                }
                else
                {
                    if((field+i*n+j)->growTime+(field+i*n+j)->death==0&&(field+i*n+j)->growTime!=0)
                    {
                        cout<<"% ";
                    }
                    else
                        cout<<(field+i*n+j)->type<<" ";
                }*/









