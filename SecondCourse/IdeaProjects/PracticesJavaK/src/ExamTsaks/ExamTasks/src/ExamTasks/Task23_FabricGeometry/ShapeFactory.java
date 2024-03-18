package ExamTasks.Task23_FabricGeometry;

public class ShapeFactory {
    public static Shape createShape(ShapeE userChoice, double... args) {
        switch (userChoice) {
            case CIRCLE -> {
                return(new Circle(args[0]));
            }
            case RECTANGLE -> {
                return(new Rectangle(args[0], args[1]));
            }
            default -> throw new IllegalArgumentException("Неизвестная фигура");
        }
    }

    public static void main(String[] args) {
        Shape userShapeOne = ShapeFactory.createShape(ShapeE.CIRCLE, 23.4);

        Shape userShapeTwo = ShapeFactory.createShape(ShapeE.RECTANGLE, 77, 46.2);


        System.out.println(userShapeOne.getArea() + "  " + userShapeTwo.getPerim());
    }
}
