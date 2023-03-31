from datetime import date
import argparse
import shelve
import socket
import shlex
import subprocess
import sys
import textwrap

#global variables

clients = shelve.open('data')

class Client:

    def __init__(self, name, service, date=None):

        self.name = name
        self.service  = service
        self.date = date

    def update():
        #TODO: updates the date
        return 0
        

def list_clients():
 
    title = 'CLIENT INFO'.center(20, '=')
    print(f'\n{title}\n')

    for k, v in clients.items():
        print_info(v)

def print_info(client):

    print(f'''Name of client:      ---> {client.name}
Service of Streaming ---> {client.service}
Date of payment      ---> {client.date}

    ''')

def add(args):
    if not args.name or not args.service:
        print("Missing arguments")
    else:
        clients[args.name] = Client(args.name, args.service, args.date)
        print(f"[*] Client {clients[args.name].name} added on the system") 

def delete(client):
    #TODO: deletes a client
    return 0

def change(args):

    obj = args.change
    if args.date:

        obj = clients[obj]
        obj.date = args.date
        print(f"[*] Date of {obj.name} changed to {obj.date}")

    clients[args.change] = obj
    clients.close()

def show_payments():

    #TODO: shows the payment contability

    return 0

if __name__ == '__main__':

    parser = argparse.ArgumentParser(description='WIN Streaming Screen Manager',formatter_class=argparse.RawDescriptionHelpFormatter, epilog=textwrap.dedent('''Example:
    win.py -a -n Maria -s Netflix -d 190804 # add client
    win.py -u Maria # update date of payment
    win.py -c Maria -s Disney+ # changes the service to Disney+
    win.py -d Maria # deletes the client Maria
    '''))

    parser.add_argument('-a', '--add', action='store_true', help='add client')
    parser.add_argument('-u', '--update', help='update the date of the payment')
    parser.add_argument('-b', '--backspace', help='delete a client')
    parser.add_argument('-n', '--name', help='sets the name of the client')
    parser.add_argument('-s', '--service', help='sets the service of streaming')
    parser.add_argument('-l', '--list', action='store_true', help='list all the clients recorded')
    parser.add_argument('-c', '--change', help='changes the value of a object')
    parser.add_argument('-d', '--date', help='sets the date of the payment')
    parser.add_argument('-p', '--payments', action='store_true', help='shows the payment contability') 

    args = parser.parse_args()

    if args.add:
        add(args)

    if args.change:
        change(args)

    if args.list:
        list_clients()

    if args.payments:
        show_payments()
