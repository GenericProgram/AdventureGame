/* 
Aventure game
Dean Leon 4/12/24
A simple dugeoun crawler for engr 103
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>


// isvalidnumericalinput function, is a boolean so return true/false. if number is in expected range return true.
//sometime in future this function should also check for chars, for now that is done in displayoptions
bool isValidNumericalInput(int numberOfOptions, int input){
    if(input > numberOfOptions || input < 1){
        return false;
    } else {
        return true;
    }
}

//displayoptions function, displays options given a room, also checks if inputs given are chars returns choice integer
int displayOptions(int room, bool roomIsSearched) {
    int choice;
    if(room==0){
        //room 0 is entrance
        printf("\n1. Go into the dungeon\n2. Leave\n");
        scanf("%d", &choice);
        while(!isValidNumericalInput(2, choice)) {  //check for valid inout with 2 choices
            printf("Invalid input, try again.\n");
            scanf("%*[^\n]"); //check for chars
            scanf("%d", &choice);
        }
        return choice;
    }
    if(room==1){
        if(roomIsSearched == false) { //if room 1 is not searched
            printf("\n1. Search room\n2. Go east\n3. Go south\n4. Go north\n");
            scanf("%d", &choice);
            while(!isValidNumericalInput(4, choice)) {  
                printf("Invalid input, try again.\n");
                scanf("%*[^\n]");
                scanf("%d", &choice);
            }
            return choice;
        } else {
            printf("\n1. Go east\n2. Go south\n3. Go north\n");
            scanf("%d", &choice);
            while(!isValidNumericalInput(3, choice)) {  
                printf("Invalid input, try again.\n");
                scanf("%*[^\n]");
                scanf("%d", &choice);
            }
            return choice;
        }
    }
    if(room==2){
        if(roomIsSearched == false) {
            printf("\n1. Search room\n2. Go east\n3. Go north\n");
            scanf("%d", &choice);
            while(!isValidNumericalInput(3, choice)) {  
                printf("Invalid input, try again.\n");
                scanf("%*[^\n]");
                scanf("%d", &choice);
            }
            return choice;
        } else {
            printf("\n1. Go east\n2. Go north\n");
            scanf("%d", &choice);
            while(!isValidNumericalInput(2, choice)) {  
                printf("Invalid input, try again.\n");
                scanf("%*[^\n]");
                scanf("%d", &choice);
            }
            return choice;
        }
    }
    if(room==3) {
        if(roomIsSearched == false) {
            printf("\n1. Search room\n2. Go west\n3. Go south\n");
            scanf("%d", &choice);
            while(!isValidNumericalInput(3, choice)) {  
                printf("Invalid input, try again.\n");
                scanf("%*[^\n]");
                scanf("%d", &choice);
            }
            return choice;
        } else {
            printf("\n1. Go west\n2. Go south\n");
            scanf("%d", &choice);
            while(!isValidNumericalInput(2, choice)) {  
                printf("Invalid input, try again.\n");
                scanf("%*[^\n]");
                scanf("%d", &choice);
            }
            return choice;
        }
    }
    if(room==4){
        if(roomIsSearched == false){
            printf("\n1. Search room\n2. Go west\n3. Go north\n4. Invistigate door\n");
            scanf("%d", &choice);
            while(!isValidNumericalInput(4, choice)) {  
                printf("Invalid input, try again.\n");
                scanf("%*[^\n]");
                scanf("%d", &choice);
            }
            return choice;
        } else {
            printf("\n1. Go west\n2. Go north\n3. Invistigate door\n");
            scanf("%d", &choice);
            while(!isValidNumericalInput(3, choice)) {  
                printf("Invalid input, try again.\n");
                scanf("%*[^\n]");
                scanf("%d", &choice);
            }
            return choice;
        }
    }
    if(room==5){
        if(roomIsSearched == false) { //use the room searched feature to figure out whether player has key yet.
            printf("\n1. Go west\n");
            scanf("%d", &choice);
            while(!isValidNumericalInput(1, choice)) {  
                printf("Invalid input, try again.\n");
                scanf("%*[^\n]");
                scanf("%d", &choice);
            }
            return choice;
        } else {
            printf("\n1. Use the key on the door\n2. Go west\n");
            scanf("%d", &choice);
            while(!isValidNumericalInput(2, choice)) {  
                printf("Invalid input, try again.\n");
                scanf("%*[^\n]");
                scanf("%d", &choice);
            }
            return choice;
        }
    }
}

int main(){
    int room = 0; //where the player is in the dungeoun
    bool escaped = false;
    bool hasKey = false;
    bool exitDisovered = false;
    srand(time(NULL)); //reset seed for rand()
    int roomWithKey = rand() % (4 - 1 + 1) + 1; //generate a random int 1-4, this is how we determine what room has the key
    int choice; //the integer of player players choice, it should be fetched from displayOptions()
    bool room4searched = false; //booleans to check if the room is searched, purely for consistency
    bool room1searched = false; //I know it looks stupid having every boolean declared sepretaly but even tho the default bool is false it wouldnt register that
    bool room2searched = false;
    bool room3searched = false; 
    
    while(!escaped) {
        if(room==0) {
            printf("You find yourself at the entrance of a dungeoun. A hallway stands before you heading into darkness. (Use numeroical inputs Ex. 1 for option 1)");
            //printf(" %d", roomWithKey); used for testing, this will displayu the room that has the key inside of it
            if(displayOptions(0, false) == 1){ //display options for room 0 (entrance) but since there are only 2 choice here we can use just 1 if else
                room = 1;
            } else {
                printf("You turn around instantly stepping into a hole covered by leaves. You fall for an eternity securing your fate until the end of time. \nGAME OVER");
                return 0;
            }
        }
        if(room==1) {
            if(!room1searched) {
                printf("You find yourself in a room decorated with tapestries and decorative rugs. A chest sits in the corner. You could search it for supplies, or you there are paths leading east, south. Alternatively you could go back north.");
                choice = displayOptions(1, false); //display the options for room 1 with the room not searched
                if(choice == 1){
                    room1searched = true;
                    if(roomWithKey==1 && exitDisovered==false){ //check that room one is the keyed room, if it is, turn has key to true, if not nothin happens
                        printf("You find a crystaline key. It glimmers spectacularly in the light, now to find where it goes.\n");
                        hasKey = true;
                    } else if(roomWithKey==1) {
                        printf("You find a crystaline key. It glimmers spectacularly in the light, you should take it to the exit.\n");
                        hasKey = true;
                    } else {
                        printf("You find nothing. That was a waste of time.\n");
                    }
                } else if(choice == 2) {
                    room = 3;
                } else if(choice == 3) {
                    room = 2;
                } else if(choice == 4) {
                    room = 0;
                }
            } else { //room 1 is searched so don't display the searhc option again
                printf("You find yourself in a room decorated with tapestries and decorative rugs. The chest you searched sits in the corner, open. There are paths leading east, south. Alternatively you could go back north.");
                choice = displayOptions(1, true); //display options with searchedroom set to true
                if(choice == 1) {
                    room = 3;
                } else if(choice == 2) {
                    room = 2;
                } else if(choice == 3) {
                    room = 0;
                }
            }
        }
        if(room == 2){
            if(!room2searched) {
                printf("As soon as you enter this room you are blasted with heat. Lava flows down the walls. The tempereture in this room is unbearable, let's not try to stay in this room for too long... You can go back north or go east.");
                choice = displayOptions(2, false);
                if(choice == 1) { //search room
                    room2searched = true;
                    if(roomWithKey==2 && exitDisovered==false){ //check that room two is the keyed room, if it is, turn has key to true, if not nothing happens
                        printf("You find a crystaline key. It glimmers spectacularly in the light, now to find where it goes.\n");
                        hasKey = true;
                    } else if(roomWithKey==2) {
                        printf("You find a crystaline key. It glimmers spectacularly in the light, you should take it to the exit.\n");
                        hasKey = true;
                    } else {
                        printf("You search the lava room to no avail, nothing.\n");
                    }
                } else if(choice == 2) { //room 4
                    room = 4;
                } else if(choice == 3) { //back to room 1
                    room = 1;
                }
            } else { //room 2 is searched so don't display the search option again
                printf("As soon as you enter this room you are blasted with heat. Lava flows down the walls. You are reminded that you found nothing here. The tempereture in this room is unbearable, let's not try to stay in this room for too long... You can go back north or go east.");
                choice = displayOptions(2, true);
                if(choice == 1) {//go east
                    room = 4;
                } else if(choice == 2) {//go north
                    room = 1;
                }
            }
        }
        if(room == 3){
            if(!room3searched){
                printf("This room is dark and musty. Furniture covered in sheets scatter in every direction. An uneasy feeling fills the atmosphere.");
                choice = displayOptions(3, false);
                if(choice == 1) { //search room
                    room3searched = true;
                    if(roomWithKey==3 && exitDisovered==false){ //check that room three is the keyed room, if it is, turn has key to true, if not nothing happens
                        printf("Under one of the sheets you find a crystaline key. It glimmers spectacularly in the light, now to find where it goes.\n");
                        hasKey = true;
                    } else if(roomWithKey==3) {
                        printf("Under one of the sheets you find a crystaline key. It glimmers spectacularly in the light, you should take it to the exit.\n");
                        hasKey = true;
                    } else {
                        printf("You fling sheets of the furniture wildly, but never find anything of use.\n");
                    }
                } else if(choice == 2) {// go west
                    room = 1;
                } else if(choice == 3) {
                    room = 4;
                }
            } else { //room 3 is searched so don't display the search option again
                printf("This room is dark and musty. Sheets layer the floor around you from your recent frenzy. An uneasy feeling fills the atmosphere.");
                choice = displayOptions(3, true);
                if(choice == 1) {//go west
                    room = 1;
                } else if(choice == 2) {//go south
                    room = 4;
                }
            }  
        }
        if(room == 4){
            if(!room4searched){
                printf("THis room is... questionable. Pink shapes cover a yellow wallpaper with puffy orange carpet depressing under your feet. A green box sits on a table in the corner. You could search it or take another path out. Or you could invistigate the ominous door that stands at the end of the room.");
                choice = displayOptions(4, false);
                if(choice == 1) { //search room
                    room4searched = true;
                    if(roomWithKey==4 && exitDisovered==false){ //check that room four is the keyed room, if it is, turn has key to true, if not nothing happens
                        printf("In the box you find a crystaline key. It glimmers spectacularly in the light, now to find where it goes.\n");
                        hasKey = true;
                    } else if(roomWithKey==4) {
                        printf("In the box you find a crystaline key. It glimmers spectacularly in the light, you should take it to the exit.\n");
                        hasKey = true;
                    } else {
                        printf("You creep closer to the box, anticipating the treasures hiden inside, you can't wait any longer. You fling the box open and... nothing.\n");
                    }
                } else if(choice == 2) {// go west
                    room = 2;
                } else if(choice == 3) {//go north
                    room = 3;
                } else if(choice == 4) {//go door 
                    room = 5;
                }
            } else { // room 4 is searched
                printf("THis room is... questionable. Pink shapes cover a yellow wallpaper with puffy orange carpet depressing under your feet. The green box sits open on the table in the corner. You could also invistigate the ominous door that stands at the end of the room.");
                choice = displayOptions(4, true);
                if(choice == 1) {//go west
                    room = 2;
                } else if(choice == 2) {//go north
                    room = 3;
                } else if(choice == 3) { // go door (exit)
                    room = 5;
                }
            }
        }
        if(room==5){
            printf("You have found the exit.");
            exitDisovered = true;
            if(hasKey==true){
                printf(" The key in your hand glows bright. It's so bright its hard to look at.");
                choice = displayOptions(5, true);
                if(choice == 1){
                    printf("You enter the door and a bright light overwhelms you. You have escaped.");
                    escaped = true;
                } else {
                    room = 4;
                }
            } else {
                printf(" You observe the door and look at a at a keywhole. You need a key to get out.");
                choice = displayOptions(5, false);
                if(choice==1){
                    room = 4;
                }
            }
        }
    }
    return 0;
}