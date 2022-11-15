import interface_stickers


def get_detected_face(hsv_frame):
    detected_face = []
    for i in range(9):
        detected_hsv = hsv_frame[interface_stickers.COORDINATES['cameraMarkers'][i][1] + 20][interface_stickers.COORDINATES['cameraMarkers'][i][0] + 20]
        detected_color = detect_color(
            detected_hsv[0], detected_hsv[1], detected_hsv[2])
        detected_face.append(detected_color)
        # print(f"{i}: H={detected_hsv[0]} S={detected_hsv[1]} V={detected_hsv[2]}")
    return detected_face


def detect_color(h, s, v):
    if 180 < s or v < 230:
        if 170 < h or h <= 5:
            return 'R'
        elif 5 < h <= 25:
            return 'O'
        elif 25 < h <= 50:
            return 'Y'
        elif 65 < h <= 95:
            return 'G'
        elif 95 < h <= 110:
            return 'B'
    return 'W'
