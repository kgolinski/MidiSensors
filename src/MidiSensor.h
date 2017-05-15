/*
  MidiSensor.h - Library for sending midi messages from __teensy__ analog/touch pins.
  Created by Krzysztof Goliński, October 25, 2016.
  Released into the public domain.
*/
#ifndef MIDI_SENSOR_H
#define MIDI_SENSOR_H

#define ANALOG_SENSOR 0
#define TOUCH_SENSOR 1

#include "Arduino.h"

class MidiSensor {
    public:
      MidiSensor(int type, int pin, int min, int max, int channel, int number, int threshold);
      void readAndSend();
      String getInfo();
    private:
      int _type;
      int _pin;
      int _min;
      int _max;
      int _threshold;
      int _channel;
      int _number;
      int _lastMidi = -1;
};
#endif
