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
cd linux-source
tar zxf ~/Downloads/linux-1.0.tar.xz
cd ..
mv linux-1.0 V1.0

./scripts/configure-lxr.pl -vv
sudo ./ custom.d/initdb.sh
cp custom.d/lxr.conf .

./genxref --url=http://localhost/lxr --version=V1.0

apache2ctl restart
sudo cp custom.d/apache-lxrserver.conf /etc/apache2/conf-available
sudo a2enconf apache-lxrserver.conf
sudo a2dismod mpm*
sudo apt-get install apache2-mpm-worker
sudo a2enmod mpm_worker





