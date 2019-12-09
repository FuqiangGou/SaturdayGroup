package com.learning.wlk.Tree.RBTree;

import java.util.HashMap;
import java.util.TreeMap;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ConcurrentHashMap;

/**
 * https://note.youdao.com/ynoteshare1/index.html?id=3587eff2cc7099af310943f845ed53a4&type=note
 */
public class TestRB {
    public static void main(String[] args) {
        MyRBTree<String,Integer> tree = new MyRBTree<>();
        for(int i = 0;i<10;i++) {
            tree.insert(i+"", 1);
        }
        System.out.println(tree.get("1"));
    }

}
