package ExamTasks.Task24_FabricNums;

public class FabricNum {
    public static Num getNum(int num, int iNum) {
        return new INum(num, iNum);
    }
    public static Num getNum(int num) {
        return new Num(num);
    }
    public static void main(String[] args) {
        Num num = getNum(1);
        num = getNum(2, 3);
    }
}

