#include <stdio.h>
#include "jnitest.h"

void simpleCMethod() {
    printf("***** Simple C method");
}
                    
JNIEXPORT jint JNICALL Java_JNITest_native_1doubleInt
  (JNIEnv *pEnv, jobject  obj, jint  value){


    jmethodID mid;
    jclass    clazz;

	printf(" ***** Entering C code\n");

    simpleCMethod();

    clazz = (*pEnv)->GetObjectClass(pEnv,obj);

    mid = (*pEnv)->GetMethodID(pEnv,clazz,"java_printNumbers","()V");

    (*pEnv)->CallVoidMethod(pEnv,obj,mid);



    printf(" ***** Exiting C Code\n");

	return value*2;

}