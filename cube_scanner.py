import cv2
import numpy
import kociemba
import serial





alreadyDetected = []
solution = []
captureCamera = cv2.VideoCapture(0)
preview = numpy.zeros((700,800,3), numpy.uint8)
arduinoPort = serial.Serial('COM3', 9600)
arduinoPort.timeout = 1





colorBGR = {
    'W': (255,255,255),
    'R': (0,0,255),
    'G': (0,255,0),
    'Y': (0,255,255),
    'O': (0,165,255),
    'B': (255,0,0),
}

# for masking
# colorHSV = {
#     'W': [numpy.array([0, 0, 70]), numpy.array([180, 30, 255])],
#     'R': [numpy.array([160, 140, 40]), numpy.array([180, 255, 255])],
#     'G': [numpy.array([55, 140, 40]), numpy.array([75, 255, 255])],
#     'Y': [numpy.array([20, 140, 40]), numpy.array([35, 255, 255])],
#     'O': [numpy.array([0, 140, 40]), numpy.array([20, 255, 255])],
#     'B': [numpy.array([95, 140, 40]), numpy.array([110, 255, 255])],
# }

stickerCoordinates = {
    'cameraMarkers': [
        [200, 200], [300, 200], [400, 200],
        [200, 300], [300, 300], [400, 300],
        [200, 400], [300, 400], [400, 400]
    ],
    'detected': [
        [20, 20], [64, 20], [108, 20],
        [20, 64], [64, 64], [108, 64],
        [20, 108], [64, 108], [108, 108]
    ],
    'U': [
        [188, 128], [232, 128], [276, 128],
        [188, 172], [232, 172], [276, 172],
        [188, 216], [232, 216], [276, 216]
    ],
    'R': [
        [326, 280], [370, 280], [414, 280],
        [326, 324], [370, 324], [414, 324],
        [326, 368], [370, 368], [414, 368]
    ],
    'F': [
        [188, 280], [232, 280], [276, 280],
        [188, 324], [232, 324], [276, 324],
        [188, 368], [232, 368], [276, 368]
    ],
    'D': [
        [188, 434], [232, 434], [276, 434],
        [188, 478], [232, 478], [276, 478],
        [188, 522], [232, 522], [276, 522]
    ], 
    'L': [
        [50, 280], [94, 280], [138, 280],
        [50, 324], [94, 324], [138, 324],
        [50, 368], [94, 368], [138, 368]
    ],
    'B': [
        [464, 280], [508, 280], [552, 280],
        [464, 324], [508, 324], [552, 324],
        [464, 368], [508, 368], [552, 368]
    ],
    
    
    'preview': [
        [120, 130], [54, 130], [88, 130],
        [120, 164], [54, 164], [88, 164],
        [120, 198], [54, 198], [88, 198]
    ],
}

faceLetter = {
    'U':['U', 242, 202],
    'R':['R', 380, 354],
    'F':['F', 242, 354],
    'D':['D', 242, 508],
    'L':['L', 104, 354],
    'B':['B', 518, 354],
}

colorToFace = {
    'W': 'U',
    'R': 'R',
    'G': 'F',
    'Y': 'D',
    'O': 'L',
    'B': 'B',
}

permutation = {
    'U': ['W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'],
    'R': ['W', 'W', 'W', 'W', 'R', 'W', 'W', 'W', 'W'],
    'F': ['W', 'W', 'W', 'W', 'G', 'W', 'W', 'W', 'W'],
    'D': ['W', 'W', 'W', 'W', 'Y', 'W', 'W', 'W', 'W'],
    'L': ['W', 'W', 'W', 'W', 'O', 'W', 'W', 'W', 'W'],
    'B': ['W', 'W', 'W', 'W', 'B', 'W', 'W', 'W', 'W'],
}





def drawCameraMarkers():

    for x, y in stickerCoordinates['cameraMarkers']:
        cv2.rectangle(cam, (x, y), (x + 30, y + 30), (255, 255, 255), 1)



def drawStickers(window, face, arrangement):

    stickerNumber = 0
    for x, y in stickerCoordinates[face]:
        cv2.rectangle(window, (x, y), (x + 40, y + 40), colorBGR[arrangement[stickerNumber]], -1)
        stickerNumber += 1



def drawFaceLetters():

    for face in permutation:
        letter = faceLetter[face][0]
        x = faceLetter[face][1]
        y = faceLetter[face][2]
        cv2.putText(preview, letter, (x, y), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 0), 2, cv2.LINE_AA)  



def detectColor(h, s, v):

    if s <=30 and v >= 70:
        return 'W'

    elif s >= 140 and v >= 40:
        if h >= 160 and h < 180:
            return 'R'
        
        elif h >= 55 and h < 75:
            return 'G'
                    
        elif h >= 20 and h < 35:
            return 'Y'
                    
        elif h < 20:
            return 'O'
                    
        elif h >= 95 and h < 110:
            return 'B'

    return 'W'



def serializeInput(permutation):

    serialized = ''
    for i in permutation:
        for j in permutation[i]:
            serialized += colorToFace[j]

    return serialized



def serializeOutput(algorithm):

    serialized = ''
    for move in algorithm.split():
        if move == 'U':
            serialized += 'U'

        elif move == 'U\'':
            serialized += 'u'

        elif move == 'U2':
            serialized += 'V'

        elif move == 'R':
            serialized += 'R'

        elif move == 'R\'':
            serialized += 'r'

        elif move == 'R2':
            serialized += 'S'

        elif move == 'F':
            serialized += 'F'

        elif move == 'F\'':
            serialized += 'f'

        elif move == 'F2':
            serialized += 'G'

        elif move == 'D':
            serialized += 'D'

        elif move == 'D\'':
            serialized += 'd'

        elif move == 'D2':
            serialized += 'E'

        elif move == 'L':
            serialized += 'L'

        elif move == 'L\'':
            serialized += 'l'

        elif move == 'L2':
            serialized += 'M'

        elif move == 'B':
            serialized += 'B'

        elif move == 'B\'':
            serialized += 'b'

        elif move == 'B2':
            serialized += 'C'

    serialized += '\n'
    return serialized





if __name__ == '__main__':

    while True:
        ret, cam = captureCamera.read()
        HSVFrame = cv2.cvtColor(cam, cv2.COLOR_BGR2HSV)
        faceDetected = []



        for i in range(9):
            detectedHSV = HSVFrame[stickerCoordinates['cameraMarkers'][i][1] + 20][stickerCoordinates['cameraMarkers'][i][0] + 20]
            faceDetected.append(detectColor(detectedHSV[0], detectedHSV[1], detectedHSV[2]))

        drawCameraMarkers()
        drawStickers(cam, 'detected', faceDetected)
        for face in permutation:
            drawStickers(preview, face, permutation[face])
        drawFaceLetters()



        keyPressed = cv2.waitKey(1) & 0xFF

        if keyPressed == 27:
            break

        elif keyPressed == ord('u'):
            alreadyDetected.append('U')
            permutation['U'] = faceDetected

        elif keyPressed == ord('r'):
            alreadyDetected.append('R')
            permutation['R'] = faceDetected

        elif keyPressed == ord('l'):
            alreadyDetected.append('L')
            permutation['L'] = faceDetected

        elif keyPressed == ord('d'):
            alreadyDetected.append('D')
            permutation['D'] = faceDetected

        elif keyPressed == ord('f'):
            alreadyDetected.append('F')
            permutation['F'] = faceDetected

        elif keyPressed == ord('b'):
            alreadyDetected.append('B')
            permutation['B'] = faceDetected

        elif keyPressed == ord('\r'):
            if len(set(alreadyDetected)) == 6:
                try:
                    solution = kociemba.solve(serializeInput(permutation))
                    
                    if solution:
                        print(solution)
                        print(serializeOutput(solution))

                        arduinoPort.write(serializeOutput(solution).encode())

                except:
                    print("Detection error")
            else:
                print("You need to scan all sides")


        cv2.imshow('Cube scheme', preview)
        cv2.imshow('Detection', cam[0:500, 0:500])


    cv2.destroyAllWindows()