
int mixer_mix(int cn,int in,int power,int duration,double divi)
{
	//int Flask.Count,Flask.FlowerA,Flask.FlowerB,Flask.FlowerC,Flask.FlowerD,Flask.FlowerE,Flask.FlowerF,Flask.FlowerG,fire,ice,hell;
	int skl[3],val[3];
	int n,value,flag=0;

	if (!duration || duration==-1 || !power || power==-1 || !divi) {
		return 0;
	}

//	Flask.FlowerA=it[in].drdata[11];
//	Flask.FlowerB=it[in].drdata[12];
//	Flask.FlowerC=it[in].drdata[13];
//	Flask.FlowerD=it[in].drdata[14];
//	Flask.FlowerE=it[in].drdata[15];
//	Flask.FlowerF=it[in].drdata[16];
//	Flask.FlowerG=it[in].drdata[17];

        //Flask.Count=Flask.FlowerA+Flask.FlowerB+Flask.FlowerC+Flask.FlowerD+Flask.FlowerE+Flask.FlowerF+Flask.FlowerG;

	fire=it[in].drdata[31];
	ice=it[in].drdata[32];
	hell=it[in].drdata[34];

	power+=fire*4;
	power+=ice*8;
	power+=hell*12;

	if (Flask.PPS>=5) power+=2;
	if (Flask.PPS>=10) power+=2;
	if (Flask.PPS>=15) power+=4;
	if (Flask.PPS>=25) power+=4;

	//log_char(cn,LOG_SYSTEM,0,"Final Power: %d",power);

        if (Flask.Count==5 && Flask.FlowerA==1 && Flask.FlowerB==1 && Flask.FlowerC==2 && Flask.FlowerD==1) {		// sword attack parry
		skl[0]=V_SWORD; if ((val[0]=power/divi/4)) flag=1;
		skl[1]=V_ATTACK; val[1]=power/divi/4;
		skl[2]=V_PARRY; val[2]=power/divi/4;
		value=10;
	} else if (Flask.Count==5 && Flask.FlowerA==1 && Flask.FlowerB==1 && Flask.FlowerC==1 && Flask.FlowerD==2) {	// two-handed attack parry
		skl[0]=V_TWOHAND; if ((val[0]=power/divi/4)) flag=1;
		skl[1]=V_ATTACK; val[1]=power/divi/4;
		skl[2]=V_PARRY; val[2]=power/divi/4;
		value=10;
	} else if (Flask.Count==5 && Flask.FlowerC==1 && Flask.FlowerD==2 && Flask.FlowerE==1 && Flask.FlowerF==1) {	// attack parry immunity
		skl[0]=V_ATTACK; if ((val[0]=power/divi/4)) flag=1;
		skl[1]=V_PARRY; val[1]=power/divi/4;
		skl[2]=V_IMMUNITY; val[2]=power/divi/4;
		value=10;
	} else if (Flask.Count==5 && Flask.FlowerB==1 && Flask.FlowerD==1 && Flask.FlowerE==2 && Flask.FlowerF==1) {	// flash magic-shield immunity
		skl[0]=V_FLASH; if ((val[0]=power/divi/4)) flag=1;
		skl[1]=V_MAGICSHIELD; val[1]=power/divi/4;
		skl[2]=V_IMMUNITY; val[2]=power/divi/4;
		value=10;
	} else if (Flask.Count==5 && Flask.FlowerD==2 && Flask.FlowerE==2 && Flask.FlowerF==1) {		// fire magic-shield immunity
		skl[0]=V_FIRE; if ((val[0]=power/divi/4)) flag=1;
		skl[1]=V_MAGICSHIELD; val[1]=power/divi/4;
		skl[2]=V_IMMUNITY; val[2]=power/divi/4;
		value=10;
	} else if (Flask.Count==4 && Flask.FlowerA==1 && Flask.FlowerB==1 && Flask.FlowerC==1 && Flask.FlowerD==1) {	// attack parry
		skl[0]=V_ATTACK; if ((val[0]=power/divi/3)) flag=1;
		skl[1]=V_PARRY; val[1]=power/divi/3;
		skl[2]=-1; val[2]=0;
		value=8;
	} else if (Flask.Count==4 && Flask.FlowerB==1 && Flask.FlowerD==1 && Flask.FlowerE==1 && Flask.FlowerF==1) {	// flash immunity
		skl[0]=V_FLASH; if ((val[0]=power/divi/3)) flag=1;
		skl[1]=V_IMMUNITY; val[1]=power/divi/3;
		skl[2]=-1; val[2]=0;
		value=8;
	} else if (Flask.Count==4 && Flask.FlowerD==2 && Flask.FlowerE==1 && Flask.FlowerF==1) {	// fire immunity
		skl[0]=V_FIRE; if ((val[0]=power/divi/3)) flag=1;
		skl[1]=V_IMMUNITY; val[1]=power/divi/3;
		skl[2]=-1; val[2]=0;
		value=8;
	} else if (Flask.Count==4 && Flask.FlowerD==1 && Flask.FlowerE==2 && Flask.FlowerF==1) {		// magic shield immunity
		skl[0]=V_MAGICSHIELD; if ((val[0]=power/divi/3)) flag=1;
		skl[1]=V_IMMUNITY; val[1]=power/divi/3;
		skl[2]=-1; val[2]=0;
		value=10;
	} else if (Flask.Count==4 && Flask.FlowerC==1 && Flask.FlowerG==1 && Flask.FlowerE==1 && Flask.FlowerF==1) {	// dagger flash
		skl[0]=V_DAGGER; if ((val[0]=power/divi/3)) flag=1;
		skl[1]=V_FLASH; val[1]=power/divi/3;
		skl[2]=-1; val[2]=0;
		value=8;
	} else if (Flask.Count==4 && Flask.FlowerC==1 && Flask.FlowerD==1 && Flask.FlowerG==1 && Flask.FlowerF==1) {	// dagger fire
		skl[0]=V_DAGGER; if ((val[0]=power/divi/3)) flag=1;
		skl[1]=V_FIRE; val[1]=power/divi/3;
		skl[2]=-1; val[2]=0;
		value=8;
	} else if (Flask.Count==4 && Flask.FlowerC==1 && Flask.FlowerD==1 && Flask.FlowerE==1 && Flask.FlowerF==1) {	// staff flash
		skl[0]=V_STAFF; if ((val[0]=power/divi/3)) flag=1;
		skl[1]=V_FLASH; val[1]=power/divi/3;
		skl[2]=-1; val[2]=0;
		value=8;
	} else if (Flask.Count==4 && Flask.FlowerC==1 && Flask.FlowerD==2 && Flask.FlowerF==1) {		// staff fire
		skl[0]=V_STAFF; if ((val[0]=power/divi/3)) flag=1;
		skl[1]=V_FIRE; val[1]=power/divi/3;
		skl[2]=-1; val[2]=0;
		value=8;
	} else if (Flask.Count==3 && Flask.FlowerC==2 && Flask.FlowerG==1) {			// dagger
		skl[0]=V_DAGGER; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerC==1 && Flask.FlowerD==1 && Flask.FlowerG==1) {		// staff
		skl[0]=V_STAFF; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerC==2 && Flask.FlowerD==1) {			// sword
		skl[0]=V_SWORD; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerC==1 && Flask.FlowerD==2) {			// two-handed
		skl[0]=V_TWOHAND; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerB==1 && Flask.FlowerC==1 && Flask.FlowerD==1) {		// attack
		skl[0]=V_ATTACK; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerA==1 && Flask.FlowerC==1 && Flask.FlowerD==1) {		// parry
		skl[0]=V_PARRY; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerB==2 && Flask.FlowerG==1) {			// perception
		skl[0]=V_PERCEPT; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerB==2 && Flask.FlowerC==1) {			// stealth
		skl[0]=V_STEALTH; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerC==2 && Flask.FlowerG==1) {			// speed
		skl[0]=V_SPEED; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerC==1 && Flask.FlowerG==1 && Flask.FlowerF==1) {		// freeze
		skl[0]=V_FREEZE; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerE==2 && Flask.FlowerF==1) {			// magic shield
		skl[0]=V_MAGICSHIELD; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerB==1 && Flask.FlowerE==1 && Flask.FlowerF==1) {		// flash
		skl[0]=V_FLASH; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerD==1 && Flask.FlowerE==1 && Flask.FlowerF==1) {		// fireball
		skl[0]=V_FIRE; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} /*else if (Flask.Count==3 && Flask.FlowerA==1 && Flask.FlowerE==1 && Flask.FlowerF==1) {		// ball
		skl[0]=V_BALL; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} */else if (Flask.Count==3 && Flask.FlowerD==2 && Flask.FlowerF==1) {		// immunity
		skl[0]=V_IMMUNITY; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerC==1 && Flask.FlowerD==1 && Flask.FlowerE==1) {	// hand to hand
		skl[0]=V_HAND; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerB==1 && Flask.FlowerD==1 && Flask.FlowerG==1) {	// warcry
		skl[0]=V_WARCRY; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerA==1 && Flask.FlowerB==1 && Flask.FlowerC==1) {	// tactics
		skl[0]=V_TACTICS; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerB==1 && Flask.FlowerC==2) {	// surround hit
		skl[0]=V_SURROUND; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerA==1 && Flask.FlowerB==2) {	// bartering
		skl[0]=V_BARTER; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerA==1 && Flask.FlowerB==1 && Flask.FlowerF==1) {	// bless
		skl[0]=V_BLESS; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerA==1 && Flask.FlowerB==1 && Flask.FlowerE==1) {	// heal
		skl[0]=V_HEAL; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerE==1 && Flask.FlowerF==2) {	// duration
		skl[0]=V_DURATION; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count==3 && Flask.FlowerD==2 && Flask.FlowerE==1) {	// rage
		skl[0]=V_RAGE; if ((val[0]=power/divi/2)) flag=1;
		skl[1]=-1; val[1]=0;
		skl[2]=-1; val[2]=0;
		value=3;
	} else if (Flask.Count) {
		for (n=0; n<3; n++) {
			if (Flask.FlowerA) { skl[n]=V_WIS; if ((val[n]=power*Flask.FlowerA/divi/Flask.Count/4)) flag=1; Flask.FlowerA=0; continue; }
			if (Flask.FlowerB) { skl[n]=V_INT; if ((val[n]=power*Flask.FlowerB/divi/Flask.Count/4)) flag=1; Flask.FlowerB=0; continue; }
			if (Flask.FlowerC) { skl[n]=V_AGI; if ((val[n]=power*Flask.FlowerC/divi/Flask.Count/4)) flag=1; Flask.FlowerC=0; continue; }
			if (Flask.FlowerD) { skl[n]=V_STR; if ((val[n]=power*Flask.FlowerD/divi/Flask.Count/4)) flag=1; Flask.FlowerD=0; continue; }
			if (Flask.FlowerE) { skl[n]=V_HP; if ((val[n]=power*Flask.FlowerE/divi/Flask.Count/2)) flag=1; Flask.FlowerE=0; continue; }
			if (Flask.FlowerF) { skl[n]=V_MANA; if ((val[n]=power*Flask.FlowerF/divi/Flask.Count/2)) flag=1; Flask.FlowerF=0; continue; }
			if (Flask.FlowerG) { skl[n]=V_ENDURANCE; if ((val[n]=power*Flask.FlowerG/divi/Flask.Count/2)) flag=1; Flask.FlowerG=0; continue; }
			skl[n]=-1; val[n]=0;
		}
		value=1;
	} else {
		// nothing useful
		return 0;
	}

    if (!flag) {
        return 0;
    }

    it[in].mod_index[0] = skl[0];
    it[in].mod_value[0] = val[0];
    it[in].mod_index[1] = skl[1];
    it[in].mod_value[1] = val[1];
    it[in].mod_index[2] = skl[2];
    it[in].mod_value[2] = val[2];

    it[in].drdata[3] = duration;





        return 1;
}