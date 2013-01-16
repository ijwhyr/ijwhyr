/*


In this tab, we're gonna write our own functions.

*/

//-- this function will create a white line

void whiteLine(){
  lineLength = random(40,100);
  stroke(255,255,255,10);
  line(0,0,100,lineLength);
}

void rotateEverything(){
    //translate everything to the exact middle of the stage
  translate(width/2,height/2);
    //rotate stage
  rotate(radians(counter));
  counter+=0.1;
}
