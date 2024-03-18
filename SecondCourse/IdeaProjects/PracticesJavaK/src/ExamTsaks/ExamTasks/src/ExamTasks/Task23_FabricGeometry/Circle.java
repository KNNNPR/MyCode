package ExamTasks.Task23_FabricGeometry;

public class Circle implements Shape{
    private double radius;



    public Circle(double userRadius) {
        radius = userRadius;
    }
    @Override
    public double getArea() {
        return(Math.PI * radius * radius);
    }

    @Override
    public double getPerim() {
        return (2 * Math.PI * radius);
    }
}
