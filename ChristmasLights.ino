// Pin assignation
const int topRoof = 2;
const int topLeftWindow = 3;
const int topCenterWindow = 4;
const int topRightWindow = 5;
const int bottomRoof = 6;
const int bottomLeftWindow = 7;
const int bottomRightWindow = 8;
const int border = 9;

const int buttonPin = 12;

const int ledPin = 13;

const int analogPin = A4;

long startTime, elapsedTime, currentMs;

int minimumValue = 10000;
int maximumValue = 0;

const int sampleSize = 1000;
int counter = 0;

bool waitingSong = false;

void WindowsRotate(double totalTime, bool clockWise = true, int repeat = 1)
{
    // Total required time for the animation
    int time = static_cast<int>(totalTime) / 5;
    // Calculates difference after dividing, to delay and get exact time
    int delta = static_cast<int>(totalTime) % 5;

    for (int i = 0; i < repeat; i++)
    {
        if (clockWise)
        {
            digitalWrite(topCenterWindow, LOW);
            delay(time);
            digitalWrite(topCenterWindow, HIGH);
            digitalWrite(topRightWindow, LOW);
            delay(time);
            digitalWrite(topRightWindow, HIGH);
            digitalWrite(bottomRightWindow, LOW);
            delay(time);
            digitalWrite(bottomRightWindow, HIGH);
            digitalWrite(bottomLeftWindow, LOW);
            delay(time);
            digitalWrite(bottomLeftWindow, HIGH);
            digitalWrite(topLeftWindow, LOW);
            delay(time);
            digitalWrite(topLeftWindow, HIGH);
            delay(delta);
        }
        else
        {
            digitalWrite(topCenterWindow, LOW);
            delay(time);
            digitalWrite(topCenterWindow, HIGH);
            digitalWrite(topLeftWindow, LOW);
            delay(time);
            digitalWrite(topLeftWindow, HIGH);
            digitalWrite(bottomLeftWindow, LOW);
            delay(time);
            digitalWrite(bottomLeftWindow, HIGH);
            digitalWrite(bottomRightWindow, LOW);
            delay(time);
            digitalWrite(bottomRightWindow, HIGH);
            digitalWrite(topRightWindow, LOW);
            delay(time);
            digitalWrite(topRightWindow, HIGH);
            delay(delta);
        }

    }
}

void blinkRandom(int state = HIGH, int repeat = 1)
{
    for (int i = 0; i < repeat; i++)
    {
        int pinState;
        int light;
        srand(static_cast<unsigned>(millis()));
        do
        {
            light = (rand() % 8) + 2;
            pinState = digitalRead(light);
        } while (pinState != state);

        pinState ^= 1;
        digitalWrite(light, pinState);
        delay(100);
        pinState ^= 1;
        digitalWrite(light, pinState);
    }
}

void blinkRandomLong()
{
    int state = LOW;
    int pinState;
    int light;
    srand(static_cast<unsigned>(millis()));
    do
    {
        light = (rand() % 8) + 2;
        pinState = digitalRead(light);
    } while (pinState != state);

    pinState ^= 1;
    digitalWrite(light, pinState);
    delay(2000);
    pinState ^= 1;
    digitalWrite(light, pinState);
}

void blinkBorderExtra(double timeBorder, double timeExtra = 0, int repeat = 1)
{
    //boolean ledState = digitalRead(bottomRoof);
    //ledState ^= 1;

    for (int i = 0; i < repeat; i++)
    {
        double currentTimeBorder = timeBorder;
        double currentTimeExtra = timeExtra;
        digitalWrite(bottomRoof, LOW);
        digitalWrite(topRoof, LOW);
        digitalWrite(border, LOW);
        if (currentTimeExtra > 0)
        {
            currentTimeBorder -= 200;
            delay(currentTimeBorder - currentTimeExtra);
            blinkRandom();
            delay(currentTimeBorder - currentTimeExtra);
        }
        else
        {
            currentTimeBorder -= 100;
            delay(currentTimeBorder);
        }
        digitalWrite(bottomRoof, HIGH);
        digitalWrite(topRoof, HIGH);
        digitalWrite(border, HIGH);
        delay(100);
    }
}

void allOff(double totalTime = 0)
{
    digitalWrite(bottomRoof, HIGH);
    digitalWrite(bottomLeftWindow, HIGH);
    digitalWrite(bottomRightWindow, HIGH);
    digitalWrite(topLeftWindow, HIGH);
    digitalWrite(topCenterWindow, HIGH);
    digitalWrite(topRightWindow, HIGH);
    digitalWrite(topRoof, HIGH);
    delay(totalTime);
}

void allOn(double totalTime = 0, int repeat = 1, bool extra = false)
{
    for (int i = 0; i < repeat; i++)
    {
        digitalWrite(bottomRoof, LOW);
        digitalWrite(bottomLeftWindow, LOW);
        digitalWrite(bottomRightWindow, LOW);
        digitalWrite(topLeftWindow, LOW);
        digitalWrite(topCenterWindow, LOW);
        digitalWrite(topRightWindow, LOW);
        digitalWrite(topRoof, LOW);
        if (extra)
        {
            delay(totalTime - 100);
            blinkRandom(LOW);
        }
        else
        {
            delay(totalTime);
        }
    }
}
void scrollUp(double totalTime, int repeat = 1)
{
    // Total required time for the animation
    int time = static_cast<int>(totalTime) / 4;

    // Calculates difference after dividing, to delay and get exact time
    int delta = static_cast<int>(totalTime) % 4;


    for (int i = 0; i < repeat; i++)
    {
        allOff();
        digitalWrite(bottomLeftWindow, LOW);
        digitalWrite(bottomRightWindow, LOW);
        delay(time);
        digitalWrite(bottomRoof, LOW);
        digitalWrite(bottomLeftWindow, HIGH);
        digitalWrite(bottomRightWindow, HIGH);
        delay(time);
        digitalWrite(topLeftWindow, LOW);
        digitalWrite(topCenterWindow, LOW);
        digitalWrite(topRightWindow, LOW);
        digitalWrite(bottomRoof, HIGH);
        delay(time);
        digitalWrite(topRoof, LOW);
        digitalWrite(topLeftWindow, HIGH);
        digitalWrite(topCenterWindow, HIGH);
        digitalWrite(topRightWindow, HIGH);
        delay(time);
        allOff(delta);

    }
}

void scrollDown(double totalTime, int repeat = 1)
{
    // Total required time for the animation
    int time = static_cast<int>(totalTime) / 4;

    // Calculates difference after dividing, to delay and get exact time
    int delta = static_cast<int>(totalTime) % 4;

    for (int i = 0; i < repeat; i++)
    {
        allOff();
        digitalWrite(topRoof, LOW);
        delay(time);
        digitalWrite(topRoof, HIGH);
        digitalWrite(topLeftWindow, LOW);
        digitalWrite(topCenterWindow, LOW);
        digitalWrite(topRightWindow, LOW);
        delay(time);
        digitalWrite(bottomRoof, LOW);
        digitalWrite(topLeftWindow, HIGH);
        digitalWrite(topCenterWindow, HIGH);
        digitalWrite(topRightWindow, HIGH);
        delay(time);
        digitalWrite(bottomLeftWindow, LOW);
        digitalWrite(bottomRightWindow, LOW);
        digitalWrite(bottomRoof, HIGH);
        delay(time);
        allOff(delta);
    }
}

void scrollUpAndDown(double totalTime)
{
    //250(ms) Sounds like a nice time for each cycle
    int cycleTime = 400;

    // not enough time for animation, run 1 cyle
    // not tested xD
    if (totalTime <= cycleTime)
    {
        // Total required time for the animation
        int time = static_cast<int>(totalTime) / 2;

        // Calculates difference after dividing, to delay and get exact time
        int delta = static_cast<int>(totalTime) / 2;
        scrollUp(time);
        scrollDown(time);
        delay(delta);
    }
    else
    {
        //// Total required time for the animation
        int repeat = static_cast<int>(totalTime) / (cycleTime * 2);
        int delta = static_cast<int>(totalTime) % (cycleTime * 2);

        for (int i = 0; i < repeat; i++)
        {
            scrollUp(cycleTime);
            scrollDown(cycleTime);
        }

        if (delta >= 500)
        {
            scrollUp(cycleTime);
            delay(delta - cycleTime);
        }
        else
        {
            delay(delta);
        }
    }

}

// Turns all lights ON for a set time and then off for the remaining time of the argument
void blink(double time)
{
    int onTime = 70;
    allOn(onTime);
    allOff(time - onTime);
}

// TODO: fix this function
void randomWindows(double totalTime)
{
    // Total required time for the animation
    int time = static_cast<int>(totalTime) / 5;

    // Calculates difference after dividing, to delay and get exact time
    int delta = static_cast<int>(totalTime) % 5;

    digitalWrite(bottomLeftWindow, LOW);
    delay(time);

    digitalWrite(bottomRightWindow, LOW);
    digitalWrite(bottomLeftWindow, HIGH);
    delay(time);

    digitalWrite(topLeftWindow, LOW);
    digitalWrite(bottomRightWindow, HIGH);
    delay(time);

    digitalWrite(topCenterWindow, LOW);
    digitalWrite(topLeftWindow, HIGH);
    delay(time);

    digitalWrite(topRightWindow, LOW);
    digitalWrite(topCenterWindow, HIGH);
    delay(time);
    allOff(delta);
}

void Log(String message)
{
    elapsedTime = (millis() - startTime);
    Serial.println(message + " " + elapsedTime);
}

void blinkBottomWindows(double totalTime)
{
    digitalWrite(bottomLeftWindow, LOW);
    digitalWrite(bottomRightWindow, LOW);
    delay(totalTime - 100);
    digitalWrite(bottomLeftWindow, HIGH);
    digitalWrite(bottomRightWindow, HIGH);
    delay(100);
}

void blinkTopWindows(double totalTime)
{
    digitalWrite(topLeftWindow, LOW);
    digitalWrite(topCenterWindow, LOW);
    digitalWrite(topRightWindow, LOW);
    delay(totalTime - 200);
    digitalWrite(topCenterWindow, HIGH);
    digitalWrite(topLeftWindow, HIGH);
    digitalWrite(topRightWindow, HIGH);
    delay(200);
}

void turnOffSections()
{
    digitalWrite(bottomRoof, LOW);
    digitalWrite(bottomLeftWindow, LOW);
    digitalWrite(bottomRightWindow, LOW);
    digitalWrite(topLeftWindow, LOW);
    digitalWrite(topCenterWindow, LOW);
    digitalWrite(topRightWindow, LOW);
    digitalWrite(topRoof, LOW);
    delay(100);
    digitalWrite(topLeftWindow, HIGH);
    digitalWrite(topRightWindow, HIGH);
    delay(100);
    digitalWrite(bottomLeftWindow, HIGH);
    digitalWrite(bottomRightWindow, HIGH);
    digitalWrite(topCenterWindow, HIGH);
    delay(100);
    digitalWrite(topRoof, HIGH);
    digitalWrite(bottomRoof, HIGH);
    delay(100);
}

void animateDiameter(double totalTime, int repeat = 1, bool clockWise = true)
{
    // Total required time for the animation
    int time = static_cast<int>(totalTime) / 3;
    // Calculates difference after dividing, to delay and get exact time
    int delta = static_cast<int>(totalTime) % 3;

    for (int i = 0; i < repeat; i++)
    {
        if (clockWise)
        {
            digitalWrite(topRightWindow, LOW);
            digitalWrite(bottomLeftWindow, LOW);
            delay(time);
            digitalWrite(topRightWindow, HIGH);
            digitalWrite(bottomLeftWindow, HIGH);
            digitalWrite(bottomRoof, LOW);
            delay(time);
            digitalWrite(bottomRoof, HIGH);
            digitalWrite(bottomRightWindow, LOW);
            digitalWrite(topLeftWindow, LOW);
            delay(time);
            digitalWrite(bottomRightWindow, HIGH);
            digitalWrite(topLeftWindow, HIGH);
            delay(delta);
        }
        else
        {
            digitalWrite(topLeftWindow, LOW);
            digitalWrite(bottomRightWindow, LOW);
            delay(time);
            digitalWrite(topLeftWindow, HIGH);
            digitalWrite(bottomRightWindow, HIGH);
            digitalWrite(bottomRoof, LOW);
            delay(time);
            digitalWrite(bottomRoof, HIGH);
            digitalWrite(bottomLeftWindow, LOW);
            digitalWrite(topRightWindow, LOW);
            delay(time);
            digitalWrite(bottomLeftWindow, HIGH);
            digitalWrite(topRightWindow, HIGH);
            delay(delta);
        }

    }
}


void mainLoop()
{
    allOn(70); //330ms
    allOff(130); // 470ms
    allOn(100); //570ms
    allOff(50); //620ms
    allOn(50); //670ms
    allOff(260); //930ms

    blink(190); //1.12s
    blink(140); //1.26s
    blink(90); //1.35s
    allOn(130); // 1.48s
    allOff(260); //1.74s
    blink(80); // 1.82s
    allOn(120); // 1.94s
    allOff(610); // 2.55s
    blink(100); // 2.65s
    allOn(150); // 2.8s
    allOff(760); // 3.56s
    blink(100); // 3.66s
    allOn(80); //3.74s
    allOff(160); // 3.9s
    blink(260); // 4.17s
    blink(110); // 4.28s
    blink(290); // 4.57s
    blink(420); //4.99s
    blink(170); // 5.16
    blink(380); //5.54s

    scrollUp(1200); //6.74s

    allOn(150); //6900ms
    allOff(300); //7200ms
    allOn(100); //7300ms
    allOff(100); //7400ms
    allOn(100); //7500ms
    allOff(700); //8200ms
    allOn(100); //8300ms
    allOff(100); //8400ms
    allOn(300); //8700ms
    allOff(300); //9000ms
    allOn(100); //9100ms
    allOff(100); // 9200ms
    allOn(300); //9500ms
    allOff(300); //9800ms
    allOn(100); //9900ms
    allOff(100); //10000ms
    allOn(300); //10300ms
    allOff(300); //10600ms
    allOn(100); //10700ms
    allOff(200); //10900ms
    allOn(200); //11100ms
    allOff(300); //11400ms
    allOn(100); //11500ms
    allOff(100); //11600ms
    allOn(100); //11700ms

    scrollDown(1400); //13100ms

    allOff(100); //13200ms

    allOn(300); // 13500

    scrollUpAndDown(4500); // 18

    allOn(300); //18.3
    allOff(200); // 18.5

    scrollUp(1200); // 19.7

    allOn(300); // 20

    scrollUpAndDown(4500); // 24.5

    allOn(400); // 24.9

    allOff(250); // 25.15

    randomWindows(1000); //26.15

    blink(620); // 26.77

    randomWindows(1000); // 27.77

    blink(610); // 28.38

    blink(200); // 28.58
    blink(590); // 29.17

    blink(200); // 29.37
    blink(430); // 29.8

    blink(400); // 30.2

    blink(400); // 30.6

    turnOffSections();

    allOn(300); // 31.3 

    scrollUpAndDown(4500); // 35.8

    allOn(200); // 36

    allOff(270); // 36.27

    randomWindows(1210); // 37.48

    allOn(300);

    scrollUpAndDown(4500);

    allOn(500); // 42.78
    allOff(160); // 42.94

    randomWindows(1000); // 43.94

    blink(620); // 44.56

    randomWindows(1000); // 45.56

    blink(580); // 46.14

    blink(200); // 46.34
    blink(630); // 46.97

    blink(200); // 47.17
    blink(400); // 47.57

    digitalWrite(topRoof, LOW);
    digitalWrite(bottomRoof, LOW);
    delay(300);
    digitalWrite(topRoof, HIGH);
    digitalWrite(bottomRoof, HIGH);
    delay(120); // 47.99

    digitalWrite(topRoof, LOW);
    digitalWrite(bottomRoof, LOW);
    delay(300);
    digitalWrite(topRoof, HIGH);
    digitalWrite(bottomRoof, HIGH);
    delay(100); // 48.39

    digitalWrite(topRoof, LOW);
    digitalWrite(bottomRoof, LOW);
    delay(300);
    digitalWrite(topRoof, HIGH);
    digitalWrite(bottomRoof, HIGH);
    delay(110); // 48.8

    digitalWrite(topRoof, LOW);
    digitalWrite(bottomRoof, LOW);
    delay(300);
    digitalWrite(topRoof, HIGH);
    digitalWrite(bottomRoof, HIGH);
    delay(100); // 49.2

    digitalWrite(topRoof, LOW);
    digitalWrite(bottomRoof, LOW);
    delay(300);
    digitalWrite(topRoof, HIGH);
    digitalWrite(bottomRoof, HIGH);
    delay(110); // 49.61

    digitalWrite(topRoof, LOW);
    digitalWrite(bottomRoof, LOW);
    delay(300);
    digitalWrite(topRoof, HIGH);
    digitalWrite(bottomRoof, HIGH);
    delay(110); // 50.02

    digitalWrite(border, LOW);
    delay(300);
    digitalWrite(border, HIGH);
    delay(100); // 50.42

    blinkBorderExtra(400); // 50.82
    blinkBorderExtra(400); // 51.22
    blinkBorderExtra(400); // 51.62
    blinkBorderExtra(400); // 52.02
    blinkBorderExtra(400); // 52.42
    blinkBorderExtra(400); // 52.82
    blinkBorderExtra(400); // 53.22
    blinkBorderExtra(400); // 53.62
    blinkBorderExtra(400); // 54.02
    blinkBorderExtra(400); // 54.42
    blinkBorderExtra(400); // 54.82
    blinkBorderExtra(400); // 55.22
    blinkBorderExtra(400); // 55.62
    blinkBorderExtra(400); // 56.02
    blinkBorderExtra(400); // 56.42
    blinkBorderExtra(400); // 56.82
    blinkBorderExtra(400); // 57.22

    blinkBorderExtra(400, 100); // 57.62
    blinkBorderExtra(400, 100); // 58.02
    blinkBorderExtra(400, 100); // 58.42

    blinkBorderExtra(400); // 58.82

    blinkBorderExtra(400, 100); // 59.02
    blinkBorderExtra(400, 100); // 59.42
    blinkBorderExtra(400, 100); // 59.82

    blinkBorderExtra(400); //

    blinkBorderExtra(400, 100);
    blinkBorderExtra(400, 100);
    blinkBorderExtra(400, 100);
    blinkBorderExtra(400, 100);
    blinkBorderExtra(400, 100);
    blinkBorderExtra(400, 100);
    blinkBorderExtra(400, 100);

    blinkBorderExtra(400); //

    blinkBorderExtra(400, 100); //
    blinkBorderExtra(400, 100); //
    blinkBorderExtra(400, 100); //

    blinkBorderExtra(400); //

    blinkBorderExtra(400, 100); //
    blinkBorderExtra(400, 100); //
    blinkBorderExtra(400, 100); //

    blinkBorderExtra(400); //

    blinkBorderExtra(400, 100);
    blinkBorderExtra(400, 100);
    blinkBorderExtra(400, 100);
    blinkBorderExtra(400, 100);
    blinkBorderExtra(400, 100);
    blinkBorderExtra(400, 100);
    blinkBorderExtra(400, 100);

    delay(175); // 1:09:80

    allOn(400);

    allOff(250);

    randomWindows(1000);

    blink(620);

    randomWindows(1000);

    blink(610);

    blink(200);
    blink(590);

    blink(200);
    blink(430);

    blink(400);

    blink(400);

    turnOffSections();

    allOn(300);

    scrollUpAndDown(4500);

    allOn(200);

    allOff(270);

    randomWindows(1210);

    allOn(300);

    scrollUpAndDown(4500);

    allOn(500);
    allOff(160);

    randomWindows(1000);

    blink(620);

    randomWindows(1000);

    blink(580); // 91446

    blinkBottomWindows(214);
    blinkBottomWindows(200);
    blinkBottomWindows(200);
    blinkBottomWindows(200);
    blinkBottomWindows(200);
    blinkBottomWindows(200); // 1.32.66

    delay(200); // 1.32.86

    digitalWrite(topCenterWindow, LOW);
    delay(224);
    digitalWrite(topCenterWindow, HIGH);
    delay(200);

    digitalWrite(topCenterWindow, LOW);
    delay(204);
    digitalWrite(topCenterWindow, HIGH);
    delay(200);

    digitalWrite(topCenterWindow, LOW);
    delay(204);
    digitalWrite(topCenterWindow, HIGH);
    delay(200);

    digitalWrite(topCenterWindow, LOW);
    delay(204);
    digitalWrite(topCenterWindow, HIGH);
    delay(200);

    blinkTopWindows(400);
    blinkTopWindows(404);
    blinkTopWindows(410);

    blinkBottomWindows(405);
    blinkBottomWindows(405);
    blinkBottomWindows(405);
    blinkBottomWindows(405);
    blinkBottomWindows(405);
    blinkBottomWindows(405);
    blinkBottomWindows(405);
    blinkBottomWindows(405);

    blinkBorderExtra(401, 100, 64); //
    delay(58);

    allOn(200);
    allOff(450);

    randomWindows(1000);

    blink(620);

    randomWindows(1000);

    blink(610);

    blink(200);
    blink(590);

    blink(200);
    blink(430);

    blink(400);

    blink(400);

    turnOffSections();

    allOn(300);

    scrollUpAndDown(4500);

    allOn(200);

    allOff(270);

    randomWindows(1210);

    allOn(300); // 2.17.767

    scrollUpAndDown(4780); // 2.22.547

    allOn(200);
    allOff(113);

    WindowsRotate(310, true, 4); // 224200
    allOn(200);
    allOff(100);

    WindowsRotate(332, false, 4); // 225740
    allOn(200);
    allOff(100);

    WindowsRotate(250, true, 2); // 225740
    allOn(220);
    allOff(100);

    WindowsRotate(250, false, 2); // 225740

    allOn(210);
    allOff(200);

    allOn(210);
    allOff(200);

    allOn(210);
    allOff(200); // 2.28.678

    turnOffSections();

    digitalWrite(border, LOW);
    WindowsRotate(400, true, 10);
    scrollDown(400, 10); // 2.45.092
    WindowsRotate(400, false, 10);
    scrollUp(400, 10); // 2.45.092

    WindowsRotate(300, true, 5);
    animateDiameter(300, 6, false);
    WindowsRotate(300, false, 5);
    animateDiameter(300, 6, true);

    //allOn(300, 22, true); // 2.51.695
    allOff();

    allOn(250);
    allOff(100);
    WindowsRotate(235, true, 2);

    allOn(200);
    allOff(100);
    WindowsRotate(250, false, 2);

    allOn(200);
    allOff(100);
    WindowsRotate(250, true, 2);

    allOn(200);
    allOff(100);
    WindowsRotate(260, false, 2);

    allOn(200);
    allOff(100);
    WindowsRotate(250, true, 2);

    allOn(200);
    allOff(100);
    WindowsRotate(260, false, 2);

    allOn(200);
    allOff(100);
    WindowsRotate(255, true, 2);

    allOn(200);
    allOff(100);
    WindowsRotate(255, false, 2);
    digitalWrite(border, HIGH);

    allOn();
    digitalWrite(topRoof, HIGH);
    delay(800);
    digitalWrite(topLeftWindow, HIGH);
    digitalWrite(topCenterWindow, HIGH);
    digitalWrite(topRightWindow, HIGH);
    delay(800);
    digitalWrite(bottomRoof, HIGH);
    delay(800);
    digitalWrite(bottomLeftWindow, HIGH);
    digitalWrite(bottomRightWindow, HIGH);

    delay(800);

    digitalWrite(border, LOW);
    allOn(300);
    digitalWrite(border, HIGH);
    allOff();

    delay(20000);
    //}
}

// Pin configuration
void setup() {
    Serial.begin(9600);

    pinMode(topRoof, OUTPUT);
    pinMode(topLeftWindow, OUTPUT);
    pinMode(topCenterWindow, OUTPUT);
    pinMode(topRightWindow, OUTPUT);
    pinMode(bottomRoof, OUTPUT);
    pinMode(bottomLeftWindow, OUTPUT);
    pinMode(bottomRightWindow, OUTPUT);
    pinMode(border, OUTPUT);

    pinMode(ledPin, OUTPUT);

    pinMode(analogPin, INPUT);

    pinMode(buttonPin, INPUT);

    // Arduino LOW = Relay CONNECTED
    digitalWrite(border, HIGH);
    allOff();
}
//////////////////////////////////////////////////////////////////////////////
//      Timings on the right refers to the time after line execution        //
//////////////////////////////////////////////////////////////////////////////
void loop() {
    digitalWrite(border, LOW);
    allOn();
    // Holds spaker input value

    //Reads speaker input value to get maximum and minimum value for sampleSize
    //Last circuit appears to get a constant 0 unless I play some music, this is not needed
    //if (counter <= sampleSize)
    //{
    //    speakerRead = analogRead(analogPin);
    //    if (speakerRead > maximumValue) maximumValue = speakerRead;
    //    if (speakerRead < minimumValue) minimumValue = speakerRead;
    //    counter++;
    //}
    //else
    //{
    //    Serial.println(minimumValue);
    //    Serial.println(maximumValue);
    //}

    if (digitalRead(buttonPin))
    {
        int speakerRead = 0;
        // Give chance to release button
        digitalWrite(border, HIGH);
        allOff();
        delay(2000);
        waitingSong = true;
        //Serial.println("Waiting for song...");
        // Indicate waiting for song state

        while (waitingSong)
        {
            speakerRead = analogRead(analogPin);
            Serial.println(speakerRead);
            if (speakerRead > 200) {
                mainLoop();
                waitingSong = false;
            }
        }

        // Give chance to release button
        delay(2000);
    }
}