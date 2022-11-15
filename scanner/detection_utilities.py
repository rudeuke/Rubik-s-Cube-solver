import cv2
import serial_data_transfer


already_detected = []


def get_key():
    key_pressed = cv2.waitKey(1) & 0xFF
    if key_pressed != 255:
        return key_pressed


def apply_detection():
    if len(set(already_detected)) == 6:
        print("All faces detected")
        return True
    else:
        print("Not all faces detected")
        return False


def detect_cube_automatically():
    arduino_data = serial_data_transfer.receive()

    if arduino_data:
        detect_face(arduino_data)


def detect_face(face):
    from scanner import my_cube, face_detected
    already_detected.append(face.upper())
    my_cube.permutation[face.upper()] = face_detected
