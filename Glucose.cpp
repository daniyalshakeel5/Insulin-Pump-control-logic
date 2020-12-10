#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>
using namespace std;
bool Button = false;

//This function is looking for a keypress to cycle the program
void Logic(){
	if(_kbhit){
		switch(_getch()){
		
						//there might be some residue code here for a start and stop function
			case 'c':
				Button = true;
				break;
					
		}
	}
	
}
// windows rand API used for sensor RNG
void sugarLevel(){
	int buzzer=7; //using this as an ASCII charecter to trigger the PC speaker, won't work properly on laptops
	int randomNumber;
	srand(time(0));
	randomNumber = rand() % 6; //this gives a random number between 0 to 5
	
	if(randomNumber<=1){
		cout<<"Low blood sugar detected, consume something sweet" << endl;
		printf("%c",buzzer);// this will make an audio alert whenever sugar level is too low. don't know if it's an API call
		cout <<"data recorded to log file \n";
		//we'll make hardwere API calls to run the pump here
		
	}
	else if (randomNumber >= 3){
		cout <<"High blood sugar detected, Insoline pump set to active" << endl;
		cout <<"data recorded to log file \n";
		//hardwere API calls to run the pump
	}
	else{
		cout << "blood sugar level normal " <<endl;
	}
	
			
}


//since this is an infinite loop we are using a user command to 
//manually cycle the program.
int main(int argc, char** argv) {
	cout <<"please press 'C' to cycle the program " << endl;
	cout<<"you can close the window to stop the program"<< endl;
	
	
	for(;;){ //this generates an infinite for loop
		Logic();
		sugarLevel();
		Sleep(5);
	}
	
}




















//   this program is made by Daniyal shakeel



