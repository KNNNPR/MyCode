package ru.mirea.labs.lab5.MilanMadrid;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MilanMadridGUI {

    private JLabel resultLabel;
    private JTextField resultField;
    private int milanScore = 0;
    private int madridscore = 0;
    private JLabel LS;
    private JLabel Winner;
    private String lastScorer;

    private void updateresult() {
        String resultText = milanScore + " X " + madridscore;
        resultField.setText(resultText);
        String win;
        if (milanScore > madridscore) {
            win = "AC Milan";
        }
        else if (milanScore < madridscore) {
            win = "AC Madrid";
        }
        else {
            win = "Draw";
        }
        Winner.setText(win);
        LS.setText(lastScorer);
    }
    public MilanMadridGUI() {

        JFrame frame = new JFrame("MilanVSMadrid");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(480, 270);

        JPanel panel = new JPanel();
        panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));

        panel.setBackground(Color.RED);
        panel.setPreferredSize(new Dimension(480, 270));

        JButton MilanButton = new JButton("AC Milan");
        JButton MadridButton = new JButton("Real Madrid");

        resultLabel = new JLabel("Result: ");
        resultField = new JTextField("0 x 0");
        LS = new JLabel("Last Scorer: ");
        Winner = new JLabel("Winner: ");

        MilanButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        MadridButton.setAlignmentX(Component.CENTER_ALIGNMENT);
        resultLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
        resultField.setAlignmentX(Component.CENTER_ALIGNMENT);
        LS.setAlignmentX(Component.CENTER_ALIGNMENT);
        Winner.setAlignmentX(Component.CENTER_ALIGNMENT);

        MilanButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                milanScore++;
                lastScorer = "AC Milan";
                updateresult();
            }
        });

        MadridButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                madridscore++;
                lastScorer = "AC Madrid";
                updateresult();
            }
        });

        panel.add(MilanButton);
        panel.add(MadridButton);
        panel.add(resultLabel);
        panel.add(resultField);
        panel.add(LS);
        panel.add(Winner);
        frame.getContentPane().add(panel);
        frame.setVisible(true);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new MilanMadridGUI();
            }
        });
    }
}
