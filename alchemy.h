/**
* Project:	Astonia Alchemy Utility
* Copyright Bloodknight Studios, 2013
*/

#ifndef ALCHEMY_H_INCLUDED
#define ALCHEMY_H_INCLUDED

#include <string>
#include <iostream>
#include <sstream>



#define V_HP		0
#define V_ENDURANCE	1
#define V_MANA		2
#define V_WIS         	3
#define V_INT          	4
#define V_AGI         	5
#define V_STR       	6
#define V_ARMOR		7
#define V_WEAPON	8
#define V_OFFENSE	9
#define V_DEFENSE	10
#define V_LIGHT		11
#define V_SPEED		12
#define V_DAGGER       	13
#define V_HAND         	14
#define V_STAFF        	15
#define V_SWORD        	16
#define V_TWOHAND      	17
#define V_ATTACK       	18
#define V_PARRY	       	19
#define V_WARCRY       	20
#define V_TACTICS      	21
#define V_SURROUND     	22
#define V_SPEEDSKILL	23
#define V_BARTER       	24
#define V_PERCEPT      	25
#define V_STEALTH      	26
#define V_BLESS		27
#define V_HEAL		28
#define V_FREEZE	29
#define V_MAGICSHIELD	30
#define V_FLASH		31
#define V_FIRE		32
#define V_REGENERATE	33
#define V_MEDITATE	34
#define V_IMMUNITY	35
#define V_DEMON		36
#define V_DURATION	37
#define V_RAGE		38
#define V_COLD		39
#define V_PROFESSION	40
#define V_MAX	       	50

#define max(a,b)	((a) > (b) ? (a) : (b))
#define min(a,b)	((a) < (b) ? (a) : (b))

struct recipe{
    int FlowerA, FlowerB, FlowerC, FlowerD, FlowerE, FlowerF, FlowerG;
    int ShroomA, ShroomB, ShroomC, ShroomD, ShroomE, ShroomF, ShroomG, ShroomH, ShroomI;
    int StoneE, StoneF, StoneI, StoneH, StoneCount;
    int Berry1, Berry2, Berry3, Berry4;

    int ModA, ModB, ModC;
    int ValueA, ValueB, ValueC;

    float Divisor;
    int Duration;
    int Power;


	int PPS;
    int Count, FlowerCount, ShroomCount;
	int solstice;
	int fullmoon;
	int equinox;
};

std::string getSkillName(int skill){
std::string skillName;
switch (skill)
{

    case 0:
        skillName="HP";
        break;
    case 1:
        skillName="END";
        break;
    case 2:
        skillName="MANA";
        break;
    case 3:
        skillName="WIS";
        break;
    case 4:
        skillName="INT";
        break;
    case 5:
        skillName="AGI";
        break;
    case 6:
        skillName="STR";
        break;
    case 13:
        skillName="Dagger";
        break;
    case 14:
        skillName="Hand to Hand";
        break;
    case 15:
        skillName="Staff";
        break;
    case 16:
        skillName="Sword";
        break;
    case 17:
        skillName="Two Handed";
        break;
    case 18:
        skillName="Attack";
        break;
    case 19:
        skillName="Parry";
        break;
    case 20:
        skillName="Warcry";
        break;
    case 21:
        skillName="Tactics";
        break;
    case 22:
        skillName="Surround Hit";
        break;
    case 23:
        skillName="Speed Skill";
        break;
    case 24:
        skillName="Barter";
        break;
    case 25:
        skillName="Perception";
        break;
    case 26:
        skillName="Stealth";
        break;
    case 27:
        skillName="Bless";
        break;
    case 28:
        skillName="Heal";
        break;
    case 29:
        skillName="Freeze";
        break;
    case 30:
        skillName="Magic Shield";
        break;
    case 31:
        skillName="Lightning";
        break;
    case 32:
        skillName="Fire";
        break;
    case 33:
        skillName="Regnerate";
        break;
    case 34:
        skillName="Meditate";
        break;
    case 35:
        skillName="Immunity";
        break;
    case 37:
        skillName="Duration";
        break;
    case 38:
        skillName="Rage";
        break;

    default:
        skillName="NOT SET";
        break;
}

return skillName;
}

recipe Flask;

template <typename T>
std::string itostr ( T Number ){
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}


void ValidateFlower(std::string flower)
{

    if(flower.compare("A")==0||flower.compare("a")==0){
        Flask.Count++;
        Flask.FlowerCount++;
        Flask.FlowerA++;
    }
    if(flower.compare("B")==0||flower.compare("b")==0){
        Flask.Count++;
        Flask.FlowerCount++;
        Flask.FlowerB++;
    }
    if(flower.compare("C")==0||flower.compare("c")==0){
        Flask.Count++;
        Flask.FlowerCount++;
        Flask.FlowerC++;
    }
    if(flower.compare("D")==0||flower.compare("d")==0){
        Flask.Count++;
        Flask.FlowerCount++;
        Flask.FlowerD++;
    }
    if(flower.compare("E")==0||flower.compare("e")==0){
        Flask.Count++;
        Flask.FlowerCount++;
        Flask.FlowerE++;
    }
    if(flower.compare("F")==0||flower.compare("f")==0){
        Flask.Count++;
        Flask.FlowerCount++;
        Flask.FlowerF++;
    }
    if(flower.compare("G")==0||flower.compare("g")==0){
        Flask.Count++;
        Flask.FlowerCount++;
        Flask.FlowerG++;
    }
}

void ValidateShroom(std::string shroom)
{


    if(shroom.compare("A")==0||shroom.compare("a")==0){
        Flask.Count++;
        Flask.ShroomCount++;
        Flask.ShroomA++;
    }
    if(shroom.compare("B")==0||shroom.compare("b")==0){
        Flask.Count++;
        Flask.ShroomCount++;
        Flask.ShroomB++;
    }
    if(shroom.compare("C")==0||shroom.compare("c")==0){
        Flask.Count++;
        Flask.ShroomCount++;
        Flask.ShroomC++;
    }
    if(shroom.compare("D")==0||shroom.compare("d")==0){
        Flask.Count++;
        Flask.ShroomCount++;
        Flask.ShroomD++;
    }
    if(shroom.compare("E")==0||shroom.compare("e")==0){
        Flask.Count++;
        Flask.ShroomCount++;
        Flask.ShroomE++;
    }
    if(shroom.compare("F")==0||shroom.compare("f")==0){
        Flask.Count++;
        Flask.ShroomCount++;
        Flask.ShroomF++;
    }
    if(shroom.compare("G")==0||shroom.compare("g")==0){
        Flask.Count++;
        Flask.ShroomCount++;
        Flask.ShroomG++;
    }
    if(shroom.compare("H")==0||shroom.compare("h")==0){
        Flask.Count++;
        Flask.ShroomCount++;
        Flask.ShroomH++;
    }
    if(shroom.compare("I")==0||shroom.compare("i")==0){
        Flask.Count++;
        Flask.ShroomCount++;
        Flask.ShroomI++;
    }
}

void ValidateBerry(std::string berry)
{
    if(berry.compare("A")==0||berry.compare("a")==0){
        Flask.Count++;
        Flask.Berry1++;
    }
    if(berry.compare("B")==0||berry.compare("b")==0){
        Flask.Count++;
        Flask.Berry2++;
    }
    if(berry.compare("C")==0||berry.compare("c")==0){
        Flask.Count++;
        Flask.Berry3++;
    }
    if(berry.compare("D")==0||berry.compare("d")==0){
        Flask.Count++;
        Flask.Berry4++;
    }
}

void SetDuration()
{
	if (Flask.Berry1>=1) { Flask.Divisor=1.75; Flask.Duration=60; }
	if (Flask.Berry2>=1) { Flask.Divisor=1.0;  Flask.Duration=10; }
	if (Flask.Berry3>=1) { Flask.Divisor=1.25; Flask.Duration=20; }
	if (Flask.Berry4>=1) { Flask.Divisor=1.5;  Flask.Duration=30; }
	if (Flask.solstice||Flask.equinox) {Flask.Duration*=2;}
}


int GetPower()
{
	int good=0,bad=0;


	if (Flask.ShroomCount==2 && Flask.ShroomA==1 && Flask.ShroomB==1) {
		if (Flask.solstice || (Flask.fullmoon && Flask.PPS>=25)) return 16;
		if (Flask.equinox || (Flask.fullmoon && Flask.PPS>=15)) return 12;
		if (Flask.fullmoon || Flask.StoneCount || Flask.PPS>=10) return 10;
	}
	if (Flask.ShroomCount==2 && Flask.ShroomB==1 && Flask.ShroomC==1) {
		if (Flask.solstice || (Flask.fullmoon && Flask.PPS>=25)) return 24;
		if (Flask.equinox || (Flask.fullmoon && Flask.PPS>=15)) return 20;
		if (Flask.fullmoon || Flask.StoneCount || Flask.PPS>=10) return 16;
	}
	if (Flask.ShroomCount==2 && Flask.ShroomC==1 && Flask.ShroomD==1) {
		if (Flask.solstice || (Flask.fullmoon && Flask.PPS>=25)) return 32;
		if (Flask.equinox || (Flask.fullmoon && Flask.PPS>=15)) return 26;
		if (Flask.fullmoon || Flask.StoneCount || Flask.PPS>=10) return 20;
	}
	if (Flask.ShroomCount==2 && Flask.ShroomD==1 && Flask.ShroomE==1) {
		if (Flask.solstice || (Flask.fullmoon && Flask.PPS>=25)) return 40;
		if (Flask.equinox || (Flask.fullmoon && Flask.PPS>=15)) return 32;
		if (Flask.fullmoon || Flask.StoneCount || Flask.PPS>=10) return 24;
	}
	if (Flask.ShroomCount==2 && Flask.ShroomE==1 && Flask.ShroomF==1) {
		if (Flask.solstice || (Flask.fullmoon && Flask.PPS>=25)) return 48;
		if (Flask.equinox || (Flask.fullmoon && Flask.PPS>=15)) return 38;
		if (Flask.fullmoon || Flask.StoneCount || Flask.PPS>=10) return 28;
	}
	if (Flask.ShroomCount==2 && Flask.ShroomF==1 && Flask.ShroomG==1) {
		if (Flask.solstice || (Flask.fullmoon && Flask.PPS>=25)) return 56;
		if (Flask.equinox || (Flask.fullmoon && Flask.PPS>=15)) return 44;
		if (Flask.fullmoon || Flask.StoneCount || Flask.PPS>=10) return 32;
	}
	if (Flask.ShroomCount==2 && Flask.ShroomG==1 && Flask.ShroomH==1) {
		if (Flask.solstice || (Flask.fullmoon && Flask.PPS>=25)) return 64;
		if (Flask.equinox || (Flask.fullmoon && Flask.PPS>=15)) return 50;
		if (Flask.fullmoon || Flask.StoneCount || Flask.PPS>=10) return 36;
	}
	if (Flask.ShroomCount==2 && Flask.ShroomH==1 && Flask.ShroomI==1) {
		if (Flask.solstice || (Flask.fullmoon && Flask.PPS>=25)) return 72;
		if (Flask.equinox || (Flask.fullmoon && Flask.PPS>=15)) return 56;
		if (Flask.fullmoon || Flask.StoneCount || Flask.PPS>=10) return 40;
	}

    if (Flask.solstice || (Flask.fullmoon && Flask.PPS >= 25)) {
        good = 8;
    } else if (Flask.equinox || (Flask.fullmoon && Flask.PPS >= 15)) {
        good = 4;
    } else if (Flask.fullmoon || Flask.PPS >= 10) {
        good = 2;
    }


	if (Flask.ShroomH) return 36+good-bad;
	if (Flask.ShroomH) return 32+good-bad;
	if (Flask.ShroomG) return 28+good-bad;
	if (Flask.ShroomF) return 24+good-bad;
	if (Flask.ShroomE) return 20+good-bad;
	if (Flask.ShroomD) return 16+good-bad;
	if (Flask.ShroomC) return 12+good-bad;
	if (Flask.ShroomB) return max(2,8+good-bad);
	if (Flask.ShroomA) return max(2,6+good-bad);

	return -1;
}


int makePotion(){

	int skl[3],val[3];
	int n,flag=0;
	int value;

	int power=Flask.Power;

	power+=Flask.StoneF*4;
	power+=Flask.StoneI*8;
	power+=Flask.StoneH*12;

	if (Flask.PPS>=5) power+=2;
	if (Flask.PPS>=10) power+=2;
	if (Flask.PPS>=15) power+=4;
	if (Flask.PPS>=25) power+=4;

	//log_char(cn,LOG_SYSTEM,0,"Final Power: %d",power);

	std::cout<<std::endl;
    std::cout<<"P= "<<power<<std::endl;
    std::cout<<"D= "<<Flask.Divisor<<std::endl;

    if (Flask.FlowerCount==5 && Flask.FlowerA==1 && Flask.FlowerB==1 && Flask.FlowerC==2 && Flask.FlowerD==1) {		// sword attack parry
		skl[0]=V_SWORD; if ((val[0]=(power/Flask.Divisor)/4)) flag=1;
		skl[1]=V_ATTACK; val[1]=(power/Flask.Divisor)/4;
		skl[2]=V_PARRY; val[2]=(power/Flask.Divisor)/4;
		value=10;
	} else if (Flask.FlowerCount==5 && Flask.FlowerA==1 && Flask.FlowerB==1 && Flask.FlowerC==1 && Flask.FlowerD==2) {	// two-handed attack parry
		skl[0]=V_TWOHAND; if ((val[0]=(power/Flask.Divisor)/4)) flag=1;
		skl[1]=V_ATTACK; val[1]=(power/Flask.Divisor)/4;
		skl[2]=V_PARRY; val[2]=(power/Flask.Divisor)/4;
		value=10;
	} else if (Flask.FlowerCount==5 && Flask.FlowerC==1 && Flask.FlowerD==2 && Flask.FlowerE==1 && Flask.FlowerF==1) {	// attack parry immunity
		skl[0]=V_ATTACK; if ((val[0]=(power/Flask.Divisor)/4)) flag=1;
		skl[1]=V_PARRY; val[1]=(power/Flask.Divisor)/4;
		skl[2]=V_IMMUNITY; val[2]=(power/Flask.Divisor)/4;
		value=10;
	} else if (Flask.FlowerCount==5 && Flask.FlowerB==1 && Flask.FlowerD==1 && Flask.FlowerE==2 && Flask.FlowerF==1) {	// flash magic-shield immunity
		skl[0]=V_FLASH; if ((val[0]=(power/Flask.Divisor)/4)) flag=1;
		skl[1]=V_MAGICSHIELD; val[1]=(power/Flask.Divisor)/4;
		skl[2]=V_IMMUNITY; val[2]=(power/Flask.Divisor)/4;
		value=10;
	} else if (Flask.FlowerCount==5 && Flask.FlowerD==2 && Flask.FlowerE==2 && Flask.FlowerF==1) {		// fire magic-shield immunity
		skl[0]=V_FIRE; if ((val[0]=(power/Flask.Divisor)/4)) flag=1;
		skl[1]=V_MAGICSHIELD; val[1]=(power/Flask.Divisor)/4;
		skl[2]=V_IMMUNITY; val[2]=(power/Flask.Divisor)/4;
		value=10;
	} else if (Flask.FlowerCount==4 && Flask.FlowerA==1 && Flask.FlowerB==1 && Flask.FlowerC==1 && Flask.FlowerD==1) {	// attack parry
		skl[0]=V_ATTACK; if ((val[0]=(power/Flask.Divisor)/3)) flag=1;
		skl[1]=V_PARRY; val[1]=(power/Flask.Divisor)/3;
		skl[2]=-1; val[2]=0;
		value=8;
	} else if (Flask.FlowerCount==4 && Flask.FlowerB==1 && Flask.FlowerD==1 && Flask.FlowerE==1 && Flask.FlowerF==1) {	// flash immunity
		skl[0]=V_FLASH; if ((val[0]=(power/Flask.Divisor)/3)) flag=1;
		skl[1]=V_IMMUNITY; val[1]=(power/Flask.Divisor)/3;
		skl[2]=-1; val[2]=0;
		value=8;
	} else if (Flask.FlowerCount==4 && Flask.FlowerD==2 && Flask.FlowerE==1 && Flask.FlowerF==1) {	// fire immunity
		skl[0]=V_FIRE; if ((val[0]=(power/Flask.Divisor)/3)) flag=1;
		skl[1]=V_IMMUNITY; val[1]=(power/Flask.Divisor)/3;
		skl[2]=-1; val[2]=0;
		value=8;
	} else if (Flask.FlowerCount==4 && Flask.FlowerD==1 && Flask.FlowerE==2 && Flask.FlowerF==1) {		// magic shield immunity
		skl[0]=V_MAGICSHIELD; if ((val[0]=(power/Flask.Divisor)/3)) flag=1;
		skl[1]=V_IMMUNITY; val[1]=(power/Flask.Divisor)/3;
		skl[2]=-1; val[2]=0;
		value=10;
	} else if (Flask.FlowerCount==4 && Flask.FlowerC==1 && Flask.FlowerG==1 && Flask.FlowerE==1 && Flask.FlowerF==1) {	// dagger flash
		skl[0]=V_DAGGER; if ((val[0]=(power/Flask.Divisor)/3)) flag=1;
		skl[1]=V_FLASH; val[1]=(power/Flask.Divisor)/3;
		skl[2]=-1; val[2]=0;
		value=8;
	} else if (Flask.FlowerCount==4 && Flask.FlowerC==1 && Flask.FlowerD==1 && Flask.FlowerG==1 && Flask.FlowerF==1) {	// dagger fire
		skl[0]=V_DAGGER; if ((val[0]=(power/Flask.Divisor)/3)) flag=1;
		skl[1]=V_FIRE; val[1]=(power/Flask.Divisor)/3;
		skl[2]=-1; val[2]=0;
		value=8;
	} else if (Flask.FlowerCount==4 && Flask.FlowerC==1 && Flask.FlowerD==1 && Flask.FlowerE==1 && Flask.FlowerF==1) {	// staff flash
		skl[0]=V_STAFF; if ((val[0]=(power/Flask.Divisor)/3)) flag=1;
		skl[1]=V_FLASH; val[1]=(power/Flask.Divisor)/3;
		skl[2]=-1; val[2]=0;
		value=8;
	} else if (Flask.FlowerCount==4 && Flask.FlowerC==1 && Flask.FlowerD==2 && Flask.FlowerF==1) {		// staff fire
		skl[0]=V_STAFF; if ((val[0]=(power/Flask.Divisor)/3)) flag=1;
		skl[1]=V_FIRE; val[1]=(power/Flask.Divisor)/3;
		skl[2]=-1; val[2]=0;
		value=8;
	} else if (Flask.FlowerCount==3 && Flask.FlowerC==2 && Flask.FlowerG==1) {			// dagger
		skl[0]=V_DAGGER; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerC==1 && Flask.FlowerD==1 && Flask.FlowerG==1) {		// staff
		skl[0]=V_STAFF; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerC==2 && Flask.FlowerD==1) {			// sword
		skl[0]=V_SWORD; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerC==1 && Flask.FlowerD==2) {			// two-handed
		skl[0]=V_TWOHAND; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerB==1 && Flask.FlowerC==1 && Flask.FlowerD==1) {		// attack
		skl[0]=V_ATTACK; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerA==1 && Flask.FlowerC==1 && Flask.FlowerD==1) {		// parry
		skl[0]=V_PARRY; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerB==2 && Flask.FlowerG==1) {			// perception
		skl[0]=V_PERCEPT; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerB==2 && Flask.FlowerC==1) {			// stealth
		skl[0]=V_STEALTH; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerC==2 && Flask.FlowerG==1) {			// speed
		skl[0]=V_SPEED; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerC==1 && Flask.FlowerG==1 && Flask.FlowerF==1) {		// freeze
		skl[0]=V_FREEZE; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerE==2 && Flask.FlowerF==1) {			// magic shield
		skl[0]=V_MAGICSHIELD; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerB==1 && Flask.FlowerE==1 && Flask.FlowerF==1) {		// flash
		skl[0]=V_FLASH; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerD==1 && Flask.FlowerE==1 && Flask.FlowerF==1) {		// fireball
		skl[0]=V_FIRE; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} /*else if (Flask.FlowerCount==3 && Flask.FlowerA==1 && Flask.FlowerE==1 && Flask.FlowerF==1) {		// ball
		skl[0]=V_BALL; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} */else if (Flask.FlowerCount==3 && Flask.FlowerD==2 && Flask.FlowerF==1) {		// immunity
		skl[0]=V_IMMUNITY; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerC==1 && Flask.FlowerD==1 && Flask.FlowerE==1) {	// hand to hand
		skl[0]=V_HAND; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerB==1 && Flask.FlowerD==1 && Flask.FlowerG==1) {	// warcry
		skl[0]=V_WARCRY; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerA==1 && Flask.FlowerB==1 && Flask.FlowerC==1) {	// tactics
		skl[0]=V_TACTICS; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerB==1 && Flask.FlowerC==2) {	// surround hit
		skl[0]=V_SURROUND; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerA==1 && Flask.FlowerB==2) {	// bartering
		skl[0]=V_BARTER; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerA==1 && Flask.FlowerB==1 && Flask.FlowerF==1) {	// bless
		skl[0]=V_BLESS; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerA==1 && Flask.FlowerB==1 && Flask.FlowerE==1) {	// heal
		skl[0]=V_HEAL; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerE==1 && Flask.FlowerF==2) {	// duration
		skl[0]=V_DURATION; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.FlowerCount==3 && Flask.FlowerD==2 && Flask.FlowerE==1) {	// rage
		skl[0]=V_RAGE; if ((val[0]=(power/Flask.Divisor)/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (!flag && Flask.FlowerCount) {
	    int doneA, doneB, doneC, doneD, doneE, doneF, doneG;
	    doneA=doneB=doneC=doneD=doneE=doneF=doneG=0;
	    skl[0]=-1; val[0]=0;
	    skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		for (n=0; n<3; n++) {
			if (!doneA && Flask.FlowerA>0) { skl[n]=V_WIS;          if ((val[n]=power*Flask.FlowerA/Flask.Divisor/Flask.FlowerCount/4)) {doneA=1; flag=1; continue; }}
			if (!doneB && Flask.FlowerB>0) { skl[n]=V_INT;          if ((val[n]=power*Flask.FlowerB/Flask.Divisor/Flask.FlowerCount/4)) {doneB=1; flag=1; continue; }}
			if (!doneC && Flask.FlowerC>0) { skl[n]=V_AGI;          if ((val[n]=power*Flask.FlowerC/Flask.Divisor/Flask.FlowerCount/4)) {doneC=1; flag=1; continue; }}
			if (!doneD && Flask.FlowerD>0) { skl[n]=V_STR;          if ((val[n]=power*Flask.FlowerD/Flask.Divisor/Flask.FlowerCount/4)) {doneD=1; flag=1; continue; }}
			if (!doneE && Flask.FlowerE>0) { skl[n]=V_HP;           if ((val[n]=power*Flask.FlowerE/Flask.Divisor/Flask.FlowerCount/2)) {doneE=1; flag=1; continue; }}
			if (!doneF && Flask.FlowerF>0) { skl[n]=V_MANA;         if ((val[n]=power*Flask.FlowerF/Flask.Divisor/Flask.FlowerCount/2)) {doneF=1; flag=1; continue; }}
			if (!doneG && Flask.FlowerG>0) { skl[n]=V_ENDURANCE;    if ((val[n]=power*Flask.FlowerG/Flask.Divisor/Flask.FlowerCount/2)) {doneG=1; flag=1; continue; }}
			skl[n]=-1; val[n]=0;
		}
        value = 1;
    } else {
        // nothing useful
        return 0;
    }

    if (!flag) {
        return 0;
    }

    Flask.ModA = skl[0];
    Flask.ValueA = val[0];
    Flask.ModB = skl[1];
    Flask.ValueB = val[1];
    Flask.ModC = skl[2];
    Flask.ValueC = val[2];


    return 1;
}




#endif // ALCHEMY_H_INCLUDED
