# jni-dbg
JNI debug testing.

##mingw build
###jnitest
mingw32-gcc -Wall -g -DBUILD_DLL -Id:/jdk1.6.0_45/include -Id:/jdk1.6.0_45/include/win32 -c jnitest.c -o jnitest.o
mingw32-g++ -shared   -Wl,--dll  jnitest.o  -o jnitest.dll -nostdlib -Wl,--add-stdcall-alias -luser32 -lgcc -lmsvcrt

###main
mingw32-gcc.exe -g -Id:/jdk1.6.0_45/include -Id:/jdk1.6.0_45/include/win32 -c main.c -o main.o
mingw32-g++.exe -o main.exe main.o -Ld:/jdk1.6.0_45/lib -ljvm -luser32 -lgcc -lmsvcrt

###Linux build
gcc -g -fPIC -I/usr/lib/jvm/java-7-openjdk-amd64/include -shared -o libjnitest.so jnitest.c

##jdb testing
>java -Xdebug -Xnoagent -Djava.compiler=none -Xrunjdwp:transport=dt_socket,server=y,suspend=y JNITest
>jdb -attach 63876
>jdb -connect com.sun.jdi.SocketAttach:hostname=localhost,port=63876

stop at class:line
stop in class:method

Ref: https://www.ibm.com/developerworks/cn/java/j-jnidebug/
