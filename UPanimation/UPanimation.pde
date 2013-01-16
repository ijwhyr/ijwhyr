import processing.serial.*;
int lf = 10;    // Linefeed in ASCII
String myString = null;
Serial myPort;  // Serial port you are using
float num;
float lineLength = 40;
float redLineNoise = 0.004;//increase or decrease this value to affectthe change
float variation;
int changeColor=255;
float counter=1;

void setup() {
  noStroke();
  size(displayWidth,displayHeight);
  myPort = new Serial(this, Serial.list()[0], 9600);
  myPort.clear();
  background(192,64,0);
}

void draw() {
  while (myPort.available() > 0) {
  myString = myPort.readStringUntil(lf);
  if (myString != null) {
  print(myString);  // Prints String
  num=float(myString);  // Converts and prints float
  println(num);
    }

      
  rotateEverything();
  whiteLine();

  if (num<50){//WHITE
    noStroke();
    fill(255,255,255,100);
    stroke(0,0,0,50);
    ellipse(num,100,num,num);
    ellipse(num,200,num,num);
    noFill();
    line(num,num,displayWidth/2,displayHeight/2); 
    
  } else if(num<100){//WHITE
    noStroke();
    fill(255,255,255,100);
    stroke(0,0,0,50);
    ellipse(num,100,num,num);
    ellipse(num,200,num,num);
    noFill();
    line(num,num,displayWidth/2,displayHeight/2);
    
  } else if(num<200){//GREEN
    noStroke();
    fill(169,196,6,100);
    stroke(0,0,0,50);
    ellipse(num,100,num,num);
    ellipse(num,200,num,num);
    noFill();
    line(num,num,displayWidth/2,displayHeight/2);   
    
  } else if(num<400){//RED
    noStroke();
    fill(255,255-num,255-num,10);
    stroke(0,0,0,50);
    ellipse(num,100,num,num);
    ellipse(num,200,num,num);
    noFill();
    line(num,num,displayWidth/2,displayHeight/2);  
  }
  else {//TEAL
    stroke(0,0,0,10);
    fill(0,100,100,20);
    stroke(0,0,0,50);
    ellipse(num,100,num,num);
    ellipse(num,200,num,num);
    noFill();
    line(num,num,displayWidth/2,displayHeight/2);  
}}
  myPort.clear();
} 

