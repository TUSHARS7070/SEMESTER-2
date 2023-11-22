abstract class Product {
    final int id;
    String name;
    double price;

    public Product(int id, String name, double price) {
        this.id = id;
        this.name = name;
        this.price = price;
    }

    public abstract void display();

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public double getPrice() {
        return price;
    }
}

class Perfume extends Product {
    String brand;
    String fragrance;
    int volume;

    public Perfume(int id, String name, double price, String brand, String fragrance, int volume) {
        super(id, name, price);
        this.brand = brand;
        this.fragrance = fragrance;
        this.volume = volume;
    }

    public void display() {
        System.out.println("Perfume ID: " + id);
        System.out.println("Perfume Name: " + name);
        System.out.println("Perfume Price: " + price);
        System.out.println("Perfume Brand: " + brand);
        System.out.println("Perfume Fragrance: " + fragrance);
        System.out.println("Perfume Volume: " + volume + " ml");
    }

    public String getBrand() {
        return brand;
    }

    public String getFragrance() {
        return fragrance;
    }

    public int getVolume() {
        return volume;
    }
}

public class PerfumeStore {
    public static void main(String[] args) {
        Perfume p1 = new Perfume(301, "Eau de Parfum", 799.99, "Chanel", "Floral", 50);
        p1.display();
    }
}
