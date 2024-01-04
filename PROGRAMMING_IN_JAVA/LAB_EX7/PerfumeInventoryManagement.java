import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Perfume {
    private String name;
    private String brand;
    private double price;
    private boolean isLimitedEdition;

    public Perfume(String name, String brand, double price, boolean isLimitedEdition) {
        this.name = name;
        this.brand = brand;
        this.price = price;
        this.isLimitedEdition = isLimitedEdition;
    }

    public String getName() {
        return name;
    }

    public String getBrand() {
        return brand;
    }

    public double getPrice() {
        return price;
    }

    public boolean isLimitedEdition() {
        return isLimitedEdition;
    }

    @Override
    public String toString() {
        return brand + " - " + name + " - $ " + price + (isLimitedEdition ? " (Limited Edition)" : "");
    }

    public static void sortPerfumes(Perfume[] perfumes, Comparator<Perfume> comparator) {
        Arrays.sort(perfumes, comparator);
    }
}

public class PerfumeInventoryManagement 
{
    private static final int MAX_PERFUMES = 100;
    private static final Perfume[] perfumes = new Perfume[MAX_PERFUMES];
    private static int numberOfPerfumes = 0;
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\nMenu:");
            System.out.println("1. Enter Perfume Details");
            System.out.println("2. Display All Perfumes");
            System.out.println("3. Display Limited Edition Perfumes");
            System.out.println("4. Sort Perfumes by Price");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");

            choice = scanner.nextInt();
            scanner.nextLine();

            switch (choice) {
                case 1:
                    enterPerfumeDetails();
                    break;

                case 2:
                    displayPerfumes();
                    break;

                case 3:
                    displayLimitedEditionPerfumes();
                    break;

                case 4:
                    sortPerfumesByPrice();
                    break;

                case 5:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice. Please enter a number between 1 and 5.");
            }
        } while (choice != 5);

        scanner.close();
    }

    private static void enterPerfumeDetails() {
        if (numberOfPerfumes < MAX_PERFUMES) {
            System.out.print("\nEnter details for the Perfume:");
            System.out.print("\nName: ");
            String name = scanner.nextLine();

            System.out.print("Brand: ");
            String brand = scanner.nextLine();

            System.out.print("Price: $ ");
            double price = scanner.nextDouble();
            scanner.nextLine();

            System.out.print("Is Limited Edition (true/false): ");
            boolean isLimitedEdition = scanner.nextBoolean();
            scanner.nextLine();

            perfumes[numberOfPerfumes++] = new Perfume(name, brand, price, isLimitedEdition);
            System.out.println("Perfume details added successfully!\n\n");
        } else {
            System.out.println("Maximum number of perfumes reached. Cannot add more perfumes.");
        }
    }

    private static void displayPerfumes() {
        System.out.println("\nAll Perfumes:");
        for (int i = 0; i < numberOfPerfumes; i++) {
            if (perfumes[i] != null) {
                System.out.println(perfumes[i]);
            }
        }
    }

    private static void displayLimitedEditionPerfumes() {
        System.out.println("\nLimited Edition Perfumes:");
        for (int i = 0; i < numberOfPerfumes; i++) {
            if (perfumes[i] != null && perfumes[i].isLimitedEdition()) {
                System.out.println(perfumes[i]);
            }
        }
    }

    private static void sortPerfumesByPrice() {
    Perfume[] validPerfumes = Arrays.copyOf(perfumes, numberOfPerfumes);
    Perfume.sortPerfumes(validPerfumes, Comparator.comparingDouble(Perfume::getPrice));

    System.out.println("\nPerfumes Sorted by Price:");
    for (Perfume perfume : validPerfumes) {
        if (perfume != null) {
            System.out.println(perfume);
        }
    }
}
}
