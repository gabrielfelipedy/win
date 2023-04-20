#! /usr/bin/python3

from datetime import datetime
import abc
import argparse
import os
import shelve
import socket
import shlex
import subprocess
import sys
import textwrap

#global variables
path = os.path.join('/data', 'data', 'com.termux', 'files', 'home', 'win')
print(os.getcwd())
os.chdir(path)
print(os.getcwd())
clients = shelve.open('data')

class CalculaValor(abc.ABC):
    @abc.abstractmethod
    def calcular(self):
        pass

class CalculaTrintaEUm:
    def calcular(self, date):
        periodo = datetime.now() - date
        days = datetime.strptime("01/02/23", "%d/%m/%y") - datetime.strptime("01/01/23", "%d/%m/%y")
        return periodo > days

class CalculaTrinta:
    def calcular(self, date):
        periodo = datetime.now() - date
        days = datetime.strptime("31/01/23", "%d/%m/%y") - datetime.strptime("01/01/23", "%d/%m/%y")
        return periodo > days

CalculaValor.register(CalculaTrinta)
CalculaValor.register(CalculaTrintaEUm)

class Client:

    def _metodoDeCalculo(self):
        if(self._date.month in [4, 6, 9, 11]):
            return CalculaTrinta()
        else:
            return CalculaTrintaEUm()

    def __init__(self, name, service, date=datetime.now()):
        self._name = name
        self._service  = service
        self._date = date
        self._CalculaValor = self._metodoDeCalculo() #aqui vou mexer depois

    def noPrazo(self):
        if self._CalculaValor.calcular(self._date):
            return "Prazo Vencido"
        else:
            return "No prazo"

    def setCalculo(self, CalculoValor):
        self._CalculoValor = CalculoValor

    def __str__(self):
        try:
            return '\nName of client:      ---> '+ str(self._name) + '\nService of Streaming ---> ' + str(self._service) + '\nDate of payment      ---> ' + str(self._date.strftime("%d/%m/%y")) + '\nStatus: ' + str(self.noPrazo())
        except Exception as e:
            return str(e)

    def update(self):
        self._date = datetime.today()

def list_clients():
    if not clients.items():
        title = 'EMPTY'.center(20, '=')
    else:
        title = 'CLIENT INFO'.center(20, '=')
    print(f'\n{title}\n')
    for k, v in clients.items():
        print_info(v)

def print_info(client):
    print(client)

def add(args):
    if not args.name or not args.service:
        print("Missing arguments".center(20, '='))
    else:
        clients[args.name] = Client(args.name, args.service)
        if args.date: insert_date(args, args.name)
        print(f"[*] Client {clients[args.name]._name} added on the system") 

def change(args):
    name = args.change
    if args.date:
        try:
            insert_date(args, name)
            print(f"[*] Date of {name} changed to {args.date}")
        except ValueError as e:
            print('[!] Invalid value')

def insert_date(args, arg_name):
        date = str(args.date)
        name = str(arg_name)
        date = datetime.strptime(date, "%d/%m/%y")
        obj = clients[name]
        obj._date = date
        clients[name] = obj

def del_client(args):
    try:
        del(clients[args.backspace])
        print(f"[*] Client {args.backspace} removed of system")
    except KeyError as e:
        print(f'''[!!] No client {args.backspace} on system
Error: {e}''')

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

    args = parser.parse_args()
    if args.add: add(args)
    if args.change: change(args)
    if args.list: list_clients()
    if args.backspace: del_client(args)
    if args.update: args.update.update()
