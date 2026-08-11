class MinHeap {
    private int[] arr;
    private int size;
    public MinHeap(int capacity) {
        arr = new int[capacity + 1]; // 1-based indexing
        size = 0;
    }
    public void add(int value) {
        if (size == arr.length - 1) {
            throw new RuntimeException("Heap is full");
        }
        size++;
        arr[size] = value;
        heapifyUp(size);
    }
    private void heapifyUp(int index) {
        while (index > 1) {
            int parent = index / 2;
            if (arr[parent] <= arr[index]) {
                break;
            }
            swap(parent, index);
            index = parent;
        }
    }
    public int remove() {
        if (size == 0) {
            throw new RuntimeException("Heap is empty");
        }
        int min = arr[1];
        arr[1] = arr[size];
        size--;
        heapifyDown(1);
        return min;
    }
    private void heapifyDown(int index) {

        while (true) {
            int left = 2 * index;
            int right = 2 * index + 1;
            if (left > size) {
                break;
            }

            // Assume left child is smaller
            int smallerChild = left;

            // Check if right child exists and is smaller
            if (right <= size && arr[right] < arr[left]) {
                smallerChild = right;
            }

            // Heap property is already satisfied
            if (arr[index] <= arr[smallerChild]) {
                break;
            }

            swap(index, smallerChild);

            index = smallerChild;
        }
    }

    public int peek() {

        if (size == 0) {
            throw new RuntimeException("Heap is empty");
        }

        return arr[1];
    }

    public int size() {
        return size;
    }

    private void swap(int i, int j) {

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
public class MInheap{

    public static void main(String[] args) {
        
    }
}