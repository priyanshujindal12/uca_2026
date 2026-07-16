import java.util.Scanner;

public class Fibonacci {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        System.out.println(sumEvenFibonacci(n));
    }

    static int sumEvenFibonacci(int n) {

        int sum = 0;

        int currentEvenFib = 2;
        int previousEvenFib = 0;
        if (n >= 2) {
            sum += 2;
        }
        while (previousEvenFib <= n) {
            int nextEvenFib = 4 * currentEvenFib + previousEvenFib;
            previousEvenFib = currentEvenFib;
            currentEvenFib = nextEvenFib;
            if (nextEvenFib <= n) {
                sum += nextEvenFib;
            }
        }

        return sum;
    }
}