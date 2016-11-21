#include <stdio.h>
#include <jni.h>

void goTest(JNIEnv *pEnv);

void main(void) {

	JavaVMInitArgs vm_args;
	JavaVMOption options[6];
   jint res;
   JavaVM *vm;
   JNIEnv *pEnv;

	options[0].optionString = "-Djava.compiler=NONE";           /* disable JIT */
	options[1].optionString = "-Djava.class.path=e:\\freespace\\rtos\\jni-dbg"; /* user classes */
	//options[2].optionString = "-Djava.library.path=c:\mylibs";  /* set native library path */
	options[2].optionString = "-Xbootclasspath/a:d:\\jdk1.6.0_45\\lib\\tools.jar";
	options[3].optionString = "-Xdebug";                   /* print JNI-related messages */
    options[4].optionString = "-Xnoagent";
    options[5].optionString = "-Xrunjdwp:transport=dt_socket,server=y,suspend=n";

	vm_args.version = JNI_VERSION_1_6;
	vm_args.options = options;
	vm_args.nOptions = 6;
	vm_args.ignoreUnrecognized = JNI_FALSE;

	/* Note that in JDK 1.2, there is no longer any need to call
	 * JNI_GetDefaultJavaVMInitArgs.
	*/
   res = JNI_CreateJavaVM(&vm, (void **)&pEnv, &vm_args);
   if (res < 0) {
      printf("failure in create java vm\n");
   }

   {
       int loop=0;
       while (loop==0) {
           printf("waiting...");
       }
   }

   goTest(pEnv);


}

void goTest(JNIEnv *pEnv) {

   jclass    javaClass;
   jmethodID mid;
   jint      result;

   javaClass = (*pEnv)->FindClass(pEnv,"JNITest");

   mid = (*pEnv)->GetStaticMethodID(pEnv,javaClass,"java_tripleNumber","(I)I");

   result = (*pEnv)->CallStaticIntMethod(pEnv,javaClass,mid,42) ;



}

