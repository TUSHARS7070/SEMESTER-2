/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package pkg262_tushar_lab10;

import java.awt.GridLayout;
import java.util.ArrayList;
import java.util.List;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

/**
 *
 * @author tushar sakuja
 */

class Perfume {
    String brand;
    String name;
    int size;
    float price;
    int quantity;

    Perfume(String name, String brand, int size, float price, int quantity) {
        this.brand = brand;
        this.name = name;
        this.size = size;
        this.price = price;
        this.quantity = quantity;
    }
}

class Customer {
    String name;
    int age;
    float totalAmount;

    Customer(String name, int age) {
        this.name = name;
        this.age = age;
        this.totalAmount = 0.0f;
    }
}


public class Perfumestore extends javax.swing.JFrame {

    
    private List<Perfume> inventory;
    private List<Customer> customers;
    
    private static final String DB_URL = "jdbc:mysql://localhost/tushar_lab10";
    private static final String DB_USER = "root";
    private static final String DB_PASSWORD = "Tushar@7070";
    
    private Connection connection;
    /**
     * Creates new form Perfumestore
     */
    public Perfumestore() {
        initComponents();
        initDatabaseConnection();
        inventory = new ArrayList<>();
        customers = new ArrayList<>();
        fetchDataFromDatabase();
    }
    
     private void initDatabaseConnection() {
    try {
        Class.forName("com.mysql.cj.jdbc.Driver");
        connection = DriverManager.getConnection(DB_URL, DB_USER, DB_PASSWORD);
        System.out.println("Connected to the database");
    } catch (ClassNotFoundException e) {
        e.printStackTrace();
        JOptionPane.showMessageDialog(null, "Error loading JDBC driver." + e.getMessage());
        System.exit(1);
    } catch (SQLException e) {
        e.printStackTrace();
        JOptionPane.showMessageDialog(null, "Error connecting to the database: " + e.getMessage());
        System.exit(1);
    }
}
    
    private void fetchDataFromDatabase() {
        fetchPerfumesFromDatabase();
        fetchCustomersFromDatabase();
    }
    
    private void fetchPerfumesFromDatabase() {
        try {
            String query = "SELECT * FROM perfume";
            try (Statement statement = connection.createStatement();
                 ResultSet resultSet = statement.executeQuery(query)) {
                while (resultSet.next()) {
                    String name = resultSet.getString("name");
                    String brand = resultSet.getString("brand");
                    int size = resultSet.getInt("size");
                    float price = resultSet.getFloat("price");
                    int quantity = resultSet.getInt("quantity");
                    
                    Perfume perfume = new Perfume(name, brand, size, price, quantity);
                    inventory.add(perfume);
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
    
    private void fetchCustomersFromDatabase() {
        try {
            String query = "SELECT * FROM customers";
            try (Statement statement = connection.createStatement();
                 ResultSet resultSet = statement.executeQuery(query)) {
                while (resultSet.next()) {
                    String name = resultSet.getString("name");
                    int age = resultSet.getInt("age");
                    float totalAmount = resultSet.getFloat("totalAmount");
                    
                    Customer customer = new Customer(name, age);
                    customer.totalAmount = totalAmount;
                    customers.add(customer);
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    
    private void closeDatabaseConnection() {
        try {
            if (connection != null && !connection.isClosed()) {
                connection.close();
                System.out.println("Connection closed");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
    
    private void insertPerfumeIntoDatabase(Perfume perfume) {
        try {
            String query = "INSERT INTO perfume (name, brand, size, price, quantity) VALUES (?, ?, ?, ?, ?)";
            try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
                preparedStatement.setString(1, perfume.name);
                preparedStatement.setString(2, perfume.brand);
                preparedStatement.setInt(3, perfume.size);
                preparedStatement.setFloat(4, perfume.price);
                preparedStatement.setInt(5, perfume.quantity);
                preparedStatement.executeUpdate();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
    
    private void insertCustomerIntoDatabase(Customer customer) {
        try {
            String query = "INSERT INTO customers (name, age, totalAmount) VALUES (?, ?, ?)";
            try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
                preparedStatement.setString(1, customer.name);
                preparedStatement.setInt(2, customer.age);
                preparedStatement.setFloat(3, customer.totalAmount);
                preparedStatement.executeUpdate();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
    
    private void updatePerfumeQuantityInDatabase(Perfume perfume) {
    try {
        String query = "UPDATE perfume SET quantity = ? WHERE name = ?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
            preparedStatement.setInt(1, perfume.quantity);
            preparedStatement.setString(2, perfume.name);
            preparedStatement.executeUpdate();
        }
    } catch (SQLException e) {
        e.printStackTrace();
    }
}

private void deletePerfumeFromDatabase(String perfumeName) {
    try {
        String query = "DELETE FROM perfume WHERE name = ?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
            preparedStatement.setString(1, perfumeName);
            preparedStatement.executeUpdate();
        }
    } catch (SQLException e) {
        e.printStackTrace();
    }
}

private void deleteCustomerFromDatabase(String customerName) {
    try {
        String query = "DELETE FROM customers WHERE name = ?";
        try (PreparedStatement preparedStatement = connection.prepareStatement(query)) {
            preparedStatement.setString(1, customerName);
            preparedStatement.executeUpdate();
        }
    } catch (SQLException e) {
        e.printStackTrace();
    }
}   
    
     private Perfume createPerfume(String name, String brand, int size, float price, int quantity) {
        return new Perfume(name, brand, size, price, quantity);
    }
    
    private void updateOutput(String message) {
        jTextArea1.append(message + "\n");
    }
    
    private Customer createCustomer(String name, int age) {
        return new Customer(name, age);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        jTextArea1 = new javax.swing.JTextArea();
        jButton1 = new javax.swing.JButton();
        jButton2 = new javax.swing.JButton();
        jButton3 = new javax.swing.JButton();
        jButton4 = new javax.swing.JButton();
        jButton5 = new javax.swing.JButton();
        jButton6 = new javax.swing.JButton();
        jButton7 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jTextArea1.setEditable(false);
        jTextArea1.setColumns(20);
        jTextArea1.setRows(5);
        jScrollPane1.setViewportView(jTextArea1);

        jButton1.setText("ADD PERFUME");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        jButton2.setText("DISPLAY PERFUME");
        jButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton2ActionPerformed(evt);
            }
        });

        jButton3.setText("BUY PERFUME");
        jButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton3ActionPerformed(evt);
            }
        });

        jButton4.setText("DISPLAY CUSTOMERS");
        jButton4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton4ActionPerformed(evt);
            }
        });

        jButton5.setText("DELETE CUSTOMERS");
        jButton5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton5ActionPerformed(evt);
            }
        });

        jButton6.setText("DELETE PERFUME");
        jButton6.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton6ActionPerformed(evt);
            }
        });

        jButton7.setText("EXIT");
        jButton7.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton7ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane1)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jButton4)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(19, 19, 19)
                                .addComponent(jButton1)))
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(85, 85, 85)
                                .addComponent(jButton7))
                            .addGroup(layout.createSequentialGroup()
                                .addGap(59, 59, 59)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jButton5)
                                    .addComponent(jButton2))))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 53, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jButton6, javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                                .addComponent(jButton3)
                                .addGap(9, 9, 9)))))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 156, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton1)
                    .addComponent(jButton3)
                    .addComponent(jButton2))
                .addGap(50, 50, 50)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton4)
                    .addComponent(jButton5)
                    .addComponent(jButton6))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 62, Short.MAX_VALUE)
                .addComponent(jButton7)
                .addGap(26, 26, 26))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        JTextField perfumebrand = new JTextField();
        JTextField perfumename = new JTextField();
        JTextField perfumesize = new JTextField();
        JTextField perfumeprice = new JTextField();
        JTextField perfumequantity = new JTextField();

        JPanel panel = new JPanel(new GridLayout(0, 1));
        panel.add(new JLabel("Perfume Brand:"));
        panel.add(perfumebrand);
        panel.add(new JLabel("Perfume Name:"));
        panel.add(perfumename);
        panel.add(new JLabel("Perfume Size:"));
        panel.add(perfumesize);
        panel.add(new JLabel("Perfume Price:"));
        panel.add(perfumeprice);
        panel.add(new JLabel("Perfume Quantity:"));
        panel.add(perfumequantity);

        int result = JOptionPane.showConfirmDialog(null, panel, "Add Perfume",
            JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE);

        if (result == JOptionPane.OK_OPTION) {
            try {
                String perfumeBrand = perfumebrand.getText();
                String perfumeName = perfumename.getText();
                int perfumeSize = Integer.parseInt(perfumesize.getText());
                float perfumePrice = Float.parseFloat(perfumeprice.getText());
                int perfumeQuantity = Integer.parseInt(perfumequantity.getText());

                Perfume newPerfume = createPerfume(perfumeName, perfumeBrand, perfumeSize, perfumePrice, perfumeQuantity);
                insertPerfumeIntoDatabase(newPerfume);
                inventory.add(newPerfume);
                updateOutput("Perfume added to inventory: " + newPerfume.name + "\n==============================================================\n");
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(null, "Invalid input. Please enter valid input.");
            }
        }
    }//GEN-LAST:event_jButton1ActionPerformed

    private void jButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton2ActionPerformed
        if (inventory.isEmpty()) {
            updateOutput("Inventory is empty.");
        } else {
            for (Perfume perfume : inventory) {
                updateOutput(String.format("%s %s | %d | Rs. %.2f | %d pcs", perfume.brand, perfume.name, perfume.size, perfume.price, perfume.quantity));
            }
        }
        updateOutput("\n==============================================================\n");
    }//GEN-LAST:event_jButton2ActionPerformed

    private void jButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton3ActionPerformed
        String perfumeName = JOptionPane.showInputDialog("Enter the name of the perfume you want to buy:");
        Perfume selectedPerfume = inventory.stream().filter(perfume -> perfume.name.equals(perfumeName)).findFirst().orElse(null);

        if (selectedPerfume == null) {
            updateOutput("Perfume not found in the inventory.\n==============================================================\n");
            return;
        }

        int quantity = Integer.parseInt(JOptionPane.showInputDialog("Enter the quantity you want to buy:"));

        if (quantity > selectedPerfume.quantity) {
            updateOutput("Insufficient quantity in stock.");
            return;
        }

        JTextField customername = new JTextField();
        JTextField customerage = new JTextField();

        JPanel panel = new JPanel(new GridLayout(0, 1));
        panel.add(new JLabel("Customer Name:"));
        panel.add(customername);
        panel.add(new JLabel("Customer Age:"));
        panel.add(customerage);

        int result = JOptionPane.showConfirmDialog(null, panel, "Customer Details",
            JOptionPane.OK_CANCEL_OPTION, JOptionPane.PLAIN_MESSAGE);

        if (result == JOptionPane.OK_OPTION) {
            try {
                String customerName = customername.getText();
                int customerAge = Integer.parseInt(customerage.getText());

                customers.add(createCustomer(customerName, customerAge));
                float totalAmount = quantity * selectedPerfume.price;

                selectedPerfume.quantity -= quantity;
                updatePerfumeQuantityInDatabase(selectedPerfume);

                for (Customer currentCustomer : customers) {
                    if (currentCustomer.name.equals(customerName)) {
                        currentCustomer.totalAmount += totalAmount;
                        insertCustomerIntoDatabase(createCustomer(customerName, customerAge));
                        break;
                    }
                }

                updateOutput("  Bill for " + customerName + ":\n" +
                    "\t\t\tSneakShop\n\t\t\t===========\n\n " +
                    selectedPerfume.name + "\t\t " + quantity + "\t\t Rs. " + selectedPerfume.price + "\n\n" +
                    "\t\t\t\tTotal Amount: Rs. " + totalAmount + "\n\n\t\t\tThank you");
                updateOutput("\n==============================================================\n");

            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(null, "Invalid input. Please enter valid input.");
            }
        }
    }//GEN-LAST:event_jButton3ActionPerformed

    private void jButton4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton4ActionPerformed
        if (customers.isEmpty()) {
            updateOutput("Customer list is empty.");
        } else {
            for (Customer customer : customers) {
                updateOutput(String.format(" %s | %d years old | Rs. %.2f", customer.name, customer.age, customer.totalAmount));
            }
        }
        updateOutput("\n==============================================================\n");
    }//GEN-LAST:event_jButton4ActionPerformed

    private void jButton5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton5ActionPerformed
        String name = JOptionPane.showInputDialog("Enter customer name to delete:");

        boolean removed = customers.removeIf(customer -> customer.name.equals(name));

        if (removed) {
            deleteCustomerFromDatabase(name);
            updateOutput("Customer " + name + " deleted.");
        } else {
            updateOutput("Customer " + name + " not found.");
        }
        updateOutput("\n==============================================================\n");
    }//GEN-LAST:event_jButton5ActionPerformed

    private void jButton6ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton6ActionPerformed
        String name = JOptionPane.showInputDialog("Enter perfume name to delete:");

        boolean removed = inventory.removeIf(perfume -> perfume.name.equals(name));

        if (removed) {
            deletePerfumeFromDatabase(name);
            updateOutput("Perfume " + name + " deleted.");
        } else {
            updateOutput("Perfume " + name + " not found in the inventory.");
        }
        updateOutput("\n==============================================================\n");
    }//GEN-LAST:event_jButton6ActionPerformed

    private void jButton7ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton7ActionPerformed
        System.exit(0);
        closeDatabaseConnection();
    }//GEN-LAST:event_jButton7ActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(Perfumestore.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Perfumestore.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Perfumestore.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Perfumestore.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Perfumestore().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButton1;
    private javax.swing.JButton jButton2;
    private javax.swing.JButton jButton3;
    private javax.swing.JButton jButton4;
    private javax.swing.JButton jButton5;
    private javax.swing.JButton jButton6;
    private javax.swing.JButton jButton7;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JTextArea jTextArea1;
    // End of variables declaration//GEN-END:variables
}
