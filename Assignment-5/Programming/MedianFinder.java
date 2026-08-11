import java.util.*;
class MedianFinder {
    PriorityQueue<Integer> maxheap;
    PriorityQueue<Integer> minheap;
    public MedianFinder() {
        maxheap=new PriorityQueue<>(Collections.reverseOrder());
        minheap=new PriorityQueue<>();
    }
    public void addNum(int num) {
        if(maxheap.size()==0)maxheap.add(num);
        else{
            if(maxheap.peek()>num)maxheap.add(num);
            else minheap.add(num);
        }
        if(maxheap.size()>=minheap.size()+2){
            minheap.add(maxheap.remove());
        }

        if(minheap.size()>=maxheap.size()+2){
            maxheap.add(minheap.remove());
        }
    }
    
    public double findMedian() {
        if(maxheap.size()==minheap.size()){
            return (maxheap.peek()+minheap.peek())/2.0;
        }
        else if(maxheap.size()>minheap.size())return maxheap.peek();
        else return minheap.peek();
    }
}

