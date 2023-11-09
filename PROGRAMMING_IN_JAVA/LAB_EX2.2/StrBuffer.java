public class StrBuffer
{
    public static void main(String[] args) 
    {
        // Creating a StringBuffer
        StringBuffer buffer = new StringBuffer("Hello, ");

        // append
        buffer.append("world!");
        System.out.println("After append(): " + buffer);

        // insert
        buffer.insert(7, "Java ");
        System.out.println("After insert(): " + buffer);

        // replace
        buffer.replace(0, 5, "Hola,");
        System.out.println("After replace(): " + buffer);

        // delete
        buffer.delete(5, 10);
        System.out.println("After delete(): " + buffer);

        // charAt
        char charAtIndex = buffer.charAt(2);
        System.out.println("Character at index 2: " + charAtIndex);

        // setCharAt
        buffer.setCharAt(0, 'H');
        System.out.println("After setCharAt(): " + buffer);

        // length
        int len = buffer.length();
        System.out.println("Length of the string: " + len);

        // capacity
        int cap = buffer.capacity();
        System.out.println("Capacity of the string: " + cap);

        // ensureCapacity
        buffer.ensureCapacity(50);
        System.out.println("After ensureCapacity(): " + buffer);

        // toString
        String resultString = buffer.toString();
        System.out.println("String representation: " + resultString);

        // substring
        String subResult1 = buffer.substring(6);
        System.out.println("Substring from index 6: " + subResult1);

        // substring
        String subResult2 = buffer.substring(0, 5);
        System.out.println("Substring from index 0 to 5: " + subResult2);
    }
}
