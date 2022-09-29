// Java program to demonstrate the removing
// of the elements from the stack
import java.util.*;
import java.io.*;
  
public class StackDemo {
    public static void main(String args[])
    {
        // Creating an empty Stack
        Stack<String> stack = new Stack<String>();
  
        // Use add() method to add elements
        stack.push("Buku");
        stack.push("Baju");
        stack.push("Kursi");
        stack.push("Tas");
        stack.push("Meja");
  
        // Displaying the Stack
        System.out.println("Initial Stack: " + stack);
  
        // Removing elements using pop() method
        System.out.println("Popped element: "
                           + stack.pop());
        System.out.println("Popped element: "
                           + stack.pop());
  
        // Displaying the Stack after pop operation
        System.out.println("Stack after pop operation "
                           + stack);
    }
}
