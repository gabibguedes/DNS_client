import socket
port = 5000

udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
origin = ('', port)
udp.bind(origin)
#udp.settimeout(100)
while True:

    msg, cliente = udp.recvfrom(1024)
    print(cliente,': ', msg)

udp.close()
