// Adventure Game: Escape the cave
#include <stdio.h>
#include <string.h>
int hasKey = 0;
int hasboots = 0;
// logic for the exit
void theexit() {
    printf("\nAfter several hours of crawling, you see light at the end of the hole you've been crawling through\n\n");
    printf("\"You breath the fresh air as you step out into the light. You've made it!\"\n CONGRATULATIONS!!!");
}
// logic for the door
void door() {
    if (hasKey) {
        printf("\n\nYou arrive at the door,inserting the key into the key hole the door creaks open to reveal a dark cavern,\nturning on the lantern,you discover a boulder blocking a way,looking closely at the boulder you discover that little light was able to pass through the gaps\nwhich could only mean one thing.THE EXIT\n");
        printf("But you can't move the boulder,which means there has to be another way out.Using the lantern,\nyou continued to search the cavern for another way,After several minutes of searching with no luck you go back to the boulder\n and behold you discover a hole beside the boulder just big enough for you fit through,\n trusting your intuition again you decided to use the hole.\n\n");
        theexit();
    }
}
// logic for picking up lantern
void ltpicking() {
    char decision2[40];
    while(1){
        printf("PICKUP THE LANTERN OR CONTINUE: ");
        fgets(decision2,sizeof(decision2),stdin);
        decision2[strcspn(decision2,"\n")] = '\0';
        //validation of input
        if(strcmp(decision2,"pickup")==0){
            printf("\nUsing the little illumination provided by the cave, you continue along a long straight path,\nYou then come across an entrance to a dark cavern,turning on the lantern,you discover a booby trap \"THANK GOODNESS YOU PICKED UP THE LANTERN\",\njumping over the trap you discover a boulder blocking a way,\nlooking closely at the boulder you discover that little light was able to pass through the gaps,which could only mean one thing.THE EXIT\n");
            printf("But you can't move the boulder,which means there has to be another way out.Using the lantern,you continued to search the cavern for another way,\nAfter several minutes of searching with no luck you go back to the boulder and behold you discover a hole beside the boulder just big enough\n for you to fit through,\n trusting your intuition again you decided to use the hole.\n\n");
            theexit();
            break;
        }else if(strcmp(decision2,"continue")==0) {
            printf("Ignoring the lantern and ");
            printf("using the little illumination provided by the cave, you continue along a straight path,\nYou then come across an entrance to a dark cavern, with no source of illumination you decide to go with your instinct\n");
            printf("After taking few steps, you step on something,immediately you feel something sharp and fast pass throught your chest,\n holding and feeling your chest you discover a hole in your chest, with blood rushing out and you falling slowly to the ground,\nyou realized what you stepped on\n \"A BOOBY TRAP\"\n\n");
            printf("You are given another chance\n");

        }else{
            printf("Invalid Choice. Input 'pickup' or 'continue'.\n\n");
        }
    }
}
//logic for right room
void rightroom() {
    char decision[20];
    while(1) {
        printf("PICKUP OR CONTINUE: ");
        fgets(decision, sizeof(decision),stdin);
        decision[strcspn(decision, "\n")] = '\0';
        //validation of input
        if (strcmp(decision,"pickup")==0){
            hasboots = 1;
            printf("\nYou pick up the boots and continue until you come across a wide-open cavern.\n There's a wide pit in the middle, and on the other side is a chest\n");
            if (hasboots){
                printf("As you near the pit, the boots you picked earlier begins to shine brightly,\n trusting your intuition, you put the boots on and decide to jump.\n");
                printf("The boot turns out to be a magical boot which gives you the ability to jump farther.\n With the help of the boots you make it to the other side of the pit and open the chest,\n and inside the chest you see a LANTERN.\n");
                ltpicking();
                break;
            }else{
                printf("You need the boots for this jump");
            }
        } else if (strcmp(decision,"continue")==0){
            printf("\nYou ignore the boots and continue until you come across a wide-open cavern.\n There's a wide pit in the middle, and on the other side is a chest\n");
            printf("You move near the pit,\n trusting your intuition, you decide to jump.\n\n");
            printf("You don't even make it to half of the pit before you fall and meet immediate death.\n");
            printf("You are given another chance\n");
            printf("SO........ ");
        } else{
            printf("Invalid choice. Input 'pickup' or 'continue'.\n");
        }
    }
}
// logic for riddle
void riddle(){
    char answer[50];
    char correctAnswer[]="echo";//answer to the riddle
    
    //loop till the user gets it
    while (1) {
        printf("\n\nThe riddle is \"I speak without a mouth and hear without ears.I have no body,but I come alive with the wind. What am I?\": ");
        fgets(answer, sizeof(answer),stdin);
        answer[strcspn(answer, "\n")] = '\0';
        //validation of input
        if (strcmp(answer,correctAnswer)==0){
            printf("\nCongratulations, you solved the riddle and the old man has given you the key and he also gives you a little lantern.");
                hasKey = 1;
                printf("You retrace your steps back to the door you saw earlier\n");
                door();//logic for the door
                break;
        }
        else{
            printf("Wrong answer.Try again\n");
        }
    }
}
//logic for footstep
void footstep(){
    char footstepchoice[20];
    printf("\nYou encounter an old man,\n He offers you a key in exchange for answering a riddle.\n You can choose to answer or walk away.\n");
    printf("SO WHAT WILL IT BE?....... RIDDLE OR WALKAWAY: ");
    while(1){
        //interaction for followiwng footstep
        fgets(footstepchoice,sizeof(footstepchoice),stdin);
        footstepchoice[strcspn(footstepchoice, "\n")] = '\0';
        //validation of input
        if (strcmp(footstepchoice,"riddle")==0){
            riddle();//logic for riddle
            break;        
        }
        else if (strcmp(footstepchoice,"walkaway")==0){
            printf("\nYou decline the oldman's offer and continue along a dark walkway,\n as you continue you fall into an abyss and DIE.\n\n YOU ARE GIVEN ANOTHER CHANCE\n");
            printf("SO WHAT WILL IT BE?....... RIDDLE OR WALKAWAY: ");
        }
        else {
            printf("Invalid Choice\n");
            printf("RIDDLE OR WALK AWAY: ");
        }
    }
}
//Logic for left room
void leftroom() {
    char choicee[10];
    while(1){
        //interactions in the left room
            printf("You have two choice: Try to open the door OR Follow the sound of the footsteps\n");
            printf("Choose either FOOTSTEP OR DOOR: ");
        fgets(choicee,sizeof(choicee),stdin);
        choicee[strcspn(choicee, "\n")] = '\0';

        //validation of input
        if (strcmp(choicee,"door")==0){
            if (hasKey){
                printf("Congratulation,you have the key,you can proceed\n");
                //logic for opening door later
                break;
            } else {
                printf("\nYou need a key to open this door.\n");
            }
        } 
            else if (strcmp(choicee, "footstep")==0) {
                printf("\nYou follow the footstep.\n\n");
                footstep();// footstep logic
                break;
            }else{
                printf("Invalid choice.\n");
            }
    }
}
void room1() {
        char choice [10];
        printf("\nYou wake up in a dark, cold cave. The\n sound of dripping water echoes around\n you.You have no memory of how you\n got here,but you know one thing-you\n need to escape\n\n");
        while(1){
           printf("You are presented with two paths \"Left or Right\", SO LEFT OR RIGHT: ");
           fgets(choice,sizeof(choice),stdin);
            choice[strcspn(choice, "\n")] = '\0' ; //Validates the input
            if (strcmp(choice, "left")==0){
                printf("\nYou enter a dimly lit passageway.\n There's a locked door and a faint sound of footsteps.\n");
                leftroom();// logic for left room
                break;
            } else if (strcmp(choice,"right")==0){
                printf("\nYou enter a dimly lit smaller cave.\n You continue and you come across a pair of weird looking boots.\n You have two choice\n");// condition for inputting right 
                rightroom();//logic the room on the right
                break;
            }else{
                printf("Invalid choice. Input 'left' or 'right'.\n");// condition for wrong choice
            } 
        }
}
int main() {
    room1();
    return 0;
}