import java.util.*;
class ClinicAndVillages{
    public int minimizedMaximum(int n, int[] quantities) {
        int m = quantities.length;
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        for (int q : quantities) {
            pq.offer(new Pair(q, 1));
        }
        n = n - m;
        while (n > 0) {
            Pair p = pq.poll();
            p.partition++;
            pq.offer(p);
            n--;
        }
        return pq.peek().load();
    }
    public static void main(String[] args) {
        
    }
}
class Pair implements Comparable<Pair> {
    int quantity;
    int partition;
    Pair(int quantity, int partition) {
        this.quantity = quantity;
        this.partition = partition;
    }
    int load() {
        return (quantity + partition - 1) / partition;
    }
    public int compareTo(Pair other) {
        return Integer.compare(other.load(), this.load());
    }
}