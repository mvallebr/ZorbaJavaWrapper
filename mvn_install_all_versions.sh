#!/bin/sh
mvn -Dmaven.test.skip=true -Pdebian32 clean install
mvn -Dmaven.test.skip=true -Pubuntu32 clean install
mvn -Dmaven.test.skip=true -Pubuntu64 clean install


