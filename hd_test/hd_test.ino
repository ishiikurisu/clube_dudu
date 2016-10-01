#include <EEPROM.h>
#ifndef LED
#define LED 13
#endif

/* I/O FUNCTIONS */
void log(String data)
{
    Serial.print("LOG: ");
    Serial.print(data);
    Serial.print("\n");
}

String read()
{
    String inlet;

    do { inlet = Serial.readString(); }
    while (inlet.length() == 0);

    return inlet;
}

/* MEMORY ACCESS FUNCTIONS */
void clear_memory()
{
    for (int i = 0; i < EEPROM.length(); ++i)
    {
        EEPROM.write(i, 0);
    }
}

String read_memory()
{
    String outlet = "";
    int address = 0;
    byte value = EEPROM.read(address);

    while (value != 0)
    {
        outlet.concat((char) value);
        value = EEPROM.read(++address);
    }

    return outlet;
}

void write_memory(String inlet)
{
    int limit = inlet.length();
    byte* data = (byte*) malloc(sizeof(byte) * limit);

    clear_memory();
    inlet.getBytes(data, limit);
    for (int i = 0; i < limit; ++i)
    {
        EEPROM.write(i, data[i]);
    }
}

/* MAIN FUNCTIONS */

//
void setup()
{
    pinMode(LED, OUTPUT);
    Serial.begin(9600);
    clear_memory();

    while (!Serial)
    {
        ;
    }
}

void loop()
{
    String data = read();

    if (data.compareTo("GET\n") == 0) {
        data = read_memory();
        log(data);
    }
    else if (data.compareTo("SET\n") == 0) {
        data = read();
        write_memory(data);
        log("DONE!");
    }
    else {
        log("INVALID INPUT");
    }
}
