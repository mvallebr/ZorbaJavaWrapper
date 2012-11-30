#!/bin/sh

export TEMP_FOLDER="/tmp/zorbaroot/"
export JAVA_DISTRO_BIN=jdk-6u37-linux-i586.bin
export JAVA_DISTRO_FOLDER=$HOME/Downloads
export C_SRC=$PWD

sudo apt-get install -y cmake libxml2-dev uuid-dev gcc make libicu-dev xerces-c3.1 libxerces-c-dev g++ swig colorgcc
#optional
sudo apt-get install -y libcurl4-openssl-dev flex bison
#optional 2
sudo apt-get install -y libboost-dev libedit-dev

rm -fr $TEMP_FOLDER
mkdir $TEMP_FOLDER
export CHROOTCMD="cd $TEMP_FOLDER && "

#not needed, as it already comes with wget
#$CHROOTCMD apt-get install wget
sh -c "$CHROOTCMD wget --no-check-certificate https://launchpad.net/zorba/trunk/2.7/+download/zorba-src-2.7.0.tar.gz"
sh -c "$CHROOTCMD tar -zxvf zorba-src-2.7.0.tar.gz"

sh -c "$CHROOTCMD mkdir ./zorba-build"
sh -c "$CHROOTCMD cd ./zorba-build && cmake  -DCMAKE_BUILD_TYPE=RELEASE -build . ../zorba-2.7.0/"
sh -c "$CHROOTCMD cd ./zorba-build && make"

#copy java
cp $JAVA_DISTRO_FOLDER/$JAVA_DISTRO_BIN $TEMP_FOLDER
chmod +x $TEMP_FOLDER/$JAVA_DISTRO_BIN
sh -c "$CHROOTCMD ./$JAVA_DISTRO_BIN"


#compile javawrapper source
mkdir -p $TEMP_FOLDER/javawrapper
cp -R $C_SRC/* $TEMP_FOLDER/javawrapper
sh -c "cd $TEMP_FOLDER/javawrapper && make"

echo "Execute the following command to copy the c_bin folder"
echo sh -c "cd $C_SRC && cp -R $TEMP_FOLDER/c_bin/ .."
echo "Don't forget to customize ../c_bin/dll_deps file, as it might be needed"
