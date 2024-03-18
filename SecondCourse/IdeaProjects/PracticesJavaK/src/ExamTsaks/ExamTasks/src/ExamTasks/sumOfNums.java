package ExamTasks;

public class sumOfNums {
    public static int sumOfNums(int userNumber, int result) {
        if(userNumber == 0) return(result);
        return(sumOfNums(userNumber / 10, result+= userNumber % 10));
    }


    public static void main(String[] args) {
        System.out.println(sumOfNums(77899, 0));
    }
}
