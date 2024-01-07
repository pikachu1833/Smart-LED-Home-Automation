// C++ code

int flag = 1;

void setup()
{
    // pinMode(2, INPUT);
    pinMode(3, OUTPUT);
    pinMode(A0, INPUT);
    flag = 1;
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
    pinMode(triggerPin, OUTPUT); // Clear the trigger
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);

    // Sets the trigger pin to HIGH state for 10 microseconds
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    pinMode(echoPin, INPUT);

    // Reads the echo pin and returns the sound wave travel time in microseconds
    return pulseIn(echoPin, HIGH);
}

void loop()
{
    if (flag > 0)
    {
        analogWrite(3, (255 - map(analogRead(A0), 6, 930, 0, 255)));
    }
    delay(10); // Delay a little bit to improve simulation performance
}
