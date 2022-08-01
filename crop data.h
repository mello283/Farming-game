#ifndef CROPS_H_INCLUDED
#define CROPS_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
class crop
{
    public:
        string name = " ";
        int  value = 0;
        char type = '.';
        bool isMulti = false;
        bool isWatered = false;
        bool isWeeded = false;
        int  growTime = 0;//if growTime == death then the plant is ready to harvest
        int  death = 0 ;//if growTime+death==0 then the plant is dead. positive death vs negative death, the plant dies either way
        char season = '.';//p spring, s summer, f fall, w winter, E eclipse, L leap day, G 7th eclipse in a row
        bool isOrganic = true;
        crop();
        crop(string n,int val,char ty,bool Multi,int growT,int de,char se)
        {
            name = n;
            value = val;
            type = ty;
            isMulti = Multi;
            growTime = growT;
            death = de;
            season = se;
        }
        crop operator=(crop&c2);
};
crop::crop()
{

}
crop crop::operator=(crop&c2)
{
    //c2.name=name;
    value=c2.value;
    type=c2.type;
    isMulti=c2.isMulti;
    isWatered=c2.isWatered;
    isWeeded=c2.isWeeded;
    growTime=c2.growTime;
    death=c2.death;
    season=c2.season;
    isOrganic=c2.isOrganic;
    return c2;
}
crop blank("Nothing",0,'.',false,0,0,'.');
//name, value, type, produces multiple, time to grow, time to die, season grown in
//spring crops
crop tomato("Tomato",10,'t',true,5,8,'p');
crop garlic("Garlic",15,'g',false,3,5,'p');
crop onion("Onion",12,'o',false,6,9,'p');
crop califlower("Cauliflower",25,'c',false,5,9,'p');
crop potato("Potato",7,'p',false,2,6,'p');
crop blueberry("Blueberry",6,'b',true,2,7,'p');
crop eggplant("Eggplant",14,'e',false,4,6,'p');
//summer
crop pepper("Pepper",10,'p',true,1,8,'s');
crop watermelon("Watermelon",20,'w',false,1,7,'s');
crop cantelope("Cantelope",25,'c',false,1,6,'s');
crop broccoli("Broccoli",30,'b',false,1,6,'s');
crop grapes("Grapes",5,'g',true,1,3,'s');
crop strawberry("Strawberry",10,'s',true,1,5,'s');
crop lettuce("Lettuce",15,'l',false,1,5,'s');
//fall
crop wheat("Wheat",15,'w',false,1,6,'f');
crop squash("Squash",25,'s',true,1,8,'f');
crop pumpkin("Pumpkin",20,'p',false,1,7,'f');
crop bean("Bean",12,'b',true,1,3,'f');
crop muscadine("Muscadine",5,'m',true,1,2,'f');
crop cranberry("Cranberry",10,'c',true,1,2,'f');
crop corn("Corn",12,'c',true,1,2,'f');
//winter
crop ginseng("Ginseng",35,'g',false,1,20,'w');//decreases growth time
crop sassafrass("Sassafrass",20,'s',false,1,5,'w');//acts as organic pesticide
crop mushroom("Mushroom",5,'m',false,1,2,'w');
crop torrentBerry("Torrent Berry",40,'t',false,1,20,'w');//creates a super saturater that keeps the soil watered for multiple days
crop frostLemon("Frost Lemon",50,'l',false,1,15,'w');//can be canned to make batteries
crop xRoot("X-Root",75,'x',false,1,25,'w');//increase the value of the crop
crop quiverStalk("Quiver Stalk",45,'q',false,1,20,'w');//increases the life expectacny of a plant

//super crops
crop leapBerry("Leap Berry",50,'L',false,-5,5,'L');//part one of a super mixture obtained on leap day if xRoot is planted on leap day it becomes a leap berry instead
crop eclipseFruit("Eclipse fruit",300,'E',false,-5,5,'E');//part two of a super mixture obtained if a crop would be ready on the day of an eclipse; gets replaced with an eclipse berry
crop superEssence("Super Essence",1000,'X',false,-5,5,'X');//when both parts of the mixture are applied to a crop it becomes super essence, enough super essence and you trigger an eclipse
crop goldenCrystalEssence("Golden Crystal Essence",100000,'G',false,-5,5,'E');//super essence has to be planted and grown during a week long eclipse for this plant, it is extremely valuable and the first one you get allows you to see the end of the game

//seed menu
crop seedList[28]={tomato,garlic,onion,califlower,potato,blueberry,eggplant,
pepper,watermelon,cantelope,broccoli,grapes,strawberry,lettuce,
wheat,squash,pumpkin,bean,muscadine,cranberry,corn,
ginseng,sassafrass,mushroom,torrentBerry,frostLemon,xRoot,quiverStalk
};

#endif // CROPS_H_INCLUDED

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <string>
#include <iostream>
using namespace std;

