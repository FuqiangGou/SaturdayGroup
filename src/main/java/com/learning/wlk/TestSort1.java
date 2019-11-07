package com.learning.wlk;

import java.util.Arrays;
import java.util.Collections;
import java.util.stream.IntStream;

/**
 * 2019-10-26作业
 * 题目：分别使用折半插入，shell排序，堆排序三种方式，实现找出数组中第k大的数字；
 * 要求：
 * 	1、利用以下给出接口
 * 	2、代码鲁棒性高，可以接受任何形式的输入
 * 	3、语言可C 或 Java
 * 	4、写出main函数，包含以下逻辑
 * 		自动生成字符串数组、传入接口方法，打印理想结果
 * 接口：
 * 	Java：public String solution(String[] array, int K);
 * 	C：void solution(char *array[][], int k);
 */
public class TestSort1 {

    public static void main(String[] args) {
        Sulotion solution = new Sulotion();
        String[] arrays = "12,23,34,45,34,23,34,34,245,345,254,6,7,37,7,58,4,93,8,54,9967,457,358,46,26,5,23,4234,23,23,42,43,43,4234,24".split(",");
        String result = solution.solution(arrays,5);
        System.out.println();
        System.out.println("result:"+result);

        String realresult = solution.solutionTest(arrays, 5);
        System.out.println();
        System.out.println("result:"+realresult);


    }




}
class Sulotion {

    /**
     * 折半插入
     * @param array
     * @param K
     * @return
     */
    public String solution(String[] array, int K) {
        int[] a = Arrays.stream(array).mapToInt(Integer::parseInt).toArray();
        int len = a.length;

        //将数组从大到小排列
        for (int i = 1; i < len; i++) {
            int low = 0, high = i - 1;
            int v = a[i];
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (a[mid] > v) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            int temp = a[i];
            int tempindex = i;
            while (tempindex > low) {
                a[tempindex] = a[tempindex - 1];
                tempindex--;
            }

            a[tempindex] = temp;
        }

        for(int i :a){
            System.out.print(i+" ");
        }
        return a[K - 1] + "";
    }

    /**
     * shell排序
     * @param array
     * @param K
     * @return
     */
    public String solution2(String[] array, int K) {
        return "";
    }

    public String solutionTest(String[] array, int K) {
        int[] a = Arrays.stream(array).mapToInt(Integer::parseInt).toArray();
        Arrays.sort(a);
        for(int i :a){
            System.out.print(i+" ");
        }
        return a[a.length - K] + "";
    }
}

