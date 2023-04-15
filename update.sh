#!/usr/bin/bash

<<note

This script was projected for termux on android
for use it at your OS, change the path of the alias named path

Thanks for visit this repository!
note

cd ~/../usr/bin/
echo ------
echo BEFORE
echo ------
ls | tail -n 50

rm -rf win.py
echo ------
echo DELETED
echo ------
ls | tail -n 50

cd ~/win/
cp win.py ~/../usr/bin/
cd ~/../usr/bin/
echo ---
echo COPY
echo ---
ls | tail -n 50
echo "[*] Win.py updated"
