package perfume;

public class Perfume extends Product {
    String brand;
    String fragrance;
    int volume;

    public Perfume(int id, String name, double price, String brand, String fragrance, int volume) {
        super(id, name, price);
        this.brand = brand;
        this.fragrance = fragrance;
        this.volume = volume;
    }

    @Override
    public void display() {
        System.out.println("Perfume ID: " + getId());
        System.out.println("Perfume Name: " + getName());
        System.out.println("Perfume Price: " + getPrice());
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
