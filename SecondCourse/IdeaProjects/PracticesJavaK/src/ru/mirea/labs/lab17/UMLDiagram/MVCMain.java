package ru.mirea.labs.lab17.UMLDiagram;

public class MVCMain {
    public static void main(String[] args) {
        Student model = new Student();

        StudentView view = new StudentView();

        StudentController control = new StudentController(model, view);

        control.setStudentName("Fedya");
        control.setStudentRollNo("rollDop yes yes");

        control.updateView();
    }
}
