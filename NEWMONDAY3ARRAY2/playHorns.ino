

//car doubles as array index for hornsLattitude[]
void playLattitude(int car, int l) {
  
  digitalWrite(hornsLattitude[car], onoff[carsLattitude[car][l][counter]]);
 
}


//car doubles as array index for hornsLongitude[]
void playLongitude(int car, int l) {
  
  digitalWrite(hornsLongitude[car], onoff[carsLongitude[car][l][counter]]);
  
}


