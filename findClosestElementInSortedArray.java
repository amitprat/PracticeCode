public static int getClosestK(int[] a, int x) {

    int low = 0;
    int high = a.length - 1;

    if (high < 0)
        throw new IllegalArgumentException("The array cannot be empty");

    while (low < high) {
        int mid = (low + high) / 2;
        assert(mid < high);
        int d1 = Math.abs(a[mid  ] - x);
        int d2 = Math.abs(a[mid+1] - x);
        if (d2 <= d1)
        {
            low = mid+1;
        }
        else
        {
            high = mid;
        }
    }
    return a[high];
}
