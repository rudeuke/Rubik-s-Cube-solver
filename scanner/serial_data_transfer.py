import serial


ARDUINO_PORT = serial.Serial('COM3', baudrate=9600, timeout=0.1)


def send(data):
   ARDUINO_PORT.write(data.encode())


def receive():
    return ARDUINO_PORT.read().decode('ascii')
