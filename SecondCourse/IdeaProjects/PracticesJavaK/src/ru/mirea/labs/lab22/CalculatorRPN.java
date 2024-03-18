package ru.mirea.labs.lab22;

import java.util.Scanner;
import java.util.Stack;

public class CalculatorRPN {
    public static double calculateRPN(String expression) {
        String[] tokens = expression.split(" "); //разделение операндов и операций и помещение их в массив
        Stack<Double> stack = new Stack<>();

        for (String token : tokens) {
            if (isNumber(token)) {
                stack.push(Double.parseDouble(token));
            } else if (isOperator(token)) {
                if (stack.size() < 2) {
                    throw new IllegalArgumentException("Недопустимое выражение: недостаточно операндов для операции " + token);
                }
                double operand2 = stack.pop();
                double operand1 = stack.pop();
                double result = performOperation(operand1, operand2, token);
                stack.push(result);
            } else {
                throw new IllegalArgumentException("Недопустимое выражение: неизвестный токен " + token);
            }
        }

        if (stack.size() != 1) {
            throw new IllegalArgumentException("Недопустимое выражение: слишком много операндов");
        }

        return stack.pop();
    }

    private static boolean isNumber(String token) {
        try {
            Double.parseDouble(token);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    private static boolean isOperator(String token) {
        return token.matches("[+\\-*/]");
    }

    private static double performOperation(double operand1, double operand2, String operator) {
        switch (operator) {
            case "+":
                return operand1 + operand2;
            case "-":
                return operand1 - operand2;
            case "*":
                return operand1 * operand2;
            case "/":
                if (operand2 == 0) {
                    throw new ArithmeticException("Делить на 0 нельзя.");
                }
                return operand1 / operand2;
            default:
                throw new IllegalArgumentException("Недопустимый оператор: " + operator);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Введите выражение в обратной Польской записи (каждое значение необходимо записывать через пробел): ");
        String rpnExpression = sc.nextLine();
        double result = calculateRPN(rpnExpression);
        System.out.println("RPN Expression: " + rpnExpression);
        System.out.println("Result: " + result);
    }
}



