

/**
 * Class to illustrate use of native methods.
 * 
 * Contains a native method as part of the class, plus
 * a number of methods other test methods.
 * 
 * @author Matthew B White
 */
public class JNITest {


    public static void main(String args[]) {
        System.out.println("In Java Main... ");

        System.out.println("Loading the library...");
        System.loadLibrary("jnitest");

        
        System.out.println(" ##### About to call native method ");
        /* ... call the native method */
        new JNITest().native_doubleInt(42);

        System.out.println(" ##### About to call again ");
        new JNITest().native_doubleInt(42);

    }


    /**
     * Java method to double an integer
     * 
     * @param value  Integer to double
     * @return Int
     */
    public int java_doubleInt(int value) {
        return value * 2;
    }


    public void java_printNumbers() {
        int start=10;
        int count=5;

        for (int i=start; i<start+count;i++) {
            System.out.println("Num="+i);
        }
    }

    public native int native_doubleInt(int value);


     

    public static int java_tripleNumber(int value) {
        System.out.println(" #### In java_tripleNumber ");
        return value*3;
    }
    
}
