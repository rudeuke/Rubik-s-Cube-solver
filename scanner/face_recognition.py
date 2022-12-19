import interface_stickers


def determine_orientation(first_face, second_face):
    color_to_face = {
        'W': 'U',
        'R': 'R',
        'G': 'F',
        'Y': 'D',
        'O': 'L',
        'B': 'B',
    }

    if first_face == 'W':
        color_to_face['W'] = 'U'
        color_to_face['Y'] = 'D'
        if second_face == 'G':
            color_to_face['R'] = 'R'
            color_to_face['G'] = 'F'
            color_to_face['O'] = 'L'
            color_to_face['B'] = 'B'
        elif second_face == 'R':
            color_to_face['B'] = 'R'
            color_to_face['R'] = 'F'
            color_to_face['G'] = 'L'
            color_to_face['O'] = 'B'
        elif second_face == 'B':
            color_to_face['O'] = 'R'
            color_to_face['B'] = 'F'
            color_to_face['R'] = 'L'
            color_to_face['G'] = 'B'
        elif second_face == 'O':
            color_to_face['G'] = 'R'
            color_to_face['O'] = 'F'
            color_to_face['B'] = 'L'
            color_to_face['R'] = 'B'

    elif first_face == 'R':
        color_to_face['R'] = 'U'
        color_to_face['O'] = 'D'
        if second_face == 'G':
            color_to_face['Y'] = 'R'
            color_to_face['G'] = 'F'
            color_to_face['W'] = 'L'
            color_to_face['B'] = 'B'
        elif second_face == 'Y':
            color_to_face['B'] = 'R'
            color_to_face['Y'] = 'F'
            color_to_face['G'] = 'L'
            color_to_face['W'] = 'B'
        elif second_face == 'B':
            color_to_face['W'] = 'R'
            color_to_face['B'] = 'F'
            color_to_face['Y'] = 'L'
            color_to_face['G'] = 'B'
        elif second_face == 'W':
            color_to_face['G'] = 'R'
            color_to_face['W'] = 'F'
            color_to_face['B'] = 'L'
            color_to_face['Y'] = 'B'

    elif first_face == 'G':
        color_to_face['G'] = 'U'
        color_to_face['B'] = 'D'
        if second_face == 'Y':
            color_to_face['R'] = 'R'
            color_to_face['Y'] = 'F'
            color_to_face['O'] = 'L'
            color_to_face['W'] = 'B'
        elif second_face == 'O':
            color_to_face['Y'] = 'R'
            color_to_face['O'] = 'F'
            color_to_face['W'] = 'L'
            color_to_face['R'] = 'B'
        elif second_face == 'W':
            color_to_face['O'] = 'R'
            color_to_face['W'] = 'F'
            color_to_face['R'] = 'L'
            color_to_face['Y'] = 'B'
        elif second_face == 'R':
            color_to_face['W'] = 'R'
            color_to_face['R'] = 'F'
            color_to_face['Y'] = 'L'
            color_to_face['O'] = 'B'

    elif first_face == 'Y':
        color_to_face['Y'] = 'U'
        color_to_face['W'] = 'D'
        if second_face == 'O':
            color_to_face['B'] = 'R'
            color_to_face['O'] = 'F'
            color_to_face['G'] = 'L'
            color_to_face['R'] = 'B'
        elif second_face == 'B':
            color_to_face['R'] = 'R'
            color_to_face['B'] = 'F'
            color_to_face['O'] = 'L'
            color_to_face['G'] = 'B'
        elif second_face == 'R':
            color_to_face['G'] = 'R'
            color_to_face['R'] = 'F'
            color_to_face['B'] = 'L'
            color_to_face['O'] = 'B'
        elif second_face == 'G':
            color_to_face['O'] = 'R'
            color_to_face['G'] = 'F'
            color_to_face['R'] = 'L'
            color_to_face['B'] = 'B'

    elif first_face == 'O':
        color_to_face['O'] = 'U'
        color_to_face['R'] = 'D'
        if second_face == 'B':
            color_to_face['Y'] = 'R'
            color_to_face['B'] = 'F'
            color_to_face['W'] = 'L'
            color_to_face['G'] = 'B'
        elif second_face == 'W':
            color_to_face['B'] = 'R'
            color_to_face['W'] = 'F'
            color_to_face['G'] = 'L'
            color_to_face['Y'] = 'B'
        elif second_face == 'G':
            color_to_face['W'] = 'R'
            color_to_face['G'] = 'F'
            color_to_face['Y'] = 'L'
            color_to_face['B'] = 'B'
        elif second_face == 'Y':
            color_to_face['G'] = 'R'
            color_to_face['Y'] = 'F'
            color_to_face['B'] = 'L'
            color_to_face['W'] = 'B'

    elif first_face == 'B':
        color_to_face['B'] = 'U'
        color_to_face['G'] = 'D'
        if second_face == 'W':
            color_to_face['R'] = 'R'
            color_to_face['W'] = 'F'
            color_to_face['O'] = 'L'
            color_to_face['Y'] = 'B'
        elif second_face == 'R':
            color_to_face['Y'] = 'R'
            color_to_face['R'] = 'F'
            color_to_face['W'] = 'L'
            color_to_face['O'] = 'B'
        elif second_face == 'Y':
            color_to_face['O'] = 'R'
            color_to_face['Y'] = 'F'
            color_to_face['R'] = 'L'
            color_to_face['W'] = 'B'
        elif second_face == 'O':
            color_to_face['W'] = 'R'
            color_to_face['O'] = 'F'
            color_to_face['Y'] = 'L'
            color_to_face['R'] = 'B'

    return color_to_face


def get_detected_face(hsv_frame):
    detected_face = []
    for i in range(9):
        detected_hsv = hsv_frame[interface_stickers.COORDINATES['cameraMarkers']
                                 [i][1] + 20][interface_stickers.COORDINATES['cameraMarkers'][i][0] + 20]
        detected_color = detect_color(
            detected_hsv[0], detected_hsv[1], detected_hsv[2])
        detected_face.append(detected_color)
        # print(f"{i}: H={detected_hsv[0]} S={detected_hsv[1]} V={detected_hsv[2]}")
    return detected_face


def detect_color(h, s, v):
    if s > 80:
        if 170 < h or h <= 5:
            return 'R'
        elif 5 < h <= 25:
            return 'O'
        elif 25 < h <= 60:
            return 'Y'
        elif 65 < h <= 87:
            return 'G'
        elif 87 < h <= 110:
            if s > 230:
                return 'B'

    return 'W'
