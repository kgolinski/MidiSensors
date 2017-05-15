#include "MidiSensor.h"

MidiSensor::MidiSensor(int type, int pin, int min, int max, int channel, int number, int threshold) {
  _type = type;
  _pin = pin;
  _min = min;
  _max = max;
  _channel = channel;
  _number = number;
  _threshold = threshold;
}
String MidiSensor::getInfo() {
  int reading = 0;
  String type = "";
  if(_type == ANALOG_SENSOR){
    type = "ANALOG";
    reading = analogRead(_pin);
  }
  else if(_type == TOUCH_SENSOR) {
    type = "TOUCH";
    reading = touchRead(_pin);
  }
  int calculated = constrain(map(reading, _min, _max, 0, 127), 0, 127);
  String sending = "";
  if(_threshold == -1){
    sending += calculated;
  }
  else {
    if(reading>_threshold){
      sending = "ON";
    }
    else {
      sending = "OFF";
    }
  }
  String info = String(_pin) + "(" + type + "):" +  reading + " -> " + sending;
  return info;
}
void MidiSensor::readAndSend() {
  int reading = 0;
  int val = 0;
  if (_type == ANALOG_SENSOR) {
    reading = analogRead(_pin);
  }
  else if (_type == TOUCH_SENSOR) {
    reading = touchRead(_pin);
  }
  if (_threshold == -1) {
    val = constrain(map(reading, _min, _max, 0, 127), 0, 127);
    if (val != _lastMidi) {
      usbMIDI.sendControlChange(_number, val, _channel);
      _lastMidi = val;
    }
  }
  else {
    if(reading>_threshold && _lastMidi!=127){
      val = constrain(map(reading, _threshold, _max, 0, 127), 0, 127);
      usbMIDI.sendNoteOn(_number, val, _channel);
      _lastMidi = 127;
    }
    else if(reading<_threshold && _lastMidi!=0){
      usbMIDI.sendNoteOff(_number, 0, _channel);
      _lastMidi = 0;
    }
  }
}
