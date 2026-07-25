class inversionCount {
   
    public static  int inversionCount(int arr[]) {
        // code here
        return mergeSort(arr,0,arr.length-1);
        
    }

    public static  int mergeSort(int arr[], int l, int r) {
        if (l >= r) {
            return 0;
        }
        int count=0;
        int mid = l + (r - l) / 2;
        count+=mergeSort(arr, l, mid);
        count+=mergeSort(arr, mid + 1, r);
        count+=merge(arr, l, mid, r);
        return count;
    }

    private static  int merge(int arr[], int l, int mid, int r) {
        int count=0;
        int n1 = mid - l + 1;
        int n2 = r - mid;
        int left[] = new int[n1];
        int right[] = new int[n2];
        for (int i = 0; i < n1; i++) {
            left[i] = arr[l + i];
        }
        for (int j = 0; j < n2; j++) {
            right[j] = arr[mid + 1 + j];
        }
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
                count+=n1-i;
            }
        }
        while (i < n1) {
            arr[k++] = left[i++];
        }
        while (j < n2) {
            arr[k++] = right[j++];
        }
        return count;
    }
    public static void main(String[] args) {
        int[] arr={5,4,3,2,1};
        int x= inversionCount(arr);
        System.out.println(x);
    }
}