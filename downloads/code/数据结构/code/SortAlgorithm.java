import com.sun.org.apache.regexp.internal.recompile;

public class SortAlgorithm {

    public static void main(String[] args) {
        System.out.printf("原始数据：");
        printArray(getArray());

        System.out.printf("直接插入排序：");
        printArray(insertSort(getArray()));

        System.out.printf("冒泡排序：");
        printArray(bubbleSort(getArray()));

        System.out.printf("快速排序：");
        printArray(quickSort(getArray(), 0, getArray().length - 1));

        System.out.printf("希尔排序：");
        printArray(shellSort(getArray(), new int[] { 3, 2, 1 }, 3));

        System.out.printf("归并排序：");
        printArray(mergeSort(getArray(), 0, getArray().length - 1));

        System.out.printf("选择排序：");
        printArray(selectSort(getArray()));

        System.out.printf("堆排序：");
        printArray(heapSort(getArray()));

    }

    static int[] getArray() {
        return new int[] { 5, 8, 2, 5, 1, 6 };
    }

    static void printArray(int[] array) {
        for (int i = 0; i < array.length; i++) {
            System.out.printf(array[i] + " ");
        }
        System.out.println();
    }

    // 直接插入排序
    static int[] insertSort(int sourceArray[]) {
        int[] array = new int[sourceArray.length];
        System.arraycopy(sourceArray, 0, array, 0, sourceArray.length);
        // 将第一个数据视为有序序列,从第二个开始插入
        for (int i = 1; i < array.length; i++) {
            // 从后往前交换
            for (int j = i; j > 0; j--) {
                if (array[j] < array[j - 1]) {
                    array[j] = array[j - 1] ^ array[j];
                    array[j - 1] = array[j - 1] ^ array[j];
                    array[j] = array[j - 1] ^ array[j];
                } else {
                    break;
                }
            }
        }
        return array;
    }

    // 冒泡排序
    static int[] bubbleSort(int sourceArray[]) {
        int[] array = new int[sourceArray.length];
        System.arraycopy(sourceArray, 0, array, 0, sourceArray.length);
        for (int i = array.length - 1; i >= 0; i--) {
            for (int j = 0; j < i; j++) {
                if (array[j] > array[j + 1]) {
                    array[j] = array[j + 1] ^ array[j];
                    array[j + 1] = array[j + 1] ^ array[j];
                    array[j] = array[j + 1] ^ array[j];
                }
            }
        }
        return array;
    }

    // 快速排序
    static int[] quickSort(int array[], int start, int end) {
        int low = start, high = end;
        // 默认使用第一个元素作为枢纽
        if (low >= high) {
            return null;
        }
        int pivoitKey = array[low];

        while (low < high) {
            while (low < high && array[high] >= pivoitKey) {
                high--;
            }
            array[low] = array[high];
            while (low < high && array[low] <= pivoitKey) {
                low++;
            }
            array[high] = array[low];
        }
        array[high] = pivoitKey;
        quickSort(array, start, high - 1);
        quickSort(array, high + 1, end);
        return array;
    }

    // 希尔排序
    static int[] shellSort(int sourceArray[], int dlta[], int t) {
        int[] array = new int[sourceArray.length];
        System.arraycopy(sourceArray, 0, array, 0, sourceArray.length);
        int temp;
        for (int i = 0; i < t; i++) {
            // 直接插入排序
            int dk = dlta[i];
            for (int j = dk; j < array.length; j++) {
                // 每次只比较两个数据就行
                if (array[j] < array[j - dk]) {
                    // 后者小于前者
                    temp = array[j];
                    int m;
                    for (m = j - dk; m >= 0 && temp < array[m]; m -= dk) {
                        // 将后者插入到前者之前的间隔内的数据序列中
                        array[m + dk] = array[m];// 后移
                    }
                    array[m + dk] = temp;
                }
            }
        }
        return array;
    }

    // 归并排序
    static int[] mergeSort(int array[], int start, int end) {
        // 对sourceArray[start...end]进行归并排序
        if (start == end) {
            return array;
        } else {
            int mid = (start + end) / 2;
            array = mergeSort(array, start, mid);
            array = mergeSort(array, mid + 1, end);
            array = merge(array, start, mid, end);
        }
        return array;
    }

    static int[] merge(int array1[], int start, int mid, int end) {
        // 将有序的array1[start...mid]和array1[mid+1,end]归并为有序的array[start...end]
        int[] array = new int[array1.length];
        System.arraycopy(array1, 0, array, 0, array1.length);

        int i = start, j = mid + 1, k = start;
        for (; i <= mid && j <= end; k++) {
            if (array1[i] < array1[j]) {
                array[k] = array1[i++];
            } else {
                array[k] = array1[j++];
            }
        }
        if (i > mid) {
            for (; j <= end; k++) {
                array[k] = array1[j++];
            }
        }
        if (j > end) {
            for (; i <= mid; k++) {
                array[k] = array1[i++];
            }
        }
        return array;
    }

    // 简单选择排序
    static int[] selectSort(int[] array) {
        for (int i = 0; i < array.length; i++) {
            int minIndex = i;
            for (int j = i + 1; j < array.length; j++) {
                if (array[minIndex] > array[j]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                array[minIndex] = array[minIndex] ^ array[i];
                array[i] = array[minIndex] ^ array[i];
                array[minIndex] = array[minIndex] ^ array[i];
            }
        }
        return array;
    }

    // 堆排序
    static int[] heapSort(int array[]) {
        int index = array.length / 2;// 非终端节点,向下取整
        // 调整为大顶堆
        // 按照0开始的编号寻找子树根节点会出现问题
        for(int j= 1;j<=array.length / 2;j++)
            for (int i = index; i >= j; i--) {
                // 检查左子树
                if (2 * i <= array.length && array[2 * i - 1] > array[i - 1]) {
                    array[2 * i - 1] = array[i - 1] ^ array[2 * i - 1];
                    array[i - 1] = array[i - 1] ^ array[2 * i - 1];
                    array[2 * i - 1] = array[i - 1] ^ array[2 * i - 1];
                }
                // 检查右子树
                if (2 * i + 1 <= array.length && array[2 * i] > array[i - 1]) {
                    array[2 * i] = array[i - 1] ^ array[2 * i];
                    array[i - 1] = array[i - 1] ^ array[2 * i];
                    array[2 * i] = array[i - 1] ^ array[2 * i];
                }
            }
        
        // 排序
        for (int i = 0; i < array.length - 1; i++) {
            // 与最后一个元素交换
            array[0] = array[0] ^ array[array.length - 1 - i];
            array[array.length - 1 - i] = array[0] ^ array[array.length - 1 - i];
            array[0] = array[0] ^ array[array.length - 1 - i];
            // 重新调整
            int adjust = 1;
            int flag1 = 1, flag2 = 1;
            while (flag1 == 1 || flag2 == 1) {
                flag1 = 1;
                flag2 = 1;
                // 检查左子树
                if (2 * adjust <= array.length - i - 1 && array[2 * adjust - 1] > array[adjust - 1]) {
                    array[2 * adjust - 1] = array[adjust - 1] ^ array[2 * adjust - 1];
                    array[adjust - 1] = array[adjust - 1] ^ array[2 * adjust - 1];
                    array[2 * adjust - 1] = array[adjust - 1] ^ array[2 * adjust - 1];
                } else {
                    flag1 = 0;
                }
                // 检查右子树
                if (2 * adjust + 1 <= array.length - i - 1 && array[2 * adjust] > array[adjust - 1]) {
                    array[2 * adjust] = array[adjust - 1] ^ array[2 * adjust];
                    array[adjust - 1] = array[adjust - 1] ^ array[2 * adjust];
                    array[2 * adjust] = array[adjust - 1] ^ array[2 * adjust];
                    if(flag1 == 1)
                    {
                        array[2 * adjust] = array[2 * adjust - 1] ^ array[2 * adjust];
                        array[2 * adjust - 1] = array[2 * adjust - 1] ^ array[2 * adjust];
                        array[2 * adjust] = array[2 * adjust - 1] ^ array[2 * adjust];
                    }
                } else {
                    flag2 = 0;
                }
                if (flag1 == 1 && flag2 == 0)
                    adjust = 2 * adjust;
                else
                    adjust = 2 * adjust + 1;
            }
        }
        return array;
    }
}