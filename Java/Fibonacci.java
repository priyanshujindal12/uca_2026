
import java.util.Scanner;

public class Fibonacci {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        EvenFibonacciNumbers(n);
    }

    static void EvenFibonacciNumbers(int n) {
        int prev1 = 0;
        int prev2 = 1;
        for (int i = 2; i <= n; i++) {
            int next = prev1 + prev2;
            prev1 = prev2;
            prev2 = next;
            if (i % 3 == 0) {
                System.out.print(prev2 + " ");
            }
        }
    }
}
