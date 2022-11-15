import kociemba
import serialization
import serial_data_transfer


COLOR_TO_FACE = {
    'W': 'U',
    'R': 'R',
    'G': 'F',
    'Y': 'D',
    'O': 'L',
    'B': 'B',
}


class Cube:
    permutation = {}

    def __init__(self):
        self.permutation = {
            'U': ['W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'],
            'R': ['R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R'],
            'F': ['G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'],
            'D': ['Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'],
            'L': ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'],
            'B': ['B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'],
        }

    def try_solve(self):
        try:
            solution = kociemba.solve(
                serialization.serialize_input(self.permutation))

            if solution:
                print(solution)
                serialized_solution = serialization.serialize_output(solution)
                print(serialized_solution)
                serial_data_transfer.send(serialized_solution)

        except:
            print("Solving error")
