import java.util.Arrays;

public class StringM 
{
    public static void main(String[] args) 
    {
        // Text
        String tataQuote = "We realizes that while our workers were thriving, the surrounding villages were still suffering. It became our goal to uplift their quality of life as well. I remember seeing a family of 4 on a motorbike in the heavy Bombay rain — I knew I wanted to do more for these families who were risking their lives for lack of an alternative";

        // charAt()
        char firstChar = tataQuote.charAt(0);
        System.out.println("First character: " + firstChar);

        // compareTo()
        String anotherQuote = "We realized that while our workers were thriving...";
        int compareResult = tataQuote.compareTo(anotherQuote);
        System.out.println("Compare Result: " + compareResult);
        
        // concat()
        String concatResult = tataQuote.concat(" This is additional information added to the paragraph.");
        System.out.println("Concatenated String: " + concatResult);

        // contains()
        boolean containsResult = tataQuote.contains("villages");
        System.out.println("Contains 'villages': " + containsResult);

        // endsWith()
        boolean endsWithResult = tataQuote.endsWith("alternative");
        System.out.println("Ends with 'alternative': " + endsWithResult);

        // equals()
        boolean equalsResult = tataQuote.equals(anotherQuote);
        System.out.println("Equals Result: " + equalsResult);

        // equalsIgnoreCase()
        boolean equalsIgnoreCaseResult = tataQuote.equalsIgnoreCase(anotherQuote);
        System.out.println("Equals Ignore Case Result: " + equalsIgnoreCaseResult);

        // format()
        String formattedString = String.format("Length of the quote: %d", tataQuote.length());
        System.out.println(formattedString);

        // getBytes()
        byte[] bytes = tataQuote.getBytes();
        System.out.println("String as bytes: " + new String(bytes));

        // getChars()
        char[] charArray = new char[20];
        tataQuote.getChars(5, 25, charArray, 0);
        System.out.println("Chars from index 5 to 25: " + new String(charArray));

        // indexOf()
        int indexOfResult = tataQuote.indexOf("thriving");
        System.out.println("Index of 'thriving': " + indexOfResult);

        // intern()
        String internedString = tataQuote.intern();
        System.out.println("Interned String: " + internedString);

        // isEmpty()
        boolean isEmptyResult = tataQuote.isEmpty();
        System.out.println("Is the string empty? " + isEmptyResult);

        // join()
        String joinedString = String.join("-", "We", "realizes", "thriving");
        System.out.println("Joined String: " + joinedString);

        // lastIndexOf()
        int lastIndexOfResult = tataQuote.lastIndexOf("for");
        System.out.println("Last Index of 'for': " + lastIndexOfResult);

        // length()
        int lengthResult = tataQuote.length();
        System.out.println("Length of the string: " + lengthResult);

        // replace()
        String replacedString = tataQuote.replace("villages", "towns");
        System.out.println("String after replacement: " + replacedString);

        // replaceAll()
        String regexReplacedString = tataQuote.replaceAll("\\bthe\\b", "THE");
        System.out.println("String after regex replacement: " + regexReplacedString);

        // split()
        String[] splitWords = tataQuote.split("\\s+");
        System.out.println("Words after split: " + Arrays.toString(splitWords));

        // startsWith()
        boolean startsWithResult = tataQuote.startsWith("We realizes");
        System.out.println("Starts with 'We realizes': " + startsWithResult);

        // substring()
        String substringResult = tataQuote.substring(30, 70);
        System.out.println("Substring from index 30 to 70: " + substringResult);

        // toCharArray()
        char[] charArrayResult = tataQuote.toCharArray();
        System.out.println("String as char array: " + Arrays.toString(charArrayResult));

        // toLowerCase()
        String lowercaseString = tataQuote.toLowerCase();
        System.out.println("Lowercased string: " + lowercaseString);

        // toUpperCase()
        String uppercaseString = tataQuote.toUpperCase();
        System.out.println("Uppercased string: " + uppercaseString);

        // trim()
        String trimmedString = "   leading and trailing spaces   ".trim();
        System.out.println("Trimmed string: '" + trimmedString + "'");

        // valueOf()
        int value = 42;
        String valueOfString = String.valueOf(value);
        System.out.println("String value of int: " + valueOfString);
    }
}
