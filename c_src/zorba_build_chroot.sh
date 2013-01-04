#!/bin/sh

export TEMP_FOLDER="/tmp/squeeze/"
export JAVA_DISTRO_BIN=jdk-6u38-linux-i586.bin
export JAVA_DISTRO_FOLDER=$HOME/Downloads

sudo apt-get install pbuilder debootstrap devscripts
#sudo pbuilder create --distribution squeeze --mirror ftp://ftp.us.debian.org/debian/ --debootstrapopts --keyring=/usr/share/keyrings/debian-archive-keyring.gpg
sudo debootstrap --arch i386 squeeze $TEMP_FOLDER http://ftp.uk.debian.org/debian/

export CHROOTCMD="sudo chroot $TEMP_FOLDER"

$CHROOTCMD apt-get install -y cmake libxml2-dev uuid-dev gcc make libicu-dev xerces-c3.1 libxerces-c-dev g++ swig colorgcc
#optional
$CHROOTCMD apt-get install -y libcurl4-openssl-dev flex bison
#optional 2
$CHROOTCMD apt-get install -y libboost-dev libedit-dev

#not needed, as it already comes with wget
#$CHROOTCMD apt-get install wget
$CHROOTCMD bash -c "cd /tmp/zorbaroot/ && wget --no-check-certificate https://launchpad.net/zorba/trunk/2.7/+download/zorba-src-2.7.0.tar.gz"
$CHROOTCMD bash -c "cd /tmp/zorbaroot/ && tar -zxvf zorba-src-2.7.0.tar.gz" 

$CHROOTCMD mkdir -p /tmp/zorbaroot/zorba-build
$CHROOTCMD bash -c "cd /tmp/zorbaroot/zorba-build && cmake  -DCMAKE_BUILD_TYPE=RELEASE -build /zorba-build /zorba-2.7.0/"
$CHROOTCMD bash -c "cd /tmp/zorbaroot/zorba-build && make"

#copy java
sudo cp $JAVA_DISTRO_FOLDER/$JAVA_DISTRO_BIN $TEMP_FOLDER/tmp/zorbaroot/
$CHROOTCMD chmod +x /tmp/zorbaroot/$JAVA_DISTRO_BIN
$CHROOTCMD /tmp/zorbaroot/$JAVA_DISTRO_BIN


#compile javawrapper source
$CHROOTCMD mkdir /javawrapper
sudo cp -R . $TEMP_FOLDER/javawrapper
$CHROOTCMD bash -c "cd /javawrapper && make"

echo "Execute the following command to copy the c_bin folder"
echo cp -R $TEMP_FOLDER/c_bin/ ..
echo "Don't forget to customize ../c_bin/dll_deps file, as it might be needed"
