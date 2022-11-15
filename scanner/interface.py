import cv2
import numpy
import interface_stickers


capture_camera = cv2.VideoCapture(1, cv2.CAP_DSHOW)
preview = numpy.zeros((700, 800, 3), numpy.uint8)


def draw_camera_markers(window):
    for x, y in interface_stickers.COORDINATES['cameraMarkers']:
        cv2.rectangle(
            window, (x, y), (x + interface_stickers.STICKER_SIZE, y + interface_stickers.STICKER_SIZE), (255, 255, 255), 1)


def draw_stickers(window, face, permutation):
    sticker_number = 0
    for x, y in interface_stickers.COORDINATES[face]:
        cv2.rectangle(window, (x, y), (x + interface_stickers.CAMERA_STICKER_SIZE, y + interface_stickers.CAMERA_STICKER_SIZE),
                      interface_stickers.COLOR_BGR[permutation[sticker_number]], -1)
        sticker_number += 1


def draw_face_letters(cube):
    for face in cube.permutation:
        letter = face
        x = interface_stickers.FACE_LETTERS[face][0]
        y = interface_stickers.FACE_LETTERS[face][1]
        cv2.putText(preview, letter, (x, y),
                    cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 0), 2, cv2.LINE_AA)
