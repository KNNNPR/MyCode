package ExamTasks.Task23_FabricGeometry;

public class Rectangle implements Shape{
    private double length;
    private double width;



    public Rectangle(double userLength, double userWidth) {
        length = userLength;
        width = userWidth;
    }
    @Override
    public double getArea() {
        return (length*width);
    }

    @Override
    public double getPerim() {
        return (width * 2 + length* 2);
    }
}
