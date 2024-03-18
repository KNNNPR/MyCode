package ru.mirea.labs.lab16;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

public class GuessNumberGame {
    private JFrame guessGameWindow;
    private JPanel guessGamePanel;
    private JTextField userInput;
    private JButton submitInput;
    private JTextField attempts;
    private Integer guessedNumber;
    int tries;

    public GuessNumberGame() {
        tries = 0;
        Integer ans = (int) (Math.random() * 20);
        System.out.println(ans);

        guessGameWindow = new JFrame("GuessGame");
        guessGameWindow.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        guessGameWindow.setSize(480, 270);


        attempts = new JTextField();
        attempts.setColumns(5);
        userInput = new JTextField();
        userInput.setColumns(5);
        submitInput = new JButton("Enter Answer");
        submitInput.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                guessedNumber = Integer.valueOf(userInput.getText());
                if(tries == 3) {
                    System.out.println("You lost(((");
                    System.exit(0);
                }
                else {
                    if(guessedNumber.equals(ans)) {
                        attempts.setText("You Won!!");
                    }
                    else if(guessedNumber > ans) {
                        tries++;
                        attempts.setText("Greater");
                    }
                    else {
                        tries++;
                        attempts.setText("Lower");
                    }
                }
            }
        });


        guessGamePanel = new JPanel();
        guessGamePanel.add(userInput);
        guessGamePanel.add(submitInput);
        guessGamePanel.add(attempts);










        guessGameWindow.getContentPane().add(guessGamePanel);
        guessGameWindow.setVisible(true);

    }

    public static void main(String[] args) {
        GuessNumberGame test = new GuessNumberGame();
    }
}
