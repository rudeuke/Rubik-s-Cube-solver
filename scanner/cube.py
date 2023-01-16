import random
import kociemba
import serialization
import face_recognition
import serial_data_transfer


class Cube:
    permutation = {}
    color_to_face = {}

    def __init__(self):
        self.permutation = {
            'U': ['W', 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W'],
            'R': ['R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R'],
            'F': ['G', 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'G'],
            'D': ['Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'],
            'L': ['O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'],
            'B': ['B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B'],
        }
        self.color_to_face = {
            'W': 'U',
            'R': 'R',
            'G': 'F',
            'Y': 'D',
            'O': 'L',
            'B': 'B',
        }

    def try_solve(self):
        try:
            solution = kociemba.solve(
                serialization.serialize_input(self.permutation))

        except:
            print("Solving error")

        else:
            print("Solving...")
            print(solution)
            serialized_solution = serialization.serialize_output(solution)
            serial_data_transfer.send(serialized_solution)

    def update_orientation(self):
        first_face = self.permutation['U'][4]
        second_face = self.permutation['F'][4]
        self.color_to_face = face_recognition.determine_orientation(
            first_face, second_face)

    def get_random_algorithm(self, number_of_moves=10):
        algorithm = ''
        last_move = ' '
        moves = ['U', 'U\'', 'U2', 'D', 'D\'', 'D2', 'L', 'L\'', 'L2',
                 'R', 'R\'', 'R2', 'F', 'F\'', 'F2', 'B', 'B\'', 'B2']

        for _ in range(number_of_moves):
            move = random.choice(moves)
            while last_move[0] in move:
                move = random.choice(moves)

            algorithm += move + ' '
            last_move = move

        return algorithm

    def scramble(self, number_of_moves=10):
        algorithm = self.get_random_algorithm(number_of_moves)
        print(f"Scrambling...")
        print(algorithm)
        serialized_algorithm = serialization.serialize_output(algorithm)
        serial_data_transfer.send(serialized_algorithm)
