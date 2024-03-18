package ExamTasks.Task24_FabricNums;

public class Num {
    private int valueOfNum;

    @Override
    public String toString() {
        return "Num{" +
                "valueOfNum=" + valueOfNum +
                '}';
    }

    public void setValueOfNum(int valueOfNum) {
        this.valueOfNum = valueOfNum;
    }

    public int getValueOfNum() {
        return valueOfNum;
    }

    public Num(int valueOfNum) {
        this.valueOfNum = valueOfNum;
    }
}
