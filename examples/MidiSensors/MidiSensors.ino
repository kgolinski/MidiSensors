#include <MidiManager.h>

MidiManager mm(20, 9600);
bool debug = true;

void setup() {
  // TOUCH_SENSOR/ANALOG_SENSOR, pin, minimum value, maximum value , midi channel, mini note number, threshold or -1 for CC
  mm.addSensor(MidiSensor(TOUCH_SENSOR, A2, 820, 10000, 1, 1, -1));
  mm.addSensor(MidiSensor(TOUCH_SENSOR, A3, 900, 10000, 1, 2, 3000));
  mm.addSensor(MidiSensor(ANALOG_SENSOR, A4, 330, 500, 1, 3, -1));
  mm.addSensor(MidiSensor(ANALOG_SENSOR, A5, 100, 800, 1, 4, 400));
}

void loop() {
  mm.loop();
}