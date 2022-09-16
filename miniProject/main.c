#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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
	printf("Bienvenue à notre événement principal, les fans de course numérique !\n J'espère que tout le monde a pris son goûter car nous allons commencer ! \n");
}
// function compte a rebours ;
void printCountDown(){
  int count =5;
  printf("Coureurs prets ! Dans...");
  while(count>=0){
  	printf("\n %d ",count);
  	count--;
  	sleep(1);
  }
  printf("\n Course !");
  }

//la function pour affiche La première place dons un tour
void printFirstPlaceAfterLAp(Race race ){
	printf("Apres le tour numero %d La premiere place est occupee par : %s dans la voiture de course %s ! \n",race.currentLap,race.firstPlaceDriverName,race.firstPlaceRaceCarColor);
		
}


// la course termine nous devons féliciter le gagnant et dire au public que la course est terminée
void printCongratulation(Race race){
		printf(" Felicitons tour %s, dans la voiture de course %s, pour son incroyable performance.etait vraiment une belle course et bonne nuit a tous ! ",race.firstPlaceDriverName,race.firstPlaceRaceCarColor);
}


// la function calculate Time To Complete un tour 
 int calculateTimeToCompleteLap(){
 	int vitesse, acceleration,nerves ;
 	vitesse = rand()%10 +1 ;
 	acceleration=rand()%10 +1 ;
 	nerves=rand()%10 +1 ;
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
	strcpy(race->firstPlaceRaceCarColor , raceCare1->raceCarColor );
	
	}
	else 
	{
		strcpy(race->firstPlaceDriverName , raceCare2 ->driveName );
	strcpy(race->firstPlaceRaceCarColor , raceCare2-> raceCarColor);
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
		updateFirstPlace(&race,racecar1,racecar2);
	 	printFirstPlaceAfterLAp(race);
	 	race.currentLap+=1 ;
	 }
	 
	 
	 printCongratulation(race);
 }

//________________________________________________________________________________________________________MAin
int main()
{
	srand(time(NULL));
	RaceCar carA ={"Youssef","Red",0};
	RaceCar carB ={"Saad","Black",0};
	system("COLOR 0C");
	printIntro();
	printCountDown();
	system("cls");
	system("COLOR 1F");
	startRace(&carA,&carB);
	
}
