import cube
import shared_variables


def serialize_input(permutation):
    serialized = ''
    for i in permutation:
        for j in permutation[i]:
            serialized += shared_variables.my_cube.color_to_face[j]

    return serialized


def serialize_output(algorithm):
    serialized = ''
    for move in algorithm.split():
        serialized += serialize_move(move)

    serialized += '\n'
    return serialized


def serialize_move(move):
    simple_move = move[0]
    color_to_be_moved = cube.FACE_TO_COLOR[simple_move]
    oriented_move = shared_variables.my_cube.color_to_face[color_to_be_moved]

    if '\'' in move:
        oriented_move = oriented_move.lower()

    if '2' in move:
        oriented_move = chr(ord(oriented_move) + 1)

    return oriented_move
