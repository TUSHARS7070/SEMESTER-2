import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Perfume {
    private String perfumeName;
    private int perfumeId;
    private int stock;
    private String customerName;

    public Perfume(String perfumeName, int perfumeId, int stock) {
        this.perfumeName = perfumeName;
        this.perfumeId = perfumeId;
        this.stock = stock;
        this.customerName = "";
    }

    public String getPerfumeName() {
        return perfumeName;
    }

    public int getPerfumeId() {
        return perfumeId;
    }

    public int getStock() {
        return stock;
    }

    public void addStock(int quantity) {
        this.stock += quantity;
    }

    public String getCustomerName() {
        return customerName;
    }

    public void setCustomerName(String customerName) {
        this.customerName = customerName;
    }
}

interface Inventory<T> {
    void addPerfume(T perfume, int quantity);
    void purchasePerfume(T perfume, String customerName, int quantity);
    void displayInventory();
}

class PerfumeStore<T> implements Inventory<T> {
    protected List<T> perfumeInventory; // Changed access to protected

    public PerfumeStore() {
        this.perfumeInventory = new ArrayList<>();
    }

    @Override
    public void addPerfume(T perfume, int quantity) {
        ((Perfume) perfume).addStock(quantity);
        perfumeInventory.add(perfume);
        System.out.println(quantity + " " + ((Perfume) perfume).getPerfumeName() + " added to the stock.");
    }

    @Override
    public void purchasePerfume(T perfume, String customerName, int quantity) {
        if (((Perfume) perfume).getStock() >= quantity) {
            ((Perfume) perfume).addStock(-quantity);
            ((Perfume) perfume).setCustomerName(customerName);
            System.out.println("Purchase of " + quantity + " " + ((Perfume) perfume).getPerfumeName() + " completed successfully!");
        } else {
            System.out.println("Insufficient stock of " + ((Perfume) perfume).getPerfumeName() + ".");
        }
    }

    @Override
    public void displayInventory() {
        System.out.println("Perfume Inventory:");
        for (T perfume : perfumeInventory) {
            System.out.println("Perfume ID: " + ((Perfume) perfume).getPerfumeId() +
                    ", Name: " + ((Perfume) perfume).getPerfumeName() +
                    ", Stock: " + ((Perfume) perfume).getStock());
        }
    }
}

public class PerfumeStoreManagement {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        PerfumeStore<Perfume> store = new PerfumeStore<>();

        while (true) {
            System.out.println("Welcome to Perfume Store Management");
            System.out.println("1. Add Perfume to Stock");
            System.out.println("2. Sell Perfume");
            System.out.println("3. Display Perfume Inventory");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter perfume ID: ");
                    int perfumeId = scanner.nextInt();
                    scanner.nextLine(); // Consume newline
                    System.out.print("Enter perfume name: ");
                    String perfumeName = scanner.nextLine();
                    System.out.print("Enter quantity to add: ");
                    int quantity = scanner.nextInt();

                    Perfume perfumeToAdd = new Perfume(perfumeName, perfumeId, quantity);
                    store.addPerfume(perfumeToAdd, quantity);
                    break;

                case 2:
                    System.out.print("Enter perfume ID to sell: ");
                    int perfumeIdToSell = scanner.nextInt();
                    System.out.print("Enter quantity to sell: ");
                    int quantityToSell = scanner.nextInt();
                    scanner.nextLine(); // Consume newline
                    System.out.print("Enter customer's name: ");
                    String customerName = scanner.nextLine();

                    Perfume perfumeToSell = store.perfumeInventory.stream()
                            .filter(perfume -> ((Perfume) perfume).getPerfumeId() == perfumeIdToSell)
                            .findFirst().orElse(null);

                    if (perfumeToSell != null) {
                        store.purchasePerfume(perfumeToSell, customerName, quantityToSell);
                    } else {
                        System.out.println("Perfume with ID " + perfumeIdToSell + " not found.");
                    }
                    break;

                case 3:
                    store.displayInventory();
                    break;

                case 4:
                    System.out.println("Exiting Perfume Store Management. Goodbye!");
                    scanner.close();
                    System.exit(0);
                    break;

                default:
                    System.out.println("Invalid choice. Please enter a valid option.");
                    break;
            }
        }
    }
}
