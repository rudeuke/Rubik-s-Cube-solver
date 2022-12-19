import cv2
import interface
import detection_utilities
import face_recognition
import shared_variables
import serial_data_transfer


is_detected = False


while True:
    ret, frame = interface.capture_camera.read()
    hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    shared_variables.face_detected = face_recognition.get_detected_face(
        hsv_frame)

    interface.draw_camera_markers(frame)
    interface.draw_stickers(frame, 'detected', shared_variables.face_detected)
    for face in shared_variables.my_cube.permutation:
        interface.draw_stickers(interface.preview, face,
                                shared_variables.my_cube.permutation[face])
    interface.draw_face_letters(shared_variables.my_cube)

    key = detection_utilities.get_key()

    if key == 27:
        break
    elif key != None:
        key = chr(key).upper()
        if key == '1':
            serial_data_transfer.send('1')
            print("Scanning initiated")
        elif key == '\r':
            is_detected = detection_utilities.apply_detection()
        elif key in ('F', 'B', 'L', 'R', 'U', 'D'):
            detection_utilities.already_detected.append(key)
            shared_variables.my_cube.permutation[key] = shared_variables.face_detected
            print(f"Face detected: {key}")

    detection_utilities.detect_cube_automatically()

    if is_detected:
        print("All faces detected. Starting solving...")
        shared_variables.my_cube.update_orientation()
        shared_variables.my_cube.try_solve()
        is_detected = False

    cv2.imshow('Cube scheme', interface.preview)
    cv2.imshow('Detection', frame[0:500, 0:500])
cv2.destroyAllWindows()
