/*
  MidiManager.h - Library for sending midi messages from __teensy__ analog/touch pins.
  Created by Krzysztof Goliński, October 25, 2016.
  Released into the public domain.
*/
#ifndef MIDI_MANAGER_H
#define MIDI_MANAGER_H

#include "Arduino.h"
#include "MidiSensor/MidiSensor.h"
#include <vector>

class MidiManager {
    public:
      MidiManager(int interval, int baudRate);
      void loop(bool debug);
      void addSensor(MidiSensor sensor);
    private:
      int _interval;
      std::vector<MidiSensor>_sensors;
      //MidiSensor _sensors[];
      int _count = 0;
      elapsedMillis _msec = 0;
};
#endif