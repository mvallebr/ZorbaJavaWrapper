CXX=colorgcc

JAVA_HOME=/opt/jdk1.7.0_07
ZORBA_CFLAGS=-I/home/mvalle/Downloads/zorba-2.7.01/include/ -I/home/mvalle/Downloads/build1/include
CXXFLAGS=-Wall -O2 -I/usr/include/ -fPIC -I. -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux $(ZORBA_CFLAGS)
OBJS=ZorbaWrapperTest.o
LIBOBJS=ZorbaWrapper.o
SWIG_OBJS=ZorbaJavaWrapperSWIG_wrap.o
PROGNAME=zorbawrapper
LDFLAGS=-L. -L/usr/lib -lzorba_simplestore

default: clean all


swig:	
	mkdir -p ../src-gen/br/com/s1mbi0se/zorbawrapper
	swig -c++ -java -package br.com.s1mbi0se.zorbawrapper -outdir ../src-gen/br/com/s1mbi0se/zorbawrapper ZorbaJavaWrapperSWIG.i	
	$(CXX) $(CXXFLAGS) -c -o ZorbaJavaWrapperSWIG_wrap.o ZorbaJavaWrapperSWIG_wrap.cxx

all: swig $(LIBOBJS) $(OBJS) 	
	ln -s libzorba_simplestore.so.2.7.0 libzorba_simplestore.so
	$(CXX) -shared $(LIBOBJS) $(SWIG_OBJS) -o lib$(PROGNAME).so $(LDFLAGS)  
	$(CXX) $(OBJS) -o $(PROGNAME) $(LDFLAGS) -L. -l$(PROGNAME) 
	ldd $(PROGNAME)

clean: 
	rm -f $(OBJS) $(LIBOBJS) $(PROGNAME) lib$(PROGNAME).so ZorbaJavaWrapperSWIG*.c* ZorbaJavaWrapperSWIG*.java libzorba_simplestore.so
