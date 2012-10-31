
//Initializes vars for the 8 pins for the horns
#include "hornpins.h"

//All of the various rhythm data in separate files
#include "carsData.h"

//Translates 0-20 quadrants to lat/long zones
#include "quadrants.h"

int limit, counter, pace, car, ticktock;

//Sample quadrants for testing
int carsDriving[10][4] = {
                        {19, 1, 11, 5},
                        {15, 2, 12, 3},
                        {11, 3, 13, 9},
                        {9, 4, 14, 8},
                        {2, 5, 15, 18},
                        {5, 6, 16, 12},
                        {6, 7, 17, 6},
                        {1, 8, 18, 3},
                        {2, 9, 19, 13},
                        {3, 10, 1, 2}
                                        };

//translates 0s and 1s to pinMode
int onoff[2] = {LOW, HIGH};

void setup() {                

initializePins();
  
  Serial.begin(9600);
  
  //96 / 8 = 12 seconds
  limit = 96;
  
  //begin counting from 0;
  counter = 0;
  
  //1000 / 8 = 125, which is a 1/8th second pause or note
  pace = 125;
  
}


void loop() {
  
  //Reset counter to 0 if limit is reached
  if(counter >= limit) {
    counter = 0;
    ticktock++;
    if(ticktock >= 10) {
      ticktock = 0;
    }
  }
  
  Serial.println(counter);
  Serial.println(carsDriving[ticktock][0]);
  Serial.println(carsDriving[ticktock][1]);
  Serial.println(carsDriving[ticktock][2]);
  Serial.println(carsDriving[ticktock][3]);
  Serial.println("--");  
  //count up by one
  counter++;
 
  for(int i = 0; i < 4; i++) {
  
    //Send car# and lat-specific zone #
    playLattitude(i, quadrants[carsDriving[ticktock][i]][0]);
  
    //Send car# and lat-specific zone #
    playLongitude(i, quadrants[carsDriving[ticktock][i]][1]);    

    }
 
        
  //Hold for 1/8th of a minute, or 125 milliseconds
  delay(pace);
 
}

