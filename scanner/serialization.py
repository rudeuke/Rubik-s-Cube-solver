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

    if '\'' in move:
        simple_move = simple_move.lower()

    if '2' in move:
        simple_move = chr(ord(simple_move) + 1)

    return simple_move
