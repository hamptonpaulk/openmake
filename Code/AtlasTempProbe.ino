
float temp;                //where the final temperature data is stored

void setup() {             //main loop
Serial.begin(38400);       //set up the hardware serial port to run at 38400
pinMode(2, OUTPUT);        //set pin 2 as an output
}


void loop() {
temp = read_temp();       //call the function “read_temp” and return the temperature in C°
Serial.println(temp);     //print the temperature data
delay(1000);              //wait 1000ms before we do it again
}

float read_temp(void){   //the read temperature function
float v_out;             //voltage output from temp sensor 
float temp;              //the final temperature is stored here
digitalWrite(A0, LOW);   //set pull-up on analog pin
digitalWrite(2, HIGH);   //set pin 2 high, this will turn on temp sensor
delay(2);                //wait 2 ms for temp to stabilize
v_out = analogRead(0);   //read the input pin
digitalWrite(2, LOW);    //set pin 2 low, this will turn off temp sensor
v_out*=.0048;            //convert ADC points to volts (we are using .0048 because this device is running at 5 volts)
v_out*=1000;             //convert volts to millivolts
temp= 0.0512 * v_out -20.5128; //the equation from millivolts to temperature
return temp;             //send back the temp
}



