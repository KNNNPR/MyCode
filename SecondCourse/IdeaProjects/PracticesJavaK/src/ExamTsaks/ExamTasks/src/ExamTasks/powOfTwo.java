package ExamTasks;

public class powOfTwo {
    public static void powOfTwo(int userNumber) {
        if(userNumber == 1) {
            System.out.println("YES");
            return;
        }
        if(userNumber % 2 != 0) {
            System.out.println("NO");
            return;
        }
        else {
            powOfTwo(userNumber / 2);
        }
    }


    public static void main(String[] args) {
        powOfTwo(1024);
    }
}
