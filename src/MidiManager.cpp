#include "MidiManager.h"

MidiManager::MidiManager(int interval, int baudRate) {
  if(baudRate>0){
    Serial.begin(baudRate);
  }
  _interval = interval;
}
void MidiManager::addSensor(MidiSensor sensor) {
  _sensors.push_back(sensor);
  _count++;
}
void MidiManager::loop(bool debug){
  if (_msec >= 20) {
    Serial.println("=================================");
    _msec = 0;
    if (debug) {
      for (int i = 0; i < _count; i++) {
        Serial.println(_sensors[i].getInfo());
      }
    }
    for (int i = 0; i < _count; i++) {
      _sensors[i].readAndSend();
    }
  }
  while (usbMIDI.read()) {} //ignore incoming messages
}