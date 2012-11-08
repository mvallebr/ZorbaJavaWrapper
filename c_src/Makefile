CXX=colorgcc

JAVA_HOME=/opt/jdk1.7.0_07
CXXFLAGS=-Wall -O2 -I/usr/include/ -fPIC -I. -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux
OBJS=ZorbaWrapperTest.o
LIBOBJS=ZorbaWrapper.o
SWIG_OBJS=ZorbaJavaWrapperSWIG_wrap.o
PROGNAME=zorbawrapper
LDFLAGS=-L/usr/lib -L. -lzorba_simplestore

default: clean all

swig:
	swig -java -outdir ../src-gen ZorbaJavaWrapperSWIG.i
	#mv ZorbaJavaWrapperSWIG_wrap.cxx ZorbaJavaWrapperSWIG_wrap.cc
	$(CXX) $(CXXFLAGS) -c -o ZorbaJavaWrapperSWIG_wrap.o ZorbaJavaWrapperSWIG_wrap.c

all: swig $(LIBOBJS) $(OBJS) 	
	$(CXX) -shared $(LIBOBJS) $(SWIG_OBJS) -o lib$(PROGNAME).so $(LDFLAGS)  
	$(CXX) $(OBJS) $(LIBOBJS) -o $(PROGNAME) $(LDFLAGS)
	ldd $(PROGNAME)

clean: 
	rm -f $(OBJS) $(LIBOBJS) $(PROGNAME) lib$(PROGNAME).so ZorbaJavaWrapperSWIG*.c* ZorbaJavaWrapperSWIG*.java
