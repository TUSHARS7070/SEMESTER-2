import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Perfume {
    String brand;
    String name;
    float price;
    int quantity;

    Perfume(String name, String brand, float price, int quantity) {
        this.brand = brand;
        this.name = name;
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

public class PerfumeRetailStore {
    private static Perfume createPerfume(String name, String brand, float price, int quantity) {
        return new Perfume(name, brand, price, quantity);
    }

    private static Customer createCustomer(String name, int age) {
        return new Customer(name, age);
    }

    private static void insertIntoInventory(List<Perfume> inventory) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter Perfume details:");
        System.out.print("Brand: ");
        String perfumeBrand = scanner.next();
        System.out.print("Name: ");
        String perfumeName = scanner.next();
        System.out.print("Price: ");
        float perfumePrice = scanner.nextFloat();
        System.out.print("Quantity: ");
        int perfumeQuantity = scanner.nextInt();

        System.out.println("\n==============================================================\n\n\n");

        Perfume newPerfume = createPerfume(perfumeName, perfumeBrand, perfumePrice, perfumeQuantity);
        inventory.add(newPerfume);
    }

    private static void insertCustomer(List<Customer> customers) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter customer details:");
        System.out.print("Name: ");
        String customerName = scanner.next();
        System.out.print("Age: ");
        int customerAge = scanner.nextInt();

        System.out.println("\n==============================================================\n\n\n");

        Customer newCustomer = createCustomer(customerName, customerAge);
        customers.add(newCustomer);
    }

    private static void displayInventory(List<Perfume> inventory) {
        System.out.println("Perfumes in the inventory:");
        if (inventory.isEmpty()) {
            System.out.println("Inventory is empty.");
        } else {
            for (Perfume perfume : inventory) {
                System.out.printf("%s %s | Rs. %.2f | %d pcs\n", perfume.brand, perfume.name, perfume.price,
                        perfume.quantity);
            }
        }
        System.out.println("\n==============================================================\n\n\n");
    }

    private static void displayCustomers(List<Customer> customers) {
        System.out.println("Customer details:");
        if (customers.isEmpty()) {
            System.out.println("Customer list is empty.");
        } else {
            for (Customer customer : customers) {
                System.out.printf(" %s | %d years old | Rs. %.2f\n", customer.name, customer.age, customer.totalAmount);
            }
        }
        System.out.println("\n==============================================================\n\n\n");
    }

    private static void deletePerfume(List<Perfume> inventory) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter perfume name to delete: ");
        String name = scanner.next();

        boolean removed = inventory.removeIf(perfume -> perfume.name.equals(name));

        if (removed) {
            System.out.println("Perfume " + name + " deleted.");
        } else {
            System.out.println("Perfume " + name + " not found in the inventory.");
        }
        System.out.println("\n==============================================================\n\n\n");
    }

    private static void deleteCustomer(List<Customer> customers) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter customer name to delete: ");
        String name = scanner.next();

        boolean removed = customers.removeIf(customer -> customer.name.equals(name));

        if (removed) {
            System.out.println("Customer " + name + " deleted.");
        } else {
            System.out.println("Customer " + name + " not found.");
        }
        System.out.println("\n==============================================================\n\n\n");
    }

    private static void buyPerfume(List<Perfume> inventory, List<Customer> customers) {
        Scanner scanner = new Scanner(System.in);
        String customerName, perfumeName;
        int customerAge, quantity;

        System.out.println("Available Perfumes for Purchase:");
        displayInventory(inventory);

        System.out.print("Enter the name of the perfume you want to buy: ");
        perfumeName = scanner.next();

        Perfume selectedPerfume = inventory.stream().filter(perfume -> perfume.name.equals(perfumeName)).findFirst()
                .orElse(null);

        if (selectedPerfume == null) {
            System.out.println("Perfume not found in the inventory.");
            System.out.println("\n==============================================================\n\n\n");
            return;
        }

        System.out.print("Enter the quantity you want to buy: ");
        quantity = scanner.nextInt();

        if (quantity > selectedPerfume.quantity) {
            System.out.println("Insufficient quantity in stock.");
            System.out.println("\n==============================================================\n\n\n");
            return;
        }

        System.out.println("Enter customer details:");
        System.out.print("Name: ");
        customerName = scanner.next();
        System.out.print("Age: ");
        customerAge = scanner.nextInt();
        System.out.println("\n==============================================================\n\n\n");

        customers.add(createCustomer(customerName, customerAge));

        float totalAmount = quantity * selectedPerfume.price;

        selectedPerfume.quantity -= quantity;

        for (Customer currentCustomer : customers) {
            if (currentCustomer.name.equals(customerName)) {
                currentCustomer.totalAmount += totalAmount;
                break;
            }
        }

        System.out.println("  Bill for " + customerName + ":\n" +
                "\t\t\tPerfume Store\n\t\t\t===============\n\n " +
                selectedPerfume.name + "\t\t Rs. " + selectedPerfume.price + "\t\t " + quantity + " pcs\n\n" +
                "\t\t\t\tTotal Amount: Rs. " + totalAmount + "\n\n\t\t\tThank you");
        System.out.println("\n==============================================================\n\n\n");
    }

    public static void main(String[] args) {
        List<Perfume> inventory = new ArrayList<>();
        List<Customer> customers = new ArrayList<>();
        int choice;

        Scanner scanner = new Scanner(System.in);

        do {
            System.out.println("\nMain Menu:");
            System.out.println("1. Add Perfume to Inventory");
            System.out.println("2. Display Perfume Inventory");
            System.out.println("3. Buy Perfume");
            System.out.println("4. Display Customers");
            System.out.println("5. Delete Customer");
            System.out.println("6. Delete Perfume");
            System.out.println("7. Exit");
            System.out.print("Enter your choice: ");
            choice = scanner.nextInt();
            System.out.println("\n==============================================================\n\n\n");

            switch (choice) {
                case 1:
                    insertIntoInventory(inventory);
                    break;

                case 2:
                    displayInventory(inventory);
                    break;

                case 3:
                    buyPerfume(inventory, customers);
                    break;

                case 4:
                    displayCustomers(customers);
                    break;

                case 5:
                    deleteCustomer(customers);
                    break;

                case 6:
                    deletePerfume(inventory);
                    break;

                case 7:
                    System.out.println("Exiting the program.");
                    break;

                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
            }

        } while (choice != 7);
    }
}
