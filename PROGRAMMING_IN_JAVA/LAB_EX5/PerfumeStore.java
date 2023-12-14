import java.util.Scanner;

abstract class Perfume {
    private String brand;
    private String name;
    private float price;
    private int quantity;

    Perfume(String brand, String name, float price, int quantity) {
        this.brand = brand;
        this.name = name;
        this.price = price;
        this.quantity = quantity;
    }

    public abstract void displaySpecialFeatures();

    public void displayPerfumeInfo() {
        System.out.println("\nBrand: " + brand);
        System.out.println("Name: " + name);
        System.out.println("Price: $" + price);
        System.out.println("Quantity: " + quantity);
    }
}

class LuxuryPerfume extends Perfume {
    private String exclusiveIngredients;

    LuxuryPerfume(String brand, String name, float price, int quantity, String exclusiveIngredients) {
        super(brand, name, price, quantity);
        this.exclusiveIngredients = exclusiveIngredients;
    }

    @Override
    public void displaySpecialFeatures() {
        System.out.println("Exclusive Ingredients: " + exclusiveIngredients);
    }
}

class RegularPerfume extends Perfume {
    private String scentFamily;

    RegularPerfume(String brand, String name, float price, int quantity, String scentFamily) {
        super(brand, name, price, quantity);
        this.scentFamily = scentFamily;
    }

    @Override
    public void displaySpecialFeatures() {
        System.out.println("Scent Family: " + scentFamily);
    }
}

class LuxuryPerfumeThread extends Thread {
    private LuxuryPerfume luxuryPerfume;

    LuxuryPerfumeThread(LuxuryPerfume luxuryPerfume) {
        this.luxuryPerfume = luxuryPerfume;
    }

    @Override
    public void run() {
        System.out.println("Luxury Perfume Info:");
        luxuryPerfume.displayPerfumeInfo();
        luxuryPerfume.displaySpecialFeatures();
    }
}

class RegularPerfumeThread extends Thread {
    private RegularPerfume regularPerfume;

    RegularPerfumeThread(RegularPerfume regularPerfume) {
        this.regularPerfume = regularPerfume;
    }

    @Override
    public void run() {
        System.out.println("Regular Perfume Info:");
        regularPerfume.displayPerfumeInfo();
        regularPerfume.displaySpecialFeatures();
    }
}

public class PerfumeStore {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter Luxury Perfume Details:");
        System.out.print("Brand: ");
        String luxuryBrand = scanner.nextLine();
        System.out.print("Name: ");
        String luxuryName = scanner.nextLine();
        System.out.print("Price: $");
        float luxuryPrice = scanner.nextFloat();
        System.out.print("Quantity: ");
        int luxuryQuantity = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Exclusive Ingredients: ");
        String exclusiveIngredients = scanner.nextLine();

        LuxuryPerfume luxuryPerfume = new LuxuryPerfume(luxuryBrand, luxuryName, luxuryPrice, luxuryQuantity, exclusiveIngredients);
        LuxuryPerfumeThread luxuryThread = new LuxuryPerfumeThread(luxuryPerfume);

        System.out.println("\nEnter Regular Perfume Details:");
        System.out.print("Brand: ");
        String regularBrand = scanner.nextLine();
        System.out.print("Name: ");
        String regularName = scanner.nextLine();
        System.out.print("Price: $");
        float regularPrice = scanner.nextFloat();
        System.out.print("Quantity: ");
        int regularQuantity = scanner.nextInt();
        scanner.nextLine();
        System.out.print("Scent Family: ");
        String scentFamily = scanner.nextLine();

        RegularPerfume regularPerfume = new RegularPerfume(regularBrand, regularName, regularPrice, regularQuantity, scentFamily);
        RegularPerfumeThread regularThread = new RegularPerfumeThread(regularPerfume);

        luxuryThread.start();

        try {
            luxuryThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        regularThread.start();
    }
}
