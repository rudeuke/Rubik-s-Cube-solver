import shared_variables


def send(data):
   shared_variables.ARDUINO_PORT.write(data.encode())


def receive():
    return shared_variables.ARDUINO_PORT.read().decode('ascii')
