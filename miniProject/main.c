#include <stdio.h>
#include <stdlib.h>

// ________________________________________Structures section

//une structure Race 
typedef struct {
	int numberOfLaps ;
	int currentLap ;
	char firstPlaceDriverName [30];
	char firstPlaceRaceCarColor [30];
}Race;

//structure racecare
typedef struct{
		char driveName[30];
		char raceCarColor[30];
		int totalLapTime ;
	}RaceCar;
	
// _________________________________________________________________________________________Print functions section
	
// function Print Intro
void printIntro(){
	printf("Bienvenue � notre �v�nement principal, les fans de course num�rique !\n J'esp�re que tout le monde a pris son go�ter car nous allons commencer ! \n");
}
// function compte a rebours ;
void printCountDown(){
  int count =5;
  printf("Coureurs pr�ts ! Dans...");
  while(count>=0){
  	printf("\n %d ",count);
  	count--;
  	sleep(2);
  	//System("clear");
  }
  printf("\n Course !");
  }

//la function pour affiche La premi�re place dons un tour
void printFirstPlaceAfterLAp(Race race ){
	printf("Apr�s le tour num�ro %d La premi�re place est occup�e par : %s dans la voiture de course %s !",race.currentLap,race.firstPlaceDriverName,race.firstPlaceRaceCarColor);
		
}


// la course termine nous devons f�liciter le gagnant et dire au public que la course est termin�e
void printCongratulation(Race race){
		printf(" F�licitons tous %S, dans la voiture de course %s, pour son incroyable performance.'�tait vraiment une belle course et bonne nuit � tous ! ",race.firstPlaceDriverName,race.firstPlaceRaceCarColor);
}


// la function calculate Time To Complete un tour 
 int calculateTimeToCompleteLap(){
 	int vitesse, acceleration,nerves ;
 	vitesse = (rand()%3) +1 ;
 	acceleration=(rand()%3) +1 ;
 	nerves=(rand()%3) +1 ;
 	switch(nerves)
	 {
	 	case 1 :
	 		nerves = 3 ;
	 		break ;
	 	case 2 :
	 		nerves = 2 ;
	 		break ;
	 	case 3 : 
	 	    nerves = 1 ;
	 	    break ;
	 }
 	vitesse = vitesse + acceleration + nerves ;
 	return vitesse ;
 }
//_________________________________________________________________________________________ Logic functions section
//(((((((((((((((((((

void updateRaceCar(RaceCar *raceCare){
	raceCare->totalLapTime+= calculateTimeToCompleteLap();
}

//((((((((((((((((((

//function up date First Place 
void updateFirstPlace(Race *race, RaceCar *raceCare1 , RaceCar *raceCare2)
{
	if(raceCare1 -> totalLapTime <= raceCare2-> totalLapTime)
	{
	strcpy(race->firstPlaceDriverName , raceCare1 ->driveName );
	strcpy(race->firstPlaceRaceCarColor , raceCare1->driveName );
	
	}
	else 
	{
		strcpy(race->firstPlaceDriverName , raceCare2 ->driveName );
	strcpy(race->firstPlaceRaceCarColor , raceCare2->driveName );
	}
}

//(((((((((((((((((((
void startRace(RaceCar *racecar1 ,RaceCar *racecar2)
 {	
 
     Race race;
	 race.numberOfLaps = 5 ;
	 race.currentLap=1 ;
	strcpy(race.firstPlaceDriverName,"") ;
	strcpy( race.firstPlaceRaceCarColor ,"");
 
 	int i ;
 	for ( i =0 ;i<race.numberOfLaps;i++)
	 {
	 	updateRaceCar(racecar1);
	 	updateRaceCar(racecar2);
	 }
	 updateFirstPlace(&race,racecar1,racecar2);
	 printCongratulation(race);
 }

//________________________________________________________________________________________________________MAin
int main()
{
	RaceCar carA ={"Youssef","Red",0};
	RaceCar carB ={"Saad","Black",0};
	printIntro();
	printCountDown();
	startRace(&carA,&carB);
	srand(time(NULL));
}
