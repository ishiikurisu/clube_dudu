#include <Servo.h>
#define MOTOR 3
#define EYE 4
#define VOICE 11

Servo motor;

void setup()
{
   motor.attach(MOTOR);
   pinMode(EYE, OUTPUT);
   pinMode(VOICE, OUTPUT);
   Serial.begin(9600);
}

void open_mouth()
{
    tone(VOICE, 2000);
    motor.write(-60);
}

void blink(int how_long)
{
    digitalWrite(EYE, HIGH);
    delay(how_long/2);
    digitalWrite(EYE, LOW);
    delay(how_long/2);
}

void play_song()
{
    // tone(VOICE, 3038); delay(250);
    // noTone(VOICE); delay(50);
    // tone(VOICE, 2864); delay(250);
    // noTone(VOICE); delay(50);
    // tone(VOICE, 3038); delay(250);
    // noTone(VOICE); delay(50);
    // tone(VOICE, 2950); delay(250);
    // noTone(VOICE); delay(50);
    // tone(VOICE, 3038); delay(250);
    // noTone(VOICE); delay(50);
    // tone(VOICE, 2684); delay(250);
    // noTone(VOICE); delay(50);
    for (int f = 2000; f <= 5000; f += 100)
    {
        tone(VOICE, f);
        delay(50);
    }
    noTone(VOICE);
}

void communicate()
{
    blink(150);
    blink(150);
    blink(150);
    blink(150);
    digitalWrite(EYE, HIGH);
    play_song();
    digitalWrite(EYE, LOW);
    blink(150);
    blink(150);
    blink(150);
    blink(150);
}

void close_mouth()
{
    noTone(VOICE);
    motor.write(60);
}

void wait()
{
    delay(2000);
}

void loop ()
{
  open_mouth();
  communicate();
  close_mouth();
  wait();
}
