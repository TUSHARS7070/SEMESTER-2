import java.util.Scanner;

public class Perfume 
{
    // Private Data members
    private String name;
    private double price;
    private String brand;

    // Default Constructor
    public Perfume() 
    {
        name = "Unknown";
        price = 0.0;
        brand = "Unknown";
    }

    // Constructor with three parameters
    public Perfume(String name, double price, String brand) 
    {
        this.name = name;
        this.price = price;
        this.brand = brand;
    }

    // Method to set perfume details
    public void setPerfumeDetails(String name, double price, String brand) 
    {
        this.name = name;
        this.price = price;
        this.brand = brand;
    }

    // Methods to display perfume details
    public void displayPerfumeDetails() 
    {
        System.out.println("Perfume Name: " + name);
        System.out.println("Price: $" + price);
        System.out.println("Brand: " + brand);
    }

    public void displayPerfumeDetails(boolean includeBrand) 
    {
        System.out.println("Perfume Name: " + name);
        System.out.println("Price: $" + price);
        if (includeBrand) 
        {
            System.out.println("Brand: " + brand);
        }
    }

    public void displayPerfumeDetails(int quantity) 
    {
        System.out.println("Quantity: " + quantity);
    }

    public void displayPerfumeDetails(String additionalInfo) 
    {
        System.out.println("Additional Info: " + additionalInfo);
    }

    public static void main(String[] args) 
    {
        // Creating a Scanner object to take user input
        Scanner scanner = new Scanner(System.in);

        Perfume perfume1 = new Perfume();
        Perfume perfume2 = new Perfume();

        // Prompt the user for entering details of Perfumes 
        System.out.println("Enter details for Perfume:");

        // Read user input for Perfumes
        System.out.print("Name: ");
        perfume2.name = scanner.nextLine();
        System.out.print("Price: Rs.");
        perfume2.price = scanner.nextDouble();
        scanner.nextLine(); 
        
        
        System.out.print("Brand: ");
        perfume2.brand = scanner.nextLine();

        // Display details for Perfume 1
        perfume1.displayPerfumeDetails();

        // Display details for Perfume 2
        perfume2.displayPerfumeDetails();

        // Prompt the user to decide whether to include the brand for Perfume 2
        System.out.print("Include Brand for Perfume (true/false): ");
        boolean includeBrand = scanner.nextBoolean();

        // Display details for Perfume 2 with or without the brand
        perfume2.displayPerfumeDetails(includeBrand);

        // Read user input for the quantity of Perfume 2
        System.out.print("Enter quantity for Perfume 2: ");
        int quantity = scanner.nextInt();

        // Display details for Perfume 2 with the quantity
        perfume2.displayPerfumeDetails(quantity);

        scanner.nextLine();

        // Take additional info for Perfume
        System.out.print("Additional Info for Perfume 2: ");
        String additionalInfo = scanner.nextLine();

        // Display additional info
        perfume2.displayPerfumeDetails(additionalInfo);

        scanner.close();
    }
}
