#!/bin/bash

sudo apt-get update -y
sudo apt-get install -y ctags
sudo apt install mysql-server
sudo apt install apache2
sudo apt-get install -y glimpse
sudo apt install libfile-mmagic-perl
sudo apt-get install -y libclass-dbi-mysql-perl
sudo apt-get install libmysqlclient-dev

cd ~
tar -zxf ~/Downloads/lxr-2.3.6.tgz
mv lxr-2.3.6 lxr
cd lxr 
mkdir linux-source
tar zxf ~/Downloads/linux 5.19.9.tar.xz

