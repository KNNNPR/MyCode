package ru.mirea.labs.lab17.UMLDiagram;

public class StudentController {
    private Student model;
    private StudentView view;

    public StudentController(Student model, StudentView view) {
        this.model = model;
        this.view = view;
    }
    public String getStudentName() {
        return(model.getName());
    }
    public String getStudentRollNo() {
        return(model.getRollNo());
    }
    public void setStudentName(String newName) {
        this.model.setName(newName);
    }
    public void setStudentRollNo(String newRollNo) {
        this.model.setRollNo(newRollNo);
    }
    public void updateView() {
        this.view.printStudentDetails(this.model.getRollNo(), this.model.getName());
    }
}
