import serial
import cube


ARDUINO_PORT = serial.Serial('COM3', baudrate=9600, timeout=0.1)
my_cube = cube.Cube()
face_detected = []
