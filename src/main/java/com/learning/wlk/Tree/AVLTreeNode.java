package com.learning.wlk.Tree;

public class AVLTreeNode<T extends  Comparable> {
    public  AVLTreeNode<T> left;
    public  AVLTreeNode<T> right;
    public int height;
    public  T key;


    public AVLTreeNode(T key, AVLTreeNode<T> left, AVLTreeNode<T> right) {
        this.key = key;
        this.left = left;
        this.right = right;
        this.height = 1;
    }
}
