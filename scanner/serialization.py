import cube


def serialize_input(permutation):
    serialized = ''
    for i in permutation:
        for j in permutation[i]:
            serialized += cube.COLOR_TO_FACE[j]

    return serialized


def serialize_output(algorithm):
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
