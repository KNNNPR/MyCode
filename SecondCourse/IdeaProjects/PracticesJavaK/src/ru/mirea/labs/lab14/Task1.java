package ru.mirea.labs.lab14;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.Scanner;

public class Task1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Введите строку:");
        String inputString = scanner.nextLine();

        while (true) {
            System.out.println("Выберите операцию:");
            System.out.println("1. Разбить строку по регулярному выражению");
            System.out.println("2. Найти совпадения по регулярному выражению");
            System.out.println("3. Заменить совпадения по регулярному выражению");
            System.out.println("4. Выйти из программы");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Введите регулярное выражение для разделения:");
                    String delimiter = scanner.next();
                    String[] parts = inputString.split(delimiter);
                    for (String part : parts) {
                        System.out.println(part);
                    }
                    break;

                case 2:
                    System.out.println("Введите регулярное выражение для поиска:");
                    String searchRegex = scanner.next();
                    Pattern pattern = Pattern.compile(searchRegex);
                    Matcher matcher = pattern.matcher(inputString);

                    while (matcher.find()) {
                        System.out.println("Найдено совпадение: " + matcher.group());
                    }
                    break;

                case 3:
                    System.out.println("Введите регулярное выражение для замены:");
                    String replaceRegex = scanner.next();
                    System.out.println("Введите замену:");
                    String replacement = scanner.next();
                    String replacedString = inputString.replaceAll(replaceRegex, replacement);
                    System.out.println("Результат после замены: " + replacedString);
                    break;

                case 4:
                    System.out.println("Программа завершена.");
                    scanner.close();
                    System.exit(0);

                default:
                    System.out.println("Неверный выбор. Попробуйте еще раз.");
            }
        }
    }
}

