# Mobile(accelermtr)-controlled-bot-with-Blink
A bot is moving forward,backward,left,right and stop for holding the mobile-phone with different angles. 

Check the project demo on my [Linkedin Page](https://www.linkedin.com/posts/manish-pakhira-bb7333171_gyroscope-nodemcu-blynk-activity-6623178485751996416-1Gc7/).

**Coding Part:**

```

#define BLYNK_PRINT Serial
//#include <SimpleTimer.h> 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
float x;
float y;
float z;

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "cT4RiwYqpmx6_YVWkw8h2zcxFk3Ddt7Z";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Huawei Y9 Prime";        //the name of hotspot where the node MCU will be connected
char pass[] = "123454321";            // password of the hotspot

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(D0,OUTPUT);
  pinMode(D2,OUTPUT);
  Blynk.begin(auth, ssid, pass);
}
  BLYNK_WRITE(V1)
  {// acceleration force applied to axis x
  x = param[0].asFloat();
  // acceleration force applied to axis y
  y = param[1].asFloat();
  // acceleration force applied to axis z
  z = param[2].asFloat();
  /*Serial.print("x =");
  Serial.print(x);
  Serial.print(",y= ");
  Serial.print(y);
  Serial.print(",z= ");
  Serial.print(z);
  Serial.println("");*/
 
  }

void loop()
{
  Blynk.run();
  //timer.run();
  Serial.print("x=>> ");
  Serial.print(x);
  Serial.print(",y=>> ");
  Serial.print(y);
  Serial.print(",z=>> ");
  Serial.print(z);
  Serial.println("");
   if(y<1)
 {digitalWrite(D0,HIGH);//FW
  digitalWrite(D2,HIGH);

    }
  else if(z<5)
 {digitalWrite(D0,LOW);//LF
  digitalWrite(D2,HIGH);

    }
  else if(x<0)
 {digitalWrite(D0,HIGH);//RG
  digitalWrite(D2,LOW);

    }
  else if(9<=y<=10)
 {digitalWrite(D0,LOW);//STOP
  digitalWrite(D2,LOW);

    }
}

```
