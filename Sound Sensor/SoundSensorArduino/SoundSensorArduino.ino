//int input_pin = null;      //won't be using right now.
int output_pin = 11;
int sound_sensor_pin = A0;

const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

void setup() {
  //Just for debugging:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  unsigned long startMillis = millis();  // Start of sample window
  unsigned int peakToPeak = 0;   // peak-to-peak level
   
  unsigned int signalMax = 0;
  unsigned int signalMin = 1024;
   
  // collect data for 50 mS
  while (millis() - startMillis < sampleWindow)
  {
     sample = analogRead(sound_sensor_pin);
     
     if (sample < 1024)  // toss out spurious readings
     {
        if (sample > signalMax)
        {
           signalMax = sample;  // save just the max levels
        }
        else if (sample < signalMin)
        {
           signalMin = sample;  // save just the min levels
        }
     }
  }
  
  peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
  double volts = (peakToPeak * 10) / 1024;  // convert to volts
   
  int out_value = map(volts, 0.0, 10, 0, 255);
  analogWrite(output_pin, out_value);
  
  Serial.println(volts);
}
