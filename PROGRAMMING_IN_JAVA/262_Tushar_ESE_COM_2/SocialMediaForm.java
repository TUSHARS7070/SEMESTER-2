import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class SocialMediaForm extends JFrame {
    private JTextField firstNameField, lastNameField, phoneField, emailField, religionField, dobField;
    private JCheckBox musicCheckbox, sportsCheckbox, technologyCheckbox; 

    public SocialMediaForm() {
        setTitle("Social Media Form");
        setSize(500, 500); 
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);

        createForm();

        setVisible(true);
    }

    private void createForm() {
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));

        JPanel personalPanel = new JPanel(new GridLayout(7, 2)); 
        personalPanel.setBorder(BorderFactory.createTitledBorder("Personal Information"));

        JLabel firstNameLabel = new JLabel("First Name:");
        firstNameField = new JTextField();
        firstNameLabel.addMouseListener(new ValidationMouseListener(firstNameLabel, firstNameField));

        JLabel lastNameLabel = new JLabel("Last Name:");
        lastNameField = new JTextField();
        lastNameLabel.addMouseListener(new ValidationMouseListener(lastNameLabel, lastNameField));

        JLabel phoneLabel = new JLabel("Phone Number:");
        phoneField = new JTextField();
        phoneLabel.addMouseListener(new ValidationMouseListener(phoneLabel, phoneField));
        phoneField.addKeyListener(new NumberKeyListener());

        JLabel emailLabel = new JLabel("Email ID:");
        emailField = new JTextField();
        emailLabel.addMouseListener(new ValidationMouseListener(emailLabel, emailField));

        JLabel religionLabel = new JLabel("Religion:");
        religionField = new JTextField();
        religionLabel.addMouseListener(new ValidationMouseListener(religionLabel, religionField));

        JLabel dobLabel = new JLabel("DOB (MM/dd/yyyy):");
        dobField = new JTextField();
        dobLabel.addMouseListener(new ValidationMouseListener(dobLabel, dobField));

        musicCheckbox = new JCheckBox("Music");
        sportsCheckbox = new JCheckBox("Sports");
        technologyCheckbox = new JCheckBox("Technology");

        personalPanel.add(firstNameLabel);
        personalPanel.add(firstNameField);
        personalPanel.add(lastNameLabel);
        personalPanel.add(lastNameField);
        personalPanel.add(phoneLabel);
        personalPanel.add(phoneField);
        personalPanel.add(emailLabel);
        personalPanel.add(emailField);
        personalPanel.add(religionLabel);
        personalPanel.add(religionField);
        personalPanel.add(dobLabel);
        personalPanel.add(dobField);

        JPanel interestedPanel = new JPanel();
        interestedPanel.setBorder(BorderFactory.createTitledBorder("Persons Interested"));
        interestedPanel.setLayout(new FlowLayout()); 

        interestedPanel.add(musicCheckbox);
        interestedPanel.add(sportsCheckbox);
        interestedPanel.add(technologyCheckbox);

        mainPanel.add(personalPanel);
        mainPanel.add(interestedPanel);

        JButton submitButton = new JButton("Submit");
        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (validateForm()) {
                    displayInput();
                }
            }
        });

        mainPanel.add(submitButton);

        add(mainPanel);
    }

    private boolean validateForm() {
        if (firstNameField.getText().trim().isEmpty() ||
                lastNameField.getText().trim().isEmpty() ||
                phoneField.getText().trim().isEmpty() ||
                emailField.getText().trim().isEmpty() ||
                religionField.getText().trim().isEmpty() ||
                dobField.getText().trim().isEmpty()) {
            JOptionPane.showMessageDialog(null, "All fields in Personal Information are mandatory.", "Validation Error", JOptionPane.ERROR_MESSAGE);
            return false;
        }

        try {
            SimpleDateFormat dateFormat = new SimpleDateFormat("MM/dd/yyyy");
            Date dob = dateFormat.parse(dobField.getText());
            Calendar cal = Calendar.getInstance();
            cal.setTime(dob);
            Calendar now = Calendar.getInstance();
            int age = now.get(Calendar.YEAR) - cal.get(Calendar.YEAR);
            if (age < 20) {
                JOptionPane.showMessageDialog(null, "Minimum age required is 20 years.", "Validation Error", JOptionPane.ERROR_MESSAGE);
                return false;
            }
        } catch (ParseException ex) {
            JOptionPane.showMessageDialog(null, "Invalid date format for DOB. Please use MM/dd/yyyy.", "Validation Error", JOptionPane.ERROR_MESSAGE);
            return false;
        }

        return true;
    }

    private void displayInput() {
        StringBuilder message = new StringBuilder();
        message.append("Form submitted successfully!\n\n");
        message.append("First Name: ").append(firstNameField.getText()).append("\n");
        message.append("Last Name: ").append(lastNameField.getText()).append("\n");
        message.append("Phone Number: ").append(phoneField.getText()).append("\n");
        message.append("Email ID: ").append(emailField.getText()).append("\n");
        message.append("Religion: ").append(religionField.getText()).append("\n");
        message.append("DOB: ").append(dobField.getText()).append("\n");

        message.append("Persons Interested: ");
        if (musicCheckbox.isSelected()) {
            message.append("Music ");
        }
        if (sportsCheckbox.isSelected()) {
            message.append("Sports ");
        }
        if (technologyCheckbox.isSelected()) {
            message.append("Technology ");
        }

        JOptionPane.showMessageDialog(null, message.toString(), "Form Submission", JOptionPane.INFORMATION_MESSAGE);
    }

    private class ValidationMouseListener extends MouseAdapter {
        private JLabel label;
        private JTextField field;

        public ValidationMouseListener(JLabel label, JTextField field) {
            this.label = label;
            this.field = field;
        }

        @Override
        public void mouseEntered(MouseEvent e) {
            if (field.getText().trim().isEmpty()) {
                JOptionPane.showMessageDialog(null, label.getText() + " is mandatory.", "Validation Error", JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    private class NumberKeyListener extends KeyAdapter {
        @Override
        public void keyTyped(KeyEvent e) {
            char c = e.getKeyChar();
            if (!(Character.isDigit(c) || c == KeyEvent.VK_BACK_SPACE || c == KeyEvent.VK_DELETE)) {
                e.consume();
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new SocialMediaForm());
    }
}
