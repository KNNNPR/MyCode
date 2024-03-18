package ru.mirea.lab4.num7;

public class LearnerTester {
    public static void main(String[] args) {
        Learner[] learners = new Learner[4];
        learners[0] = new Pupil("Дмитрий");
        learners[1] = new Pupil("Александра");
        learners[2] = new Student("Алексей");
        learners[3] = new Student("Елена");

        System.out.println("Школьники: ");
        for (Learner learner : learners) {
            if (learner instanceof Pupil) {
                Pupil pupil = (Pupil) learner;
                System.out.println("Имя: " + pupil.getName());
            }
        }
        System.out.println();
        System.out.println("Студенты: ");
        for (Learner learner : learners) {
            if (learner instanceof Student) {
                Student student = (Student) learner;
                System.out.println("Имя: " + student.getName());
            }
        }
    }
}
