#!/bin/sh

export TEMP_FOLDER="/tmp/squeeze/"
export JAVA_DISTRO_BIN=jdk-6u37-linux-i586.bin
export JAVA_DISTRO_FOLDER=$HOME/Downloads

sudo apt-get install pbuilder debootstrap devscripts
#sudo pbuilder create --distribution squeeze --mirror ftp://ftp.us.debian.org/debian/ --debootstrapopts --keyring=/usr/share/keyrings/debian-archive-keyring.gpg
sudo debootstrap --arch i386 squeeze $TEMP_FOLDER http://ftp.uk.debian.org/debian/

export CHROOTCMD="sudo chroot $TEMP_FOLDER"

#not needed, as it already comes with wget
#$CHROOTCMD apt-get install wget
$CHROOTCMD wget --no-check-certificate https://launchpad.net/zorba/trunk/2.7/+download/zorba-src-2.7.0.tar.gz
$CHROOTCMD tar -zxvf zorba-src-2.7.0.tar.gz 
$CHROOTCMD apt-get install -y cmake libxml2-dev uuid-dev gcc make libicu-dev xerces-c3.1 libxerces-c-dev g++ swig colorgcc

$CHROOTCMD mkdir /zorba-build
$CHROOTCMD bash -c "cd /zorba-build && cmake  -DCMAKE_BUILD_TYPE=RELEASE -build /zorba-build /zorba-2.7.0/"
$CHROOTCMD bash -c "cd /zorba-build && make"

#copy java
sudo cp $JAVA_DISTRO_FOLDER/$JAVA_DISTRO_BIN $TEMP_FOLDER
$CHROOTCMD chmod +x /$JAVA_DISTRO_BIN
$CHROOTCMD /$JAVA_DISTRO_BIN


#compile javawrapper source
$CHROOTCMD mkdir /javawrapper
sudo cp -R . $TEMP_FOLDER/javawrapper
$CHROOTCMD bash -c "cd /javawrapper && make"

sudo cp -R $TEMP_FOLDER/c_bin/ ..
echo "Don't forget to customize ../c_bin/dll_deps file, as it might be needed"
