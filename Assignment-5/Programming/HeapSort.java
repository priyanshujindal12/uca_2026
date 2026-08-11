import java.util.Arrays;

class Heap {

    public static void sort(int[] arr) {
        int n = arr.length;
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapifyDown(arr, n, i);
        }
        for (int i = n - 1; i > 0; i--) {
            swap(arr, 0, i);
            heapifyDown(arr, i, 0);
        }
    }

    private static void heapifyDown(int[] arr, int size, int index) {

        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left >= size) {
                break;
            }

            int largerChild = left;

            if (right < size && arr[right] > arr[left]) {
                largerChild = right;
            }

            if (arr[index] >= arr[largerChild]) {
                break;
            }

            swap(arr, index, largerChild);
            index = largerChild;
        }
    }

    private static void swap(int[] arr, int i, int j) {

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

public class HeapSort {

    public static void main(String[] args) {

        int[] arr = {4, 10, 3, 5, 1};

        System.out.println("Before sorting:");
        System.out.println(Arrays.toString(arr));

        Heap.sort(arr);

        System.out.println("After sorting:");
        System.out.println(Arrays.toString(arr));
    }
}