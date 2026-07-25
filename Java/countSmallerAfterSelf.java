
import java.util.*;


public class countSmallerAfterSelf {
    int[] count;
    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        count = new int[n];
        Pair[] arr = new Pair[n];
        for (int i = 0; i < n; i++) {
            arr[i] = new Pair(nums[i], i);
        }

        mergeSort(arr, 0, n - 1);
        List<Integer> ans = new ArrayList<>();
        for (int x : count)
            ans.add(x);

        return ans;
    }
    private void mergeSort(Pair[] arr, int l, int r) {
        if (l >= r)
            return;
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
    private void merge(Pair[] arr, int l, int mid, int r) {
        int n1 = mid - l + 1;
        int n2 = r - mid;
        Pair[] left = new Pair[n1];
        Pair[] right = new Pair[n2];
        for (int i = 0; i < n1; i++)
            left[i] = arr[l + i];
        for (int j = 0; j < n2; j++)
            right[j] = arr[mid + 1 + j];
        int i = 0, j = 0, k = l;
        int rightCount = 0;
        while (i < n1 && j < n2) {
            if (left[i].value <= right[j].value) {
                count[left[i].index] += rightCount;
                arr[k++] = left[i++];
            } else {
                rightCount++;
                arr[k++] = right[j++];
            }
        }

        while (i < n1) {
            count[left[i].index] += rightCount;
            arr[k++] = left[i++];
        }

        while (j < n2) {
            arr[k++] = right[j++];
        }
    }
}
 class Pair {
        int value;
        int index;

        Pair(int value, int index) {
            this.value = value;
            this.index = index;
        }
    }