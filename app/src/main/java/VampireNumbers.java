/**
 * Vampire Number Examples:
 * 1260 = 21*60
 * 1827 = 32*87
 * 2187 = 27*81
 */
public class VampireNumbers {

    public static void main(String[] args) {
        int[] intArr = new int[4];
        for (int num = 1001; num < 10000; num++) {
            if (num % 100 == 0) {
                continue;
            }

//            int tempNum = num;
//            intArr[0] = tempNum / 1000;
//            tempNum = tempNum - intArr[0] * 1000;
//            if(tempNum >= 100) {
//                intArr[1] = tempNum / 100;
//                tempNum = tempNum - intArr[1] * 100;
//            }
//            if(tempNum >= 10){
//                intArr[2] = tempNum / 10;
//                tempNum = tempNum - intArr[2] * 10;
//            }
//            intArr[3] = tempNum % 10;


            int tempNum = num;
            for (int i = 0; tempNum > 0 && i < intArr.length; i++) {
                intArr[i] = tempNum % 10;
                tempNum = tempNum / 10;
            }

            for (int i = 0; i < intArr.length; i++) {
                prt(intArr[i] + " ");
            }

            prtln("");
        }
    }

    public static void prt(String msg) {
        System.out.print(msg);
    }

    public static void prtln(String msg) {
        System.out.println(msg);
    }
}
