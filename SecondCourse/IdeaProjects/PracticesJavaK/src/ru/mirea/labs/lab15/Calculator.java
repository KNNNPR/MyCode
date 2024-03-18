package ru.mirea.labs.lab15;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Calculator implements ActionListener {
    static JFrame frame;
    static JTextField result;
    static String a = "", b = "", operation = "";


    public static void main(String[] args) {

        Calculator listen = new Calculator();

        frame = new JFrame("Calculator");

        result = new JTextField(10);
        result.setEditable(false);

        ArrayList<JButton> buttons = new ArrayList<>();
        for (int i = 0; i < 10; i++) {
            JButton jTempButton = new JButton(Integer.toString(i));
            jTempButton.addActionListener(listen);
            buttons.add(jTempButton);
        }

        List<String> operations = Arrays.asList("+", "-", "/", "*", "C", "=");

        JPanel opButtons = new JPanel();
        buttons.forEach(opButtons::add);
        operations.forEach(it -> {
            JButton jTmpButton = new JButton(it);
            jTmpButton.addActionListener(listen);
            opButtons.add(jTmpButton);
        });

        GridLayout numsAndOpsLayout = new GridLayout(4, 4);
        opButtons.setLayout(numsAndOpsLayout);



        JPanel mainPanel = new JPanel();
        mainPanel.add(result);
        mainPanel.add(opButtons);

        frame.add(mainPanel);
        frame.setSize(360, 180);
        frame.setVisible(true);



    }
    @Override
    public void actionPerformed(ActionEvent e) {
        System.out.println(e.getActionCommand());
        String s = e.getActionCommand();
        if (s.charAt(0) >= '0' && s.charAt(0) <= '9') {
            if (operation.equals("")) {
                a = a + s;
            } else {
                b = b + s;
            }
            result.setText(a + operation + b);
        } else if (s.charAt(0) == 'C') {
            a = operation = b = "";
            result.setText(a + operation + b);
        } else if (s.charAt(0) == '=') {
            int rslt = switch (operation) {
                case "+" -> Integer.parseInt(a) + Integer.parseInt(b);
                case "-" -> Integer.parseInt(a) - Integer.parseInt(b);
                case "/" -> Integer.parseInt(a) / Integer.parseInt(b);
                default -> Integer.parseInt(a) * Integer.parseInt(b);
            };
            a = String.valueOf(rslt);
            result.setText(a);
            operation = b = "";
        } else {
            if (operation.equals(""))
                operation = s;
            result.setText(a + operation + b);
        }
    }

}
