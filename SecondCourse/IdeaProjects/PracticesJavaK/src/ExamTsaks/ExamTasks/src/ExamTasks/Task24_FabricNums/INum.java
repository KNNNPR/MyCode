package ExamTasks.Task24_FabricNums;

public class INum extends Num{
    private int imageValueOfNum;
    public INum(int valueOfNum, int imageValueOfNum) {
        super(valueOfNum);
        this.imageValueOfNum = imageValueOfNum;
    }

    public int getImageValueOfNum() {
        return imageValueOfNum;
    }

    public void setImageValueOfNum(int imageValueOfNum) {
        this.imageValueOfNum = imageValueOfNum;
    }
}
