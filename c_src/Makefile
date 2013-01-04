CXX=colorgcc

JAVA_HOME=/tmp/zorbaroot/jdk1.6.0_38/
ZORBA_BUILD_HOME=/tmp/zorbaroot/zorba-build
ZORBA_HOME=/tmp/zorbaroot/zorba-2.7.0
OUTPUT_LIB_DIR=../c_bin

export LD_LIBRARY_PATH=$(ZORBA_BUILD_HOME)/src
ZORBA_CFLAGS=-I$(ZORBA_HOME)/include/ -I$(ZORBA_BUILD_HOME)/include
CXXFLAGS=-Wall -O2 -I/usr/include/ -fPIC -I. -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux $(ZORBA_CFLAGS)
OBJS=ZorbaWrapperTest.o
LIBOBJS=ZorbaWrapper.o
SWIG_OBJS=ZorbaJavaWrapperSWIG_wrap.o
PROGNAME=zorbawrapper
LDFLAGS=-L. -L$(ZORBA_BUILD_HOME)/src -L/usr/lib -lzorba_simplestore

default: clean all

copy-modules:
	mkdir $(OUTPUT_LIB_DIR)
	cp -R -v $(ZORBA_BUILD_HOME)/LIB_PATH $(OUTPUT_LIB_DIR)/
	rm -vf `find $(OUTPUT_LIB_DIR)/LIB_PATH -type f | grep -v -e "\.so\|\.xq\|\.zth\|\.xsd"`
	cp -R -v $(ZORBA_BUILD_HOME)/URI_PATH $(OUTPUT_LIB_DIR)/
	rm -vf `find $(OUTPUT_LIB_DIR)/URI_PATH -type f | grep -v -e "\.so\|\.xq\|\.zth\|\.xsd"`
	#cp -R -v $(ZORBA_BUILD_HOME)/modules $(OUTPUT_LIB_DIR)/
	#rm -vf `find $(OUTPUT_LIB_DIR)/modules -type f | grep -v -e "\.so\|\.xq\|\.zth\|\.xsd"`
	cd $(OUTPUT_LIB_DIR) && find ./LIB_PATH -type f >> filelist 
	cd $(OUTPUT_LIB_DIR) && find ./URI_PATH -type f >> filelist 
	#cd $(OUTPUT_LIB_DIR) && find ./modules -type f >> filelist 

swig:	
	mkdir -p ../src-gen/br/com/s1mbi0se/zorbawrapper
	swig -c++ -java -package br.com.s1mbi0se.zorbawrapper -outdir ../src-gen/br/com/s1mbi0se/zorbawrapper ZorbaJavaWrapperSWIG.i	
	$(CXX) $(CXXFLAGS) -c -o ZorbaJavaWrapperSWIG_wrap.o ZorbaJavaWrapperSWIG_wrap.cxx

all: swig copy-modules $(LIBOBJS) $(OBJS) 	
	# ln -s $(OUTPUT_LIB_DIR)/libzorba_simplestore.so.2.7.0 $(OUTPUT_LIB_DIR)/libzorba_simplestore.so
	$(CXX) -shared $(LIBOBJS) $(SWIG_OBJS) -o $(OUTPUT_LIB_DIR)/lib$(PROGNAME).so $(LDFLAGS)  
	$(CXX) $(OBJS) -o $(PROGNAME) $(LDFLAGS) -L$(OUTPUT_LIB_DIR) -l$(PROGNAME) 
	ldd $(OUTPUT_LIB_DIR)/libzorbawrapper.so | cut -d">" -f 2 | cut -d "(" -f 1 > $(OUTPUT_LIB_DIR)/dll_deps
	for x in `cat $(OUTPUT_LIB_DIR)/dll_deps`; do cp $$x $(OUTPUT_LIB_DIR)/; done
	cat $(OUTPUT_LIB_DIR)/dll_deps
	ls $(OUTPUT_LIB_DIR)

clean: 
	rm -fr $(OUTPUT_LIB_DIR) $(OBJS) $(LIBOBJS) $(PROGNAME) lib$(PROGNAME).so ZorbaJavaWrapperSWIG*.c* ZorbaJavaWrapperSWIG*.java libzorba_simplestore.so
